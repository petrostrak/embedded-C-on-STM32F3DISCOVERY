/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2024 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>

uint32_t *const pRCC_Register 			= (uint32_t*)0x40021014;
uint32_t *const pGPIOA_Mode_Register 		= (uint32_t*)0x48000000;
uint32_t *const pGPIOA_Input_Register 		= (uint32_t*)0x48000010;
uint32_t *const pGPIOE_Mode_Register 		= (uint32_t*)0x48001000;
uint32_t *const pGPIOE_Output_Data_Register 	= (uint32_t*)0x48001014;

int main(void)
{
	// 1. Enable the clock for GPIOE and GPIOA peripherals in the AHB bus
	// Set the 21th and 17th bit from AHB RCC_AHBENR
	*pRCC_Register |= (0x11 << 17);

	// 2. Configure the mode of the IO pin as output.
	// a) First we clear the bits 17-16 (&)
	*pGPIOE_Mode_Register &= ~(3 << 18);

	// b) Second, set the 16th bit to HIGH (|)
	*pGPIOE_Mode_Register |= (1 << 18);

	// Configure PA0 as input mode (GPIOA Mode Register)
	*pGPIOA_Mode_Register &= ~(3 << 0);


    /* Loop forever */
	for(;;)
	{
		// Read the pin status of the pin PA0 (GPIOA Input Data Register)
		uint8_t pin_status = (uint8_t*)(*pGPIOA_Input_Register & 0x1); // Extract the 1st bin only.

		if (pin_status) {
			// turn on the LED
			*pGPIOE_Output_Data_Register |= (1 << 9);
		} else {
			// turn off the LED
			*pGPIOE_Output_Data_Register &= ~(1 << 9);
		}
	}
}
