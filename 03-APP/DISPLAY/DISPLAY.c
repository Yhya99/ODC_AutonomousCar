
#include "LCD_interface.h"

#include "DISPLAY.h"


_enuDispalyDirction_t_ enuDirectionState = DISPLAY_STOPPED;

void DISPLAY_vidInit(void)
{
	LCD_vidInit();
}

void DISPLAY_vidSetDirection(_enuDispalyDirction_t_ enuDirection)
{
	enuDirectionState = enuDirection;
}

void DISPALY_vidShowDirection(void)
{
	LCD_vidClearScreen();
    switch (enuDirectionState)
    {
    case DISPLAY_FORWARD:
    	LCD_vidDisplayString("MOVEING!!");
        break;
    case DISPLAY_RIGHT:
    	LCD_vidDisplayString("SPINNING RIGHT");
        break;
    case DISPLAY_LEFT:
        LCD_vidDisplayString("SPINNING LEFT");
        break;
    case DISPLAY_STOPPED:
        LCD_vidDisplayString("STOPPED!!");
        break;
    default:
        break;
    }
}
