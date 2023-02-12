#ifndef _APP_DISPLAY_H_ 
#define _APP_DISPLAY_H_

#include "Types.h"
#include "BIT_math.h"

#include "LCD_interface.h"

typedef enum
{
    forward,
    right,
    left,
    stopped
}_enuDirction_t_;

void DISPLAY_vidInit(void);
void DISPALY_vidShowDirection(void);
void DISPLAY_vidSetDirection(_enuDirction_t_ enuDirection);

#endif
