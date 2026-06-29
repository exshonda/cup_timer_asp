/*
 *  Copyright (C) 2006 by Nagoya University Extension Course for
 *                       Embedded Software Specialists(NEXCESS), JAPAN
 *                2014 by Nagoya University
 *                        Graduate School of Information Science
 *                        Center for Embedded Computing Systems(NCES), JAPAN
 *                2014 by Mitsuhiro Matsuura
 */

/*
 * カップラーメンタイマ
 */

#include <kernel.h>
#include "kernel_cfg.h"
#include <t_syslog.h>
#include <t_stdlib.h>
#include "device.h"
#include "cup_timer.h"

/*
 *  API Error Log Output Function
 */
Inline void
svc_perror(const char *file, int_t line, const char *expr, ER ercd)
{
	if (ercd < 0) {
		t_perror(LOG_ERROR, file, line, expr, ercd);
	}
}

#define SVC_PERROR(expr)	svc_perror(__FILE__, __LINE__, #expr, (expr))


/*
 *  Glboal Variable
 */
unsigned char sw1;
unsigned char sw8;

/*
 *  Timer Task Flag Bit Assigment
 */
#define TIMER_SW1_ON	0x01
#define TIMER_SW1_OFF	0x02
#define TIMER_PUSH1_ON	0x04
#define TIMER_BASE_TIME	0x08
#define TIMER_ALL		0x0f

/*
 *  Blink Task Flag Bit Assigment
 */
#define BLINK_ACTIVE	0x01
#define BLINK_TIMEOUT	0x02
#define BLINK_BLINK		0x04
#define BLINK_OFF		0x08
#define BLINK_ALL		0x0f


/*
 *  Timer Task
 */
void
timer_task(intptr_t exinf)
{
	int timer;
	FLGPTN flgptn;

	for (;;) {
		timer = 0;
		do {
			wai_flg(FLG_TIMER, TIMER_ALL, TWF_ORW, &flgptn);
			if ((flgptn & TIMER_SW1_ON) != 0) {
				timer = INIT_TIME;
				set_flg(FLG_BLINK, BLINK_ACTIVE);
				syslog(LOG_NOTICE, "Timer start!");
			}
			if ((flgptn & TIMER_SW1_OFF) != 0) {
				set_flg(FLG_BLINK, BLINK_OFF);
				syslog(LOG_NOTICE, "Timer stop!");
			}
		} while (timer == 0);

		sta_cyc(BASE_TIME_HANDLER);
		while (timer > 0) {
			wai_flg(FLG_TIMER, TIMER_ALL, TWF_ORW, &flgptn);
			if ((flgptn & TIMER_SW1_OFF) != 0) {
				set_flg(FLG_BLINK, BLINK_OFF);
				syslog(LOG_NOTICE, "Timer stop!");
				timer = 0;
			}
			else {
				if ((flgptn & TIMER_PUSH1_ON) != 0) {
					timer = timer + EXTRA_UNIT;
					syslog(LOG_NOTICE, "Extend %d sec. Remaining  %d sec",
							EXTRA_UNIT, timer);
				}
				if ((flgptn & TIMER_BASE_TIME) != 0) {
					timer = timer - 1;
					if (timer == 0) {
						set_flg(FLG_BLINK, BLINK_TIMEOUT);
						syslog(LOG_NOTICE, "Timer timeout");
					}
					else if ((timer % ACT_INTERVAL) == 0) {
						set_flg(FLG_BLINK, BLINK_ACTIVE);
						syslog(LOG_NOTICE, "Remaining  %d sec", timer);

					}
				}
			}
		}
		stp_cyc(BASE_TIME_HANDLER);
	}
}


/*
 *  LED4 Blink Task
 */
void
blink_task(intptr_t exinf)
{
	int bcount;
	FLGPTN flgptn;
	unsigned char sta_led = OFF;

	for (;;) {
		bcount = 0;
		do {
			wai_flg(FLG_BLINK, BLINK_ALL, TWF_ORW, &flgptn);
			if ((flgptn & BLINK_ACTIVE) != 0) {
				bcount = ACT_BLINK_TIME;
			}
			if ((flgptn & BLINK_TIMEOUT) != 0) {
				bcount = TIMEOUT_BLINK;
			}
		} while (bcount == 0);

		sta_cyc(LED4_BLINK_TIME_HANDLER);
		while (bcount > 0) {
			wai_flg(FLG_BLINK, BLINK_ALL, TWF_ORW, &flgptn);
			if ((flgptn & BLINK_BLINK) != 0) {
				if(sta_led == ON)
					sta_led = OFF;
				else
					sta_led = ON;
				set_led4_state(sta_led);
				bcount--;
			}
			if ((flgptn & BLINK_OFF) != 0) {
				sta_led = OFF;
				set_led4_state(sta_led);
				bcount = 0;
			}
		}
		stp_cyc(LED4_BLINK_TIME_HANDLER);
	}
}


/*
 *  Initialization Routine
 */
void
cup_timer_init(intptr_t exinf)
{
	sw8 = get_push1_state();
	sw1 = get_sw1_state();
}


/*
 *  LED1 Blink Cyclic Handler
 */
void
led1_blink_handler(intptr_t exinf){
	static unsigned char sta_led = OFF;

	if (sta_led == ON) {
		sta_led = OFF;
	} else {
		sta_led = ON;
	}

	set_led1_state(sta_led);
}


/*
 *  LED4 Blink Time Generate Cyclic Handler
 */
void
led4_blink_time_handler(intptr_t exinf){
	SVC_PERROR(iset_flg(FLG_BLINK, BLINK_BLINK));
}


/*
 *  Switch State Scan Cyclic Handler
 */
void
sw_scan_handler(intptr_t exinf){
	unsigned char sw;
	FLGPTN flgptn = 0;

	sw = get_sw1_state();
	if (sw1 != sw) {
		if (sw == ON) {
			flgptn |= TIMER_SW1_ON;
		} else {
			flgptn |= TIMER_SW1_OFF;
		}
		sw1 = sw;
	}

	sw = get_push1_state();
	if (sw8 != sw) {
		if (sw == ON) {
			flgptn |= TIMER_PUSH1_ON;
			set_led2_state(ON);
		} else {
			set_led2_state(OFF);
		}
		sw8 = sw;
	}

	if (flgptn != 0x00)
		SVC_PERROR(iset_flg(FLG_TIMER, flgptn));
}


/*
 *  Base Time Generate Cyclic Handler
 */
void
base_time_handler(intptr_t exinf){
	SVC_PERROR(iset_flg(FLG_TIMER, TIMER_BASE_TIME));
}
