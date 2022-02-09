#ifndef _MOTOR_H_
#define  _MOTOR_H_

#include <Arduino.h>
#include <ESP32Encoder.h>

#define MOTORA_PWM    23
#define MOTORA_PIN1   19
#define MOTORA_PNI2   21

#define MOTORB_PWM    23
#define MOTORB_PIN1   19
#define MOTORB_PNI2   21

void A_motor_init(void);

void A_turn_clockwise(uint8_t speed);
void A_turn_counterclockwise(uint8_t speed);
void A_soft_stop(void);
void A_fast_stop(void);
void A_fast_stop_2(void);

void B_turn_clockwise(uint8_t speed);
void B_turn_counterclockwise(uint8_t speed);
void B_soft_stop(void);
void B_fast_stop(void);
void B_fast_stop_2(void);

#endif