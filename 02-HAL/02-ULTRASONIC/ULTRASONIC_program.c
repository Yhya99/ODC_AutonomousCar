
#ifndef F_CPU
#define F_CPU	16000000UL
#endif

#include "Types.h"
#include "BIT_math.h"

#include "DIO_interface.h"

#include "ULTRASONIC_private.h"
#include "ULTRASONIC_config.h"
#include "ULTRASONIC_interface.h"
#include "util/delay.h"

u64 counter = 0;
double distance = 0;

void ULTRASONIC_vidInit(void)
{
	DIO_vidSetPinMode(TRIGGER_PORT,TRIGGER_PIN,OUTPUT);
	DIO_vidSetPinMode(ECHO_PORT,ECHO_PIN,INPUT_PULLUP);
}

double ULTRASONIC_doubleGetDistance(void)
{

	DIO_vidWritePin(TRIGGER_PORT,TRIGGER_PIN,HIGH);
	_delay_us(10);
	DIO_vidWritePin(TRIGGER_PORT,TRIGGER_PIN,LOW);

	while(DIO_vidReadPin(ECHO_PORT,ECHO_PIN) == 0);
	counter = 0;
	while(DIO_vidReadPin(ECHO_PORT,ECHO_PIN) == 1)
	{
		++counter;
	}
	distance = (((double)(counter*85 + 16)*0.0625)/58.3);
	return distance;
}

