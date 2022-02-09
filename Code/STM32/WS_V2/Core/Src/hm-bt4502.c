/*
 * HM-BT4502.c
 *
 *  Created on: 2 gru 2021
 *      Author: Krzysztof Półchłopek
 */

#include <hm-bt4502.h>

extern UART_HandleTypeDef hlpuart1;


void btInit(void) {
	HAL_GPIO_WritePin(BT_WAKEUP_GPIO_Port, BT_WAKEUP_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(BT_PDN_GPIO_Port, BT_PDN_Pin, GPIO_PIN_RESET);
	HAL_Delay(20);
	// reset BLE module
	btSend((uint8_t*) "TTM:RST-SYSTEMRESET\r\n\0",
			sizeof("TTM:RST-SYSTEMRESET\r\n"));
	HAL_Delay(20);
}
void btSend(uint8_t *data, size_t len) {
	HAL_GPIO_WritePin(BT_WAKEUP_GPIO_Port, BT_WAKEUP_Pin, GPIO_PIN_RESET);
	HAL_Delay(2);
	HAL_UART_Transmit(&hlpuart1, data, len, 100);
	HAL_GPIO_WritePin(BT_WAKEUP_GPIO_Port, BT_WAKEUP_Pin, GPIO_PIN_SET);
}
void btSleep(void) {
	HAL_GPIO_WritePin(BT_PDN_GPIO_Port, BT_PDN_Pin, GPIO_PIN_SET);
}
void btWakeup(void) {
	HAL_GPIO_WritePin(BT_PDN_GPIO_Port, BT_PDN_Pin, GPIO_PIN_RESET);
}

void btStateSwitch(void) {
	HAL_GPIO_TogglePin(BT_PDN_GPIO_Port, BT_PDN_Pin);
}

GPIO_PinState btGetState(void) {
	return HAL_GPIO_ReadPin(BT_PDN_GPIO_Port, BT_PDN_Pin);
}
