#include "../02-TMR1/TMR1_CONFIG.h"
#include "../02-TMR1/TMR1_INTERFACE.h"
#include "../02-TMR1/TMR1_PRIVATE.h"
#include "Types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"



void TMR1_VidInit(const _strTMR1CONFIG_t *Ptr_strTMR1Config)
{
	TMR1->TCCR1B.strBITS.CS1 = Ptr_strTMR1Config->enuTMR1PSC;
	TMR1->TCCR1A.strBITS.WGM1_01 = ((Ptr_strTMR1Config->enuTMR1_MODE) & 0x03);
	TMR1->TCCR1B.strBITS.WGM1_23 = ((Ptr_strTMR1Config->enuTMR1_MODE >> 2) & 0x03);
	TMR1->TCCR1A.strBITS.COM1A = Ptr_strTMR1Config->enuTMR1OCR1A_MODE;
	TMR1->TCCR1A.strBITS.COM1B = Ptr_strTMR1Config->enuTMR1OCR1B_MODE;
	TMR1->TCCR1B.strBITS.ICNC1 = Ptr_strTMR1Config->enuTMR1ICNC_MODE;
}

void TMR1_vidPWMWrite(_enuTMR1PWMCHANNEL_t enuTMR1PWMChannel, u16 u16DutyCycle)
{
	if(enuTMR1PWMChannel == OC1A)
	{
		TMR1->OCR1AH = (u16DutyCycle >> 8); // Write High Register First Because of Register buffer
		TMR1->OCR1AL = (u16DutyCycle);
	}
	else if(enuTMR1PWMChannel == OC1B)
	{
		TMR1->OCR1BH = (u16DutyCycle >> 8);
		TMR1->OCR1BL = (u16DutyCycle);
	}
	else
	{
		//
	}
}

void TMR1_vidICRWrite(u16 u16TMR1ICRValue)
{
	TMR1->ICR1H = (u16TMR1ICRValue >>8);
	TMR1->ICR1L = (u16TMR1ICRValue);
}

void TMR1_vidClear(void)
{
	TMR1->TCNT1H = 0;
	TMR1->TCNT1L = 0;
}

u16 TMR1_u16ICREAD(_enuTMR1ICES_t enuTMR1ICES)
{
    TMR1->TCCR1B.strBITS.ICES1 = enuTMR1ICES;
	u16 u16ICValue;
	while(TMR1->TIFR1.strBITS.ICF1 == 0);
	u16ICValue = TMR1->ICR1L;
	u16ICValue |= (8<<(TMR1->ICR1H));
	TMR1->TIFR1.strBITS.ICF1 = 1;
	return u16ICValue;
}
