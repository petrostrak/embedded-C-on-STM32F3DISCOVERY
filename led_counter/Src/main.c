#include <stdint.h>
#include "leds.h"

uint8_t volatile counter = 0;

int main(void)
{
	// Enable the clock for GPIOE peripheral in the AHBENR
	set_gpioe_bus();

	// Enable the clock for GPIOA peripheral in the AHBENR
	set_gpioa_bus();

	// Configure the mode of the IO pins as output.
	set_led_mode_to_output();

	// Configure the mode of the IO pin PA0 as input
	clear_gpioa_mode_input();

	while(1)
	{
		// Read the PA0 status (GPIOA input data register)
		uint8_t PA0ButtonPassed = read_button_status();

		if(PA0ButtonPassed)
		{
			counter++;
			delay(1);
			led_on(counter);


			if(counter >= 9)
			{
				counter = 0;
				clear_all_leds();
			}
		}
	}
}
