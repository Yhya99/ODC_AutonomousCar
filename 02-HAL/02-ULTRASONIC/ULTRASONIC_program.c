
#ifndef F_CPU
#define F_CPU	16000000UL
#endif

#include "Types.h"
#include "BIT_math.h"

#include "DIO_interface.h"
#include "../../01-MCAL/02-TMR1/TMR1_INTERFACE.h"

#include "ULTRASONIC_private.h"
#include "ULTRASONIC_config.h"
#include "ULTRASONIC_interface.h"
#include "util/delay.h"


static const float TICK_TIME = (1000000/(F_CPU/64));

static const _strTMR1CONFIG_t ULTRASONIC_strTMR1Config=
{
	TMR1_NORMAL_MODE,
	OCR1A_DISCONNECTED,
	OCR1B_DISCONNECTED,
	ICNC_ENABLE,
	TMR1_PSC_64
};

void ULTRASONIC_vidInit(void)
{
	TMR1_VidInit(&ULTRASONIC_strTMR1Config);
	DIO_vidSetPinMode(TRIGGER_PORT,TRIGGER_PIN,OUTPUT);
	DIO_vidSetPinMode(ECHO_PORT,ECHO_PIN,INPUT);
}

u16 ULTRASONIC_u16CalculateDistance()
{
	u16 u16Distance;
	DIO_vidWritePin(TRIGGER_PORT,TRIGGER_PIN,HIGH);
	_delay_us(10);
	DIO_vidWritePin(TRIGGER_PORT,TRIGGER_PIN,LOW);
	TMR1_vidClear();
	u16 u16FirstRead = TMR1_u16ICREAD(IC_RISING_EDGE);
	u16 u16SecondRead = TMR1_u16ICREAD(IC_FALLING_EDGE);
	u16Distance = (u16)((((float)(u16SecondRead - u16FirstRead))*TICK_TIME)/58);
	return u16Distance;
}
