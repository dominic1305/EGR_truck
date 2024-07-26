#include <Arduino.h>
#include "Eyes.hpp"

Sensor* getSensor(uint8_t trig, uint8_t echo) {
	Sensor* tmp = (Sensor*)malloc(sizeof(Sensor));
	tmp->trig = trig;
	tmp->echo = echo;

	pinMode(tmp->trig, OUTPUT);
	pinMode(tmp->echo, INPUT);

	return tmp;
}

float getDistance(const Sensor *sensor) {
	digitalWrite(sensor->trig, LOW);
	delayMicroseconds(2);
	digitalWrite(sensor->trig, HIGH);
	delayMicroseconds(10);
	digitalWrite(sensor->trig, LOW);

	auto duration = pulseIn(sensor->echo, HIGH);
	if (duration == 0) return getDistance(sensor); //misread, read again

	return duration * 0.034f / 2.0f;
}

bool getDistance(const Sensor *sensor, float threshold, bool inclusive = false) {
	return (inclusive) ?getDistance(sensor) <= threshold : getDistance(sensor) < threshold;
}