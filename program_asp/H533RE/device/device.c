/*
 *
 * Device Driver for CUP Noodle Timer (NUCLEO-H533RE)
 *
 *  H5化: 生レジスタ(F4絶対番地)を CMSIS 構造体アクセスに置換。
 *  ピン: LED1-4=PA8/7/6/5, SW1-3=PB3/4/5, SW4=PC9, PUSH1/2=PC7/PC8(内部プルダウン)。
 *  スイッチは周期ハンドラからポーリングで読む（EXTI割込はcup_timer未使用）。
 */
#include <kernel.h>
#include "device.h"
#include "stm32h5xx.h"

/*
 * Initialize Interrupt (CMSIS NVIC)
 */
void
init_int(IRQn_Type irq, unsigned char pri){
	NVIC_SetPriority(irq, pri);
	NVIC_EnableIRQ(irq);
}

/* ---- LED (PA5..PA8 output) ---- */
void
led_init(intptr_t exinf){
	unsigned int pins[4] = { LED1_PINPOS, LED2_PINPOS, LED3_PINPOS, LED4_PINPOS };
	int i;

	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOAEN;
	for (i = 0; i < 4; i++) {
		unsigned int p = pins[i];
		GPIOA->MODER = (GPIOA->MODER & ~(3u << (p*2))) | (1u << (p*2)); /* output */
	}
}

void
led_out(unsigned short led_data){
	unsigned int reg = GPIOA->ODR & ~((unsigned int)LED_MASK);
	GPIOA->ODR = reg | (led_data & LED_MASK);
}

/* ---- PUSH switch (PC7=PUSH1, PC8=PUSH2 入力, 内部プルダウン) ----
 * ボタンは押下でHigh。外部プルが無く浮くため内部プルダウンで idle=Low とする。 */
void
switch_push_init(intptr_t exinf){
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
	GPIOC->MODER &= ~(3u << (PUSH1_PINNO*2));   /* PC7 input */
	GPIOC->MODER &= ~(3u << (PUSH2_PINNO*2));   /* PC8 input */
	GPIOC->PUPDR = (GPIOC->PUPDR & ~((3u<<(PUSH1_PINNO*2))|(3u<<(PUSH2_PINNO*2))))
				 | ((2u<<(PUSH1_PINNO*2))|(2u<<(PUSH2_PINNO*2)));  /* pull-down */
}

unsigned int
switch_push_sense(void){
	return GPIOC->IDR & PUSH_MASK;
}

/* ---- Slide switch (SW1-3=PB3/4/5, SW4=PC9 入力, no pull) ---- */
void
switch_slide_init(intptr_t exinf){
	unsigned int pins[3] = { SW1_PINNO, SW2_PINNO, SW3_PINNO };
	int i;

	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOBEN | RCC_AHB2ENR_GPIOCEN;
	for (i = 0; i < 3; i++) {               /* SW1-3 on GPIOB */
		unsigned int p = pins[i];
		GPIOB->MODER &= ~(3u << (p*2));     /* input */
		GPIOB->PUPDR &= ~(3u << (p*2));     /* no pull */
	}
	GPIOC->MODER &= ~(3u << (SW4_PC_PINNO*2));   /* SW4 = PC9 input */
	GPIOC->PUPDR &= ~(3u << (SW4_PC_PINNO*2));   /* no pull */
}

/* SW1-3 を GPIOB から、SW4(PC9) を GPIOC から読み、論理ビット(SW1..SW4)に合成 */
unsigned int
switch_slide_sense(void){
	unsigned int v = GPIOB->IDR & (SW1 | SW2 | SW3);
	if (GPIOC->IDR & (1u << SW4_PC_PINNO)) v |= SW4;
	return v;
}

/* ---- EXTI ヘルパ（cup_timer 未使用。PUSH=PC7/PC8 → EXTIブロックでポートC選択） ---- */
static void
connect_exti_to_gpioc(unsigned int pinpos){
	unsigned int idx = pinpos >> 2;          /* EXTICR[idx] */
	unsigned int sh  = (pinpos & 0x3) * 8;   /* byte field  */
	EXTI->EXTICR[idx] = (EXTI->EXTICR[idx] & ~(0xFFu << sh)) | (2u << sh); /* 2 = GPIOC */
}

static void
init_exti(unsigned int pinpos){
	EXTI->RTSR1 |=  (1u << pinpos);   /* rising  */
	EXTI->FTSR1 &= ~(1u << pinpos);
	EXTI->RPR1   =  (1u << pinpos);   /* clear pending */
	EXTI->IMR1  |=  (1u << pinpos);   /* unmask  */
}

void
exti9_5_init(intptr_t ilvl){
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
	GPIOC->MODER &= ~(3u << (PUSH1_PINNO*2));
	GPIOC->PUPDR = (GPIOC->PUPDR & ~(3u<<(PUSH1_PINNO*2))) | (2u<<(PUSH1_PINNO*2));
	connect_exti_to_gpioc(PUSH1_PINNO);
	init_exti(PUSH1_PINNO);
}

void
exti9_5_clear(void){
	EXTI->RPR1 = (1u << PUSH1_PINNO);
}

void
exti15_10_init(intptr_t ilvl){
	RCC->AHB2ENR |= RCC_AHB2ENR_GPIOCEN;
	GPIOC->MODER &= ~(3u << (PUSH2_PINNO*2));
	GPIOC->PUPDR = (GPIOC->PUPDR & ~(3u<<(PUSH2_PINNO*2))) | (2u<<(PUSH2_PINNO*2));
	connect_exti_to_gpioc(PUSH2_PINNO);
	init_exti(PUSH2_PINNO);
}

void
exti15_10_clear(void){
	EXTI->RPR1 = (1u << PUSH2_PINNO);
}

/*
 *  LED State Variable
 */
static unsigned short LedState;

void
set_led_state(unsigned short led, unsigned char state){
	if (state == ON) LedState |= led; else LedState &= ~led;
	led_out(LedState);
}
void set_led1_state(unsigned char s){ set_led_state(LED1, s); }
void set_led2_state(unsigned char s){ set_led_state(LED2, s); }
void set_led3_state(unsigned char s){ set_led_state(LED3, s); }
void set_led4_state(unsigned char s){ set_led_state(LED4, s); }

/*
 *  Get Individual Slide Switch
 */
unsigned char get_sw1_state(void){ return ((switch_slide_sense() & SW1) == SW1) ? ON : OFF; }
unsigned char get_sw2_state(void){ return ((switch_slide_sense() & SW2) == SW2) ? ON : OFF; }
unsigned char get_sw3_state(void){ return ((switch_slide_sense() & SW3) == SW3) ? ON : OFF; }
unsigned char get_sw4_state(void){ return ((switch_slide_sense() & SW4) == SW4) ? ON : OFF; }

/*
 *  Get Individual Push Switch
 */
unsigned char get_push1_state(void){ return ((switch_push_sense() & PUSH1) == PUSH1) ? ON : OFF; }
unsigned char get_push2_state(void){ return ((switch_push_sense() & PUSH2) == PUSH2) ? ON : OFF; }
