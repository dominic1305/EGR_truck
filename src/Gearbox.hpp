#pragma once

enum class State : uint8_t { STOP, REVERSE, FORWARD };

typedef struct {
	bool posState;
	bool negState;
	uint8_t posPin;
	uint8_t negPin;
} Gearbox;

void stop(Gearbox& gearbox);

void forward(Gearbox& gearbox);

void reverse(Gearbox& gearbox);

State getState(const Gearbox& gearbox);