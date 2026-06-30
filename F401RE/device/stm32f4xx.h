/*
 *  TOPPERS/ASP Kernel
 *      Toyohashi Open Platform for Embedded Real-Time Systems/
 *      Just Standard Profile Kernel
 * 
 *  Copyright (C) 2015      by Roi Takeuchi
 *
 *  上記著作権者は，以下の (1)～(4) の条件か，Free Software Foundation 
 *  によって公表されている GNU General Public License の Version 2 に記
 *  述されている条件を満たす場合に限り，本ソフトウェア（本ソフトウェア
 *  を改変したものを含む．以下同じ）を使用・複製・改変・再配布（以下，
 *  利用と呼ぶ）することを無償で許諾する．
 *  (1) 本ソフトウェアをソースコードの形で利用する場合には，上記の著作
 *      権表示，この利用条件および下記の無保証規定が，そのままの形でソー
 *      スコード中に含まれていること．
 *  (2) 本ソフトウェアを，ライブラリ形式など，他のソフトウェア開発に使
 *      用できる形で再配布する場合には，再配布に伴うドキュメント（利用
 *      者マニュアルなど）に，上記の著作権表示，この利用条件および下記
 *      の無保証規定を掲載すること．
 *  (3) 本ソフトウェアを，機器に組み込むなど，他のソフトウェア開発に使
 *      用できない形で再配布する場合には，次のいずれかの条件を満たすこ
 *      と．
 *    (a) 再配布に伴うドキュメント（利用者マニュアルなど）に，上記の著
 *        作権表示，この利用条件および下記の無保証規定を掲載すること．
 *    (b) 再配布の形態を，別に定める方法によって，TOPPERSプロジェクトに
 *        報告すること．
 *  (4) 本ソフトウェアの利用により直接的または間接的に生じるいかなる損
 *      害からも，上記著作権者およびTOPPERSプロジェクトを免責すること．
 *
 *  本ソフトウェアは，無保証で提供されているものである．上記著作権者お
 *  よびTOPPERSプロジェクトは，本ソフトウェアに関して，その適用可能性も
 *  含めて，いかなる保証も行わない．また，本ソフトウェアの利用により直
 *  接的または間接的に生じたいかなる損害に関しても，その責任を負わない．
 * 
 *  @(#) $Id: stm32f4xx.h,v 1.1 2015/07/18 21:48:24 roi Exp $
 */

#ifndef _STM32F4XX_H_
#define _STM32F4XX_H_

#include "cmsis_f4.h"

/*
 *  INTERRUPT NUMBER
 */
#define INTNO_NONMASKABLE	-14		/* 2 Non Maskable Interrupt */
#define INTNO_MEMORYMANAGER -12		/* 4 Cortex-M4 Memory Management Interrupt */
#define INTNO_BUSFAULT      -11		/* 5 Cortex-M4 Bus Fault Interrupt */
#define INTNO_USAGEFAULT    -10		/* 6 Cortex-M4 Usage Fault Interrupt */
#define INTNO_SVCALL        -5		/* 11 Cortex-M4 SV Call Interrupt */
#define INTNO_DEBUGMONITOR  -4		/* 12 Cortex-M4 Debug Monitor Interrupt */
#define INTNO_PENDSV        -2		/* 14 Cortex-M4 Pend SV Interrupt */
#define INTNO_SYSTICK       -1		/* 15 Cortex-M4 System Tick Interrupt */
/*  STM32 specific Interrupt Numbers */
#define INTNO_WWDG          0		/* Window WatchDog Interrupt */
#define INTNO_PVD           1		/* PVD through EXTI Line detection Interrupt */
#define INTNO_TAMP_STAMP    2		/* Tamper and TimeStamp interrupts through the EXTI line */
#define INTNO_RTC_WKUP      3		/* RTC Wakeup interrupt through the EXTI line */
#define INTNO_FLASH         4		/* FLASH global Interrupt */
#define INTNO_RCC           5		/* RCC global Interrupt */
#define INTNO_EXTI0         6		/* EXTI Line0 Interrupt */
#define INTNO_EXTI1         7		/* EXTI Line1 Interrupt */
#define INTNO_EXTI2         8		/* EXTI Line2 Interrupt */
#define INTNO_EXTI3         9		/* EXTI Line3 Interrupt */
#define INTNO_EXTI4         10		/* EXTI Line4 Interrupt */
#define INTNO_DMA1_STREAM0  11		/* DMA1 Stream 0 global Interrupt */
#define INTNO_DMA1_STREAM1  12		/* DMA1 Stream 1 global Interrupt */
#define INTNO_DMA1_STREAM2  13		/* DMA1 Stream 2 global Interrupt */
#define INTNO_DMA1_STREAM3  14		/* DMA1 Stream 3 global Interrupt */
#define INTNO_DMA1_STREAM4  15		/* DMA1 Stream 4 global Interrupt */
#define INTNO_DMA1_STREAM5  16		/* DMA1 Stream 5 global Interrupt */
#define INTNO_DMA1_STREAM6  17		/* DMA1 Stream 6 global Interrupt */
#define INTNO_ADC           18		/* ADC1, ADC2 and ADC3 global Interrupts */
#define INTNO_CAN1_TX       19		/* CAN1 TX Interrupt */
#define INTNO_CAN1_RX0      20		/* CAN1 RX0 Interrupt */
#define INTNO_CAN1_RX1      21		/* CAN1 RX1 Interrupt */
#define INTNO_CAN1_SCE      22		/* CAN1 SCE Interrupt */
#define INTNO_EXTI9_5       23		/* External Line[9:5] Interrupts */
#define INTNO_TIM1_BRK_TIM9 24		/* TIM1 Break interrupt and TIM9 global interrupt */
#define INTNO_TIM1_UP_TIM10 25		/* TIM1 Update Interrupt and TIM10 global interrupt */
#define INTNO_TIM1_TRG_COM_TIM11 26	/* TIM1 Trigger and Commutation Interrupt and TIM11 global interrupt */
#define INTNO_TIM1_CC       27		/* TIM1 Capture Compare Interrupt */
#define INTNO_TIM2          28		/* TIM2 global Interrupt */
#define INTNO_TIM3          29		/* TIM3 global Interrupt */
#define INTNO_TIM4          30		/* TIM4 global Interrupt */
#define INTNO_I2C1_EV       31		/* I2C1 Event Interrupt */
#define INTNO_I2C1_ER       32		/* I2C1 Error Interrupt */
#define INTNO_I2C2_EV       33		/* I2C2 Event Interrupt */
#define INTNO_I2C2_ER       34		/* I2C2 Error Interrupt */
#define INTNO_SPI1          35		/* SPI1 global Interrupt */
#define INTNO_SPI2          36		/* SPI2 global Interrupt */
#define INTNO_USART1        37		/* USART1 global Interrupt */
#define INTNO_USART2        38		/* USART2 global Interrupt */
#define INTNO_USART3        39		/* USART3 global Interrupt */
#define INTNO_EXTI15_10     40		/* External Line[15:10] Interrupts */
#define INTNO_RTC_ALARM     41		/* RTC Alarm (A and B) through EXTI Line Interrupt */
#define INTNO_OTG_FS_WKUP   42		/* USB OTG FS Wakeup through EXTI line interrupt */
#define INTNO_TIM8_BRK_TIM12 43		/* TIM8 Break Interrupt and TIM12 global interrupt */
#define INTNO_TIM8_UP_TIM13 44		/* TIM8 Update Interrupt and TIM13 global interrupt */
#define INTNO_TIM8_TRG_COM_TIM14 45	/* TIM8 Trigger and Commutation Interrupt and TIM14 global interrupt */
#define INTNO_TIM8_CC       46		/* TIM8 Capture Compare Interrupt */
#define INTNO_DMA1_STREAM7  47		/* DMA1 Stream7 Interrupt */
#define INTNO_FSMC          48		/* FSMC global Interrupt */
#define INTNO_SDIO          49		/* SDIO global Interrupt */
#define INTNO_TIM5          50		/* TIM5 global Interrupt */
#define INTNO_SPI3          51		/* SPI3 global Interrupt */
#define INTNO_UART4         52		/* UART4 global Interrupt */
#define INTNO_UART5         53		/* UART5 global Interrupt */
#define INTNO_TIM6_DAC      54		/* TIM6 global and DAC1&2 underrun error interrupts */
#define INTNO_TIM7          55		/* TIM7 global interrupt */
#define INTNO_DMA2_STREAM0  56		/* DMA2 Stream 0 global Interrupt */
#define INTNO_DMA2_STREAM1  57		/* DMA2 Stream 1 global Interrupt */
#define INTNO_DMA2_STREAM2  58		/* DMA2 Stream 2 global Interrupt */
#define INTNO_DMA2_STREAM3  59		/* DMA2 Stream 3 global Interrupt */
#define INTNO_DMA2_STREAM4  60		/* DMA2 Stream 4 global Interrupt */
#define INTNO_ETH           61		/* Ethernet global Interrupt */
#define INTNO_ETH_WKUP      62		/* Ethernet Wakeup through EXTI line Interrupt */
#define INTNO_CAN2_TX       63		/* CAN2 TX Interrupt */
#define INTNO_CAN2_RX0      64		/* CAN2 RX0 Interrupt */
#define INTNO_CAN2_RX1      65		/* CAN2 RX1 Interrupt */
#define INTNO_CAN2_SCE      66		/* CAN2 SCE Interrupt */
#define INTNO_OTG_FS        67		/* USB OTG FS global Interrupt */
#define INTNO_DMA2_STREAM5  68		/* DMA2 Stream 5 global interrupt */
#define INTNO_DMA2_STREAM6  69		/* DMA2 Stream 6 global interrupt */
#define INTNO_DMA2_STREAM7  70		/* DMA2 Stream 7 global interrupt */
#define INTNO_USART6        71		/* USART6 global interrupt */
#define INTNO_I2C3_EV       72		/* I2C3 event interrupt */
#define INTNO_I2C3_ER       73		/* I2C3 error interrupt */
#define INTNO_OTG_HS_EP1_OUT 74		/* USB OTG HS End Point 1 Out global interrupt */
#define INTNO_OTG_HS_EP1_IN 75		/* USB OTG HS End Point 1 In global interrupt */
#define INTNO_OTG_HS_WKUP   76		/* USB OTG HS Wakeup through EXTI interrupt */
#define INTNO_OTG_HS        77		/* USB OTG HS global interrupt */
#define INTNO_DCMI          78		/* DCMI global interrupt */
#define INTNO_CRYP          79		/* CRYP crypto global interrupt */
#define INTNO_HASH_RNG      80		/* Hash and Rng global interrupt */
#define INTNO_FPU           81		/* FPU global interrupt */

/*
 *  PERIPHERAL MEMORY MAP
 */
#define FLASH_BASE          0x08000000	/*!< FLASH(up to 1 MB) base address in the alias region                         */
#define CCMDATARAM_BASE     0x10000000	/*!< CCM(core coupled memory) data RAM(64 KB) base address in the alias region  */
#define SRAM1_BASE          0x20000000	/*!< SRAM1(112 KB) base address in the alias region                             */
#define SRAM2_BASE          0x2001C000	/*!< SRAM2(16 KB) base address in the alias region                              */
#define PERIPH_BASE         0x40000000	/*!< Peripheral base address in the alias region                                */
#define BKPSRAM_BASE        0x40024000	/*!< Backup SRAM(4 KB) base address in the alias region                         */
#define FSMC_R_BASE         0xA0000000	/*!< FSMC registers base address                                                */

#define CCMDATARAM_BB_BASE  0x12000000	/*!< CCM(core coupled memory) data RAM(64 KB) base address in the bit-band region  */
#define SRAM1_BB_BASE       0x22000000	/*!< SRAM1(112 KB) base address in the bit-band region                             */
#define SRAM2_BB_BASE       0x2201C000	/*!< SRAM2(16 KB) base address in the bit-band region                              */
#define PERIPH_BB_BASE      0x42000000	/*!< Peripheral base address in the bit-band region                                */
#if BOARDNO == 3
#define BKPSRAM_BB_BASE     0x42480000	/*!< Backup SRAM(4 KB) base address in the bit-band region                         */
#else
#define BKPSRAM_BB_BASE     0x42024000	/*!< Backup SRAM(4 KB) base address in the bit-band region                         */
#endif

