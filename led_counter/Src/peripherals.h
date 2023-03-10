#ifndef PERIPHERALS_H_
#define PERIPHERALS_H_

#define RCCE_BASE_ADDR 			((RCC_AHBENR_t*) 0x40021014)
#define RCCA_BASE_ADDR 			((RCC_AHBENR_t*) 0x40021014)
#define GPIOE_BASE_ADDR 		((GPIOx_MODER_t*) 0x48001000)
#define GPIOA_MODE_BASE_ADDR 	((GPIOx_MODER_t*) 0x48000000)
#define GPIOE_OUTPUT 			((GPIOx_ODR_t*) 0x48001014)
#define GPIOA_INPUT 			((GPIOx_IDR_t*) 0x48000010)

#define STATE_HIGH				(1)
#define STATE_LOW 				(0)
#define DELAY					(300000)

#include <stdint.h>

typedef struct
{
	uint32_t DMA1EN		:1;
	uint32_t DMA2EN		:1;
	uint32_t SRAMEN		:1;
	uint32_t Res0x3		:1;
	uint32_t FLITFEN	:1;
	uint32_t FMCEN_1	:1;
	uint32_t CRCEN		:1;
	uint32_t Res0x7_15	:9;
	uint32_t IOPHEN_1	:1;
	uint32_t IOPAEN		:1;
	uint32_t IOPBEN		:1;
	uint32_t IOPCEN		:1;
	uint32_t IOPDEN		:1;
	uint32_t IOPEEN		:1;
	uint32_t IOPFEN		:1;
	uint32_t IOPGEN_1	:1;
	uint32_t TSCEN		:1;
	uint32_t Res0x25_27	:3;
	uint32_t ADC12EN	:1;
	uint32_t ADC34EN	:1;
	uint32_t Res0x30_31	:2;
}RCC_AHBENR_t;

typedef struct
{
	uint32_t MODER_0	:2;
	uint32_t MODER_1	:2;
	uint32_t MODER_2	:2;
	uint32_t MODER_3	:2;
	uint32_t MODER_4	:2;
	uint32_t MODER_5	:2;
	uint32_t MODER_6	:2;
	uint32_t MODER_7	:2;
	uint32_t MODER_8	:2;
	uint32_t MODER_9	:2;
	uint32_t MODER_10	:2;
	uint32_t MODER_11	:2;
	uint32_t MODER_12	:2;
	uint32_t MODER_13	:2;
	uint32_t MODER_14	:2;
	uint32_t MODER_15	:2;
}GPIOx_MODER_t;

typedef struct
{
	uint32_t ODR0		:1;
	uint32_t ODR1		:1;
	uint32_t ODR2		:1;
	uint32_t ODR3		:1;
	uint32_t ODR4		:1;
	uint32_t ODR5		:1;
	uint32_t ODR6		:1;
	uint32_t ODR7		:1;
	uint32_t ODR8		:1;
	uint32_t ODR9		:1;
	uint32_t ODR10		:1;
	uint32_t ODR11		:1;
	uint32_t ODR12		:1;
	uint32_t ODR13		:1;
	uint32_t ODR14		:1;
	uint32_t ODR15		:1;
	uint32_t Res0x16_31	:16;
}GPIOx_ODR_t;

typedef struct
{
	uint32_t IDR0		:1;
	uint32_t IDR1		:1;
	uint32_t IDR2		:1;
	uint32_t IDR3		:1;
	uint32_t IDR4		:1;
	uint32_t IDR5		:1;
	uint32_t IDR6		:1;
	uint32_t IDR7		:1;
	uint32_t IDR8		:1;
	uint32_t IDR9		:1;
	uint32_t IDR10		:1;
	uint32_t IDR11		:1;
	uint32_t IDR12		:1;
	uint32_t IDR13		:1;
	uint32_t IDR14		:1;
	uint32_t IDR15		:1;
	uint32_t Res0x16_31	:16;
}GPIOx_IDR_t;

#endif /* PERIPHERALS_H_ */
