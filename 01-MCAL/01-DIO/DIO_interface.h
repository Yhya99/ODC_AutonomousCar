#ifndef _MCAL_DIO_INTERFACE_H_
#define _MCAL_DIO_INTERFACE_H_

#include "DIO_private.h"

// #define GPIOA			((_strGPIO_t*)	GPIOA_BASE)
#define GPIOB			((volatile _strGPIO_t*)	GPIOB_BASE)
#define GPIOC			((volatile _strGPIO_t*)	GPIOC_BASE)
#define GPIOD			((volatile _strGPIO_t*)	GPIOD_BASE)

typedef enum
{
	PIN0 = 0,
	PIN1 = 1,
	PIN2 = 2,
	PIN3 = 3,
	PIN4 = 4,
	PIN5 = 5,
	PIN6 = 6,
	PIN7 = 7
}_enuPINx_t;


typedef enum
{
	INPUT,
	OUTPUT,
	INPUT_PULLUP
}_enuIOx_t;

typedef enum
{
	LOW,
	HIGH
}_enuPINVALUE_t;

typedef struct
{
	volatile u8	PIN;
	volatile u8	DDR;
	volatile u8	PORT;
}_strGPIO_t;

void DIO_vidSetPinMode(volatile _strGPIO_t* strGPIOx, _enuPINx_t enuPINx,  _enuIOx_t enuPinDirection);
void DIO_vidWritePin(volatile _strGPIO_t* strGPIOx, _enuPINx_t enuPINx, _enuPINVALUE_t enuPinValue);
_enuPINVALUE_t DIO_vidReadPin(volatile _strGPIO_t* strGPIOx, _enuPINx_t enuPINx);

void DIO_vidSetPortMode(volatile _strGPIO_t* strGPIOx,  _enuIOx_t enuPinDirection);
void DIO_vidWritePort(volatile _strGPIO_t* strGPIOx, u8 u8Value);

void DIO_vidSetLowNibbleMode(volatile _strGPIO_t* strGPIOx , _enuIOx_t enuPinDirection);
void DIO_vidWriteLowNibble(volatile _strGPIO_t* strGPIOx, u8 u8Value);
void DIO_vidSetHighNibbleMode(volatile _strGPIO_t* strGPIOx , _enuIOx_t enuPinDirection);
void DIO_vidWriteHighNibble(volatile _strGPIO_t* strGPIOx, u8 u8Value);

#endif
