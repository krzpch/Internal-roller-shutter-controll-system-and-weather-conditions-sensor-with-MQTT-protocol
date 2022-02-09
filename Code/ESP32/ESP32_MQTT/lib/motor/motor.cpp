#include "motor.h"

// A motor
void A_motor_init(void) {
  pinMode(MOTORA_PIN1, OUTPUT);
	pinMode(MOTORA_PNI2, OUTPUT);
	ledcAttachPin(MOTORA_PWM, 0);
	ledcSetup(0, 500, 8);
}


void A_turn_clockwise(uint8_t speed) {
  ledcWrite(0, speed);
  digitalWrite(MOTORA_PIN1,LOW);
  digitalWrite(MOTORA_PNI2,HIGH);
}

void A_turn_counterclockwise(uint8_t speed) {
  ledcWrite(0, speed);
  digitalWrite(MOTORA_PIN1,HIGH);
  digitalWrite(MOTORA_PNI2,LOW);
}

void A_soft_stop(void) {
  ledcWrite(0, 0);
  digitalWrite(MOTORA_PIN1,LOW);
  digitalWrite(MOTORA_PNI2,LOW);
}

void A_fast_stop(void) {
  ledcWrite(0, 255);
  digitalWrite(MOTORA_PIN1,LOW);
  digitalWrite(MOTORA_PNI2,LOW);
}

void A_fast_stop_2(void) {
  ledcWrite(0, 255);
  digitalWrite(MOTORA_PIN1,HIGH);
  digitalWrite(MOTORA_PNI2,HIGH);
}

// B motor
void B_turn_clockwise(uint8_t speed) {
  ledcWrite(0, speed);
  digitalWrite(MOTORB_PIN1,LOW);
  digitalWrite(MOTORB_PNI2,HIGH);
}

void B_turn_counterclockwise(uint8_t speed) {
  ledcWrite(0, speed);
  digitalWrite(MOTORB_PIN1,HIGH);
  digitalWrite(MOTORB_PNI2,LOW);
}

void B_soft_stop(void) {
  ledcWrite(0, 0);
  digitalWrite(MOTORB_PIN1,LOW);
  digitalWrite(MOTORB_PNI2,LOW);
}

void B_fast_stop(void) {
  ledcWrite(0, 255);
  digitalWrite(MOTORB_PIN1,LOW);
  digitalWrite(MOTORB_PNI2,LOW);
}

void B_fast_stop_2(void) {
  ledcWrite(0, 255);
  digitalWrite(MOTORB_PIN1,HIGH);
  digitalWrite(MOTORB_PNI2,HIGH);
}