/*!< Peripheral memory map */
#define APB1PERIPH_BASE     PERIPH_BASE
#define APB2PERIPH_BASE     (PERIPH_BASE + 0x00010000)
#define AHB1PERIPH_BASE     (PERIPH_BASE + 0x00020000)
#define AHB2PERIPH_BASE     (PERIPH_BASE + 0x10000000)

/*
 *  TIM
 */
#define TADR_TIM2_BASE      (APB1PERIPH_BASE + 0x0000)
#define TADR_TIM3_BASE      (APB1PERIPH_BASE + 0x0400)
#define TADR_TIM4_BASE      (APB1PERIPH_BASE + 0x0800)
#define TADR_TIM5_BASE      (APB1PERIPH_BASE + 0x0C00)
#define TADR_TIM6_BASE      (APB1PERIPH_BASE + 0x1000)
#define TADR_TIM7_BASE      (APB1PERIPH_BASE + 0x1400)
#define TADR_TIM12_BASE     (APB1PERIPH_BASE + 0x1800)
#define TADR_TIM13_BASE     (APB1PERIPH_BASE + 0x1C00)
#define TADR_TIM14_BASE     (APB1PERIPH_BASE + 0x2000)
#define TADR_TIM1_BASE      (APB2PERIPH_BASE + 0x0000)
#define TADR_TIM8_BASE      (APB2PERIPH_BASE + 0x0400)
#define TADR_TIM9_BASE      (APB2PERIPH_BASE + 0x4000)
#define TADR_TIM10_BASE     (APB2PERIPH_BASE + 0x4400)
#define TADR_TIM11_BASE     (APB2PERIPH_BASE + 0x4800)
#define TOFF_TIM_CR1        0x0000		/* (RW-16) TIM control register 1 */
#define TOFF_TIM_CR2        0x0004		/* (RW-16) TIM control register 2 */
#define TOFF_TIM_SMCR       0x0008		/* (RW-16) TIM slave mode control register */
#define TOFF_TIM_DIER       0x000C		/* (RW-16) TIM DMA/interrupt enable register */
#define TOFF_TIM_SR         0x0010		/* (RW-16) TIM status register */
#define TOFF_TIM_EGR        0x0014		/* (RW-16) TIM event generation register */
#define TOFF_TIM_CCMR1      0x0018		/* (RW-16) TIM capture/compare mode register 1 */
#define TOFF_TIM_CCMR2      0x001C		/* (RW-16) TIM capture/compare mode register 2 */
#define TOFF_TIM_CCER       0x0020		/* (RW-16) TIM capture/compare enable register */
#define TOFF_TIM_CNT        0x0024		/* (RW)    TIM counter register */
#define TOFF_TIM_PSC        0x0028		/* (RW-16) TIM prescaler */
#define TOFF_TIM_ARR        0x002C		/* (RW)    TIM auto-reload register */
#define TOFF_TIM_RCR        0x0030		/* (RW-16) TIM repetition counter register */
#define TOFF_TIM_CCR1       0x0034		/* (RW)    TIM capture/compare register 1 */
#define TOFF_TIM_CCR2       0x0038		/* (RW)    TIM capture/compare register 2 */
#define TOFF_TIM_CCR3       0x003C		/* (RW)    TIM capture/compare register 3 */
#define TOFF_TIM_CCR4       0x0040		/* (RW)    TIM capture/compare register 4 */
#define TOFF_TIM_BDTR       0x0044		/* (RW-16) TIM break and dead-time register */
#define TOFF_TIM_DCR        0x0048		/* (RW-16) TIM DMA control register */
#define TOFF_TIM_DMAR       0x004C		/* (RW-16) TIM DMA address for full transfer */
#define TOFF_TIM_OR         0x0050		/* (RW-16) TIM option register */

/*
 *  REAL-TIME CLOCK
 */
#define TADR_RTC_BASE       (APB1PERIPH_BASE + 0x2800)
#define TOFF_RTC_TR         0x0000		/* (RW) RTC time register */
#define TOFF_RTC_DR         0x0004		/* (RW) RTC date register */
#define TOFF_RTC_CR         0x0008		/* (RW) RTC control register */
#define TOFF_RTC_ISR        0x000C		/* (RW) RTC initialization and status register */
#define TOFF_RTC_PRER       0x0010		/* (RW) RTC prescaler register */
#define TOFF_RTC_WUTR       0x0014		/* (RW) RTC wakeup timer register */
#define TOFF_RTC_CALIBR     0x0018		/* (RW) RTC calibration register */
#define TOFF_RTC_ALRMAR     0x001C		/* (RW) RTC alarm A register */
#define TOFF_RTC_ALRMBR     0x0020		/* (RW) RTC alarm B register */
#define TOFF_RTC_WPR        0x0024		/* (RW) RTC write protection register */
#define TOFF_RTC_SSR        0x0028		/* (RW) RTC sub second register */
#define TOFF_RTC_SHIFTR     0x002C		/* (RW) RTC shift control register */
#define TOFF_RTC_TSTR       0x0030		/* (RW) RTC time stamp time register */
#define TOFF_RTC_TSDR       0x0034		/* (RW) RTC time stamp date register */
#define TOFF_RTC_TSSSR      0x0038		/* (RW) RTC time-stamp sub second register */
#define TOFF_RTC_CALR       0x003C		/* (RW) RTC calibration register */
#define TOFF_RTC_TAFCR      0x0040		/* (RW) RTC tamper and alternate function configuration register */
#define TOFF_RTC_ALRMASSR   0x0044		/* (RW) RTC alarm A sub second register */
#define TOFF_RTC_ALRMBSSR   0x0048		/* (RW) RTC alarm B sub second register */
#define TOFF_RTC_BKP0R      0x0050		/* (RW) RTC backup register 0 */
#define TOFF_RTC_BKP1R      0x0054		/* (RW) RTC backup register 1 */
#define TOFF_RTC_BKP2R      0x0058		/* (RW) RTC backup register 2 */
#define TOFF_RTC_BKP3R      0x005C		/* (RW) RTC backup register 3 */
#define TOFF_RTC_BKP4R      0x0060		/* (RW) RTC backup register 4 */
#define TOFF_RTC_BKP5R      0x0064		/* (RW) RTC backup register 5 */
#define TOFF_RTC_BKP6R      0x0068		/* (RW) RTC backup register 6 */
#define TOFF_RTC_BKP7R      0x006C		/* (RW) RTC backup register 7 */
#define TOFF_RTC_BKP8R      0x0070		/* (RW) RTC backup register 8 */
#define TOFF_RTC_BKP9R      0x0074		/* (RW) RTC backup register 9 */
#define TOFF_RTC_BKP10R     0x0078		/* (RW) RTC backup register 10 */
#define TOFF_RTC_BKP11R     0x007C		/* (RW) RTC backup register 11 */
#define TOFF_RTC_BKP12R     0x0080		/* (RW) RTC backup register 12 */
#define TOFF_RTC_BKP13R     0x0084		/* (RW) RTC backup register 13 */
#define TOFF_RTC_BKP14R     0x0088		/* (RW) RTC backup register 14 */
#define TOFF_RTC_BKP15R     0x008C		/* (RW) RTC backup register 15 */
#define TOFF_RTC_BKP16R     0x0090		/* (RW) RTC backup register 16 */
#define TOFF_RTC_BKP17R     0x0094		/* (RW) RTC backup register 17 */
#define TOFF_RTC_BKP18R     0x0098		/* (RW) RTC backup register 18 */
#define TOFF_RTC_BKP19R     0x009C		/* (RW) RTC backup register 19 */

/*
 *  WINDOW WATCHDOG
 */
#define TADR_WWDG_BASE      (APB1PERIPH_BASE + 0x2C00)
#define TOFF_WWDG_CR        0x0000		/* (RW) WWDG Control register */
#define TOFF_WWDG_CFR       0x0004		/* (RW) WWDG Configuration register */
#define TOFF_WWDG_SR        0x0008		/* (R)  WWDG Status register */

/*
 *  INDEPENDENT WATCHDOG
 */
#define TADR_IWDG_BASE      (APB1PERIPH_BASE + 0x3000)
#define TOFF_IWDG_KR        0x0000		/* (RW) IWDG Key register */
#define TOFF_IWDG_PR        0x0004		/* (RW) IWDG Prescaler register */
#define TOFF_IWDG_RLR       0x0008		/* (RW) IWDG Reload register */
#define TOFF_IWDG_SR        0x000C		/* (RW) IWDG Status register */

/*
 *  SERIAL PERIPHERAL IINTERFACE
 */
#define TADR_I2S2EXTt_BASE  (APB1PERIPH_BASE + 0x3400)
#define TADR_SPI2_BASE      (APB1PERIPH_BASE + 0x3800)
#define TADR_SPI3_BASE      (APB1PERIPH_BASE + 0x3C00)
#define TADR_I2S3EXT_BASE   (APB1PERIPH_BASE + 0x4000)
#define TADR_SPI1_BASE      (APB2PERIPH_BASE + 0x3000)
#define TOFF_SPI_CR1        0x0000		/* (RW-16) SPI control register 1 (not used in I2S mode) */
#define TOFF_SPI_CR2        0x0004		/* (RW-16) SPI control register 2 */
#define TOFF_SPI_SR         0x0008		/* (RW-16) SPI status register */
#define TOFF_SPI_DR         0x000C		/* (RW-16) SPI data register */
#define TOFF_SPI_CRCPR      0x0010		/* (RW-16) SPI CRC polynomial register (not used in I2S mode) */
#define TOFF_SPI_RXCRCR     0x0014		/* (RW-16) SPI RX CRC register (not used in I2S mode) */
#define TOFF_SPI_TXCRCR     0x0018		/* (RW-16) SPI TX CRC register (not used in I2S mode) */
#define TOFF_SPI_I2SCFGR    0x001C		/* (RW-16) SPI_I2S configuration register */
#define TOFF_SPI_I2SPR      0x0020		/* (RW-16) SPI_I2S prescaler register */

/*
 *  UNIVERSAL SYNCHRONOUS ASYNCHORONOUS RECEIVER TRANSMITTER
 */
#define TADR_USART2_BASE    (APB1PERIPH_BASE + 0x4400)
#define TADR_USART3_BASE    (APB1PERIPH_BASE + 0x4800)
#define TADR_UART4_BASE     (APB1PERIPH_BASE + 0x4C00)
#define TADR_UART5_BASE     (APB1PERIPH_BASE + 0x5000)
#define TADR_USART1_BASE    (APB2PERIPH_BASE + 0x1000)
#define TADR_USART6_BASE    (APB2PERIPH_BASE + 0x1400)
#define TOFF_USART_SR       0x0000		/* (RW-16) USART Status register */
  #define USART_SR_PE        0x0001		/* Parity Error */
  #define USART_SR_FE        0x0002		/* Framing Error */
  #define USART_SR_NE        0x0004		/* Noise Error Flag */
  #define USART_SR_ORE       0x0008		/* OverRun Error */
  #define USART_SR_IDLE      0x0010		/* IDLE line detected */
  #define USART_SR_RXNE      0x0020		/* Read Data Register Not Empty */
  #define USART_SR_TC        0x0040		/* Transmission Complete */
  #define USART_SR_TXE       0x0080		/* Transmit Data Register Empty */
  #define USART_SR_LBD       0x0100		/* LIN Break Detection Flag */
  #define USART_SR_CTS       0x0200		/* CTS Flag */
