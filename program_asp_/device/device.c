/*
 * 
 * Device Driver for CUP Noodle Timer
 *
 */
#include <kernel.h>
#include "device.h"
#include "stm32f4xx.h"

/*
 *  Programmable I/O Port
 */
#define TADR_SYSCFG_EXTICR	0x40013808	/* EXTI CONF Register */
#define TADR_EXTI_IMR		0x40013C00	/* EXTI INT MASK Register */
#define TADR_EXTI_EMR		0x40013C04	/* EXTI EVENT MASK Register */
#define TADR_EXTI_RTSR		0x40013C08	/* EXTI RISE TRIGGER Register */
#define TADR_EXTI_FTSR		0x40013C0C	/* EXTI FALL TRIGGER Register */
#define TADR_EXTI_PR		0x40013C14	/* EXTI PEND Register */
#define TADR_RCC_AHB1ENR	0x40023830	/* RCC AHB1ENR Register */
#define TADR_RCC_APB2ENR	0x40023844	/* RCC APB2EN Register */
#define TADR_GPIOA_MODER	0x40020000	/* A Port MODE Register */
#define TADR_GPIOA_ODR		0x40020014	/* A Port Output Data Register */
#define TADR_GPIOA_PUPDR	0x4002000C	/* A Port PUPD Register */
#define TADR_GPIOA_IDR		0x40020010	/* A Port ID Register */
#define TADR_GPIOB_MODER	0x40020400	/* B Port MODE Register */
#define TADR_GPIOB_PUPDR	0x4002040C	/* B Port PUPD Register */
#define TADR_GPIOB_IDR		0x40020410	/* B Port ID Register */
#define TADR_SCB_AIRCR		0xE000ED0C	/* SCB AIRCR Register */
#define TADR_NVIC_ISER		0xE000E100	/* NVIC INT SET ENABLE Register */
#define TADR_NVIC_ICER		0xE000E180	/* NVIC INT CLR ENABLE Register */
#define TADR_NVIC_IP		0xE000E400	/* NVIC IP Register */

#define TREG_SYSCFG_EXTICR	((volatile unsigned long *)(TADR_SYSCFG_EXTICR))	/* EXTI CONF Register */
#define TREG_EXTI_IMR		((volatile unsigned long *)(TADR_EXTI_IMR))			/* EXTI INT MASK Register */
#define TREG_EXTI_EMR		((volatile unsigned long *)(TADR_EXTI_EMR))			/* EXTI EVENT MASK Register */
#define TREG_EXTI_RTSR		((volatile unsigned long *)(TADR_EXTI_RTSR))		/* EXTI RISE TRIGGER Register */
#define TREG_EXTI_FTSR		((volatile unsigned long *)(TADR_EXTI_FTSR))		/* EXTI FALL TRIGGER Register */
#define TREG_EXTI_PR		((volatile unsigned long *)(TADR_EXTI_PR))			/* EXTI PEND Register */
#define TREG_RCC_AHB1ENR	((volatile unsigned long *)(TADR_RCC_AHB1ENR))		/* RCC AHB1EN Register */
#define TREG_RCC_APB2ENR	((volatile unsigned long *)(TADR_RCC_APB2ENR))		/* RCC APB2EN Register */
#define TREG_GPIOA_MODER	((volatile unsigned long *)(TADR_GPIOA_MODER))		/* A Port MODE Register */
#define TREG_GPIOA_ODR		((volatile unsigned long *)(TADR_GPIOA_ODR))		/* A Port Output Data Register */
#define TREG_GPIOA_PUPDR	((volatile unsigned long *)(TADR_GPIOA_PUPDR))		/* A Port PUPD Register */
#define TREG_GPIOA_IDR		((volatile unsigned long *)(TADR_GPIOA_IDR))		/* A Port ID Register */
#define TREG_GPIOB_MODER	((volatile unsigned long *)(TADR_GPIOB_MODER))		/* B Port MODE Register */
#define TREG_GPIOB_PUPDR	((volatile unsigned long *)(TADR_GPIOB_PUPDR))		/* B Port OUT PUPD Register */
#define TREG_GPIOB_IDR		((volatile unsigned long *)(TADR_GPIOB_IDR))		/* B Port ID Register */
#define TREG_SCB_AIRCR		((volatile unsigned long *)(TADR_SCB_AIRCR))
#define TREG_NVIC_ISER		((volatile unsigned long *)(TADR_NVIC_ISER))		/* NVIC INT SET ENABLE Register */
#define TREG_NVIC_ICER		((volatile unsigned long *)(TADR_NVIC_ISER))		/* NVIC INT CLR ENABLE Register */
#define TREG_NVIC_IP		((volatile unsigned long *)(TADR_NVIC_IP))			/* NVIC IP Register */

