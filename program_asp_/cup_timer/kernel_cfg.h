/* kernel_cfg.h */
#ifndef TOPPERS_KERNEL_CFG_H
#define TOPPERS_KERNEL_CFG_H

#define TNUM_TSKID	3
#define TNUM_SEMID	4
#define TNUM_FLGID	2
#define TNUM_DTQID	0
#define TNUM_PDQID	0
#define TNUM_MBXID	0
#define TNUM_MPFID	0
#define TNUM_CYCID	4
#define TNUM_ALMID	0

#define LOGTASK	1
#define TIMER_TASK	2
#define BLINK_TASK	3
#define SERIAL_RCV_SEM1	1
#define SERIAL_SND_SEM1	2
#define SERIAL_RCV_SEM2	3
#define SERIAL_SND_SEM2	4
#define FLG_TIMER	1
#define FLG_BLINK	2
#define LED1_BLINK_HANDLER	1
#define LED4_BLINK_TIME_HANDLER	2
#define SW_SCAN_HANDLER	3
#define BASE_TIME_HANDLER	4

#endif /* TOPPERS_KERNEL_CFG_H */

