#pragma once

typedef struct {
	uint8_t trig;
	uint8_t echo;
} Sensor;

Sensor* getSensor(uint8_t trig, uint8_t echo);

float getDistance(const Sensor* sensor);

bool getDistance(const Sensor* sensor, float threshold, bool inclusive = false);