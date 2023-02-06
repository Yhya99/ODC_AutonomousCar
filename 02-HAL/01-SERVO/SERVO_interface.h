#ifndef _HAL_SERVO_INTERFACE_H_
#define _HAL_SERVO_INTERFACE_H_

#include "Types.h"

typedef enum
{
	SERVO_CHANNEL_1,
	SERVO_CHANNEL_2
}_enuSERVOCHANNEL_t;

typedef struct
{
	_enuSERVOCHANNEL_t enuSERVOChannel;
}_strSERVO_t;

void SERVO_vidInit(const _strSERVO_t *PTR_strSERVO);

void SERVO_vidWrite(const _strSERVO_t *PTR_strSERVO,u8 u8Degree);

#endif
