#include "../../01-MCAL/03-TMR0/TMR0_interface.h"
#include "Types.h"
#include "BIT_math.h"

#include "DIO_interface.h"
#include "MOTOR_private.h"
#include "MOTOR_config.h"
#include "MOTOR_interface.h"

static _strTMR0CONFIG_t MOTOR_strTMR0Config =
{
	TMR0_PWM_PHASE_CORRECT_MODE,
	OCR0A_DISCONNECTED,
	OCR0B_DISCONNECTED,
	TMR0_PSC_1024
};

void MOTOR_vidInit(const _strMOTORCONFIG_t *PTR_strMOTORConfig)
{
	DIO_vidSetPinMode(PTR_strMOTORConfig->OUT1_PORT, PTR_strMOTORConfig->OUT1_PIN, OUTPUT);
	DIO_vidSetPinMode(PTR_strMOTORConfig->OUT2_PORT, PTR_strMOTORConfig->OUT2_PIN, OUTPUT);
	DIO_vidSetPinMode(PTR_strMOTORConfig->ENABLE_PORT, PTR_strMOTORConfig->ENABLE_PIN, OUTPUT);

	DIO_vidWritePin(PTR_strMOTORConfig->OUT1_PORT, PTR_strMOTORConfig->OUT1_PIN, LOW);
	DIO_vidWritePin(PTR_strMOTORConfig->OUT2_PORT, PTR_strMOTORConfig->OUT2_PIN, LOW);
	DIO_vidWritePin(PTR_strMOTORConfig->ENABLE_PORT, PTR_strMOTORConfig->ENABLE_PIN, LOW);
	if(PTR_strMOTORConfig->ENABLE_PORT == GPIOD && PTR_strMOTORConfig->ENABLE_PIN == PIN6)
	{
		MOTOR_strTMR0Config.enuTMR0OCR0A_MODE =OCR0A_CLEAR;
	}else if(PTR_strMOTORConfig->ENABLE_PORT == GPIOD && PTR_strMOTORConfig->ENABLE_PIN == PIN5)
	{
		MOTOR_strTMR0Config.enuTMR0OCR0B_MODE =OCR0B_CLEAR;
	}else
	{
		//
	}
	TMR0_VidInit(&MOTOR_strTMR0Config);
}

void MOTOR_vidSetSpeed(const _strMOTORCONFIG_t *PTR_strMOTORConfig, u8 u8Speed)
{
	if(u8Speed > 100)
	{
		u8Speed =100;
	}
	else
	{
		//
	}

	if(PTR_strMOTORConfig->ENABLE_PORT == GPIOD && PTR_strMOTORConfig->ENABLE_PIN == PIN6)
	{
		TMR0_vidPWMWrite(OC0A,((u8)(u8Speed * 2.55)));
	}else if(PTR_strMOTORConfig->ENABLE_PORT == GPIOD && PTR_strMOTORConfig->ENABLE_PIN == PIN5)
	{
		TMR0_vidPWMWrite(OC0B,((u8)(u8Speed * 2.55)));
	}else if(u8Speed > 0)
	{
		DIO_vidWritePin(PTR_strMOTORConfig->ENABLE_PORT, PTR_strMOTORConfig->ENABLE_PIN, HIGH);
	}else
	{
		DIO_vidWritePin(PTR_strMOTORConfig->ENABLE_PORT, PTR_strMOTORConfig->ENABLE_PIN, LOW);
	}

}

void MOTOR_vidStop(const _strMOTORCONFIG_t *PTR_strMOTORConfig)
{
	DIO_vidWritePin(PTR_strMOTORConfig->OUT1_PORT, PTR_strMOTORConfig->OUT1_PIN, LOW);
	DIO_vidWritePin(PTR_strMOTORConfig->OUT2_PORT, PTR_strMOTORConfig->OUT2_PIN, LOW);
}

void MOTOR_vidMoveForward(const _strMOTORCONFIG_t *PTR_strMOTORConfig)
{
	DIO_vidWritePin(PTR_strMOTORConfig->OUT1_PORT, PTR_strMOTORConfig->OUT1_PIN, HIGH);
	DIO_vidWritePin(PTR_strMOTORConfig->OUT2_PORT, PTR_strMOTORConfig->OUT2_PIN, LOW);
}

void MOTOR_vidMoveReverse(const _strMOTORCONFIG_t *PTR_strMOTORConfig)
{
	DIO_vidWritePin(PTR_strMOTORConfig->OUT1_PORT, PTR_strMOTORConfig->OUT1_PIN, LOW);
	DIO_vidWritePin(PTR_strMOTORConfig->OUT2_PORT, PTR_strMOTORConfig->OUT2_PIN, HIGH);
}