#define TOFF_USART_DR       0x0004		/* (RW-16) USART Data register */
#define TOFF_USART_BRR      0x0008		/* (RW-16) USART Baud rate register */
#define TOFF_USART_CR1      0x000C		/* (RW-16) USART Control register 1 */
  #define USART_CR1_SBK      0x0001		/* Send Break */
  #define USART_CR1_RWU      0x0002		/* Receiver wakeup */
  #define USART_CR1_RE       0x0004		/* Receiver Enable */
  #define USART_CR1_TE       0x0008		/* Transmitter Enable */
  #define USART_CR1_IDLEIE   0x0010		/* IDLE Interrupt Enable */
  #define USART_CR1_RXNEIE   0x0020		/* RXNE Interrupt Enable */
  #define USART_CR1_TCIE     0x0040		/* Transmission Complete Interrupt Enable */
  #define USART_CR1_TXEIE    0x0080		/* PE Interrupt Enable */
  #define USART_CR1_PEIE     0x0100		/* PE Interrupt Enable */
  #define USART_CR1_PS       0x0200		/* Parity Selection */
  #define USART_CR1_PCE      0x0400		/* Parity Control Enable */
  #define USART_CR1_WAKE     0x0800		/* Wakeup method */
  #define USART_CR1_M        0x1000		/* Word length */
  #define USART_CR1_UE       0x2000		/* USART Enable */
  #define USART_CR1_OVER8    0x8000		/* USART Oversampling by 8 enable */
#define TOFF_USART_CR2      0x0010		/* (RW-16) USART Control register 2 */
  #define USART_CR2_ADD      0x000F		/* Address of the USART node */
  #define USART_CR2_LBDL     0x0020		/* LIN Break Detection Length */
  #define USART_CR2_LBDIE    0x0040		/* LIN Break Detection Interrupt Enable */
  #define USART_CR2_LBCL     0x0100		/* Last Bit Clock pulse */
  #define USART_CR2_CPHA     0x0200		/* Clock Phase */
  #define USART_CR2_CPOL     0x0400		/* Clock Polarity */
  #define USART_CR2_CLKEN    0x0800		/* Clock Enable */
  #define USART_CR2_STOP     0x3000		/* STOP[1:0] bits (STOP bits) */
  #define USART_CR2_STOP_0   0x1000		/* Bit 0 */
  #define USART_CR2_STOP_1   0x2000		/* Bit 1 */
  #define USART_CR2_LINEN    0x4000		/* LIN mode enable */
#define TOFF_USART_CR3      0x0014		/* (RW-16) USART Control register 3 */
  #define USART_CR3_EIE      0x0001		/* Error Interrupt Enable */
  #define USART_CR3_IREN     0x0002		/* IrDA mode Enable */
  #define USART_CR3_IRLP     0x0004		/* IrDA Low-Power */
  #define USART_CR3_HDSEL    0x0008		/* Half-Duplex Selection */
  #define USART_CR3_NACK     0x0010		/* Smartcard NACK enable */
  #define USART_CR3_SCEN     0x0020		/* Smartcard mode enable */
  #define USART_CR3_DMAR     0x0040		/* DMA Enable Receiver */
  #define USART_CR3_DMAT     0x0080		/* DMA Enable Transmitter */
  #define USART_CR3_RTSE     0x0100		/* RTS Enable */
  #define USART_CR3_CTSE     0x0200		/* CTS Enable */
  #define USART_CR3_CTSIE    0x0400		/* CTS Interrupt Enable */
  #define USART_CR3_ONEBIT   0x0800		/* USART One bit method enable */
#define TOFF_USART_GTPR     0x0018		/* (RW-16) USART Guard time and prescaler register */
  #define USART_GTPR_PSC     0x00FF		/* PSC[7:0] bits (Prescaler value) */
  #define USART_GTPR_PSC_0   0x0001		/* Bit 0 */
  #define USART_GTPR_PSC_1   0x0002		/* Bit 1 */
  #define USART_GTPR_PSC_2   0x0004		/* Bit 2 */
  #define USART_GTPR_PSC_3   0x0008		/* Bit 3 */
  #define USART_GTPR_PSC_4   0x0010		/* Bit 4 */
  #define USART_GTPR_PSC_5   0x0020		/* Bit 5 */
  #define USART_GTPR_PSC_6   0x0040		/* Bit 6 */
  #define USART_GTPR_PSC_7   0x0080		/* Bit 7 */
  #define USART_GTPR_GT      0xFF00		/* Guard time value */

/*
 *  INTER-INTERATED CIRCUIT IINTERFACE(16)
 */
#define TADR_I2C1_BASE      (APB1PERIPH_BASE + 0x5400)
#define TADR_I2C2_BASE      (APB1PERIPH_BASE + 0x5800)
#define TADR_I2C3_BASE      (APB1PERIPH_BASE + 0x5C00)
#define TOFF_I2C_CR1        0x0000		/* (RW-16) I2C Control register 1 */
#define TOFF_I2C_CR2        0x0004		/* (RW-16) I2C Control register 2 */
#define TOFF_I2C_OAR1       0x0008		/* (RW-16) I2C Own address register 1 */
#define TOFF_I2C_OAR2       0x000C		/* (RW-16) I2C Own address register 2 */
#define TOFF_I2C_DR         0x0010		/* (RW-16) I2C Data register */
#define TOFF_I2C_SR1        0x0014		/* (R-16)  I2C Status register 1 */
#define TOFF_I2C_SR2        0x0018		/* (R-16)  I2C Status register 2 */
#define TOFF_I2C_CCR        0x001C		/* (RW-16) I2C Clock control register */
#define TOFF_I2C_TRISE      0x0020		/* (RW-16) I2C TRISE register */

/*
 *  CONTROLLER AREA NETWORK
 */
#define TADR_CAN1_BASE      (APB1PERIPH_BASE + 0x6400)
#define TADR_CAN2_BASE      (APB1PERIPH_BASE + 0x6800)
#define TOFF_CAN_MCR        0x0000		/* (RW) CAN master control register */
#define TOFF_CAN_MSR        0x0004		/* (R)  CAN master status register */
#define TOFF_CAN_TSR        0x0008		/* (R)  CAN transmit status register */
#define TOFF_CAN_RF0R       0x000C		/* (RW) CAN receive FIFO 0 register */
#define TOFF_CAN_RF1R       0x0010		/* (RW) CAN receive FIFO 1 register */
#define TOFF_CAN_IER        0x0014		/* (RW) CAN interrupt enable register */
#define TOFF_CAN_ESR        0x0018		/* (RW) CAN error status register */
#define TOFF_CAN_BTR        0x001C		/* (RW) CAN bit timing register */
										/* CAN TX MailBox */
#define TOFF_CAN_TIR1       0x0180		/* (RW) CAN(1) TX mailbox identifier register */
#define TOFF_CAN_TDTR1      0x0184		/* (RW) CAN(1) mailbox data length control and time stamp register */
#define TOFF_CAN_TDLR1      0x0188		/* (RW) CAN(1) mailbox data low register */
#define TOFF_CAN_TDHR1      0x018C		/* (RW) CAN(1) mailbox data high register */
#define TOFF_CAN_TIR2       0x0190		/* (RW) CAN(2) TX mailbox identifier register */
#define TOFF_CAN_TDTR2      0x0194		/* (RW) CAN(2) mailbox data length control and time stamp register */
#define TOFF_CAN_TDLR2      0x0198		/* (RW) CAN(2) mailbox data low register */
#define TOFF_CAN_TDHR2      0x019C		/* (RW) CAN(2) mailbox data high register */
#define TOFF_CAN_TIR3       0x01A0		/* (RW) CAN(3) TX mailbox identifier register */
#define TOFF_CAN_TDTR3      0x01A4		/* (RW) CAN(3) mailbox data length control and time stamp register */
#define TOFF_CAN_TDLR3      0x01A8		/* (RW) CAN(3) mailbox data low register */
#define TOFF_CAN_TDHR3      0x01AC		/* (RW) CAN(3) mailbox data high register */
										/* CAN FIFO MailBox */
#define TOFF_CAN_RIR1       0x01B0		/* (RW) CAN(1) receive FIFO mailbox identifier register */
#define TOFF_CAN_RDTR1      0x01B4		/* (RW) CAN(1) receive FIFO mailbox data length control and time stamp register */
#define TOFF_CAN_RDLR1      0x01B8		/* (RW) CAN(1) receive FIFO mailbox data low register */
#define TOFF_CAN_RDHR1      0x01BC		/* (RW) CAN(1) receive FIFO mailbox data high register */
#define TOFF_CAN_RIR2       0x01C0		/* (RW) CAN(2) receive FIFO mailbox identifier register */
#define TOFF_CAN_RDTR2      0x01C4		/* (RW) CAN(2) receive FIFO mailbox data length control and time stamp register */
#define TOFF_CAN_RDLR2      0x01C8		/* (RW) CAN(2) receive FIFO mailbox data low register */
#define TOFF_CAN_RDHR2      0x01CC		/* (RW) CAN(2) receive FIFO mailbox data high register */
#define TOFF_CAN_FMR        0x0200		/* (RW) CAN filter master register */
#define TOFF_CAN_FM1R       0x0204		/* (RW) CAN filter mode register */
#define TOFF_CAN_FS1R       0x020C		/* (RW) CAN filter scale register */
#define TOFF_CAN_FFA1R      0x0214		/* (RW) CAN filter FIFO assignment register */
#define TOFF_CAN_FA1R       0x0218		/* (RW) CAN filter activation register */
#define TOFF_CAN_FR_BASE    0x0240
#define TOFF_CAN_FR1        0x0240		/* (RW) CAN Filter bank register 1 */
#define TOFF_CAN_FR2        0x0244		/* (RW) CAN Filter bank register 1 */

/*
 *  POWER CONTROL
 */
#define TADR_PWR_BASE       (APB1PERIPH_BASE + 0x7000)
#define TOFF_PWR_CR         0x0000		/* (RW) PWR power control register */
  #define PWR_CR_LPDS              0x00000001	/* Low-Power Deepsleep */
  #define PWR_CR_PDDS              0x00000002	/* Power Down Deepsleep */
  #define PWR_CR_CWUF              0x00000004	/* Clear Wakeup Flag */
  #define PWR_CR_CSBF              0x00000008	/* Clear Standby Flag */
  #define PWR_CR_PVDE              0x00000010	/* Power Voltage Detector Enable */
  #define PWR_CR_PLS_0             0x00000020	/* Bit 0 */
  #define PWR_CR_PLS_1             0x00000040	/* Bit 1 */
  #define PWR_CR_PLS_2             0x00000080	/* Bit 2 */
  #define PWR_CR_DBP               0x00000100	/* Disable Backup Domain write protection */
  #define PWR_CR_FPDS              0x00000200	/* Flash power down in Stop mode */
#if BOARDNO == 3
  #define PWR_CR_VOS               0x0000C000   /* VOS[1:0] bits (Regulator voltage scaling output selection) */ 
  #define PWR_CR_VOS_0             0x00004000   /* Bit 0 */
  #define PWR_CR_VOS_1             0x00008000   /* Bit 1 */
#else
  #define PWR_CR_VOS               0x00004000	/* Regulator voltage scaling output selection */
#endif
  #define PWR_CR_ODEN              0x00010000	/*  Over Drive enable */
  #define PWR_CR_ODSWEN            0x00020000	/* Over Drive switch enabled */
  #define PWR_CR_UDEN_0            0x00040000	/* Under Drive enable in stop mode Bit 0 */
  #define PWR_CR_UDEN_1            0x00080000	/* Under Drive enable in stop mode Bit 1 */
  /* Legacy define */
  #define PWR_CR_PMODE             PWR_CR_VOS
#define TOFF_PWR_CSR        0x0004		/* (RW) PWR power control/status register */
  #define PWR_CSR_WUF              0x00000001	/* Wakeup Flag */
  #define PWR_CSR_SBF              0x00000002	/* Standby Flag */
  #define PWR_CSR_PVDO             0x00000004	/* PVD Output */
  #define PWR_CSR_BRR              0x00000008	/* Backup regulator ready */
  #define PWR_CSR_EWUP             0x00000100	/* Enable WKUP pin */
  #define PWR_CSR_BRE              0x00000200	/* Backup regulator enable */
  #define PWR_CSR_VOSRDY           0x00004000	/* Regulator voltage scaling output selection ready */
  #define PWR_CSR_ODRDY            0x00010000	/* Over Drive generator ready */
  #define PWR_CSR_ODSWRDY          0x00020000	/* Over Drive Switch ready */
  #define PWR_CSR_UDSWRDY          0x000C0000	/* Under Drive ready */
  /* Legacy define */
  #define PWR_CSR_REGRDY           PWR_CSR_VOSRDY

