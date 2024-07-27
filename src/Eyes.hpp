#pragma once

typedef struct Sensor {
	uint8_t trig;
	uint8_t echo;
	float* storage;
};

Sensor* getSensor(uint8_t trig, uint8_t echo);

float getDistance(const Sensor* sensor);

bool withinThreshold(const Sensor* sensor, float threshold, bool inclusive = false);