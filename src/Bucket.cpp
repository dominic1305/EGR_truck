#include <Arduino.h>
#include <servo/Servo.h>
#include "Bucket.hpp"

_Servo* getServo(uint8_t pinNumber) {
	_Servo* tmp = (_Servo*)malloc(sizeof(_Servo));
	tmp->servo.attach(pinNumber);

	pinMode(pinNumber, OUTPUT);

	tmp->currentPos = 0;
	writeServo(tmp, 0);
}

void writeServo(_Servo* servo, uint8_t newPos) {
	servo->servo.write(newPos);
	servo->currentPos = newPos;
}

void writeServo(_Servo* servo, uint8_t newPos, unsigned long delayms) {
	if (servo->currentPos == newPos) return; // already at position

	const bool direction = newPos - servo->currentPos > 0; // true = bigger, false = smaller

	while (servo->currentPos != newPos) {// loop until at new position
		(direction) ? servo->currentPos++ : servo->currentPos--;
		servo->servo.write(servo->currentPos);
		delay(delayms);
	}
}