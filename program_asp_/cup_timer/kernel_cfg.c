/* kernel_cfg.c */
#include "kernel/kernel_int.h"
#include "kernel_cfg.h"

#if TKERNEL_PRID != 0x07u
#error The kernel does not match this configuration file.
#endif

/*
 *  Include Directives (#include)
 */

#include "target_timer.h"
#include "syssvc/syslog.h"
#include "syssvc/banner.h"
#include "target_syssvc.h"
#include "target_serial.h"
#include "syssvc/serial.h"
#include "syssvc/logtask.h"
#include "cup_timer.h"
#include "device.h"

/*
 *  Default Definitions of Trace Log Macros
 */

#ifndef LOG_ISR_ENTER
#define LOG_ISR_ENTER(intno)
#endif /* LOG_ISR_ENTER */

#ifndef LOG_ISR_LEAVE
#define LOG_ISR_LEAVE(intno)
#endif /* LOG_ISR_LEAVE */

/*
 *  Task Management Functions
 */

const ID _kernel_tmax_tskid = (TMIN_TSKID + TNUM_TSKID - 1);

static STK_T _kernel_stack_LOGTASK[COUNT_STK_T(LOGTASK_STACK_SIZE)];
static STK_T _kernel_stack_TIMER_TASK[COUNT_STK_T(STACK_SIZE)];
static STK_T _kernel_stack_BLINK_TASK[COUNT_STK_T(STACK_SIZE)];

const TINIB _kernel_tinib_table[TNUM_TSKID] = {
	{ (TA_ACT), (intptr_t)(LOGTASK_PORTID), ((TASK)(logtask_main)), INT_PRIORITY(LOGTASK_PRIORITY), ROUND_STK_T(LOGTASK_STACK_SIZE), _kernel_stack_LOGTASK, (TA_NULL), (NULL) },
	{ (TA_ACT), (intptr_t)(0), ((TASK)(timer_task)), INT_PRIORITY(DEFAULT_PRIORITY), ROUND_STK_T(STACK_SIZE), _kernel_stack_TIMER_TASK, (TA_NULL), (NULL) },
	{ (TA_ACT), (intptr_t)(0), ((TASK)(blink_task)), INT_PRIORITY(DEFAULT_PRIORITY), ROUND_STK_T(STACK_SIZE), _kernel_stack_BLINK_TASK, (TA_NULL), (NULL) }
};

TCB _kernel_tcb_table[TNUM_TSKID];

const ID _kernel_torder_table[TNUM_TSKID] = {
	LOGTASK, TIMER_TASK, BLINK_TASK
};

/*
 *  Semaphore Functions
 */

const ID _kernel_tmax_semid = (TMIN_SEMID + TNUM_SEMID - 1);

const SEMINIB _kernel_seminib_table[TNUM_SEMID] = {
	{ (TA_TPRI), (0), (1) },
	{ (TA_TPRI), (1), (1) },
	{ (TA_TPRI), (0), (1) },
	{ (TA_TPRI), (1), (1) }
};

SEMCB _kernel_semcb_table[TNUM_SEMID];

/*
 *  Eventflag Functions
 */

const ID _kernel_tmax_flgid = (TMIN_FLGID + TNUM_FLGID - 1);

const FLGINIB _kernel_flginib_table[TNUM_FLGID] = {
	{ (TA_CLR), (0) },
	{ (TA_CLR), (0) }
};

FLGCB _kernel_flgcb_table[TNUM_FLGID];

/*
 *  Dataqueue Functions
 */

const ID _kernel_tmax_dtqid = (TMIN_DTQID + TNUM_DTQID - 1);

TOPPERS_EMPTY_LABEL(const DTQINIB, _kernel_dtqinib_table);
TOPPERS_EMPTY_LABEL(DTQCB, _kernel_dtqcb_table);

/*
 *  Priority Dataqueue Functions
 */

const ID _kernel_tmax_pdqid = (TMIN_PDQID + TNUM_PDQID - 1);

TOPPERS_EMPTY_LABEL(const PDQINIB, _kernel_pdqinib_table);
TOPPERS_EMPTY_LABEL(PDQCB, _kernel_pdqcb_table);

/*
 *  Mailbox Functions
 */

