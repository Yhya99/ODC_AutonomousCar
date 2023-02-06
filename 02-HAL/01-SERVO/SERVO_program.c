
#include "../../01-MCAL/02-TMR1/TMR1_INTERFACE.h"
#include "Types.h"
#include "BIT_math.h"

#include "DIO_interface.h"
#include "SERVO_private.h"
#include "SERVO_config.h"
#include "SERVO_interface.h"

static _strTMR1CONFIG_t SERVO_strTMR1Config=
{
	TMR1_FAST_PWM_ICR1_MODE,
	OCR1A_DISCONNECTED,
	OCR1B_DISCONNECTED,
	ICNC_DISABLE,
	TMR1_PSC_8
};

void SERVO_vidInit(const _strSERVO_t *PTR_strSERVO)
{
	if(PTR_strSERVO->enuSERVOChannel == SERVO_CHANNEL_1)
	{
		DIO_vidSetPinMode(GPIOB, PIN1, OUTPUT);
		SERVO_strTMR1Config.enuTMR1OCR1A_MODE = OCR1A_CLEAR;
	}
	else if(PTR_strSERVO->enuSERVOChannel == SERVO_CHANNEL_2)
	{
		DIO_vidSetPinMode(GPIOB, PIN2, OUTPUT);
		SERVO_strTMR1Config.enuTMR1OCR1B_MODE = OCR1B_CLEAR;
	}else
	{
		//
	}
	TMR1_VidInit(&SERVO_strTMR1Config);
	TMR1_vidICRWrite(39999);
}

void SERVO_vidWrite(const _strSERVO_t *PTR_strSERVO,u8 u8Degree)
{
	if((u8Degree > 0) && (u8Degree <= 180))
	{
		u16 value = (u16)((float)u8Degree/(0.09));
		TMR1_vidPWMWrite(PTR_strSERVO->enuSERVOChannel,(2000+(value)));
	}
	else
	{
		TMR1_vidPWMWrite(PTR_strSERVO->enuSERVOChannel,1999);	// 0' degree
	}
}