/*
 *  DIGITAL TO ANALOG CONVTER
 */
#define TADR_DAC_BASE       (APB1PERIPH_BASE + 0x7400)
#define TOFF_DAC_CR         0x0000		/* (RW) DAC control register */
#define TOFF_DAC_SWTRIGR	0x0004		/* (RW) DAC software trigger register */
#define TOFF_DAC_DHR12R1    0x0008		/* (RW) DAC channel1 12-bit right-aligned data holding register */
#define TOFF_DAC_DHR12L1    0x000C		/* (RW) DAC channel1 12-bit left aligned data holding register */
#define TOFF_DAC_DHR8R1     0x0010		/* (RW) DAC channel1 8-bit right aligned data holding register */
#define TOFF_DAC_DHR12R2    0x0014		/* (RW) DAC channel2 12-bit right aligned data holding register */
#define TOFF_DAC_DHR12L2    0x0018		/* (RW) DAC channel2 12-bit left aligned data holding register */
#define TOFF_DAC_DHR8R2     0x001C		/* (RW) DAC channel2 8-bit right-aligned data holding register */
#define TOFF_DAC_DHR12RD    0x0020		/* (RW) Dual DAC 12-bit right-aligned data holding register */
#define TOFF_DAC_DHR12LD    0x0024		/* (RW) DUAL DAC 12-bit left aligned data holding register */
#define TOFF_DAC_DHR8RD     0x0028		/* (RW) DUAL DAC 8-bit right aligned data holding register */
#define TOFF_DAC_DOR1       0x002C		/* (RW) DAC channel1 data output register */
#define TOFF_DAC_DOR2       0x0030		/* (RW) DAC channel2 data output register */
#define TOFF_DAC_SR         0x0034		/* (RW) DAC status register */


/*
 *  ANALOG TO DIGITAL CONVERTER
 */
#define TADR_ADC1_BASE      (APB2PERIPH_BASE + 0x2000)
#define TADR_ADC2_BASE      (APB2PERIPH_BASE + 0x2100)
#define TADR_ADC3_BASE      (APB2PERIPH_BASE + 0x2200)
#define TOFF_ADC_SR         0x0000		/* (RW) ADC status register */
#define TOFF_ADC_CR1        0x0004		/* (RW) ADC control register 1 */
#define TOFF_ADC_CR2        0x0008		/* (RW) ADC control register 2 */
#define TOFF_ADC_SMPR1      0x000C		/* (RW) ADC sample time register 1 */
#define TOFF_ADC_SMPR2      0x0010		/* (RW) ADC sample time register 2 */
#define TOFF_ADC_JOFR1      0x0014		/* (RW) ADC injected channel data offset register 1 */
#define TOFF_ADC_JOFR2      0x0018		/* (RW) ADC injected channel data offset register 2 */
#define TOFF_ADC_JOFR3      0x001C		/* (RW) ADC injected channel data offset register 3 */
#define TOFF_ADC_JOFR4      0x0020		/* (RW) ADC injected channel data offset register 4 */
#define TOFF_ADC_HTR        0x0024		/* (RW) ADC watchdog higher threshold register */
#define TOFF_ADC_LTR        0x0028		/* (RW) ADC watchdog lower threshold register */
#define TOFF_ADC_SQR1       0x002C		/* (RW) ADC regular sequence register 1 */
#define TOFF_ADC_SQR2       0x0030		/* (RW) ADC regular sequence register 2 */
#define TOFF_ADC_SQR3       0x0034		/* (RW) ADC regular sequence register 3 */
#define TOFF_ADC_JSQR       0x0038		/* (RW) ADC injected sequence register */
#define TOFF_ADC_JDR1       0x003C		/* (RW) ADC injected data register 1 */
#define TOFF_ADC_JDR2       0x0040		/* (RW) ADC injected data register 2 */
#define TOFF_ADC_JDR3       0x0044		/* (RW) ADC injected data register 3 */
#define TOFF_ADC_JDR4       0x0048		/* (RW) ADC injected data register 4 */
#define TOFF_ADC_DR         0x004C		/* (RW) ADC regular data register */

#define TADR_ADC_BASE       (APB2PERIPH_BASE + 0x2300)
#define TOFF_ADC_CSR        0x0000		/* (RW) ADC Common status register */
#define TOFF_ADC_CCR        0x0004		/* (RW) ADC common control register */
#define TOFF_ADC_CDR        0x0008		/* (RW) ADC common regular data register for dual AND triple modes */

/*
 *  SD HOST INTERFACE
 */
#define TADR_SDIO_BASE      (APB2PERIPH_BASE + 0x2C00)
#define TOFF_SDIO_POWER     0x0000		/* (RW) SDIO power control register */
#define TOFF_SDIO_CLKCR     0x0004		/* (RW) SDI clock control register */
#define TOFF_SDIO_ARG       0x0008		/* (RW) SDIO argument register */
#define TOFF_SDIO_CMD       0x000C		/* (RW) SDIO command register */
#define TOFF_SDIO_RESPCMD   0x0018		/* (R)  SDIO command response register */
#define TOFF_SDIO_RESP      0x0014		/* (R)  SDIO response 1 register */
#define TOFF_SDIO_RESP2     0x0018		/* (R)  SDIO response 2 register */
#define TOFF_SDIO_RESP3     0x001C		/* (R)  SDIO response 3 register */
#define TOFF_SDIO_RESP4     0x0020		/* (R)  SDIO response 4 register */
#define TOFF_SDIO_DTIMER    0x0024		/* (RW) SDIO data timer register */
#define TOFF_SDIO_DLEN      0x0028		/* (RW) SDIO data length register */
#define TOFF_SDIO_DCTRL     0x002C		/* (RW) SDIO data control register */
#define TOFF_SDIO_DCOUNT    0x0030		/* (R)  SDIO data counter register */
#define TOFF_SDIO_STA       0x0034		/* (R)  SDIO status register */
#define TOFF_SDIO_ICR       0x0038		/* (RW) SDIO interrupt clear register */
#define TOFF_SDIO_MASK      0x003C		/* (RW) SDIO mask register */
#define TOFF_SDIO_FIFOCNT   0x0048		/* (R)  SDIO FIFO counter register */
#define TOFF_SDIO_FIFO      0x0080		/* (RW) SDIO data FIFO register */

/*
 *  SYSTEM CONFIGURATION CONTROLLER
 */
#define TADR_SYSCFG_BASE    (APB2PERIPH_BASE + 0x3800)
#define TOFF_SYSCFG_MEMRMP  0x0000		/* (RW) SYSCFG memory remap register */
#define TOFF_SYSCFG_PMC     0x0004		/* (RW) SYSCFG peripheral mode configuration register */
#define TOFF_SYSCFG_EXTICR0 0x0008		/* (RW) SYSCFG external interrupt configuration registers 0 */
#define TOFF_SYSCFG_EXTICR1 0x000C		/* (RW) SYSCFG external interrupt configuration registers 1 */
#define TOFF_SYSCFG_EXTICR2 0x0010		/* (RW) SYSCFG external interrupt configuration registers 2 */
#define TOFF_SYSCFG_EXTICR3 0x0014		/* (RW) SYSCFG external interrupt configuration registers 3 */
#define TOFF_SYSCFG_CMPCR   0x0020		/* (RW) SYSCFG Compensation cell control register */

/*
 *  EXTERNAL INTERRUPT/EVENT CONTROLLER
 */
#define TADR_EXTI_BASE      (APB2PERIPH_BASE + 0x3C00)
#define TOFF_EXTI_IMR       0x0000		/* (RW) EXTI Interrupt mask register */
#define TOFF_EXTI_EMR       0x0004		/* (RW) EXTI Event mask register */
#define TOFF_EXTI_RTSR      0x0008		/* (RW) EXTI Rising trigger selection register */
#define TOFF_EXTI_FTSR      0x000C		/* (RW) EXTI Falling trigger selection register */
#define TOFF_EXTI_SWIER     0x0010		/* (RW) EXTI Software interrupt event register */
#define TOFF_EXTI_PR        0x0014		/* (RW) EXTI Pending register */

/*
 *  GENERAL PURPOSE I/O
 */
#define TADR_GPIOA_BASE     (AHB1PERIPH_BASE + 0x0000)
#define TADR_GPIOB_BASE     (AHB1PERIPH_BASE + 0x0400)
#define TADR_GPIOC_BASE     (AHB1PERIPH_BASE + 0x0800)
#define TADR_GPIOD_BASE     (AHB1PERIPH_BASE + 0x0C00)
#define TADR_GPIOE_BASE     (AHB1PERIPH_BASE + 0x1000)
#define TADR_GPIOF_BASE     (AHB1PERIPH_BASE + 0x1400)
#define TADR_GPIOG_BASE     (AHB1PERIPH_BASE + 0x1800)
#define TADR_GPIOH_BASE     (AHB1PERIPH_BASE + 0x1C00)
#define TADR_GPIOI_BASE     (AHB1PERIPH_BASE + 0x2000)
#define TOFF_GPIO_MODER     0x0000		/* (RW) GPIO port mode register */
  #define GPIO_MODER_MODER0  0x1
  #define GPIO_MODER_MODER1  0x2
  #define GPIO_MODER_MODER2  0x3
#define TOFF_GPIO_OTYPER    0x0004		/* (RW) GPIO port output type register */
  #define GPIO_OTYPER_OT     0x1
#define TOFF_GPIO_OSPEEDR   0x0008		/* (RW) GPIO port output speed register */
  #define GPIO_OSPEEDER_OSPEEDR0 0x1
  #define GPIO_OSPEEDER_OSPEEDR1 0x2
  #define GPIO_OSPEEDER_OSPEEDR2 0x3
#define TOFF_GPIO_PUPDR     0x000C		/* (RW) GPIO port pull-up/pull-down register */
  #define GPIO_PUPDR_PUPDR0  0x1
  #define GPIO_PUPDR_PUPDR1  0x2
  #define GPIO_PUPDR_PUPDR2  0x3
#define TOFF_GPIO_IDR       0x0010		/* (R)  GPIO port input data register */
#define TOFF_GPIO_ODR       0x0014		/* (RW) GPIO port output data register */
#define TOFF_GPIO_BSRRL     0x0018		/* (RW-16) GPIO port bit set/reset low register */
#define TOFF_GPIO_BSRRH     0x001A		/* (RW-16) GPIO port bit set/reset high register */
#define TOFF_GPIO_LCKR      0x001C		/* (RW) GPIO port configuration lock register */
#define TOFF_GPIO_AFR0      0x0020		/* (RW) GPIO alternate function registers */
#define TOFF_GPIO_AFR1      0x0024		/* (RW) GPIO alternate function registers */

/*
 *  CRC CALCULATION UNIT
 */
#define TADR_CRC_BASE       (AHB1PERIPH_BASE + 0x3000)
#define TOFF_CRC_DR         0x0000		/* (RW) CRC Data register */
#define TOFF_CRC_IDR        0x0004		/* (RW-8) CRC Independent data register */
#define TOFF_CRC_CR         0x0008		/* (RW) CRC Control register */

/*
 *  RESET AND CLOCK CONTROL
 */
