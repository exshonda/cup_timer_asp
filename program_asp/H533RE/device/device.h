/*
 *
 * Device Driver for CUP Noodle Timer (NUCLEO-H533RE)
 *
 */

/*
 *  LED connected Port  (LED1-4 = PA8/PA7/PA6/PA5)
 */
#define LED1_PINPOS		8
#define LED2_PINPOS		7
#define LED3_PINPOS		6
#define LED4_PINPOS		5

/*
 *  LED connected Bit
 */
#define LED1	(1<<LED1_PINPOS)
#define LED2	(1<<LED2_PINPOS)
#define LED3	(1<<LED3_PINPOS)
#define LED4	(1<<LED4_PINPOS)

#define LED_MASK	(LED1 | LED2 | LED3 | LED4)

#ifndef TOPPERS_MACRO_ONLY

/*
 *  LED Connected Port Initialize
 */
extern void led_init(intptr_t exinf);

/*
 *  LED State Set
 */
extern void led_out(unsigned short led);

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  Slide Switch Connected Port
 *  H533RE: SW1-3 = PB3/PB4/PB5 (GPIOB), SW4 = PC9 (GPIOC, Arduino D10)
 *  （F401RE は SW4=PB6。Arduino D10 のMCUピンがH533REで異なるため SW4 のみ別ポート）
 *  SWx_PINNO は論理ビット位置兼 SW1-3 のGPIOBピン位置。SW4 の物理ピンは SW4_PC_PINNO。
 */
#define SW1_PINNO	3
#define SW2_PINNO	4
#define SW3_PINNO	5
#define SW4_PINNO	6
#define SW4_PC_PINNO	9	/* SW4 物理ピン: PC9 */

/*
 *  Slide Switch Connected Bit
 */
#define SW1			(1 << SW1_PINNO)
#define SW2			(1 << SW2_PINNO)
#define SW3			(1 << SW3_PINNO)
#define SW4			(1 << SW4_PINNO)
#define SW_MASK		(SW1|SW2|SW3|SW4)

#ifndef TOPPERS_MACRO_ONLY

/*
 *  Initialize Slide Switch Connected Port Function
 */
extern void switch_slide_init(intptr_t exinf);

/*
 *  Read Slide Switch State
 */
extern unsigned int switch_slide_sense(void);

#endif /* TOPPERS_MACRO_ONLY */

/*
 *  PUSH Switch Connected Port
 *  H533RE: PUSH1 = PC7 (Arduino D8), PUSH2 = PC8 (Arduino D2)
 *  （F401RE は PA9/PA10。押下=High のため内部プルダウンを使用）
 */
#define PUSH1_PINNO		7
#define PUSH2_PINNO		8

/*
 *  PUSH Switch Connected Bit
 */
#define PUSH1			(1 << PUSH1_PINNO)
#define PUSH2			(1 << PUSH2_PINNO)
#define PUSH_MASK		(PUSH1|PUSH2)

#ifndef TOPPERS_MACRO_ONLY

/*
 *  Initialize PUSH Switch Connected Port Function
 */
extern void switch_push_init(intptr_t exinf);

/*
 *  Read PUSH Switch State
 */
extern unsigned int switch_push_sense(void);

#endif /* TOPPERS_MACRO_ONLY */

/*
 *   PUSH1/PUSH2 の EXTI 割込（cup_timer では未使用。周期ハンドラでポーリングするため）
 *   参考として宣言のみ残す。
 */
#define INTNO_PUSH1   (23 + 16)
#define INHNO_PUSH1   (23 + 16)
#define INTNO_PUSH2   (40 + 16)
#define INHNO_PUSH2   (40 + 16)

#ifndef TOPPERS_MACRO_ONLY

extern void exti9_5_init(intptr_t ilvl);
#define push1_int_init exti9_5_init
extern void exti9_5_clear(void);
#define push1_int_clear exti9_5_clear

extern void exti15_10_init(intptr_t ilvl);
#define push2_int_init exti15_10_init
extern void exti15_10_clear(void);
#define push2_int_clear exti15_10_clear

#endif /* TOPPERS_MACRO_ONLY */

/*
 * LED and Switch state Macro
 */
#define ON		1
#define OFF		0

#ifndef TOPPERS_MACRO_ONLY

/*
 *  Set Individual LED
 */
extern void set_led1_state(unsigned char state);
extern void set_led2_state(unsigned char state);
extern void set_led3_state(unsigned char state);
extern void set_led4_state(unsigned char state);

/*
 *  Get Individual Slide Switch
 */
extern unsigned char get_sw1_state(void);
extern unsigned char get_sw2_state(void);
extern unsigned char get_sw3_state(void);
extern unsigned char get_sw4_state(void);

/*
 *  Get Individual Push Switch
 */
extern unsigned char get_push1_state(void);
extern unsigned char get_push2_state(void);

#endif /* TOPPERS_MACRO_ONLY */