const ID _kernel_tmax_mbxid = (TMIN_MBXID + TNUM_MBXID - 1);

TOPPERS_EMPTY_LABEL(const MBXINIB, _kernel_mbxinib_table);
TOPPERS_EMPTY_LABEL(MBXCB, _kernel_mbxcb_table);

/*
 *  Fixed-sized Memorypool Functions
 */

const ID _kernel_tmax_mpfid = (TMIN_MPFID + TNUM_MPFID - 1);

TOPPERS_EMPTY_LABEL(const MPFINIB, _kernel_mpfinib_table);
TOPPERS_EMPTY_LABEL(MPFCB, _kernel_mpfcb_table);

/*
 *  Cyclic Handler Functions
 */

const ID _kernel_tmax_cycid = (TMIN_CYCID + TNUM_CYCID - 1);

const CYCINIB _kernel_cycinib_table[TNUM_CYCID] = {
	{ (TA_STA), (intptr_t)(0), (led1_blink_handler), (LED1_BLINK_INTERVAL), (1) },
	{ (TA_NULL), (intptr_t)(0), (led4_blink_time_handler), (LED4_BLINK_INTERVAL), (0) },
	{ (TA_STA), (intptr_t)(0), (sw_scan_handler), (SW_SCAN_INTERVAL), (1) },
	{ (TA_NULL), (intptr_t)(0), (base_time_handler), (BASE_TIME_INTERVAL), (0) }
};

CYCCB _kernel_cyccb_table[TNUM_CYCID];

/*
 *  Alarm Handler Functions
 */

const ID _kernel_tmax_almid = (TMIN_ALMID + TNUM_ALMID - 1);

TOPPERS_EMPTY_LABEL(const ALMINIB, _kernel_alminib_table);
TOPPERS_EMPTY_LABEL(ALMCB, _kernel_almcb_table);

/*
 *  Interrupt Management Functions
 */

void
_kernel_inthdr_54(void)
{
	i_begin_int(54);
	LOG_ISR_ENTER(54);
	((ISR)(sio_isr))((intptr_t)(SIO_PORTID));
	LOG_ISR_LEAVE(54);
	i_end_int(54);
}

#define TNUM_INHNO	2
const uint_t _kernel_tnum_inhno = TNUM_INHNO;

INTHDR_ENTRY(INHNO_TIMER, 15, target_timer_handler)
INTHDR_ENTRY(54, 54, _kernel_inthdr_54)

const INHINIB _kernel_inhinib_table[TNUM_INHNO] = {
	{ (INHNO_TIMER), (TA_NULL), (FP)(INT_ENTRY(INHNO_TIMER, target_timer_handler)) },
	{ (54), (TA_NULL), (FP)(INT_ENTRY(54, _kernel_inthdr_54)) }
};

#define TNUM_INTNO	2
const uint_t _kernel_tnum_intno = TNUM_INTNO;

const INTINIB _kernel_intinib_table[TNUM_INTNO] = {
	{ (INTNO_TIMER), (TA_ENAINT|INTATR_TIMER), (INTPRI_TIMER) },
	{ (INTNO_SIO), (TA_ENAINT|INTATR_SIO), (INTPRI_SIO) }
};

/*
 *  CPU Exception Management Functions
 */

#define TNUM_EXCNO	0
const uint_t _kernel_tnum_excno = TNUM_EXCNO;


TOPPERS_EMPTY_LABEL(const EXCINIB, _kernel_excinib_table);

/*
 *  Stack Area for Non-task Context
 */

#ifdef DEFAULT_ISTK

#define TOPPERS_ISTKSZ		DEFAULT_ISTKSZ
#define TOPPERS_ISTK		DEFAULT_ISTK

#else /* DEAULT_ISTK */

static STK_T _kernel_istack[COUNT_STK_T(DEFAULT_ISTKSZ)];

#define TOPPERS_ISTKSZ		ROUND_STK_T(DEFAULT_ISTKSZ)
#define TOPPERS_ISTK		_kernel_istack

#endif /* DEAULT_ISTK */

const SIZE		_kernel_istksz = TOPPERS_ISTKSZ;
STK_T *const	_kernel_istk = TOPPERS_ISTK;

