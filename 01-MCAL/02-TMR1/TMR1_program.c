#include "Types.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "TMR1_PRIVATE.h"
#include "TMR1_CONFIG.h"
#include "TMR1_INTERFACE.h"

#define NULLPTR   ((void*)0)

static void (*TMR1_OVF_Fptr) (void)=NULLPTR;
static void (*TMR1_OCA_Fptr) (void)=NULLPTR;
static void (*TMR1_OCB_Fptr) (void)=NULLPTR;
static void (*TMR1_ICU_Fptr) (void)=NULLPTR;

#define SREG	*(volatile u8*) 0x5f
void TMR1_VidInit(const _strTMR1CONFIG_t *Ptr_strTMR1Config)
{
	TMR1->TCCR1B.strBITS.CS1 = Ptr_strTMR1Config->enuTMR1PSC;
	TMR1->TCCR1A.strBITS.WGM1_01 = ((Ptr_strTMR1Config->enuTMR1_MODE) & 0x03);
	TMR1->TCCR1B.strBITS.WGM1_23 = ((Ptr_strTMR1Config->enuTMR1_MODE >> 2) & 0x03);
	TMR1->TCCR1A.strBITS.COM1A = Ptr_strTMR1Config->enuTMR1OCR1A_MODE;
	TMR1->TCCR1A.strBITS.COM1B = Ptr_strTMR1Config->enuTMR1OCR1B_MODE;
	TMR1->TCCR1B.strBITS.ICNC1 = Ptr_strTMR1Config->enuTMR1ICNC_MODE;
	SET_BIT(SREG,7);
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
u8 TMR1_ICF_GET(void)
{
	return(GET_BIT((*(volatile u8*)0x36),5));
//	return (TMR1->TIFR1.strBITS.ICF1);
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

u16 TMR1_u16ReadICR(void)
{
	volatile u16 u16TMR1ICRValue;
	u16TMR1ICRValue = TMR1->ICR1L;
	u16TMR1ICRValue |= (8<<(TMR1->ICR1H));
	return u16TMR1ICRValue;
}

void TMR1_vidSetICREdge(_enuTMR1ICES_t enuTMR1ICES)
{
    TMR1->TCCR1B.strBITS.ICES1 = enuTMR1ICES;
}

void TMR1_ICF_CLR(void)
{
	SET_BIT((*(volatile u8*)0x36),5);
//	TMR1->TIFR1.strBITS.ICF1 = 1;
}

void TMR1_OVF_CLR(void)
{
	TMR1->TIFR1.strBITS.TOV1 = 1;
}

void TMR1_OVF_InterruptEnable(void)
{
	TMR1->TIMSK1.strBITS.TOIE1 = 1;
}

void TMR1_OVF_InterruptDisable(void)
{
	TMR1->TIMSK1.strBITS.TOIE1 = 0;
}
void TMR1_OCR1A_InterruptEnable(void)
{
	TMR1->TIMSK1.strBITS.OCIE1A = 1;
}

void TMR1_OCR1A_InterruptDisable(void)
{
	TMR1->TIMSK1.strBITS.OCIE1A = 0;
}

void TMR1_OCR1B_InterruptEnable(void)
{
	TMR1->TIMSK1.strBITS.OCIE1B = 1;
}

void TMR1_OCR1B_InterruptDisable(void)
{
	TMR1->TIMSK1.strBITS.OCIE1B = 0;
}

void TMR1_ICU_InterruptEnable(void)
{
	TMR1->TIMSK1.strBITS.ICIE1 = 1;
}
void TMR1_ICU_InterruptDisable(void)
{
	TMR1->TIMSK1.strBITS.ICIE1 = 0;
}

void TMR1_OVF_SetCallBack(void(*LocalFptr)(void))
{
	TMR1_OVF_Fptr = LocalFptr;
}

void TMR1_OCR1A_SetCallBack(void(*LocalFptr)(void))
{
	TMR1_OCA_Fptr=LocalFptr;
}

void TMR1_OCR1B_SetCallBack(void(*LocalFptr)(void))
{
	TMR1_OCB_Fptr=LocalFptr;
}

void TMR1_ICU_SetCallBack(void(*LocalFptr)(void))
{
	TMR1_ICU_Fptr=LocalFptr;
}

// DON't in include "avr/interrupt.h" in the top, Gives syntax errors
//#include <avr/interrupt.h>
//
//ISR(TIMER1_OVF_vect)
//{
//	if(TMR1_OVF_Fptr!=NULLPTR)
//	{
//		TMR1_OVF_Fptr();
//	}
//}
//
//ISR(TIMER1_COMPA_vect)
//{
//	if(TMR1_OCA_Fptr!=NULLPTR)
//	{
//		TMR1_OCA_Fptr();
//	}
//}
//
//ISR(TIMER1_COMPB_vect)
//{
//	if(TMR1_OCB_Fptr!=NULLPTR)
//	{
//		TMR1_OCB_Fptr();
//	}
//}
//
//ISR(TIMER1_CAPT_vect)
//{
//	if(TMR1_ICU_Fptr!=NULLPTR)
//	{
//		TMR1_ICU_Fptr();
//	}
//}