#define TADR_RCC_BASE       (AHB1PERIPH_BASE + 0x3800)
#define TOFF_RCC_CR         0x0000		/* (RW) RCC clock control register */
  #define RCC_CR_HSION             0x00000001
  #define RCC_CR_HSIRDY            0x00000002
  #define RCC_CR_HSITRIM_0         0x00000008	/* Bit 0 */
  #define RCC_CR_HSITRIM_1         0x00000010	/* Bit 1 */
  #define RCC_CR_HSITRIM_2         0x00000020	/* Bit 2 */
  #define RCC_CR_HSITRIM_3         0x00000040	/* Bit 3 */
  #define RCC_CR_HSITRIM_4         0x00000080	/* Bit 4 */
  #define RCC_CR_HSICAL_0          0x00000100	/* Bit 0 */
  #define RCC_CR_HSICAL_1          0x00000200	/* Bit 1 */
  #define RCC_CR_HSICAL_2          0x00000400	/* Bit 2 */
  #define RCC_CR_HSICAL_3          0x00000800	/* Bit 3 */
  #define RCC_CR_HSICAL_4          0x00001000	/* Bit 4 */
  #define RCC_CR_HSICAL_5          0x00002000	/* Bit 5 */
  #define RCC_CR_HSICAL_6          0x00004000	/* Bit 6 */
  #define RCC_CR_HSICAL_7          0x00008000	/* Bit 7 */
  #define RCC_CR_HSEON             0x00010000
  #define RCC_CR_HSERDY            0x00020000
  #define RCC_CR_HSEBYP            0x00040000
  #define RCC_CR_CSSON             0x00080000
  #define RCC_CR_PLLON             0x01000000
  #define RCC_CR_PLLRDY            0x02000000
  #define RCC_CR_PLLI2SON          0x04000000
  #define RCC_CR_PLLI2SRDY         0x08000000
#define TOFF_RCC_PLLCFGR    0x0004		/* (RW) RCC PLL configuration register */
  #define  RCC_PLLCFGR_PLLM_0      0x00000001
  #define  RCC_PLLCFGR_PLLM_1      0x00000002
  #define  RCC_PLLCFGR_PLLM_2      0x00000004
  #define  RCC_PLLCFGR_PLLM_3      0x00000008
  #define  RCC_PLLCFGR_PLLM_4      0x00000010
  #define  RCC_PLLCFGR_PLLM_5      0x00000020
  #define  RCC_PLLCFGR_PLLN_0      0x00000040
  #define  RCC_PLLCFGR_PLLN_1      0x00000080
  #define  RCC_PLLCFGR_PLLN_2      0x00000100
  #define  RCC_PLLCFGR_PLLN_3      0x00000200
  #define  RCC_PLLCFGR_PLLN_4      0x00000400
  #define  RCC_PLLCFGR_PLLN_5      0x00000800
  #define  RCC_PLLCFGR_PLLN_6      0x00001000
  #define  RCC_PLLCFGR_PLLN_7      0x00002000
  #define  RCC_PLLCFGR_PLLN_8      0x00004000
  #define  RCC_PLLCFGR_PLLP_0      0x00010000
  #define  RCC_PLLCFGR_PLLP_1      0x00020000
  #define  RCC_PLLCFGR_PLLSRC_HSE  0x00400000
  #define  RCC_PLLCFGR_PLLSRC_HSI  0x00000000
  #define  RCC_PLLCFGR_PLLQ_0      0x01000000
  #define  RCC_PLLCFGR_PLLQ_1      0x02000000
  #define  RCC_PLLCFGR_PLLQ_2      0x04000000
  #define  RCC_PLLCFGR_PLLQ_3      0x08000000
#define TOFF_RCC_CFGR       0x0008		/* (RW) RCC clock configuration register */
  #define RCC_CFGR_SW_0            0x00000001	/* Bit 0 */
  #define RCC_CFGR_SW_1            0x00000002	/* Bit 1 */
  #define RCC_CFGR_SW_HSI          0x00000000	/* HSI selected as system clock */
  #define RCC_CFGR_SW_HSE          0x00000001	/* HSE selected as system clock */
  #define RCC_CFGR_SW_PLL          0x00000002	/* PLL selected as system clock */
  #define RCC_CFGR_SWS_0           0x00000004	/* Bit 0 */
  #define RCC_CFGR_SWS_1           0x00000008	/* Bit 1 */
  #define RCC_CFGR_SWS_HSI         0x00000000	/* HSI oscillator used as system clock */
  #define RCC_CFGR_SWS_HSE         0x00000004	/* HSE oscillator used as system clock */
  #define RCC_CFGR_SWS_PLL         0x00000008	/* PLL used as system clock */
  #define RCC_CFGR_HPRE_0          0x00000010	/* Bit 0 */
  #define RCC_CFGR_HPRE_1          0x00000020	/* Bit 1 */
  #define RCC_CFGR_HPRE_2          0x00000040	/* Bit 2 */
  #define RCC_CFGR_HPRE_3          0x00000080	/* Bit 3 */
  #define RCC_CFGR_HPRE_DIV1       0x00000000	/* SYSCLK not divided */
  #define RCC_CFGR_HPRE_DIV2       0x00000080	/* SYSCLK divided by 2 */
  #define RCC_CFGR_HPRE_DIV4       0x00000090	/* SYSCLK divided by 4 */
  #define RCC_CFGR_HPRE_DIV8       0x000000A0	/* SYSCLK divided by 8 */
  #define RCC_CFGR_HPRE_DIV16      0x000000B0	/* SYSCLK divided by 16 */
  #define RCC_CFGR_HPRE_DIV64      0x000000C0	/* SYSCLK divided by 64 */
  #define RCC_CFGR_HPRE_DIV128     0x000000D0	/* SYSCLK divided by 128 */
  #define RCC_CFGR_HPRE_DIV256     0x000000E0	/* SYSCLK divided by 256 */
  #define RCC_CFGR_HPRE_DIV512     0x000000F0	/* SYSCLK divided by 512 */
  #define RCC_CFGR_PPRE1_0         0x00000400	/* Bit 0 */
  #define RCC_CFGR_PPRE1_1         0x00000800	/* Bit 1 */
  #define RCC_CFGR_PPRE1_2         0x00001000	/* Bit 2 */
  #define RCC_CFGR_PPRE1_DIV1      0x00000000	/* HCLK not divided */
  #define RCC_CFGR_PPRE1_DIV2      0x00001000	/* HCLK divided by 2 */
  #define RCC_CFGR_PPRE1_DIV4      0x00001400	/* HCLK divided by 4 */
  #define RCC_CFGR_PPRE1_DIV8      0x00001800	/* HCLK divided by 8 */
  #define RCC_CFGR_PPRE1_DIV16     0x00001C00	/* HCLK divided by 16 */
  #define RCC_CFGR_PPRE2_0         0x00002000	/* Bit 0 */
  #define RCC_CFGR_PPRE2_1         0x00004000	/* Bit 1 */
  #define RCC_CFGR_PPRE2_2         0x00008000	/* Bit 2 */
  #define RCC_CFGR_PPRE2_DIV1      0x00000000	/* HCLK not divided */
  #define RCC_CFGR_PPRE2_DIV2      0x00008000	/* HCLK divided by 2 */
  #define RCC_CFGR_PPRE2_DIV4      0x0000A000	/* HCLK divided by 4 */
  #define RCC_CFGR_PPRE2_DIV8      0x0000C000	/* HCLK divided by 8 */
  #define RCC_CFGR_PPRE2_DIV16     0x0000E000	/* HCLK divided by 16 */
  #define RCC_CFGR_RTCPRE_0        0x00010000
  #define RCC_CFGR_RTCPRE_1        0x00020000
  #define RCC_CFGR_RTCPRE_2        0x00040000
  #define RCC_CFGR_RTCPRE_3        0x00080000
  #define RCC_CFGR_RTCPRE_4        0x00100000
  #define RCC_CFGR_MCO1_0          0x00200000
  #define RCC_CFGR_MCO1_1          0x00400000
  #define RCC_CFGR_I2SSRC          0x00800000
  #define RCC_CFGR_MCO1PRE_0       0x01000000
  #define RCC_CFGR_MCO1PRE_1       0x02000000
  #define RCC_CFGR_MCO1PRE_2       0x04000000
  #define RCC_CFGR_MCO2PRE_0       0x08000000
  #define RCC_CFGR_MCO2PRE_1       0x10000000
  #define RCC_CFGR_MCO2PRE_2       0x20000000
  #define RCC_CFGR_MCO2_0          0x40000000
  #define RCC_CFGR_MCO2_1          0x80000000
#define TOFF_RCC_CIR        0x000C		/* (RW) RCC clock interrupt register */
  #define RCC_CIR_LSIRDYF          0x00000001
  #define RCC_CIR_LSERDYF          0x00000002
  #define RCC_CIR_HSIRDYF          0x00000004
  #define RCC_CIR_HSERDYF          0x00000008
  #define RCC_CIR_PLLRDYF          0x00000010
  #define RCC_CIR_PLLI2SRDYF       0x00000020
  #define RCC_CIR_CSSF             0x00000080
  #define RCC_CIR_LSIRDYIE         0x00000100
  #define RCC_CIR_LSERDYIE         0x00000200
  #define RCC_CIR_HSIRDYIE         0x00000400
  #define RCC_CIR_HSERDYIE         0x00000800
  #define RCC_CIR_PLLRDYIE         0x00001000
  #define RCC_CIR_PLLI2SRDYIE      0x00002000
  #define RCC_CIR_LSIRDYC          0x00010000
  #define RCC_CIR_LSERDYC          0x00020000
  #define RCC_CIR_HSIRDYC          0x00040000
  #define RCC_CIR_HSERDYC          0x00080000
  #define RCC_CIR_PLLRDYC          0x00100000
  #define RCC_CIR_PLLI2SRDYC       0x00200000
  #define RCC_CIR_CSSC             0x00800000
#define TOFF_RCC_AHB1RSTR   0x0010		/* (RW) RCC AHB1 peripheral reset register */
  #define RCC_AHB1RSTR_GPIOARST    0x00000001
  #define RCC_AHB1RSTR_GPIOBRST    0x00000002
  #define RCC_AHB1RSTR_GPIOCRST    0x00000004
  #define RCC_AHB1RSTR_GPIODRST    0x00000008
  #define RCC_AHB1RSTR_GPIOERST    0x00000010
  #define RCC_AHB1RSTR_GPIOFRST    0x00000020
  #define RCC_AHB1RSTR_GPIOGRST    0x00000040
  #define RCC_AHB1RSTR_GPIOHRST    0x00000080
  #define RCC_AHB1RSTR_GPIOIRST    0x00000100
  #define RCC_AHB1RSTR_CRCRST      0x00001000
  #define RCC_AHB1RSTR_DMA1RST     0x00200000
  #define RCC_AHB1RSTR_DMA2RST     0x00400000
  #define RCC_AHB1RSTR_ETHMACRST   0x02000000
  #define RCC_AHB1RSTR_OTGHRST     0x10000000
#define TOFF_RCC_AHB2RSTR   0x0014		/* (RW) RCC AHB2 peripheral reset register */
  #define RCC_AHB2RSTR_DCMIRST     0x00000001
  #define RCC_AHB2RSTR_CRYPRST     0x00000010
  #define RCC_AHB2RSTR_HSAHRST     0x00000020
  #define RCC_AHB2RSTR_RNGRST      0x00000040
  #define RCC_AHB2RSTR_OTGFSRST    0x00000080
#define TOFF_RCC_AHB3RSTR   0x0018		/* (RW) RCC AHB3 peripheral reset register */
  #define RCC_AHB3RSTR_FSMCRST     0x00000001
#define TOFF_RCC_APB1RSTR   0x0020		/* (RW) RCC APB1 peripheral reset register */
  #define RCC_APB1RSTR_TIM2RST     0x00000001
  #define RCC_APB1RSTR_TIM3RST     0x00000002
  #define RCC_APB1RSTR_TIM4RST     0x00000004
  #define RCC_APB1RSTR_TIM5RST     0x00000008
  #define RCC_APB1RSTR_TIM6RST     0x00000010
  #define RCC_APB1RSTR_TIM7RST     0x00000020
  #define RCC_APB1RSTR_TIM12RST    0x00000040
  #define RCC_APB1RSTR_TIM13RST    0x00000080
  #define RCC_APB1RSTR_TIM14RST    0x00000100
  #define RCC_APB1RSTR_WWDGEN      0x00000800
#if BOARDNO == 3
  #define RCC_APB1RSTR_SPI2RST     0x00004000
  #define RCC_APB1RSTR_SPI3RST     0x00008000