#ifdef TOPPERS_ISTKPT
STK_T *const	_kernel_istkpt = TOPPERS_ISTKPT(TOPPERS_ISTK, TOPPERS_ISTKSZ);
#endif /* TOPPERS_ISTKPT */

/*
 *  Time Event Management
 */

TMEVTN   _kernel_tmevt_heap[TNUM_TSKID + TNUM_CYCID + TNUM_ALMID];

/*
 *  Module Initialization Function
 */

void
_kernel_initialize_object(void)
{
	_kernel_initialize_task();
	_kernel_initialize_semaphore();
	_kernel_initialize_eventflag();
	_kernel_initialize_cyclic();
	_kernel_initialize_interrupt();
	_kernel_initialize_exception();
}

/*
 *  Initialization Routine
 */

void
_kernel_call_inirtn(void)
{
	((INIRTN)(target_timer_initialize))((intptr_t)(0));
	((INIRTN)(syslog_initialize))((intptr_t)(0));
	((INIRTN)(print_banner))((intptr_t)(0));
	((INIRTN)(sio_initialize))((intptr_t)(0));
	((INIRTN)(serial_initialize))((intptr_t)(0));
	((INIRTN)(led_init))((intptr_t)(0));
	((INIRTN)(switch_push_init))((intptr_t)(0));
	((INIRTN)(switch_slide_init))((intptr_t)(0));
	((INIRTN)(cup_timer_init))((intptr_t)(0));
}

/*
 *  Termination Routine
 */

void
_kernel_call_terrtn(void)
{
	((TERRTN)(logtask_terminate))((intptr_t)(0));
	((TERRTN)(target_timer_terminate))((intptr_t)(0));
}

/*
 *  Target-dependent Definitions (ARM-M)
 */



