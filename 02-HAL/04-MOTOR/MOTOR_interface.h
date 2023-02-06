#ifndef _HAL_MOTOR_INTERFACE_H_
#define _HAL_MOTOR_INTERFACE_H_

#include "DIO_interface.h"

typedef struct
{
	_strGPIO_t *OUT1_PORT;
	_enuPINx_t OUT1_PIN;
	_strGPIO_t *OUT2_PORT;
	_enuPINx_t OUT2_PIN;
	_strGPIO_t *ENABLE_PORT;
	_enuPINx_t ENABLE_PIN;
}_strMOTORCONFIG_t;

void MOTOR_voidInit(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
void MOTOR_vidSetSpeed(const _strMOTORCONFIG_t *PTR_strMOTORConfig, u8 u8Speed);
void MOTOR_vidStop(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
void MOTOR_vidMoveForward(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
void MOTOR_vidMoveReverse(const _strMOTORCONFIG_t *PTR_strMOTORConfig);



#endif