#else
  #define RCC_APB1RSTR_SPI2RST     0x00008000
  #define RCC_APB1RSTR_SPI3RST     0x00010000
#endif
  #define RCC_APB1RSTR_USART2RST   0x00020000
  #define RCC_APB1RSTR_USART3RST   0x00040000
  #define RCC_APB1RSTR_UART4RST    0x00080000
  #define RCC_APB1RSTR_UART5RST    0x00100000
  #define RCC_APB1RSTR_I2C1RST     0x00200000
  #define RCC_APB1RSTR_I2C2RST     0x00400000
  #define RCC_APB1RSTR_I2C3RST     0x00800000
  #define RCC_APB1RSTR_CAN1RST     0x02000000
  #define RCC_APB1RSTR_CAN2RST     0x04000000
  #define RCC_APB1RSTR_PWRRST      0x10000000
  #define RCC_APB1RSTR_DACRST      0x20000000
#define TOFF_RCC_APB2RSTR   0x0024		/* (RW) RCC APB2 peripheral reset register */
  #define RCC_APB2RSTR_TIM1RST     0x00000001
  #define RCC_APB2RSTR_TIM8RST     0x00000002
  #define RCC_APB2RSTR_USART1RST   0x00000010
  #define RCC_APB2RSTR_USART6RST   0x00000020
  #define RCC_APB2RSTR_ADCRST      0x00000100
  #define RCC_APB2RSTR_SDIORST     0x00000800
  #define RCC_APB2RSTR_SPI1RST     0x00001000
  #define RCC_APB2RSTR_SYSCFGRST   0x00004000
  #define RCC_APB2RSTR_TIM9RST     0x00010000
  #define RCC_APB2RSTR_TIM10RST    0x00020000
  #define RCC_APB2RSTR_TIM11RST    0x00040000
  /* Old SPI1RST bit definition, maintained for legacy purpose */
  #define RCC_APB2RSTR_SPI1        RCC_APB2RSTR_SPI1RST
#define TOFF_RCC_AHB1ENR    0x0030		/* (RW) RCC AHB1 peripheral clock register */
  #define RCC_AHB1ENR_GPIOAEN      0x00000001
  #define RCC_AHB1ENR_GPIOBEN      0x00000002
  #define RCC_AHB1ENR_GPIOCEN      0x00000004
  #define RCC_AHB1ENR_GPIODEN      0x00000008
  #define RCC_AHB1ENR_GPIOEEN      0x00000010
  #define RCC_AHB1ENR_GPIOFEN      0x00000020
  #define RCC_AHB1ENR_GPIOGEN      0x00000040
  #define RCC_AHB1ENR_GPIOHEN      0x00000080
  #define RCC_AHB1ENR_GPIOIEN      0x00000100
  #define RCC_AHB1ENR_CRCEN        0x00001000
  #define RCC_AHB1ENR_BKPSRAMEN    0x00040000
  #define RCC_AHB1ENR_CCMDATARAMEN 0x00100000
  #define RCC_AHB1ENR_DMA1EN       0x00200000
  #define RCC_AHB1ENR_DMA2EN       0x00400000
  #define RCC_AHB1ENR_ETHMACEN     0x02000000
  #define RCC_AHB1ENR_ETHMACTXEN   0x04000000
  #define RCC_AHB1ENR_ETHMACRXEN   0x08000000
  #define RCC_AHB1ENR_ETHMACPTPEN  0x10000000
  #define RCC_AHB1ENR_OTGHSEN      0x20000000
  #define RCC_AHB1ENR_OTGHSULPIEN  0x40000000
#define TOFF_RCC_AHB2ENR    0x0034		/* (RW) RCC AHB2 peripheral clock register */
  #define RCC_AHB2ENR_DCMIEN       0x00000001
  #define RCC_AHB2ENR_CRYPEN       0x00000010
  #define RCC_AHB2ENR_HASHEN       0x00000020
  #define RCC_AHB2ENR_RNGEN        0x00000040
  #define RCC_AHB2ENR_OTGFSEN      0x00000080
#define TOFF_RCC_AHB3ENR    0x0038		/* (RW) RCC AHB3 peripheral clock register */
  #define RCC_AHB3ENR_FSMCEN       0x00000001
#define TOFF_RCC_APB1ENR    0x0040		/* (RW) RCC APB1 peripheral clock enable register */
  #define RCC_APB1ENR_TIM2EN       0x00000001
  #define RCC_APB1ENR_TIM3EN       0x00000002
  #define RCC_APB1ENR_TIM4EN       0x00000004
  #define RCC_APB1ENR_TIM5EN       0x00000008
  #define RCC_APB1ENR_TIM6EN       0x00000010
  #define RCC_APB1ENR_TIM7EN       0x00000020
  #define RCC_APB1ENR_TIM12EN      0x00000040
  #define RCC_APB1ENR_TIM13EN      0x00000080
  #define RCC_APB1ENR_TIM14EN      0x00000100
  #define RCC_APB1ENR_WWDGEN       0x00000800
  #define RCC_APB1ENR_SPI2EN       0x00004000
  #define RCC_APB1ENR_SPI3EN       0x00008000
  #define RCC_APB1ENR_USART2EN     0x00020000
  #define RCC_APB1ENR_USART3EN     0x00040000
  #define RCC_APB1ENR_UART4EN      0x00080000
  #define RCC_APB1ENR_UART5EN      0x00100000
  #define RCC_APB1ENR_I2C1EN       0x00200000
  #define RCC_APB1ENR_I2C2EN       0x00400000
  #define RCC_APB1ENR_I2C3EN       0x00800000
  #define RCC_APB1ENR_CAN1EN       0x02000000
  #define RCC_APB1ENR_CAN2EN       0x04000000
  #define RCC_APB1ENR_PWREN        0x10000000
  #define RCC_APB1ENR_DACEN        0x20000000
#define TOFF_RCC_APB2ENR    0x0044		/* (RW) RCC APB2 peripheral clock enable register */
  #define RCC_APB2ENR_TIM1EN       0x00000001
  #define RCC_APB2ENR_TIM8EN       0x00000002
  #define RCC_APB2ENR_USART1EN     0x00000010
  #define RCC_APB2ENR_USART6EN     0x00000020
  #define RCC_APB2ENR_ADC1EN       0x00000100
  #define RCC_APB2ENR_ADC2EN       0x00000200
  #define RCC_APB2ENR_ADC3EN       0x00000400
  #define RCC_APB2ENR_SDIOEN       0x00000800
  #define RCC_APB2ENR_SPI1EN       0x00001000
  #define RCC_APB2ENR_SPI4EN       0x00002000
  #define RCC_APB2ENR_SYSCFGEN     0x00004000
  #define RCC_APB2ENR_TIM11EN      0x00040000
  #define RCC_APB2ENR_TIM10EN      0x00020000
  #define RCC_APB2ENR_TIM9EN       0x00010000
#define TOFF_RCC_AHB1LPENR  0x0050		/* (RW) RCC AHB1 peripheral clock enable in low power mode register */
  #define RCC_AHB1LPENR_GPIOALPEN     0x00000001
  #define RCC_AHB1LPENR_GPIOBLPEN     0x00000002
  #define RCC_AHB1LPENR_GPIOCLPEN     0x00000004
  #define RCC_AHB1LPENR_GPIODLPEN     0x00000008
  #define RCC_AHB1LPENR_GPIOELPEN     0x00000010
  #define RCC_AHB1LPENR_GPIOFLPEN     0x00000020
  #define RCC_AHB1LPENR_GPIOGLPEN     0x00000040
  #define RCC_AHB1LPENR_GPIOHLPEN     0x00000080
  #define RCC_AHB1LPENR_GPIOILPEN     0x00000100
  #define RCC_AHB1LPENR_CRCLPEN       0x00001000
  #define RCC_AHB1LPENR_FLITFLPEN     0x00008000
  #define RCC_AHB1LPENR_SRAM1LPEN     0x00010000
  #define RCC_AHB1LPENR_SRAM2LPEN     0x00020000
  #define RCC_AHB1LPENR_BKPSRAMLPEN   0x00040000
  #define RCC_AHB1LPENR_DMA1LPEN      0x00200000
  #define RCC_AHB1LPENR_DMA2LPEN      0x00400000
  #define RCC_AHB1LPENR_ETHMACLPEN    0x02000000
  #define RCC_AHB1LPENR_ETHMACTXLPEN  0x04000000
  #define RCC_AHB1LPENR_ETHMACRXLPEN  0x08000000
  #define RCC_AHB1LPENR_ETHMACPTPLPEN 0x10000000
  #define RCC_AHB1LPENR_OTGHSLPEN     0x20000000
  #define RCC_AHB1LPENR_OTGHSULPILPEN 0x40000000
#define TOFF_RCC_AHB2LPENR  0x0054		/* (RW) RCC AHB2 peripheral clock enable in low power mode register */
  #define RCC_AHB2LPENR_DCMILPEN   0x00000001
  #define RCC_AHB2LPENR_CRYPLPEN   0x00000010
  #define RCC_AHB2LPENR_HASHLPEN   0x00000020
  #define RCC_AHB2LPENR_RNGLPEN    0x00000040
  #define RCC_AHB2LPENR_OTGFSLPEN  0x00000080
#define TOFF_RCC_AHB3LPENR  0x0058		/* (RW) RCC AHB3 peripheral clock enable in low power mode register */
  #define RCC_AHB3LPENR_FSMCLPEN   0x00000001
#define TOFF_RCC_APB1LPENR  0x0060		/* (RW) RCC APB1 peripheral clock enable in low power mode register */
  #define RCC_APB1LPENR_TIM2LPEN   0x00000001
  #define RCC_APB1LPENR_TIM3LPEN   0x00000002
  #define RCC_APB1LPENR_TIM4LPEN   0x00000004
  #define RCC_APB1LPENR_TIM5LPEN   0x00000008
  #define RCC_APB1LPENR_TIM6LPEN   0x00000010
  #define RCC_APB1LPENR_TIM7LPEN   0x00000020
  #define RCC_APB1LPENR_TIM12LPEN  0x00000040
  #define RCC_APB1LPENR_TIM13LPEN  0x00000080
  #define RCC_APB1LPENR_TIM14LPEN  0x00000100
  #define RCC_APB1LPENR_WWDGLPEN   0x00000800
  #define RCC_APB1LPENR_SPI2LPEN   0x00004000
  #define RCC_APB1LPENR_SPI3LPEN   0x00008000
  #define RCC_APB1LPENR_USART2LPEN 0x00020000
  #define RCC_APB1LPENR_USART3LPEN 0x00040000
  #define RCC_APB1LPENR_UART4LPEN  0x00080000
  #define RCC_APB1LPENR_UART5LPEN  0x00100000
  #define RCC_APB1LPENR_I2C1LPEN   0x00200000
  #define RCC_APB1LPENR_I2C2LPEN   0x00400000
  #define RCC_APB1LPENR_I2C3LPEN   0x00800000
  #define RCC_APB1LPENR_CAN1LPEN   0x02000000
  #define RCC_APB1LPENR_CAN2LPEN   0x04000000
  #define RCC_APB1LPENR_PWRLPEN    0x10000000
  #define RCC_APB1LPENR_DACLPEN    0x20000000
#define TOFF_RCC_APB2LPENR  0x0064		/* (RW) RCC APB2 peripheral clock enable in low power mode register */
  #define RCC_APB2LPENR_TIM1LPEN   0x00000001
  #define RCC_APB2LPENR_TIM8LPEN   0x00000002
  #define RCC_APB2LPENR_USART1LPEN 0x00000010
  #define RCC_APB2LPENR_USART6LPEN 0x00000020
  #define RCC_APB2LPENR_ADC1LPEN   0x00000100
  #define RCC_APB2LPENR_ADC2PEN    0x00000200
  #define RCC_APB2LPENR_ADC3LPEN   0x00000400
  #define RCC_APB2LPENR_SDIOLPEN   0x00000800
  #define RCC_APB2LPENR_SPI1LPEN   0x00001000
  #define RCC_APB2LPENR_SPI4LPEN   0x00002000
  #define RCC_APB2LPENR_SYSCFGLPEN 0x00004000
  #define RCC_APB2LPENR_TIM9LPEN   0x00010000
  #define RCC_APB2LPENR_TIM10LPEN  0x00020000
  #define RCC_APB2LPENR_TIM11LPEN  0x00040000
