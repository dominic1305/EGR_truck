#include <Arduino.h>
#include "Gearbox.hpp"

void forward(Gearbox* gearbox) {
	if (getState(gearbox) == State::FORWARD) return; // already moving forward, don't set pins

	digitalWrite(gearbox->posPin, HIGH);
	digitalWrite(gearbox->negPin, LOW);
	gearbox->posState = true; // set to NC
	gearbox->negState = false; // set to NO
}

void reverse(Gearbox* gearbox) {
	if (getState(gearbox) == State::REVERSE) return; // already reversing, don't set pins

	digitalWrite(gearbox->posPin, LOW);
	digitalWrite(gearbox->negPin, HIGH);
	gearbox->posState = false; // set to NO
	gearbox->negState = true; // set to NC
}

void stop(Gearbox* gearbox) {
	if (getState(gearbox) == State::STOP) return; // already stopped, don't set pins

	digitalWrite(gearbox->posPin, LOW);
	digitalWrite(gearbox->negPin, LOW);
	gearbox->posState = true; // set to NC
	gearbox->negState = true; // set to NC
}

State getState(const Gearbox* gearbox) {
	uint8_t sum = (uint8_t)gearbox->posState + (uint8_t)gearbox->negState;

	switch (sum) {
		case 0: // both relays are on normally closed
			return State::STOP;
		case 1: // posPin & !negPin = forward, !posPin & negPin = reverse
			return (gearbox->posState) ? State::FORWARD : State::REVERSE;
		case 2: // both relays are on normally open
			return State::STOP;
	}
}

Gearbox* getGearbox(bool posState, bool negState, uint8_t posPin, uint8_t negPin) {
    Gearbox* tmp = (Gearbox*)malloc(sizeof(Gearbox));
	tmp->posState = posState;
	tmp->negState = negState;
	tmp->posPin = posPin;
	tmp->negPin = negPin;

	pinMode(tmp->posPin, OUTPUT);
	pinMode(tmp->negPin, OUTPUT);

	return tmp;
}