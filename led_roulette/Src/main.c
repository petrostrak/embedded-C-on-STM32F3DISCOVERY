#include <stdint.h>
#include "leds.h"
#include "peripherals.h"

RCC_AHBENR_t volatile *const pRCCE = RCC_BASE_ADDR;
GPIOx_MODER_t volatile *const pGPIOEmode = GPIOE_BASE_ADDR;
GPIOx_ODR_t volatile *const pGPIOEoutput = GPIOE_OUTPUT;
GPIOx_MODER_t volatile *const pGPIOAmode = GPIOA_MODE_BASE_ADDR;
GPIOx_IDR_t const volatile *const pGPIOAinput = GPIOA_INPUT; // we can use const volatile in read only memory addresses

int main(void)
{
	// Enable the clock for GPIOE peripheral in the AHBENR
	pRCCE->IOPEEN = STATE_HIGH;

	// Enable the clock for GPIOA peripheral in the AHBENR
	pRCCE->IOPAEN = STATE_HIGH; // SET the 21st bit position

	// Configure the mode of the IO pins as output.
	pGPIOEmode->MODER_8 	= STATE_HIGH; // set the 8th-15th pin mode to 01 general purpose output mode)
	pGPIOEmode->MODER_9 	= STATE_HIGH;
	pGPIOEmode->MODER_10	= STATE_HIGH;
	pGPIOEmode->MODER_11	= STATE_HIGH;
	pGPIOEmode->MODER_12	= STATE_HIGH;
	pGPIOEmode->MODER_13	= STATE_HIGH;
	pGPIOEmode->MODER_14	= STATE_HIGH;
	pGPIOEmode->MODER_15	= STATE_HIGH;

	// Configure the mode of the IO pin PA0 as input
	pGPIOAmode->MODER_0	= STATE_LOW;


	while(1)
	{
		// Read the PA0 status (GPIOA input data register)
		uint32_t PA0Status = pGPIOAinput->IDR0; // Since we only need to read the 1st bit, we zeroed all others

		if(PA0Status)
		{
			clearPins(pGPIOEoutput);
			for(uint8_t current = 8; current < 16; current++)
			{
				uint8_t next = (current + 1) % 8;
				ledON((uint32_t*)pGPIOEoutput, next);
				delay(2);
				ledOFF((uint32_t*)pGPIOEoutput, current);
				delay(2);
			}
		} else {
			clearPins(pGPIOEoutput);
			for(uint8_t current = 15; current >= 8; current--)
			{
				uint8_t next = (current - 1) % 8;
				ledON((uint32_t*)pGPIOEoutput, next);
				delay(2);
				ledOFF((uint32_t*)pGPIOEoutput, current);
				delay(2);
			}
		}
	}
}