#define TOFF_RCC_BDCR       0x0070		/* (RW) RCC Backup domain control register */
  #define RCC_BDCR_LSEON           0x00000001
  #define RCC_BDCR_LSERDY          0x00000002
  #define RCC_BDCR_LSEBYP          0x00000004
  #define RCC_BDCR_RTCSEL          0x00000300
  #define RCC_BDCR_RTCSEL_0        0x00000100
  #define RCC_BDCR_RTCSEL_1        0x00000200
  #define RCC_BDCR_RTCEN           0x00008000
  #define RCC_BDCR_BDRST           0x00010000
#define TOFF_RCC_CSR        0x0074		/* (RW) RCC clock control & status register */
  #define RCC_CSR_LSION            0x00000001
  #define RCC_CSR_LSIRDY           0x00000002
  #define RCC_CSR_RMVF             0x01000000
  #define RCC_CSR_BORRSTF          0x02000000
  #define RCC_CSR_PADRSTF          0x04000000
  #define RCC_CSR_PORRSTF          0x08000000
  #define RCC_CSR_SFTRSTF          0x10000000
  #define RCC_CSR_WDGRSTF          0x20000000
  #define RCC_CSR_WWDGRSTF         0x40000000
  #define RCC_CSR_LPWRRSTF         0x80000000
#define TOFF_RCC_SSCGR      0x0080		/* (RW) RCC spread spectrum clock generation register */
  #define RCC_SSCGR_MODPER         0x00001FFF
  #define RCC_SSCGR_INCSTEP        0x0FFFE000
  #define RCC_SSCGR_SPREADSEL      0x40000000
  #define RCC_SSCGR_SSCGEN         0x80000000
#define TOFF_RCC_PLLI2SCFGR 0x0084		/* (RW) RCC PLLI2S configuration register */
  #define RCC_PLLI2SCFGR_PLLI2SN   0x00007FC0
  #define RCC_PLLI2SCFGR_PLLI2SR   0x70000000

/*
 *  FLASH REGISTERS
 */
#define TADR_FLASH_R_BASE   (AHB1PERIPH_BASE + 0x3C00)
#define TOFF_FLASH_ACR      0x0000		/* (RW) FLASH access control register */
  #define FLASH_ACR_LATENCY_0WS    0x00000000
  #define FLASH_ACR_LATENCY_1WS    0x00000001
  #define FLASH_ACR_LATENCY_2WS    0x00000002
  #define FLASH_ACR_LATENCY_3WS    0x00000003
  #define FLASH_ACR_LATENCY_4WS    0x00000004
  #define FLASH_ACR_LATENCY_5WS    0x00000005
  #define FLASH_ACR_LATENCY_6WS    0x00000006
  #define FLASH_ACR_LATENCY_7WS    0x00000007
  #define FLASH_ACR_PRFTEN         0x00000100
  #define FLASH_ACR_ICEN           0x00000200
  #define FLASH_ACR_DCEN           0x00000400
  #define FLASH_ACR_ICRST          0x00000800
  #define FLASH_ACR_DCRST          0x00001000
  #define FLASH_ACR_BYTE0_ADDRESS  0x40023C00
  #define FLASH_ACR_BYTE2_ADDRESS  0x40023C03
#define TOFF_FLASH_KEYR     0x0004		/* (RW) FLASH key register */
#define TOFF_FLASH_OPTKEYR  0x0008		/* (RW) FLASH option key register */
#define TOFF_FLASH_SR       0x000C		/* (RW) FLASH status register */
  #define FLASH_SR_EOP             0x00000001
  #define FLASH_SR_SOP             0x00000002
  #define FLASH_SR_WRPERR          0x00000010
  #define FLASH_SR_PGAERR          0x00000020
  #define FLASH_SR_PGPERR          0x00000040
  #define FLASH_SR_PGSERR          0x00000080
  #define FLASH_SR_BSY             0x00010000
#define TOFF_FLASH_CR       0x0010		/* (RW) FLASH control register */
  #define FLASH_CR_PG              0x00000001
  #define FLASH_CR_SER             0x00000002
  #define FLASH_CR_MER             0x00000004
  #define FLASH_CR_SNB_0           0x00000008
  #define FLASH_CR_SNB_1           0x00000010
  #define FLASH_CR_SNB_2           0x00000020
  #define FLASH_CR_SNB_3           0x00000040
  #define FLASH_CR_PSIZE_0         0x00000100
  #define FLASH_CR_PSIZE_1         0x00000200
  #define FLASH_CR_STRT            0x00010000
  #define FLASH_CR_EOPIE           0x01000000
  #define FLASH_CR_LOCK            0x80000000
#define TOFF_FLASH_OPTCR    0x0014		/* (RW) FLASH option control register */
  #define FLASH_OPTCR_OPTLOCK      0x00000001
  #define FLASH_OPTCR_OPTSTRT      0x00000002
  #define FLASH_OPTCR_BOR_LEV_0    0x00000004
  #define FLASH_OPTCR_BOR_LEV_1    0x00000008
  #define FLASH_OPTCR_BOR_LEV      0x0000000C
  #define FLASH_OPTCR_WDG_SW       0x00000020
  #define FLASH_OPTCR_nRST_STOP    0x00000040
  #define FLASH_OPTCR_nRST_STDBY   0x00000080
  #define FLASH_OPTCR_RDP_0        0x00000100
  #define FLASH_OPTCR_RDP_1        0x00000200
  #define FLASH_OPTCR_RDP_2        0x00000400
  #define FLASH_OPTCR_RDP_3        0x00000800
  #define FLASH_OPTCR_RDP_4        0x00001000
  #define FLASH_OPTCR_RDP_5        0x00002000
  #define FLASH_OPTCR_RDP_6        0x00004000
  #define FLASH_OPTCR_RDP_7        0x00008000
  #define FLASH_OPTCR_nWRP_0       0x00010000
  #define FLASH_OPTCR_nWRP_1       0x00020000
  #define FLASH_OPTCR_nWRP_2       0x00040000
  #define FLASH_OPTCR_nWRP_3       0x00080000
  #define FLASH_OPTCR_nWRP_4       0x00100000
  #define FLASH_OPTCR_nWRP_5       0x00200000
  #define FLASH_OPTCR_nWRP_6       0x00400000
  #define FLASH_OPTCR_nWRP_7       0x00800000
  #define FLASH_OPTCR_nWRP_8       0x01000000
  #define FLASH_OPTCR_nWRP_9       0x02000000
  #define FLASH_OPTCR_nWRP_10      0x04000000
  #define FLASH_OPTCR_nWRP_11      0x08000000

/* 
 *  DMA CONTROLLER
 */
#define TADR_DMA1_BASE      (AHB1PERIPH_BASE + 0x6000)
#define TADR_DMA2_BASE      (AHB1PERIPH_BASE + 0x6400)
#define TOFF_DMAI_LISR      0x0000		/* (RW) DMA low interrupt status register */
#define TOFF_DMAI_HISR      0x0004		/* (RW) DMA high interrupt status register */
#define TOFF_DMAI_LIFCR     0x0008		/* (RW) DMA low interrupt flag clear register */
#define TOFF_DMAI_HIFCR     0x000C		/* (RW) DMA high interrupt flag clear register */

#define TADR_DMA1_STM0_BASE (DMA1_BASE + 0x010)
#define TADR_DMA1_STM1_BASE (DMA1_BASE + 0x028)
#define TADR_DMA1_STM2_BASE (DMA1_BASE + 0x040)
#define TADR_DMA1_STM3_BASE (DMA1_BASE + 0x058)
#define TADR_DMA1_STM4_BASE (DMA1_BASE + 0x070)
#define TADR_DMA1_STM5_BASE (DMA1_BASE + 0x088)
#define TADR_DMA1_STM6_BASE (DMA1_BASE + 0x0A0)
#define TADR_DMA1_STM7_BASE (DMA1_BASE + 0x0B8)
#define TADR_DMA2_STM0_BASE (DMA2_BASE + 0x010)
#define TADR_DMA2_STM1_BASE (DMA2_BASE + 0x028)
#define TADR_DMA2_STM2_BASE (DMA2_BASE + 0x040)
#define TADR_DMA2_STM3_BASE (DMA2_BASE + 0x058)
#define TADR_DMA2_STM4_BASE (DMA2_BASE + 0x070)
#define TADR_DMA2_STM5_BASE (DMA2_BASE + 0x088)
#define TADR_DMA2_STM6_BASE (DMA2_BASE + 0x0A0)
#define TADR_DMA2_STM7_BASE (DMA2_BASE + 0x0B8)
#define TOFF_DMAS_CR        0x0000		/* (RW) DMA stream x configuration register      */
#define TOFF_DMAS_NDTR      0x0004		/* (RW) DMA stream x number of data register     */
#define TOFF_DMAS_PAR       0x0008		/* (RW) DMA stream x peripheral address register */
#define TOFF_DMAS_M0AR      0x000C		/* (RW) DMA stream x memory 0 address register   */
#define TOFF_DMAS_M1AR      0x0010		/* (RW) DMA stream x memory 1 address register   */
#define TOFF_DMAS_FCR       0x0014		/* (RW) DMA stream x FIFO control register       */




#define ETH_BASE            (AHB1PERIPH_BASE + 0x8000)
#define ETH_MAC_BASE        (ETH_BASE)
#define ETH_MMC_BASE        (ETH_BASE + 0x0100)
#define ETH_PTP_BASE        (ETH_BASE + 0x0700)
#define ETH_DMA_BASE        (ETH_BASE + 0x1000)



/*
 *  DCMI
 */
#define TADR_DCMI_BASE      (AHB2PERIPH_BASE + 0x50000)
#define TOFF_DCMI_CR        0x0000		/* (RW) DCMI control register 1 */
#define TOFF_DCMI_SR        0x0004		/* (R)  DCMI status register */
#define TOFF_DCMI_RISR      0x0008		/* (R)  DCMI raw interrupt status register */
#define TOFF_DCMI_IER       0x000C		/* (RW) DCMI interrupt enable register */
#define TOFF_DCMI_MISR      0x0010		/* (RW) DCMI masked interrupt status register */
#define TOFF_DCMI_ICR       0x0014		/* (RW) DCMI interrupt clear register */
#define TOFF_DCMI_ESCR      0x0018		/* (RW) DCMI embedded synchronization code register */
#define TOFF_DCMI_ESUR      0x001C		/* (RW) DCMI embedded synchronization unmask register */
#define TOFF_DCMI_CWSTRTR   0x0020		/* (RW) DCMI crop window start */
#define TOFF_DCMI_CWSIZER   0x0024		/* (RW) DCMI crop window size */
#define TOFF_DCMI_DR        0x0028		/* (RW) DCMI data register */

/*
 *  CRYPTO PROCESSER
 */
