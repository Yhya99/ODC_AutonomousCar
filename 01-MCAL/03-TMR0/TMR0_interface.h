#ifndef _MCAL_TMR0_INTERFACE_H_
#define _MCAL_TMR0_INTERFACE_H_

#include "DIO_interface.h"

typedef enum
{
	TMR0_NORMAL_MODE = 0,
	TMR0_PWM_PHASE_CORRECT_MODE,
	TMR0_CTC_OCR1A_MODE,
	TMR0_FAST_PWM_MODE,
	TMR0_PWM_PHASE_CORRECT_OCR1A_MODE = 5,
	TMR0_FAST_PWM_OCR1A_MODE = 7
}_enuTMR0MODE_t;

typedef enum
{
	OCR0A_DISCONNECTED = 0,
	OCR0A_TOGGLE,
	OCR0A_CLEAR,
	OCR0A_SET,
}_enuTMR0OCR0AMODE_t;

typedef enum
{
	OCR0B_DISCONNECTED = 0,
	OCR0B_TOGGLE,
	OCR0B_CLEAR,
	OCR0B_SET,
}_enuTMR0OCR0BMODE_t;

typedef enum
{
	TMR0_PSC_1 = 1,
	TMR0_PSC_8,
	TMR0_PSC_64,
	TMR0_PSC_256,
	TMR0_PSC_1024,
	TMR0_EXT_FALLING_EDGE,
	TMR0_EXT_RISING_EDGE
}_enuTMR0PSC_t;

typedef enum
{
	OC0A,
	OC0B
}_enuTMR0PWMCHANNEL_t;

typedef struct
{
	_enuTMR0MODE_t enuTMR0_MODE;
	_enuTMR0OCR0AMODE_t enuTMR0OCR0A_MODE;
	_enuTMR0OCR0BMODE_t enuTMR0OCR0B_MODE;
	_enuTMR0PSC_t enuTMR0PSC;
}_strTMR0CONFIG_t;

// FUNCTIONS PROTOTYPING
void TMR0_VidInit(const _strTMR0CONFIG_t *Ptr_strTMR0Config);

void TMR0_vidPWMWrite(_enuTMR0PWMCHANNEL_t enuTMR0PWMChannel,u16 u16DutyCycle);
void TMR0_vidClear();

#endif