__attribute__ ((section(".vector"))) 
const FP _kernel_vector_table[] =      
{                                    
	(FP)(TOPPERS_ISTKPT(TOPPERS_ISTK, TOPPERS_ISTKSZ)), /* 0 The initial stack pointer */
	(FP)_kernel__start,                    /* 1 The reset handler */
 	(FP)(_kernel_core_exc_entry), /* 2 */
 	(FP)(_kernel_core_exc_entry), /* 3 */
 	(FP)(_kernel_core_exc_entry), /* 4 */
 	(FP)(_kernel_core_exc_entry), /* 5 */
 	(FP)(_kernel_core_exc_entry), /* 6 */
 	(FP)(_kernel_core_exc_entry), /* 7 */
 	(FP)(_kernel_core_exc_entry), /* 8 */
 	(FP)(_kernel_core_exc_entry), /* 9 */
 	(FP)(_kernel_core_exc_entry), /* 10 */
 	(FP)(_kernel_svc_handler),        /* 11 SVCall handler */
 	(FP)(_kernel_core_exc_entry), /* 12 */
 	(FP)(_kernel_core_exc_entry), /* 13 */
 	(FP)(_kernel_core_exc_entry), /* 14 */
 	(FP)(_kernel_core_int_entry), /* 15 */
 	(FP)(_kernel_core_int_entry), /* 16 */
 	(FP)(_kernel_core_int_entry), /* 17 */
 	(FP)(_kernel_core_int_entry), /* 18 */
 	(FP)(_kernel_core_int_entry), /* 19 */
 	(FP)(_kernel_core_int_entry), /* 20 */
 	(FP)(_kernel_core_int_entry), /* 21 */
 	(FP)(_kernel_core_int_entry), /* 22 */
 	(FP)(_kernel_core_int_entry), /* 23 */
 	(FP)(_kernel_core_int_entry), /* 24 */
 	(FP)(_kernel_core_int_entry), /* 25 */
 	(FP)(_kernel_core_int_entry), /* 26 */
 	(FP)(_kernel_core_int_entry), /* 27 */
 	(FP)(_kernel_core_int_entry), /* 28 */
 	(FP)(_kernel_core_int_entry), /* 29 */
 	(FP)(_kernel_core_int_entry), /* 30 */
 	(FP)(_kernel_core_int_entry), /* 31 */
 	(FP)(_kernel_core_int_entry), /* 32 */
 	(FP)(_kernel_core_int_entry), /* 33 */
 	(FP)(_kernel_core_int_entry), /* 34 */
 	(FP)(_kernel_core_int_entry), /* 35 */
 	(FP)(_kernel_core_int_entry), /* 36 */
 	(FP)(_kernel_core_int_entry), /* 37 */
 	(FP)(_kernel_core_int_entry), /* 38 */
 	(FP)(_kernel_core_int_entry), /* 39 */
 	(FP)(_kernel_core_int_entry), /* 40 */
 	(FP)(_kernel_core_int_entry), /* 41 */
 	(FP)(_kernel_core_int_entry), /* 42 */
 	(FP)(_kernel_core_int_entry), /* 43 */
 	(FP)(_kernel_core_int_entry), /* 44 */
 	(FP)(_kernel_core_int_entry), /* 45 */
 	(FP)(_kernel_core_int_entry), /* 46 */
 	(FP)(_kernel_core_int_entry), /* 47 */
 	(FP)(_kernel_core_int_entry), /* 48 */
 	(FP)(_kernel_core_int_entry), /* 49 */
 	(FP)(_kernel_core_int_entry), /* 50 */
 	(FP)(_kernel_core_int_entry), /* 51 */
 	(FP)(_kernel_core_int_entry), /* 52 */
 	(FP)(_kernel_core_int_entry), /* 53 */
 	(FP)(_kernel_core_int_entry), /* 54 */
 	(FP)(_kernel_core_int_entry), /* 55 */
 	(FP)(_kernel_core_int_entry), /* 56 */
 	(FP)(_kernel_core_int_entry), /* 57 */
 	(FP)(_kernel_core_int_entry), /* 58 */
 	(FP)(_kernel_core_int_entry), /* 59 */
 	(FP)(_kernel_core_int_entry), /* 60 */
 	(FP)(_kernel_core_int_entry), /* 61 */
 	(FP)(_kernel_core_int_entry), /* 62 */
 	(FP)(_kernel_core_int_entry), /* 63 */
 	(FP)(_kernel_core_int_entry), /* 64 */
 	(FP)(_kernel_core_int_entry), /* 65 */
 	(FP)(_kernel_core_int_entry), /* 66 */
 	(FP)(_kernel_core_int_entry), /* 67 */
 	(FP)(_kernel_core_int_entry), /* 68 */
 	(FP)(_kernel_core_int_entry), /* 69 */
 	(FP)(_kernel_core_int_entry), /* 70 */
 	(FP)(_kernel_core_int_entry), /* 71 */
 	(FP)(_kernel_core_int_entry), /* 72 */
 	(FP)(_kernel_core_int_entry), /* 73 */
 	(FP)(_kernel_core_int_entry), /* 74 */
 	(FP)(_kernel_core_int_entry), /* 75 */
 	(FP)(_kernel_core_int_entry), /* 76 */
 	(FP)(_kernel_core_int_entry), /* 77 */
 	(FP)(_kernel_core_int_entry), /* 78 */
 	(FP)(_kernel_core_int_entry), /* 79 */
 	(FP)(_kernel_core_int_entry), /* 80 */
 	(FP)(_kernel_core_int_entry), /* 81 */
 	(FP)(_kernel_core_int_entry), /* 82 */
 	(FP)(_kernel_core_int_entry), /* 83 */
 	(FP)(_kernel_core_int_entry), /* 84 */
 	(FP)(_kernel_core_int_entry), /* 85 */
 	(FP)(_kernel_core_int_entry), /* 86 */
 	(FP)(_kernel_core_int_entry), /* 87 */
 	(FP)(_kernel_core_int_entry), /* 88 */
 	(FP)(_kernel_core_int_entry), /* 89 */
 	(FP)(_kernel_core_int_entry), /* 90 */
 	(FP)(_kernel_core_int_entry), /* 91 */
 	(FP)(_kernel_core_int_entry), /* 92 */
 	(FP)(_kernel_core_int_entry), /* 93 */
 	(FP)(_kernel_core_int_entry), /* 94 */
 	(FP)(_kernel_core_int_entry), /* 95 */
 	(FP)(_kernel_core_int_entry), /* 96 */
 	(FP)(_kernel_core_int_entry), /* 97 */
 	(FP)(_kernel_core_int_entry), /* 98 */
 	(FP)(_kernel_core_int_entry), /* 99 */
 	(FP)(_kernel_core_int_entry), /* 100 */

};


