
#include "LCD_interface.h"

#include "DISPLAY.h"


_enuDirction_t_ enuDirectionState = stopped;

void DISPLAY_vidInit(void)
{
	LCD_vidInit();
}

void DISPLAY_vidSetDirection(_enuDirction_t_ enuDirection)
{
	enuDirectionState = enuDirection;
}

void DISPALY_vidShowDirection(void)
{
    switch (enuDirectionState)
    {
    case forward:
    	LCD_vidDisplayString("MOVEING!!");
        break;
    case right:
    	LCD_vidDisplayString("SPINNING RIGHT");
        break;
    case left:
        LCD_vidDisplayString("SPINNING LEFT");
        break;
    case stopped:
        LCD_vidDisplayString("STOPPED!!");
        break;
    default:
        break;
    }
}
