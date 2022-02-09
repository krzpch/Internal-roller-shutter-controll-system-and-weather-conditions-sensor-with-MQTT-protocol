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
#include "dma.h"
#include "i2c.h"
#include "usart.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "string.h"
#include "bme280.h"
#include "bh1750.h"

#include "stdio.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */
typedef enum {
	bt_disconnected = 0,
	bt_connected = 1
} bt_state_t;
/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */
bme280_t bme;
bh1750_t bh;

// BT module variables
size_t len;
char rx_buff[50];
char tx_buff[100];
uint8_t dma_state = 0;
bt_state_t bt_state = bt_disconnected;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */
void TimeCallback(void);
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
  MX_DMA_Init();
  MX_LPUART1_UART_Init();
  /* USER CODE BEGIN 2 */
  HAL_Delay(1000);

  HAL_GPIO_WritePin(BT_WAKEUP_GPIO_Port, BT_WAKEUP_Pin, GPIO_PIN_RESET);
  HAL_Delay(10);
  HAL_UART_Transmit(&hlpuart1, (uint8_t*) "TTM: NAM-?\n\r\0", 13, 100);
  HAL_GPIO_WritePin(BT_WAKEUP_GPIO_Port, BT_WAKEUP_Pin, GPIO_PIN_SET);


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
  HAL_Delay(1000);
  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
  BME280_ReadAll(&bme);
  bh1750_ReadMeasurement(&bh);
  HAL_Delay(1000);
  HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
/*
  HAL_PWR_EnableSleepOnExit();
  HAL_RTCEx_SetWakeUpTimer_IT(&hrtc, 9, RTC_WAKEUPCLOCK_CK_SPRE_16BITS);
*/


  //HAL_UART_Transmit(&hlpuart1, (uint8_t*) "TTM: MAC-? \r\n\0", strlen("TTM: MAC-? \r\n\0"), 100);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	SystemClock_Config();
	HAL_ResumeTick();
	  if (bt_state == bt_connected) {
		  // read data form all sensors
		  BME280_ReadAll(&bme);
		  bh1750_ReadMeasurement(&bh);
		  // turn it into string
		  len = sprintf((char*) tx_buff, "T:%.2f H:%.2f P:%.2f L:%.2f\n\r", bme.temp,bme.hum, bme.press, bh.lx);
		  // send it to Bluetooth module
		  HAL_GPIO_WritePin(BT_WAKEUP_GPIO_Port, BT_WAKEUP_Pin, GPIO_PIN_RESET);
		  HAL_Delay(2);
		  HAL_UART_Transmit(&hlpuart1, (uint8_t*) tx_buff, len, 100);
		  HAL_GPIO_WritePin(BT_WAKEUP_GPIO_Port, BT_WAKEUP_Pin, GPIO_PIN_SET);

		  HAL_Delay(5000);
	  }

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
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_LSE|RCC_OSCILLATORTYPE_MSI;
  RCC_OscInitStruct.LSEState = RCC_LSE_ON;
  RCC_OscInitStruct.MSIState = RCC_MSI_ON;
  RCC_OscInitStruct.MSICalibrationValue = 0;
  RCC_OscInitStruct.MSIClockRange = RCC_MSIRANGE_6;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_MSI;
  RCC_OscInitStruct.PLL.PLLM = 1;
  RCC_OscInitStruct.PLL.PLLN = 24;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV7;
  RCC_OscInitStruct.PLL.PLLQ = RCC_PLLQ_DIV2;
  RCC_OscInitStruct.PLL.PLLR = RCC_PLLR_DIV2;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_1) != HAL_OK)
  {
    Error_Handler();
  }
  /** Enable MSI Auto calibration
  */
  HAL_RCCEx_EnableMSIPLLMode();
}

/* USER CODE BEGIN 4 */
/*
 * Receive data from bt module
 */
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin) {
	SystemClock_Config();
	HAL_ResumeTick();

	//HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
	//BME280_ReadAll(&bme);
	//bh1750_ReadMeasurement(&bh);
	//HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);


	if (GPIO_Pin == BT_INT_Pin) {
		if (dma_state == 0) {
			if (HAL_UARTEx_ReceiveToIdle_DMA(&hlpuart1, (uint8_t*) rx_buff, 50) == HAL_OK) {
				dma_state = 1;
			}
		} else if (dma_state == 1) {
			//HAL_UART_DMAStop(&hlpuart1);
			dma_state = 0;
			 if (strncmp((char*) rx_buff, (char *)"TTM:CONNECT\r\n", 13) == 0) {
				 HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_SET);
				 bt_state = bt_connected;
			 } else if (strncmp((char*) rx_buff, (char *)"TTM:DISCONNECT\r\n", 16) == 0) {
				 HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
				 bt_state = bt_disconnected;
			 }
			 else if (strncmp((char*) rx_buff, (char *)"TTM:DISCONNECT FOR TIMEOUT\r\n", 28) == 0) {
			 	HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, GPIO_PIN_RESET);
			 	bt_state = bt_disconnected;
			 }
			 memset((void*)rx_buff,'\0',50);
		}
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
  while (1)
  {
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