#define TADR_CRYP_BASE      (AHB2PERIPH_BASE + 0x60000)
#define TOFF_CRYP_CR        0x0000		/* (RW) CRYP control register */
#define TOFF_CRYP_SR        0x0004		/* (R)  CRYP status register */
#define TOFF_CRYP_DR        0x0008		/* (RW) CRYP data input register */
#define TOFF_CRYP_DOUT      0x000C		/* (RW) CRYP data output register */
#define TOFF_CRYP_DMACR     0x0010		/* (RW) CRYP DMA control register */
#define TOFF_CRYP_IMSCR     0x0014		/* (RW) CRYP interrupt mask set/clear register */
#define TOFF_CRYP_RISR      0x0018		/* (RW) CRYP raw interrupt status register */
#define TOFF_CRYP_MISR      0x001C		/* (RW) CRYP masked interrupt status register */
#define TOFF_CRYP_K0LR      0x0020		/* (RW) CRYP key left  register 0 */
#define TOFF_CRYP_K0RR      0x0024		/* (RW) CRYP key right register 0 */
#define TOFF_CRYP_K1LR      0x0028		/* (RW) CRYP key left  register 1 */
#define TOFF_CRYP_K1RR      0x002C		/* (RW) CRYP key right register 1 */
#define TOFF_CRYP_K2LR      0x0030		/* (RW) CRYP key left  register 2 */
#define TOFF_CRYP_K2RR      0x0034		/* (RW) CRYP key right register 2 */
#define TOFF_CRYP_K3LR      0x0038		/* (RW) CRYP key left  register 3 */
#define TOFF_CRYP_K3RR      0x003C		/* (RW) CRYP key right register 3 */
#define TOFF_CRYP_IV0LR     0x0040		/* (RW) CRYP initialization vector left-word  register 0 */
#define TOFF_CRYP_IV0RR     0x0044		/* (RW) CRYP initialization vector right-word register 0 */
#define TOFF_CRYP_IV1LR     0x0048		/* (RW) CRYP initialization vector left-word  register 1 */
#define TOFF_CRYP_IV1RR     0x004C		/* (RW) CRYP initialization vector right-word register 1 */

/*
 *  HASH
 */
#define TADR_HASH_BASE      (AHB2PERIPH_BASE + 0x60400)
#define TOFF_HASH_CR        0x0000		/* (RW) HASH control register */
#define TOFF_HASH_DIN       0x0004		/* (RW) HASH data input register */
#define TOFF_HASH_STR       0x0008		/* (RW) HASH start register */
#define TOFF_HASH_HR0       0x000C		/* (RW) HASH digest registers 0 */
#define TOFF_HASH_HR1       0x0010		/* (RW) HASH digest registers 1 */
#define TOFF_HASH_HR2       0x0014		/* (RW) HASH digest registers 2 */
#define TOFF_HASH_HR3       0x0018		/* (RW) HASH digest registers 3 */
#define TOFF_HASH_HR4       0x001C		/* (RW) HASH digest registers 4 */
#define TOFF_HASH_IMR       0x0020		/* (RW) HASH interrupt enable register */
#define TOFF_HASH_SR        0x0024		/* (R)  HASH status register */
#define TOFF_HASH_CSR0      0x00F8		/* (RW) HASH context swap registers 0 */
#define TOFF_HASH_CSR1      0x00FC		/* (RW) HASH context swap registers 1 */
#define TOFF_HASH_CSR2      0x0100		/* (RW) HASH context swap registers 2 */
#define TOFF_HASH_CSR3      0x0104		/* (RW) HASH context swap registers 3 */
#define TOFF_HASH_CSR4      0x0108		/* (RW) HASH context swap registers 4 */
#define TOFF_HASH_CSR5      0x010C		/* (RW) HASH context swap registers 5 */
#define TOFF_HASH_CSR6      0x0110		/* (RW) HASH context swap registers 6 */
#define TOFF_HASH_CSR7      0x0114		/* (RW) HASH context swap registers 7 */
#define TOFF_HASH_CSR8      0x0118		/* (RW) HASH context swap registers 8 */
#define TOFF_HASH_CSR9      0x011C		/* (RW) HASH context swap registers 9 */
#define TOFF_HASH_CSR10     0x0120		/* (RW) HASH context swap registers 10 */
#define TOFF_HASH_CSR11     0x0124		/* (RW) HASH context swap registers 11 */
#define TOFF_HASH_CSR12     0x0128		/* (RW) HASH context swap registers 12 */
#define TOFF_HASH_CSR13     0x012C		/* (RW) HASH context swap registers 13 */
#define TOFF_HASH_CSR14     0x0130		/* (RW) HASH context swap registers 14 */
#define TOFF_HASH_CSR15     0x0134		/* (RW) HASH context swap registers 15 */
#define TOFF_HASH_CSR16     0x0138		/* (RW) HASH context swap registers 16 */
#define TOFF_HASH_CSR17     0x013C		/* (RW) HASH context swap registers 17 */
#define TOFF_HASH_CSR18     0x0140		/* (RW) HASH context swap registers 18 */
#define TOFF_HASH_CSR19     0x0144		/* (RW) HASH context swap registers 19 */
#define TOFF_HASH_CSR20     0x0148		/* (RW) HASH context swap registers 20 */
#define TOFF_HASH_CSR21     0x014C		/* (RW) HASH context swap registers 21 */
#define TOFF_HASH_CSR22     0x0150		/* (RW) HASH context swap registers 22 */
#define TOFF_HASH_CSR23     0x0154		/* (RW) HASH context swap registers 23 */
#define TOFF_HASH_CSR24     0x0158		/* (RW) HASH context swap registers 24 */
#define TOFF_HASH_CSR25     0x015C		/* (RW) HASH context swap registers 25 */
#define TOFF_HASH_CSR26     0x0160		/* (RW) HASH context swap registers 26 */
#define TOFF_HASH_CSR27     0x0164		/* (RW) HASH context swap registers 27 */
#define TOFF_HASH_CSR28     0x0168		/* (RW) HASH context swap registers 28 */
#define TOFF_HASH_CSR29     0x016C		/* (RW) HASH context swap registers 29 */
#define TOFF_HASH_CSR30     0x0170		/* (RW) HASH context swap registers 30 */
#define TOFF_HASH_CSR31     0x0174		/* (RW) HASH context swap registers 31 */
#define TOFF_HASH_CSR32     0x0178		/* (RW) HASH context swap registers 32 */
#define TOFF_HASH_CSR33     0x017C		/* (RW) HASH context swap registers 33 */
#define TOFF_HASH_CSR34     0x0180		/* (RW) HASH context swap registers 34 */
#define TOFF_HASH_CSR35     0x0184		/* (RW) HASH context swap registers 35 */
#define TOFF_HASH_CSR36     0x0188		/* (RW) HASH context swap registers 36 */
#define TOFF_HASH_CSR37     0x018C		/* (RW) HASH context swap registers 37 */
#define TOFF_HASH_CSR38     0x0190		/* (RW) HASH context swap registers 38 */
#define TOFF_HASH_CSR39     0x0194		/* (RW) HASH context swap registers 39 */
#define TOFF_HASH_CSR40     0x0198		/* (RW) HASH context swap registers 40 */
#define TOFF_HASH_CSR41     0x019C		/* (RW) HASH context swap registers 41 */
#define TOFF_HASH_CSR42     0x01A0		/* (RW) HASH context swap registers 42 */
#define TOFF_HASH_CSR43     0x01A4		/* (RW) HASH context swap registers 43 */
#define TOFF_HASH_CSR44     0x01A8		/* (RW) HASH context swap registers 44 */
#define TOFF_HASH_CSR45     0x01AC		/* (RW) HASH context swap registers 45 */
#define TOFF_HASH_CSR46     0x01B0		/* (RW) HASH context swap registers 46 */
#define TOFF_HASH_CSR47     0x01B4		/* (RW) HASH context swap registers 47 */
#define TOFF_HASH_CSR48     0x01B8		/* (RW) HASH context swap registers 48 */
#define TOFF_HASH_CSR49     0x01BC		/* (RW) HASH context swap registers 49 */
#define TOFF_HASH_CSR50     0x01C0		/* (RW) HASH context swap registers 50 */

/*
 *  RNG
 */
#define TADR_RNG_BASE       (AHB2PERIPH_BASE + 0x60800)
#define TOFF_RNG_CR         0x0000		/* (RW) RNG control register */
#define TOFF_RNG_SR         0x0004		/* (RW) RNG status register */
#define TOFF_RNG_DR         0x0008		/* (RW) RNG data register */

/*
 *  FLEXIBLE STATIC MEMORY
 */
#define TADR_FSMC_R_BASE    (FSMC_R_BASE + 0x0000)

/*
 *  FLEXIBLE STATIC MEMORY CONTROLLER
 */
#define TOFF_FSMC_R_BTCR0   0x0000		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 0 */
#define TOFF_FSMC_R_BTCR1   0x0004		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 1 */
#define TOFF_FSMC_R_BTCR2   0x0008		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 2 */
#define TOFF_FSMC_R_BTCR3   0x000C		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 3 */
#define TOFF_FSMC_R_BTCR4   0x0010		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 4 */
#define TOFF_FSMC_R_BTCR5   0x0014		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 5 */
#define TOFF_FSMC_R_BTCR6   0x0018		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 6 */
#define TOFF_FSMC_R_BTCR7   0x001C		/* (RW) NOR/PSRAM chip-select control register(BCR) and chip-select timing register(BTR) 7 */

/*
 *  FLEXIBLE STATIC MEMORY CONTROLLER BANK1E
 */
#define TOFF_FSMC_R_BWTR0   0x0104		/* (RW) NOR/PSRAM write timing registers 0 */
#define TOFF_FSMC_R_BWTR1   0x0108		/* (RW) NOR/PSRAM write timing registers 1 */
#define TOFF_FSMC_R_BWTR2   0x010C		/* (RW) NOR/PSRAM write timing registers 2 */
#define TOFF_FSMC_R_BWTR3   0x0110		/* (RW) NOR/PSRAM write timing registers 3 */
#define TOFF_FSMC_R_BWTR4   0x0114		/* (RW) NOR/PSRAM write timing registers 4 */
#define TOFF_FSMC_R_BWTR5   0x0118		/* (RW) NOR/PSRAM write timing registers 5 */
#define TOFF_FSMC_R_BWTR6   0x011C		/* (RW) NOR/PSRAM write timing registers 6 */

/*
 *  FLEXIBLE STATIC MEMORY CONTROLLER BANK2
 */
#define TOFF_FSMC_R_PCR2    0x0060		/* (RW) NAND Flash control register 2 */
#define TOFF_FSMC_R_SR2     0x0064		/* (RW) NAND Flash FIFO status and interrupt register 2 */
#define TOFF_FSMC_R_PMEM2   0x0068		/* (RW) NAND Flash Common memory space timing register 2 */
#define TOFF_FSMC_R_PATT2   0x006C		/* (RW) NAND Flash Attribute memory space timing register 2 */
#define TOFF_FSMC_R_ECCR2   0x0074		/* (RW) NAND Flash ECC result registers 2 */

/*
 *  FLEXIBLE STATIC MEMORY CONTROLLER BANK3
 */
#define TOFF_FSMC_R_PCR3    0x0080		/* (RW) NAND Flash control register 3 */
#define TOFF_FSMC_R_SR3     0x0084		/* (RW) NAND Flash FIFO status and interrupt register 3 */
#define TOFF_FSMC_R_PMEM3   0x0088		/* (RW) NAND Flash Common memory space timing register 3 */
#define TOFF_FSMC_R_PATT3   0x008C		/* (RW) NAND Flash Attribute memory space timing register 3 */
#define TOFF_FSMC_R_ECCR3   0x0094		/* (RW) NAND Flash ECC result registers 3 */

/*
 *  FLEXIBLE STATIC MEMORY CONTROLLER BANK4
 */
#define TOFF_FSMC_R_PCR4    0x00A0		/* (RW) PC Card  control register 4 */
#define TOFF_FSMC_R_SR4     0x00A4		/* (RW) PC Card  FIFO status and interrupt register 4 */
#define TOFF_FSMC_R_PMEM4   0x00A8		/* (RW) PC Card  Common memory space timing register 4 */
#define TOFF_FSMC_R_PATT4   0x00AC		/* (RW) PC Card  Attribute memory space timing register 4 */
#define TOFF_FSMC_R_PIO4    0x00B0		/* (RW) PC Card  I/O space timing register 4 */

/*
 *  DEBUG MCU
 */
#define TADR_DBGMCU_BASE    0xE0042000
#define TOFF_DBGMCU_IDCODE  0x0000		/* (RW) MCU device ID code */
#define TOFF_DBGMCU_CR      0x0004		/* (RW) Debug MCU configuration register */
#define TOFF_DBGMCU_APB1FZ  0x0008		/* (RW) Debug MCU APB1 freeze register */
#define TOFF_DBGMCU_APB2FZ  0x000C		/* (RW) Debug MCU APB2 freeze register */


#endif  /* _STM32F4XX_H_ */

