
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
static float degree_fraction = (MAX_US - MIN_US)/180;

static u16 SERVO_u16UsToTick(float floatValue)
{
	u16 tick_value;
	tick_value = (u16)(floatValue * 2);
	return tick_value;
}

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
	float value_us;
	u16 PWM_value;
	if((u8Degree > 0) && (u8Degree <= 180))
	{
		value_us = MIN_US + degree_fraction*((float)u8Degree);
		PWM_value = SERVO_u16UsToTick(value_us);
	}
	else
	{
		PWM_value = SERVO_u16UsToTick(MIN_US);
	}
	TMR1_vidPWMWrite(PTR_strSERVO->enuSERVOChannel,PWM_value);
}