#define EXTI_PortSourceGPIOA   (0x00)

/*
 * NVIC Priority Offset
 */
#define NVIC_PRI_OFFSET 4

/*
 * Initialize Interrupt
 */
void
init_int(unsigned char no, unsigned char pri){
	unsigned char tmppri;
	unsigned int  regno;
	unsigned int  offset;
	unsigned int  reg;

	/* Set value  */
	tmppri = pri << NVIC_PRI_OFFSET;
	/* Registor number */
	regno = no >> 2;
	/* Bit offset */
	offset = 8 * (no & 0x03);

	/* Set Priority */
	reg = TREG_NVIC_IP[regno];
	reg &= ~(0xFF << offset);
	reg |= tmppri << offset;
	TREG_NVIC_IP[regno] = reg;

	/* Enable the Selected IRQ Channels */
	TREG_NVIC_ISER[no >> 0x05] = 0x01 << (no & 0x1F);
}

/*
 *  LED Connected Port Initialize
 */ 
void
led_init(intptr_t exinf){
	unsigned long reg;

	*TREG_RCC_AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	/* Set As Output Mode */
	reg = *TREG_GPIOA_MODER & ~(0x03 << (LED1_PINPOS * 2));
	*TREG_GPIOA_MODER = reg | (0x01 << (LED1_PINPOS * 2));

	reg = *TREG_GPIOA_MODER & ~(0x03 << (LED2_PINPOS * 2));
	*TREG_GPIOA_MODER = reg | (0x01 << (LED2_PINPOS * 2));

	reg = *TREG_GPIOA_MODER & ~(0x03 << (LED3_PINPOS * 2));
	*TREG_GPIOA_MODER = reg | (0x01 << (LED3_PINPOS * 2));

	reg = *TREG_GPIOA_MODER & ~(0x03 << (LED4_PINPOS * 2));
	*TREG_GPIOA_MODER = reg | (0x01 << (LED4_PINPOS * 2));
}

/*
 *  LED Set Function
 */
void
led_out(unsigned short led_data){
	unsigned int reg;
	
	reg = *TREG_GPIOA_ODR;
	reg = reg & ~LED_MASK;

	led_data = led_data & LED_MASK;
	
	reg = reg | led_data;
	*TREG_GPIOA_ODR = reg;
}

/*
 *  Initialize PUSH Switch Connected Port Function
 */
void
switch_push_init(intptr_t exinf){
	/* Set as input port */
	/* Enable the BUTTON Clock */
	*TREG_RCC_AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	/* Configure Button pin as input */
	*TREG_GPIOA_MODER &= ~(0x03 << (PUSH1_PINNO * 2));
	*TREG_GPIOA_MODER &= ~(0x03 << (PUSH2_PINNO * 2));

	/* Pull-up Pull down resistor configuration*/
	*TREG_GPIOA_PUPDR &= ~(0x03 << (PUSH1_PINNO * 2));
	*TREG_GPIOA_PUPDR &= ~(0x03 << (PUSH2_PINNO * 2));
}

/*
 *  Read PUSH Switch State
 */
unsigned int
switch_push_sense(void){
	unsigned int reg;

	reg = *TREG_GPIOA_IDR;

	return reg & PUSH_MASK;
}

/*
 *  Initialize Slide Switch Connected Port Function
 */
void
switch_slide_init(intptr_t exinf){
	/* Enable the BUTTON Clock */
	*TREG_RCC_AHB1ENR |= RCC_AHB1ENR_GPIOBEN;

	/* Configure Button pin as input */
	*TREG_GPIOB_MODER &= ~(0x03 << (SW1_PINNO * 2));
	
	*TREG_GPIOB_MODER &= ~(0x03 << (SW2_PINNO * 2));
	*TREG_GPIOB_MODER &= ~(0x03 << (SW3_PINNO * 2));
	*TREG_GPIOB_MODER &= ~(0x03 << (SW4_PINNO * 2));

	/* Pull-up Pull down resistor configuration*/
	*TREG_GPIOB_PUPDR &= ~(0x03 << (SW1_PINNO * 2));
	*TREG_GPIOB_PUPDR &= ~(0x03 << (SW2_PINNO * 2));
	*TREG_GPIOB_PUPDR &= ~(0x03 << (SW3_PINNO * 2));
	*TREG_GPIOB_PUPDR &= ~(0x03 << (SW4_PINNO * 2));
}

/*
 *  Read Slide Switch State
 */
unsigned int
switch_slide_sense(void){
	unsigned int reg;

	reg = *TREG_GPIOB_IDR;

	return reg & SW_MASK;
}

/*
 * Connect EXTI Line to GPIO Pin
 */
