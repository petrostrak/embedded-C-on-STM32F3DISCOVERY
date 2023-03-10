#ifndef KEYS_H_
#define KEYS_H_
#include <stdint.h>
#include <stdio.h>

RCC_AHBENR_t volatile *const pRCCE = RCC_BASE_ADDR;
GPIOx_MODER_t volatile *const pGPIODmode = GPIOD_BASE_ADDR;
GPIOx_ODR_t volatile *const pGPIODoutput = GPIOD_OUTPUT;
GPIOx_IDR_t const volatile *const pGPIODinput = GPIOD_INPUT;
GPIOx_PUPDR_t volatile *const pGPIODpullUp = GPIOD_PULL_UP_DOWN;

void set_gpiod_bus()
{
	pRCCE->IOPDEN = STATE_HIGH;
}

void set_gpiod_mode_output()
{
	pGPIODmode->MODER_0 = STATE_HIGH;
	pGPIODmode->MODER_1 = STATE_HIGH;
	pGPIODmode->MODER_2 = STATE_HIGH;
	pGPIODmode->MODER_3 = STATE_HIGH;
}

void clear_gpiod_mode_input()
{
	pGPIODmode->MODER_8 = STATE_LOW;
	pGPIODmode->MODER_9 = STATE_LOW;
	pGPIODmode->MODER_10 = STATE_LOW;
	pGPIODmode->MODER_11 = STATE_LOW;
}

void set_pull_up_resistors()
{
	pGPIODpullUp->PUPDR08 = STATE_HIGH;
	pGPIODpullUp->PUPDR09 = STATE_HIGH;
	pGPIODpullUp->PUPDR10 = STATE_HIGH;
	pGPIODpullUp->PUPDR11 = STATE_HIGH;
}

// delay simulates a human-eye-visible delay
void delay(uint32_t volatile seconds)
{
	seconds *= DELAY;
	for(uint32_t i = 0; i < seconds; i++);
}

void set_rows_high()
{
	pGPIODoutput->ODR0 = STATE_HIGH;
	pGPIODoutput->ODR1 = STATE_HIGH;
	pGPIODoutput->ODR2 = STATE_HIGH;
	pGPIODoutput->ODR3 = STATE_HIGH;
}

void scan_row_1()
{
	pGPIODoutput->ODR0 = STATE_LOW;

	// read C1, C2, C3, C4 (PD8, 9, 10, 11)
	uint32_t c1Status = pGPIODinput->IDR8;
	uint32_t c2Status = pGPIODinput->IDR9;
	uint32_t c3Status = pGPIODinput->IDR10;
	uint32_t c4Status = pGPIODinput->IDR11;

	if(!c1Status)
	{
		delay(1);
		printf("1\n");
	}

	if(!c2Status) {
		delay(1);
		printf("2\n");
	}

	if(!c3Status) {
		delay(1);
		printf("3\n");
	}

	if(!c4Status) {
		delay(1);
		printf("A\n");
	}
}

void scan_row_2()
{
	pGPIODoutput->ODR0 = STATE_HIGH;
	pGPIODoutput->ODR1 = STATE_LOW;

	// read C1, C2, C3, C4 (PD8, 9, 10, 11)
	uint32_t c1Status = pGPIODinput->IDR8;
	uint32_t c2Status = pGPIODinput->IDR9;
	uint32_t c3Status = pGPIODinput->IDR10;
	uint32_t c4Status = pGPIODinput->IDR11;

	if(!c1Status)
	{
		delay(1);
		printf("4\n");
	}

	if(!c2Status) {
		delay(1);
		printf("5\n");
	}

	if(!c3Status) {
		delay(1);
		printf("6\n");
	}

	if(!c4Status) {
		delay(1);
		printf("B\n");
	}
}

void scan_row_3()
{
	pGPIODoutput->ODR1 = STATE_HIGH;
	pGPIODoutput->ODR2 = STATE_LOW;

	// read C1, C2, C3, C4 (PD8, 9, 10, 11)
	uint32_t c1Status = pGPIODinput->IDR8;
	uint32_t c2Status = pGPIODinput->IDR9;
	uint32_t c3Status = pGPIODinput->IDR10;
	uint32_t c4Status = pGPIODinput->IDR11;

	if(!c1Status)
	{
		delay(1);
		printf("7\n");
	}

	if(!c2Status) {
		delay(1);
		printf("8\n");
	}

	if(!c3Status) {
		delay(1);
		printf("9\n");
	}

	if(!c4Status) {
		delay(1);
		printf("C\n");
	}
}

void scan_row_4()
{
	pGPIODoutput->ODR2 = STATE_HIGH;
	pGPIODoutput->ODR3 = STATE_LOW;

	// read C1, C2, C3, C4 (PD8, 9, 10, 11)
	uint32_t c1Status = pGPIODinput->IDR8;
	uint32_t c2Status = pGPIODinput->IDR9;
	uint32_t c3Status = pGPIODinput->IDR10;
	uint32_t c4Status = pGPIODinput->IDR11;

	if(!c1Status)
	{
		delay(1);
		printf("*\n");
	}

	if(!c2Status) {
		delay(1);
		printf("0\n");
	}

	if(!c3Status) {
		delay(1);
		printf("#\n");
	}

	if(!c4Status) {
		delay(1);
		printf("D\n");
	}
}

#endif /* KEYS_H_ */
