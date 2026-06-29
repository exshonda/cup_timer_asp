/*
 *  System Clock Configuration (NUCLEO-H533RE)
 *
 *  asp3_stm32cube の検証済み設定を踏襲。
 *  HSI(64MHz)/2 = 32MHz を SYSCLK とする（PLL不使用・VOS3・FLASH_LATENCY_1）。
 *  Step2a(カーネル起動検証)の最小・最堅実構成。高速化は起動確認後に実施。
 */

/* Includes ------------------------------------------------------------------*/
#include "stm32h5xx_hal.h"
#include "stm32h5xx_nucleo.h"

extern void Error_Handler(void);

/**
  * @brief  System Clock Configuration
  *         SYSCLK = HCLK = 32MHz (HSI/2), PCLK1/2/3 = 32MHz
  * @retval None
  */
void
SystemClock_Config(void)
{
	RCC_OscInitTypeDef RCC_OscInitStruct = {0};
	RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

	/* 内部レギュレータ出力電圧の設定 */
	__HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE3);
	while (!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

	/* 発振器(HSI)の設定 */
	RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
	RCC_OscInitStruct.HSIState = RCC_HSI_ON;
	RCC_OscInitStruct.HSIDiv = RCC_HSI_DIV2;
	RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
	RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
	if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK) {
		Error_Handler();
	}

	/* CPU/AHB/APB バスクロックの設定 */
	RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK | RCC_CLOCKTYPE_SYSCLK
								 | RCC_CLOCKTYPE_PCLK1 | RCC_CLOCKTYPE_PCLK2
								 | RCC_CLOCKTYPE_PCLK3;
	RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
	RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
	RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;
	RCC_ClkInitStruct.APB3CLKDivider = RCC_HCLK_DIV1;
	if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK) {
		Error_Handler();
	}

	/* プログラミングディレイの設定 */
	__HAL_FLASH_SET_PROGRAM_DELAY(FLASH_PROGRAMMING_DELAY_0);
}
