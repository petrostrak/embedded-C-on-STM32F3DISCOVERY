#ifndef LEDS_H_
#define LEDS_H_

#include <stdint.h>
#include "peripherals.h"

RCC_AHBENR_t volatile *const pRCCE = RCCE_BASE_ADDR;
RCC_AHBENR_t volatile *const pRCCA = RCCA_BASE_ADDR;
GPIOx_MODER_t volatile *const pGPIOEmode = GPIOE_BASE_ADDR;
GPIOx_ODR_t volatile *const pGPIOEoutput = GPIOE_OUTPUT;
GPIOx_MODER_t volatile *const pGPIOAmode = GPIOA_MODE_BASE_ADDR;
GPIOx_IDR_t const volatile *const pGPIOAinput = GPIOA_INPUT; // we can use const volatile in read only memory addresses

// Read the PA0 status (GPIOA input data register)
uint8_t read_button_status()
{
	// Since we only need to read the 1st bit, we zeroed all others
	return pGPIOAinput->IDR0;
}

// Clear all output bits before start the iteration
void clear_all_leds()
{
	pGPIOEoutput->ODR8 = STATE_LOW;
	pGPIOEoutput->ODR9 = STATE_LOW;
	pGPIOEoutput->ODR10 = STATE_LOW;
	pGPIOEoutput->ODR11 = STATE_LOW;
	pGPIOEoutput->ODR12 = STATE_LOW;
	pGPIOEoutput->ODR13 = STATE_LOW;
	pGPIOEoutput->ODR14 = STATE_LOW;
	pGPIOEoutput->ODR15 = STATE_LOW;
}

// delay simulates a human-eye-visible delay
void delay(uint32_t volatile seconds)
{
	seconds *= DELAY;
	for(uint32_t i = 0; i < seconds; i++);
}

void clear_gpioa_mode_input()
{
	pGPIOAmode->MODER_0 = STATE_LOW;
}

// set the 8th-15th pin mode to 01 general purpose output mode)
void set_led_mode_to_output()
{
	pGPIOEmode->MODER_8 = STATE_HIGH;
	pGPIOEmode->MODER_9 = STATE_HIGH;
	pGPIOEmode->MODER_10 = STATE_HIGH;
	pGPIOEmode->MODER_11 = STATE_HIGH;
	pGPIOEmode->MODER_12 = STATE_HIGH;
	pGPIOEmode->MODER_13 = STATE_HIGH;
	pGPIOEmode->MODER_14 = STATE_HIGH;
	pGPIOEmode->MODER_15 = STATE_HIGH;
}

void set_gpioe_bus()
{
	pRCCE->IOPEEN = STATE_HIGH;

}

void set_gpioa_bus()
{
	pRCCA->IOPAEN = STATE_HIGH;
}

// ledON sets the (i + 8)-th bit of the output data register HIGH (value: 1) (3,3 Volts)
void led_on(uint8_t i)
{
	switch (i) {
	case 1:
		pGPIOEoutput->ODR9 = STATE_HIGH;
		break;
	case 2:
		pGPIOEoutput->ODR10 = STATE_HIGH;
		break;
	case 3:
		pGPIOEoutput->ODR11 = STATE_HIGH;
		break;
	case 4:
		pGPIOEoutput->ODR12 = STATE_HIGH;
		break;
	case 5:
		pGPIOEoutput->ODR13 = STATE_HIGH;
		break;
	case 6:
		pGPIOEoutput->ODR14 = STATE_HIGH;
		break;
	case 7:
		pGPIOEoutput->ODR15 = STATE_HIGH;
		break;
	default:
		pGPIOEoutput->ODR8 = STATE_HIGH;
		break;
	}
}

#endif /* LEDS_H_ */
