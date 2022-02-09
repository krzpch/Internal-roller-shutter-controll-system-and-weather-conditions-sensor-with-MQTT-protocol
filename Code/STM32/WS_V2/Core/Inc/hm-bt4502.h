/*
 * HM-BT4502.h
 *
 *  Created on: 2 gru 2021
 *      Author: Krzysztof Półchłopek
 */

#ifndef INC_HM_BT4502_H_
#define INC_HM_BT4502_H_

#include "main.h"

void btInit(void);
void btSend(uint8_t *data, size_t len);
void btSleep(void);
void btWakeup(void);
void btStateSwitch(void);
GPIO_PinState btGetState(void);

#endif /* INC_HM_BT4502_H_ */
