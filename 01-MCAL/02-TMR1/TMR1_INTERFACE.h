#ifndef _MCAL_TMR1_INTERFACE_H_
#define _MCAL_TMR1_INTERFACE_H_

#include "Types.h"

typedef enum
{
	TMR1_NORMAL_MODE = 0,
	TMR1_PWM_PHASE_CORRECT_8BIT_MODE,
	TMR1_PWM_PHASE_CORRECT_9BIT_MODE,
	TMR1_PWM_PHASE_CORRECT_10IT_MODE,
	TMR1_CTC_OCR1A_MODE,
	TMR1_FAST_PWM_8BIT_MODE,
	TMR1_FAST_PWM_9BIT_MODE,
	TMR1_FAST_PWM_10BIT_MODE,
	TMR1_PWM_PHASE_FREQUENCY_CORRECT_ICR1_MODE,
	TMR1_PWM_PHASE_FREQUENCY_CORRECT_OCR1A_MODE,
	TMR1_PWM_PHASE_CORRECT_ICR1_MODE,
	TMR1_PWM_PHASE_CORRECT_OCR1A_MODE,
	TMR1_CTC_ICR1_MODE=12,
	TMR1_FAST_PWM_ICR1_MODE=14,
	TMR1_FAST_PWM_OCR1A_MODE=15
}_enuTMR1MODE_t;

typedef enum
{
	OCR1A_DISCONNECTED = 0,
	OCR1A_TOGGLE,
	OCR1A_CLEAR,
	OCR1A_SET,
}_enuTMR1OCR1AMODE_t;

typedef enum
{
	OCR1B_DISCONNECTED = 0,
	OCR1B_TOGGLE,
	OCR1B_CLEAR,
	OCR1B_SET,
}_enuTMR1OCR1BMODE_t;

typedef enum
{
	TMR1_PSC_1 = 1,
	TMR1_PSC_8,
	TMR1_PSC_64,
	TMR1_PSC_256,
	TMR1_PSC_1024,
	EXT_FALLING_EDGE,
	EXT_RISING_EDGE
}_enuTMR1PSC_t;

typedef enum
{
	IC_FALLING_EDGE,
	IC_RISING_EDGE,
}_enuTMR1ICES_t;

typedef enum
{
	ICNC_DISABLE,
	ICNC_ENABLE,
}_enuTMR1ICNC_t;

typedef enum
{
	OC1A,
	OC1B
}_enuTMR1PWMCHANNEL_t;


typedef struct
{
	_enuTMR1MODE_t enuTMR1_MODE;
	_enuTMR1OCR1AMODE_t enuTMR1OCR1A_MODE;
	_enuTMR1OCR1BMODE_t enuTMR1OCR1B_MODE;
	_enuTMR1ICNC_t enuTMR1ICNC_MODE;
	_enuTMR1PSC_t enuTMR1PSC;
}_strTMR1CONFIG_t;

// FUNCTIONS PROTOTYPING
void TMR1_VidInit(const _strTMR1CONFIG_t *Ptr_strTMR1Config);
u16 TMR1_u16ICREAD(_enuTMR1ICES_t enuTMR1ICES);
void TMR1_vidClear(void);
void TMR1_vidICRWrite(u16 u16TMR1ICRValue);
void TMR1_vidPWMWrite(_enuTMR1PWMCHANNEL_t enuTMR1PWMChannel, u16 u16DutyCycle);

void TMR1_OVF_InterruptEnable(void);

void TMR1_OVF_InterruptDisable(void);

void TMR1_OCR1A_InterruptEnable(void);

void TMR1_OCR1A_InterruptDisable(void);

void TMR1_OCR1B_InterruptEnable(void);

void TMR1_OCR1B_InterruptDisable(void);

void TMR1_ICU_InterruptEnable(void);

void TMR1_ICU_InterruptDisable(void);

void TMR1_OVF_SetCallBack(void(*LocalFptr)(void));

void TMR1_OCR1A_SetCallBack(void(*LocalFptr)(void));

void TMR1_OCR1B_SetCallBack(void(*LocalFptr)(void));

void TMR1_ICU_SetCallBack(void(*LocalFptr)(void));

#endif
