#ifndef LEDS_H_
#define LEDS_H_
#include "peripherals.h"

// ledON sets the (i + 8)-th bit of the output data register HIGH (value: 1) (3,3 Volts)
void ledON(uint32_t volatile *led, uint8_t i)
{
	*led |= (1 << (i + 8));
}

// ledOFF clears the i-th bit of the output data register to LOW (value: 0) (0 Volts)
void ledOFF(uint32_t volatile *led, uint8_t i)
{
	*led &= ~(1 << i);
}

// delay simulates a human-eye-visible delay
void delay(uint32_t volatile seconds)
{
	seconds *= DELAY;
	for(uint32_t i = 0; i < seconds; i++);
}

void clearPins(GPIOx_ODR_t volatile *led)
{
	led->ODR8  = STATE_LOW;
	led->ODR9  = STATE_LOW;
	led->ODR10 = STATE_LOW;
	led->ODR11 = STATE_LOW;
	led->ODR12 = STATE_LOW;
	led->ODR13 = STATE_LOW;
	led->ODR14 = STATE_LOW;
	led->ODR15 = STATE_LOW;
}

#endif /* LEDS_H_ */
