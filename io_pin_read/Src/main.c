#include <stdint.h>
#include "peripherals.h"

RCC_AHBENR_t volatile *const pRCCE 						= RCC_BASE_ADDR;
GPIOx_MODER_t volatile *const pGPIOAMode				= GPIOA_MODE_BASE_ADDR;
GPIOx_IDR_t volatile *const pGPIOAInput					= GPIOA_INPUT;
GPIOx_MODER_t volatile *const pGPIOEMode				= GPIOE_MODE_BASE_ADDR;
GPIOx_ODR_t volatile *const pGPIOEOutput				= GPIOE_OUTPUT;

int main(void)
{
	// 1. Enable the clock for GPIOE and GPIOA peripherals in the AHB bus
	// Set the 21th and 17th bit from AHB RCC_AHBENR
	pRCCE->IOPAEN = STATE_HIGH;
	pRCCE->IOPEEN = STATE_HIGH;

	// 2. Configure the mode of the IO pin as output.
	// a) First we clear the bits 17-16 (&)
	pGPIOEMode->MODER_9 = STATE_HIGH;

	// Configure PA0 as input mode (GPIOA Mode Register)
	pGPIOAMode->MODER_0 = STATE_LOW;


    /* Loop forever */
	for(;;)
	{
		// Read the pin status of the pin PA0 (GPIOA Input Data Register)
		uint8_t PA0Status = pGPIOAInput->IDR0; // Extract the 1st bin only.

		if (PA0Status) {
			// turn on the LED
			ledOn((uint32_t*)pGPIOEOutput, 9);
		} else {
			// turn off the LED
			ledOff((uint32_t*)pGPIOEOutput, 9);
		}
	}
}
