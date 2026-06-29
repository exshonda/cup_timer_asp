/*
 *  Copyright (C) 2006 by Nagoya University Extension Course for
 *                       Embedded Software Specialists(NEXCESS), JAPAN
 *                2014-2018 by Nagoya University
 *                        Graduate School of Information Science
 *                        Center for Embedded Computing Systems(NCES), JAPAN
 *                2014 by Mitsuhiro Matsuura
 */

/*
 *  Task Priority
 */

#define DEFAULT_PRIORITY    8

/*
 *  Constant Definition
 */

#define STACK_SIZE      4096    /* Task Stack Size */


#define LED1_BLINK_INTERVAL 1000    /* LED1 Blink Cycle */
#define LED4_BLINK_INTERVAL 250     /* LED4 Blink Cycle */
#define SW_SCAN_INTERVAL    10      /* SW Scan Cycle    */
#define BASE_TIME_INTERVAL  1000    /* Time Unit        */

#define INIT_TIME       30  /* Timeout Time at Startup     */
#define EXTRA_UNIT      30  /* Time Extension Unit         */
#define TIMEOUT_BLINK   60  /* Blink Time at Timeout       */
#define ACT_INTERVAL    10  /* Timer Active LED Interval   */
#define ACT_BLINK_TIME  4   /* Timer Active LED Blink Time */


/*
 *  Function Prototype Declaration
 */

#ifndef TOPPERS_MACRO_ONLY
extern void led_init(intptr_t exinf);
extern void switch_slide_init(intptr_t exinf);
extern void switch_push_init(intptr_t exinf);
extern void timer_task(intptr_t exinf);
extern void blink_task(intptr_t exinf);
extern void cup_timer_init(intptr_t exinf);
extern void led1_blink_handler(intptr_t exinf);
extern void led4_blink_time_handler(intptr_t exinf);
extern void sw_scan_handler(intptr_t exinf);
extern void base_time_handler(intptr_t exinf);
#endif /* TOPPERS_MACRO_ONLY */
