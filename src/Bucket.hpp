#pragma once
#include <servo/Servo.h>

typedef struct _Servo {
	Servo servo;
	uint8_t currentPos;
};

_Servo* getServo(uint8_t pinNumber);

void writeServo(_Servo* servo, uint8_t newPos);

void writeServo(_Servo* servo, uint8_t newPos, unsigned long delay);