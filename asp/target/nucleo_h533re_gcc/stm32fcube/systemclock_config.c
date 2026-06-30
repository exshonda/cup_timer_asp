/*
 *  System Clock Configuration (NUCLEO-H533RE)
 *
 *  SYSCLK = 250MHz。HSE(24MHz・ST-LINK MCO)→PLL1(M=12,N=250,P=2)で 250MHz。
 *  VOS0・FLASH 5WS。ベアメタル版 cup_timer_bm/H533RE の実機検証済み設定を
 *  HAL 形式に移植したもの（bm は LL で同一パラメータ）。
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32h5xx_hal.h"
#include "stm32h5xx_nucleo.h"

extern void Error_Handler(void);

/**
  * @brief  System Clock Configuration
  *         SYSCLK = HCLK = PCLK1/2/3 = 250MHz (HSE 24MHz / PLL1)
  * @retval None
  */
void
SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/* 内部レギュレータ出力電圧の設定（250MHz には VOS0 が必須） */
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);
	while (!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

	/* 発振器(HSE)＋PLL1: HSE=24MHz, /M12=2MHz, *N250=500MHz, /P2=250MHz */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
	RCC_OscInitStruct.HSEState = RCC_HSE_ON;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
	RCC_OscInitStruct.PLL.PLLSource = RCC_PLL1_SOURCE_HSE;
	RCC_OscInitStruct.PLL.PLLM = 12;
	RCC_OscInitStruct.PLL.PLLN = 250;
	RCC_OscInitStruct.PLL.PLLP = 2;
	RCC_OscInitStruct.PLL.PLLQ = 2;
	RCC_OscInitStruct.PLL.PLLR = 2;
	RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1_VCIRANGE_1;     /* VCO入力 2-4MHz */
	RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1_VCORANGE_WIDE;
	RCC_OscInitStruct.PLL.PLLFRACN = 0;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/* CPU/AHB/APB バスクロックの設定（全て /1 = 250MHz） */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
								 | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2
								 | RCC_CLOCKTYPE_PCLK3;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK) {
		Error_Handler();
	}
}
