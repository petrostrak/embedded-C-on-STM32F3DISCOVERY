#include <stdint.h>

// ledON sets the (i + 8)-th bit of the output data register HIGH (value: 1) (3,3 Volts)
void ledOn(uint32_t volatile *led, uint8_t i)
{
	*led |= (1 << i);
}

// ledOFF clears the i-th bit of the output data register to LOW (value: 0) (0 Volts)
void ledOff(uint32_t volatile *led, uint8_t i)
{
	*led &= ~(1 << i);
}