const FP _kernel_exc_tbl[] = 
{
	(FP)(_kernel_default_exc_handler), /* 0 */
	(FP)(_kernel_default_exc_handler), /* 1 */
	(FP)(_kernel_default_exc_handler), /* 2 */
	(FP)(_kernel_default_exc_handler), /* 3 */
	(FP)(_kernel_default_exc_handler), /* 4 */
	(FP)(_kernel_default_exc_handler), /* 5 */
	(FP)(_kernel_default_exc_handler), /* 6 */
	(FP)(_kernel_default_exc_handler), /* 7 */
	(FP)(_kernel_default_exc_handler), /* 8 */
	(FP)(_kernel_default_exc_handler), /* 9 */
	(FP)(_kernel_default_exc_handler), /* 10 */
	(FP)(_kernel_default_exc_handler), /* 11 */
	(FP)(_kernel_default_exc_handler), /* 12 */
	(FP)(_kernel_default_exc_handler), /* 13 */
	(FP)(_kernel_default_exc_handler), /* 14 */
	(FP)(target_timer_handler), /* 15 */
	(FP)(_kernel_default_int_handler), /* 16 */
	(FP)(_kernel_default_int_handler), /* 17 */
	(FP)(_kernel_default_int_handler), /* 18 */
	(FP)(_kernel_default_int_handler), /* 19 */
	(FP)(_kernel_default_int_handler), /* 20 */
	(FP)(_kernel_default_int_handler), /* 21 */
	(FP)(_kernel_default_int_handler), /* 22 */
	(FP)(_kernel_default_int_handler), /* 23 */
	(FP)(_kernel_default_int_handler), /* 24 */
	(FP)(_kernel_default_int_handler), /* 25 */
	(FP)(_kernel_default_int_handler), /* 26 */
	(FP)(_kernel_default_int_handler), /* 27 */
	(FP)(_kernel_default_int_handler), /* 28 */
	(FP)(_kernel_default_int_handler), /* 29 */
	(FP)(_kernel_default_int_handler), /* 30 */
	(FP)(_kernel_default_int_handler), /* 31 */
	(FP)(_kernel_default_int_handler), /* 32 */
	(FP)(_kernel_default_int_handler), /* 33 */
	(FP)(_kernel_default_int_handler), /* 34 */
	(FP)(_kernel_default_int_handler), /* 35 */
	(FP)(_kernel_default_int_handler), /* 36 */
	(FP)(_kernel_default_int_handler), /* 37 */
	(FP)(_kernel_default_int_handler), /* 38 */
	(FP)(_kernel_default_int_handler), /* 39 */
	(FP)(_kernel_default_int_handler), /* 40 */
	(FP)(_kernel_default_int_handler), /* 41 */
	(FP)(_kernel_default_int_handler), /* 42 */
	(FP)(_kernel_default_int_handler), /* 43 */
	(FP)(_kernel_default_int_handler), /* 44 */
	(FP)(_kernel_default_int_handler), /* 45 */
	(FP)(_kernel_default_int_handler), /* 46 */
	(FP)(_kernel_default_int_handler), /* 47 */
	(FP)(_kernel_default_int_handler), /* 48 */
	(FP)(_kernel_default_int_handler), /* 49 */
	(FP)(_kernel_default_int_handler), /* 50 */
	(FP)(_kernel_default_int_handler), /* 51 */
	(FP)(_kernel_default_int_handler), /* 52 */
	(FP)(_kernel_default_int_handler), /* 53 */
	(FP)(_kernel_inthdr_54), /* 54 */
	(FP)(_kernel_default_int_handler), /* 55 */
	(FP)(_kernel_default_int_handler), /* 56 */
	(FP)(_kernel_default_int_handler), /* 57 */
	(FP)(_kernel_default_int_handler), /* 58 */
	(FP)(_kernel_default_int_handler), /* 59 */
	(FP)(_kernel_default_int_handler), /* 60 */
	(FP)(_kernel_default_int_handler), /* 61 */
	(FP)(_kernel_default_int_handler), /* 62 */
	(FP)(_kernel_default_int_handler), /* 63 */
	(FP)(_kernel_default_int_handler), /* 64 */
	(FP)(_kernel_default_int_handler), /* 65 */
	(FP)(_kernel_default_int_handler), /* 66 */
	(FP)(_kernel_default_int_handler), /* 67 */
	(FP)(_kernel_default_int_handler), /* 68 */
	(FP)(_kernel_default_int_handler), /* 69 */
	(FP)(_kernel_default_int_handler), /* 70 */
	(FP)(_kernel_default_int_handler), /* 71 */
	(FP)(_kernel_default_int_handler), /* 72 */
	(FP)(_kernel_default_int_handler), /* 73 */
	(FP)(_kernel_default_int_handler), /* 74 */
	(FP)(_kernel_default_int_handler), /* 75 */
	(FP)(_kernel_default_int_handler), /* 76 */
	(FP)(_kernel_default_int_handler), /* 77 */
	(FP)(_kernel_default_int_handler), /* 78 */
	(FP)(_kernel_default_int_handler), /* 79 */
	(FP)(_kernel_default_int_handler), /* 80 */
	(FP)(_kernel_default_int_handler), /* 81 */
	(FP)(_kernel_default_int_handler), /* 82 */
	(FP)(_kernel_default_int_handler), /* 83 */
	(FP)(_kernel_default_int_handler), /* 84 */
	(FP)(_kernel_default_int_handler), /* 85 */
	(FP)(_kernel_default_int_handler), /* 86 */
	(FP)(_kernel_default_int_handler), /* 87 */
	(FP)(_kernel_default_int_handler), /* 88 */
	(FP)(_kernel_default_int_handler), /* 89 */
	(FP)(_kernel_default_int_handler), /* 90 */
	(FP)(_kernel_default_int_handler), /* 91 */
	(FP)(_kernel_default_int_handler), /* 92 */
	(FP)(_kernel_default_int_handler), /* 93 */
	(FP)(_kernel_default_int_handler), /* 94 */
	(FP)(_kernel_default_int_handler), /* 95 */
	(FP)(_kernel_default_int_handler), /* 96 */
	(FP)(_kernel_default_int_handler), /* 97 */
	(FP)(_kernel_default_int_handler), /* 98 */
	(FP)(_kernel_default_int_handler), /* 99 */
	(FP)(_kernel_default_int_handler), /* 100 */

};

