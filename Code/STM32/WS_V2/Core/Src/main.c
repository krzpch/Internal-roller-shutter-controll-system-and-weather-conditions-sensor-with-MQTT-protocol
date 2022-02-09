/* USER CODE BEGIN Header */
/**
 ******************************************************************************
 * @file           : main.c
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2021 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "i2c.h"
#include "usart.h"
#include "rtc.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <string.h>
#include <stdio.h>
#include "bh1750.h"
#include "bme280.h"
#include "hm-bt4502.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define BLE_RxTableLen 20
#define BLE_TxTableLen 50
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
// RTC variables
uint8_t RTC_interrupt = 0;

// BLE variables
uint8_t BLE_interrupt = 0;
uint16_t BLE_RxLen;
uint8_t BLE_RxTable[BLE_RxTableLen];
uint16_t BLE_TxLen;
uint8_t BLE_TxTable[BLE_TxTableLen];
uint8_t BLE_connected = 0;

// sensor variables
bme280_t bme;
bh1750_t bh;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void LED_Blink(uint8_t blinsk,uint16_t interval);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_I2C1_Init();
  MX_LPUART1_UART_Init();
  MX_RTC_Init();
  /* USER CODE BEGIN 2 */

	bme.i2c = &hi2c1;

	bme.filter = BME280_FILTER_OFF;
	bme.temp_oversampling = BME280_TEMPERATURE_OVER_1;
	bme.press_oversampling = BME280_PRESSURE_OVER_1;
	bme.hum_oversampling = BME280_HUMIDITY_OVER_1;
	bme.work_mode = BME280_NORMAL_MODE;
	bme.standby_time = BME280_STANDBY_20;

	bh.i2c = &hi2c1;
	bh.work_mode = BH1750_ONE_H_RES2_MODE;

	BME280_Init(&bme);
	bh1750_init(&bh);

	btInit();	// initialize ble pins and reset module
	memset((void*) BLE_RxTable, '\0', sizeof(BLE_RxTable));

	LED_Blink(1, 400);

	BME280_ReadAll(&bme);
	bh1750_ReadMeasurement(&bh);

	LED_Blink(1, 400);

	HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 10, RTC_WAKEUPCLOCK_CK_SPRE_16BITS);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	while (1) {


		if (BLE_interrupt == 1) {
			BLE_interrupt = 0;
			if (strcmp((char*) BLE_RxTable, (char*) "TTM:CONNECT\r\n") == 0) {
				BLE_connected = 1;
				LED_Blink(3, 200);
				if (BLE_connected == 1) {
					BME280_ReadAll(&bme);
					bh1750_ReadMeasurement(&bh);

					memcpy((uint8_t*)BLE_TxTable, &bme.temp, 4);
					memcpy((uint8_t*)BLE_TxTable + 4, &bme.hum, 4);
					memcpy((uint8_t*)BLE_TxTable + 8, &bme.press, 4);
					memcpy((uint8_t*)BLE_TxTable + 12, &bh.lx, 4);

					//BLE_TxLen = sprintf((char*) BLE_TxTable, "T:%.2f H:%.2f P:%.2f L:%.2f\n", bme.temp, bme.hum, bme.press, bh.lx);
					HAL_Delay(1000);
					// send and go to sleep

					btSend((uint8_t*) BLE_TxTable, 16);
					memset((void*) BLE_TxTable, 0, sizeof(BLE_TxTable));
					HAL_Delay(1000);
					btSleep();

					BLE_connected = 0;
				}

				HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 60, RTC_WAKEUPCLOCK_CK_SPRE_16BITS);

			} else if (strcmp((char*) BLE_RxTable, (char*) "TTM:DISCONNECT\r\n") == 0) {
				BLE_connected = 0;
				LED_Blink(2, 200);
			} else if (strcmp((char*) BLE_RxTable, (char*) "TTM:DISCONNECT FOR TIMEOUT\r\n") == 0) {
				LED_Blink(1, 500);
				NVIC_SystemReset();

			}
			memset((void*) BLE_RxTable, 0, sizeof(BLE_RxTable));
		}

		if (RTC_interrupt == 1) {
			RTC_interrupt = 0;

			if (btGetState() == GPIO_PIN_SET) {
				// if BT module is in sleep wake it up and set timer for 10 seconds
				btWakeup();
				HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 10, RTC_WAKEUPCLOCK_CK_SPRE_16BITS);

			} else {
				//else wait for 1 min for next connection cycle
				BLE_connected = 0;
				btSleep();
				HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 60, RTC_WAKEUPCLOCK_CK_SPRE_16BITS);
			}

		}
		//HAL_GPIO_TogglePin(LD3_GPIO_Port, LD3_Pin);
    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */

		HAL_SuspendTick();
		HAL_PWREx_EnterSTOP2Mode(PWR_STOPENTRY_WFI);
	}
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  if (HAL_PWREx_ControlVoltageScaling(PWR_REGULATOR_VOLTAGE_SCALE1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Configure LSE Drive Capability
  */
  HAL_PWR_EnableBkUpAccess();
  __HAL_RCC_LSEDRIVE_CONFIG(RCC_LSEDRIVE_LOW);
  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI|RCC_OSCILLATORTYPE_LSI
                              |RCC_OSCILLATORTYPE_LSE;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.LSIState = RCC_LSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
void HAL_RTCEx_WakeUpTimerEventCallback(RTC_HandleTypeDef *hrtc) {
	SystemClock_Config();
	HAL_ResumeTick();
	HAL_RTCEx_DeactivateWakeUpTimer(hrtc);
	RTC_interrupt = 1;
}

void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	SystemClock_Config();
	HAL_ResumeTick();
	if (GPIO_Pin == BT_INT_Pin) {
		HAL_UARTEx_ReceiveToIdle(&hlpuart1, (uint8_t*) BLE_RxTable,
				BLE_RxTableLen, &BLE_RxLen, 30);
		if (BLE_RxLen > 0) { // set flag only if received something
			BLE_interrupt = 1;
		}
	}
}

void LED_Blink(uint8_t blinsk,uint16_t interval) {
	for (uint8_t i = 0; i < blinsk; i++) {
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
		HAL_Delay(interval>>1);
		HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
		HAL_Delay(interval>>1);
	}

}

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
	/* User can add his own implementation to report the HAL error return state */
	__disable_irq();
	while (1) {
	}
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
