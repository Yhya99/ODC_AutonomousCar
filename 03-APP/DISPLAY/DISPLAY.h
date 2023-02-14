#ifndef _APP_DISPLAY_H_ 
#define _APP_DISPLAY_H_

#include "Types.h"
#include "BIT_math.h"

#include "LCD_interface.h"

typedef enum
{
    DISPLAY_FORWARD,
	DISPLAY_RIGHT,
	DISPLAY_LEFT,
	DISPLAY_STOPPED
}_enuDispalyDirction_t_;

void DISPLAY_vidInit(void);
void DISPALY_vidShowDirection(void);
void DISPLAY_vidSetDirection(_enuDispalyDirction_t_ enuDirection);

#endif