const uint32_t _kernel_bitpat_cfgint[7] = {
	UINT32_C(0x00008000), 
	UINT32_C(0x00400000), 
	UINT32_C(0x00000000), 
	UINT32_C(0x00000000), 
	UINT32_C(0x00000000), 
	UINT32_C(0x00000000), 
	UINT32_C(0x00000000), 

};

const uint32_t _kernel_int_iipm_tbl[] = {
	UINT32_C(0x00000000), /* 0x000 */
	UINT32_C(0x00000000), /* 0x001 */
	UINT32_C(0x00000000), /* 0x002 */
	UINT32_C(0x00000000), /* 0x003 */
	UINT32_C(0x00000000), /* 0x004 */
	UINT32_C(0x00000000), /* 0x005 */
	UINT32_C(0x00000000), /* 0x006 */
	UINT32_C(0x00000000), /* 0x007 */
	UINT32_C(0x00000000), /* 0x008 */
	UINT32_C(0x00000000), /* 0x009 */
	UINT32_C(0x00000000), /* 0x00a */
	UINT32_C(0x00000000), /* 0x00b */
	UINT32_C(0x00000000), /* 0x00c */
	UINT32_C(0x00000000), /* 0x00d */
	UINT32_C(0x00000000), /* 0x00e */
	UINT32_C(0x000000a0), /* 0x00f */
	UINT32_C(0x00000000), /* 0x010 */
	UINT32_C(0x00000000), /* 0x011 */
	UINT32_C(0x00000000), /* 0x012 */
	UINT32_C(0x00000000), /* 0x013 */
	UINT32_C(0x00000000), /* 0x014 */
	UINT32_C(0x00000000), /* 0x015 */
	UINT32_C(0x00000000), /* 0x016 */
	UINT32_C(0x00000000), /* 0x017 */
	UINT32_C(0x00000000), /* 0x018 */
	UINT32_C(0x00000000), /* 0x019 */
	UINT32_C(0x00000000), /* 0x01a */
	UINT32_C(0x00000000), /* 0x01b */
	UINT32_C(0x00000000), /* 0x01c */
	UINT32_C(0x00000000), /* 0x01d */
	UINT32_C(0x00000000), /* 0x01e */
	UINT32_C(0x00000000), /* 0x01f */
	UINT32_C(0x00000000), /* 0x020 */
	UINT32_C(0x00000000), /* 0x021 */
	UINT32_C(0x00000000), /* 0x022 */
	UINT32_C(0x00000000), /* 0x023 */
	UINT32_C(0x00000000), /* 0x024 */
	UINT32_C(0x00000000), /* 0x025 */
	UINT32_C(0x00000000), /* 0x026 */
	UINT32_C(0x00000000), /* 0x027 */
	UINT32_C(0x00000000), /* 0x028 */
	UINT32_C(0x00000000), /* 0x029 */
	UINT32_C(0x00000000), /* 0x02a */
	UINT32_C(0x00000000), /* 0x02b */
	UINT32_C(0x00000000), /* 0x02c */
	UINT32_C(0x00000000), /* 0x02d */
	UINT32_C(0x00000000), /* 0x02e */
	UINT32_C(0x00000000), /* 0x02f */
	UINT32_C(0x00000000), /* 0x030 */
	UINT32_C(0x00000000), /* 0x031 */
	UINT32_C(0x00000000), /* 0x032 */
	UINT32_C(0x00000000), /* 0x033 */
	UINT32_C(0x00000000), /* 0x034 */
	UINT32_C(0x00000000), /* 0x035 */
	UINT32_C(0x000000d0), /* 0x036 */
	UINT32_C(0x00000000), /* 0x037 */
	UINT32_C(0x00000000), /* 0x038 */
	UINT32_C(0x00000000), /* 0x039 */
	UINT32_C(0x00000000), /* 0x03a */
	UINT32_C(0x00000000), /* 0x03b */
	UINT32_C(0x00000000), /* 0x03c */
	UINT32_C(0x00000000), /* 0x03d */
	UINT32_C(0x00000000), /* 0x03e */
	UINT32_C(0x00000000), /* 0x03f */
	UINT32_C(0x00000000), /* 0x040 */
	UINT32_C(0x00000000), /* 0x041 */
	UINT32_C(0x00000000), /* 0x042 */
	UINT32_C(0x00000000), /* 0x043 */
	UINT32_C(0x00000000), /* 0x044 */
	UINT32_C(0x00000000), /* 0x045 */
	UINT32_C(0x00000000), /* 0x046 */
	UINT32_C(0x00000000), /* 0x047 */
	UINT32_C(0x00000000), /* 0x048 */
	UINT32_C(0x00000000), /* 0x049 */
	UINT32_C(0x00000000), /* 0x04a */
	UINT32_C(0x00000000), /* 0x04b */
	UINT32_C(0x00000000), /* 0x04c */
	UINT32_C(0x00000000), /* 0x04d */
	UINT32_C(0x00000000), /* 0x04e */
	UINT32_C(0x00000000), /* 0x04f */
	UINT32_C(0x00000000), /* 0x050 */
	UINT32_C(0x00000000), /* 0x051 */
	UINT32_C(0x00000000), /* 0x052 */
	UINT32_C(0x00000000), /* 0x053 */
	UINT32_C(0x00000000), /* 0x054 */
	UINT32_C(0x00000000), /* 0x055 */
	UINT32_C(0x00000000), /* 0x056 */
	UINT32_C(0x00000000), /* 0x057 */
	UINT32_C(0x00000000), /* 0x058 */
	UINT32_C(0x00000000), /* 0x059 */
	UINT32_C(0x00000000), /* 0x05a */
	UINT32_C(0x00000000), /* 0x05b */
	UINT32_C(0x00000000), /* 0x05c */
	UINT32_C(0x00000000), /* 0x05d */
	UINT32_C(0x00000000), /* 0x05e */
	UINT32_C(0x00000000), /* 0x05f */
	UINT32_C(0x00000000), /* 0x060 */
	UINT32_C(0x00000000), /* 0x061 */
	UINT32_C(0x00000000), /* 0x062 */
	UINT32_C(0x00000000), /* 0x063 */
	UINT32_C(0x00000000), /* 0x064 */

};

