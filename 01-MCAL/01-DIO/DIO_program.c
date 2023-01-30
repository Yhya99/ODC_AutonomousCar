#include "Types.h"
#include "BIT_math.h"

#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"


void DIO_vidSetPinMode(_strGPIO_t* strGPIOx, _enuPINx_t enuPINx,  _enuIOx_t enuPinDirection)
{
	if(enuPinDirection == OUTPUT)
	{
		SET_BIT(strGPIOx->DDR, enuPINx);
	}
	else if(enuPinDirection == INPUT_PULLUP)
	{
		CLR_BIT(strGPIOx->DDR, enuPINx);
		SET_BIT(strGPIOx->PORT, enuPINx);
	}else
	{
		CLR_BIT(strGPIOx->DDR, enuPINx);
	}
}
void DIO_vidWritePin(_strGPIO_t* strGPIOx, _enuPINx_t enuPINx, _enuPINVALUE_t enuPinValue)
{
	if(enuPinValue == HIGH)
	{
		SET_BIT(strGPIOx->PORT, enuPINx);
	}else
	{
		CLR_BIT(strGPIOx->PORT, enuPINx);
	}
}

_enuPINVALUE_t DIO_vidReadPin(_strGPIO_t* strGPIOx, _enuPINx_t enuPINx)
{
	_enuPINVALUE_t enuPinValue;
	enuPinValue = GET_BIT(strGPIOx->PIN,enuPINx);
	return enuPinValue;
}

void DIO_vidSetPortMode(_strGPIO_t* strGPIOx,  _enuIOx_t enuPinDirection)
{
	if(enuPinDirection == OUTPUT)
	{
		strGPIOx->DDR = 0xff;
	}
	else if(enuPinDirection == INPUT_PULLUP)
	{
		strGPIOx->DDR = 0x00;
		strGPIOx->PORT = 0xff;
	}
	else
	{
		strGPIOx->DDR = 0x00;
	}
}

void DIO_vidWritePort(_strGPIO_t* strGPIOx, u8 u8Value)
{
	strGPIOx->PORT = u8Value;
}

void DIO_vidSetLowNibbleMode(_strGPIO_t* strGPIOx , _enuIOx_t enuPinDirection)
{
	if(enuPinDirection == OUTPUT)
	{
		strGPIOx->DDR 	|= 0x0f;
	}
	else if(enuPinDirection == INPUT_PULLUP)
	{
		strGPIOx->DDR 	&= 0xf0;
		strGPIOx->PORT 	|= 0x0f;
	}
	else
	{
		strGPIOx->DDR 	&= 0xf0;
	}
}
void DIO_vidWriteLowNibble(_strGPIO_t* strGPIOx, u8 u8Value)
{
	u8Value &= 0x0f;
	strGPIOx->PORT |= u8Value;
}

void DIO_vidSetHighNibbleMode(_strGPIO_t* strGPIOx , _enuIOx_t enuPinDirection)
{
	if(enuPinDirection == OUTPUT)
	{
		strGPIOx->DDR 	|= 0xf0;
	}
	else if(enuPinDirection == INPUT_PULLUP)
	{
		strGPIOx->DDR 	&= 0x0f;
		strGPIOx->PORT 	|= 0xf0;
	}
	else
	{
		strGPIOx->DDR 	&= 0x0f;
	}
}
void DIO_vidWriteHighNibble(_strGPIO_t* strGPIOx, u8 u8Value)
{
	u8Value &= 0xf0;
	strGPIOx->PORT |= u8Value;
}
