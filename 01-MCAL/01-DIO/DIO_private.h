#ifndef _MCAL_DIO_PRIVATE_H_
#define _MCAL_DIO_PRIVATE_H_

#include "Types.h"

#define GPIOA_BASE		0x39
#define GPIOB_BASE		0x36
#define GPIOC_BASE		0x33
#define GPIOD_BASE		0x30

typedef struct
{
	volatile u8	PIN;
	volatile u8	DDR;
	volatile u8	PORT;
}_strGPIO_t;

#endif
