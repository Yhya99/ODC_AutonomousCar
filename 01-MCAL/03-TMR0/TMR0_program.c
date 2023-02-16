#include "../03-TMR0/TMR0_config.h"
#include "../03-TMR0/TMR0_interface.h"
#include "../03-TMR0/TMR0_private.h"
#include "Types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"



void TMR0_VidInit(const _strTMR0CONFIG_t *Ptr_strTMR0Config)
{
	TMR0->TCCR0B.strBITS.CS0 = Ptr_strTMR0Config->enuTMR0PSC;
	TMR0->TCCR0A.strBITS.WGM0_01 = ((Ptr_strTMR0Config->enuTMR0_MODE) & 0x03);
	TMR0->TCCR0B.strBITS.WGM0_2 = ((Ptr_strTMR0Config->enuTMR0_MODE >> 2) & 0x01);
	TMR0->TCCR0A.strBITS.COM0A = Ptr_strTMR0Config->enuTMR0OCR0A_MODE;
	TMR0->TCCR0A.strBITS.COM0B = Ptr_strTMR0Config->enuTMR0OCR0B_MODE;
}

void TMR0_vidPWMWrite(_enuTMR0PWMCHANNEL_t enuTMR0PWMChannel,u16 u16DutyCycle)
{
	if(enuTMR0PWMChannel == OC0A)
	{
		DIO_vidSetPinMode(GPIOD, PIN6, OUTPUT);
		TMR0->OCR0A = (u16DutyCycle);
	}
	else if(enuTMR0PWMChannel == OC0B)
	{
		DIO_vidSetPinMode(GPIOD, PIN5, OUTPUT);
		TMR0->OCR0B = (u16DutyCycle);
	}
	else
	{
		//
	}
}

void TMR0_vidClear()
{
	TMR0->TCNT0 = 0;
}