static void
connect_exti_to_gpioa(unsigned int pinpos) {
	unsigned long reg;

	/* Connect Button EXTI Line to Button GPIO Pin */
	reg = 0x04 * (pinpos & 0x03);
	TREG_SYSCFG_EXTICR[pinpos >> 0x02] &= ~(0x0F << reg);
	TREG_SYSCFG_EXTICR[pinpos >> 0x02] |= EXTI_PortSourceGPIOA << reg;
}

/*
 * Initilize EXTI
 */
static void
init_exti(unsigned int pinpos) {
	/* Configure Button EXTI line */
	/* Clear EXTI line configuration */
	*TREG_EXTI_IMR &= ~(1<<pinpos);
	*TREG_EXTI_EMR &= ~(1<<pinpos);
	*TREG_EXTI_IMR |= 1<<pinpos;

	/* Clear Rising Falling edge configuration */
	*TREG_EXTI_RTSR &= ~(1<<pinpos);
	*TREG_EXTI_FTSR &= ~(1<<pinpos);
	*TREG_EXTI_RTSR |= 1<<pinpos;
}


/*
 *  Initlize EXTI9_5(PUSH1) Interrupt
 */
void
exti9_5_init(intptr_t ilvl){
	/* Set as input port */
	/* Enable the BUTTON Clock */
	*TREG_RCC_AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	*TREG_RCC_APB2ENR |= RCC_APB2ENR_SYSCFGEN;

	/* Configure Button pin as input */
	*TREG_GPIOA_MODER &= ~(0x03 << (PUSH1_PINNO * 2));

	/* Pull-up Pull down resistor configuration*/
	*TREG_GPIOA_PUPDR &= ~(0x03 << (PUSH1_PINNO * 2));

	/* Connect Button EXTI Line to Button GPIO Pin */
	connect_exti_to_gpioa(PUSH1_PINNO);
	/* Initilize EXTI */
	init_exti(PUSH1_PINNO);
}

/*
 *  Clear EXTI9_5(PUSH1) Interrupt
 */
void
exti9_5_clear(void) {
	*TREG_EXTI_PR = (1<<PUSH1_PINNO);
}

/*
 *  Initlize EXTI15_10(PUSH2) Interrupt
 */
void
exti15_10_init(intptr_t ilvl){
	/* Set as input port */
	/* Enable the BUTTON Clock */
	*TREG_RCC_AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	*TREG_RCC_APB2ENR |= RCC_APB2ENR_SYSCFGEN;

	/* Configure Button pin as input */
	*TREG_GPIOA_MODER &= ~(0x03 << (PUSH2_PINNO * 2));

	/* Pull-up Pull down resistor configuration*/
	*TREG_GPIOA_PUPDR &= ~(0x03 << (PUSH2_PINNO * 2));

	/* Connect Button EXTI Line to Button GPIO Pin */
	connect_exti_to_gpioa(PUSH2_PINNO);
	/* Initilize EXTI */
	init_exti(PUSH2_PINNO);
}

/*
 *  Clear EXTI5_10(PUSH2) Interrupt
 */
void
exti15_10_clear(void) {
	*TREG_EXTI_PR = (1<<PUSH2_PINNO);
}

/*
 *  LED State Variable
 */
unsigned short LedState;

/*
 *  Set Individual LED
 */
void 
set_led_state(unsigned short led, unsigned char state){
	if (state == ON) {
		LedState = LedState | led;
	} else {
		LedState = LedState & ~led;
	}
	led_out(LedState);
}

void
set_led1_state(unsigned char state){ 
	set_led_state(LED1, state);
}

void
set_led2_state(unsigned char state){
	set_led_state(LED2, state);
}

void
set_led3_state(unsigned char state){
	set_led_state(LED3, state);
}

void
set_led4_state(unsigned char state){
	set_led_state(LED4, state);
}

/*
 *  Get Individual Slide Switch
 */
unsigned char
get_sw1_state(void) {
	if((switch_slide_sense() & SW1) == SW1){
		return ON;
	}
	else {
		return OFF;
	}
}

unsigned char
get_sw2_state(void) {
	if((switch_slide_sense() & SW2) == SW2){
		return ON;
	}
	else {
		return OFF;
	}
}

unsigned char
get_sw3_state(void) {
	if((switch_slide_sense() & SW3) == SW3){
		return ON;
	}
	else {
		return OFF;
	}
}

unsigned char
get_sw4_state(void) {
	if((switch_slide_sense() & SW4) == SW4){
		return ON;
	}
	else {
		return OFF;
	}
}

/*
 *  Get Individual Push Switch
 */
unsigned char
get_push1_state(void){
	if((switch_push_sense() & PUSH1) == PUSH1){
		return ON;
	}
	else {
		return OFF;
	}
}

unsigned char
get_push2_state(void){
	if((switch_push_sense() & PUSH2) == PUSH2){
		return ON;
	}
	else {
		return OFF;
	}
}
