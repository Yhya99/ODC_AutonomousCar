
#ifndef F_CPU
#define F_CPU	16000000UL
#endif

#include "Types.h"
#include "BIT_math.h"

#include "DIO_interface.h"
#include "TMR1_INTERFACE.h"

#include "ULTRASONIC_private.h"
#include "ULTRASONIC_config.h"
#include "ULTRASONIC_interface.h"
#include "util/delay.h"


static const float TICK_TIME = (1000000/(F_CPU/64));
volatile u8 over_flow = 0;

static const _strTMR1CONFIG_t ULTRASONIC_strTMR1Config=
{
	TMR1_NORMAL_MODE,
	OCR1A_DISCONNECTED,
	OCR1B_DISCONNECTED,
	ICNC_ENABLE,
	TMR1_PSC_64
};

static void ULTRASONIC_vidCountOverFlow(void)
{
	over_flow++;
}
void ULTRASONIC_vidInit(void)
{
	TMR1_VidInit(&ULTRASONIC_strTMR1Config);
	DIO_vidSetPinMode(TRIGGER_PORT,TRIGGER_PIN,OUTPUT);
	DIO_vidSetPinMode(ECHO_PORT,ECHO_PIN,INPUT);
	TMR1_OVF_InterruptEnable();
	TMR1_OVF_SetCallBack(ULTRASONIC_vidCountOverFlow);
}

u16 ULTRASONIC_u16CalculateDistance()
{
	u16 u16Distance;
	DIO_vidWritePin(TRIGGER_PORT,TRIGGER_PIN,HIGH);
	_delay_us(10);
	DIO_vidWritePin(TRIGGER_PORT,TRIGGER_PIN,LOW);
	TMR1_u16ICREAD(IC_RISING_EDGE);
	TMR1_vidClear();
	over_flow = 0;
	u16 u16TimeRead = TMR1_u16ICREAD(IC_FALLING_EDGE);
	u16Distance = (u16)(((float)(u16TimeRead + (over_flow * 65535))*TICK_TIME)/58);
	return u16Distance;
}
