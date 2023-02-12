#include "DISPLAY.h"
u8 dirctionState;
void displayDirctionState(void)
{
    switch (_enuDirction_t_)
    {
    case (_enuDirction_t_==0):
    {void LCD_vidDisplayString("MOVEING!!");
        
        break;
    }
    case (_enuDirction_t_==1):
    void LCD_vidDisplayString("SPINNING RIGHT");
    {
        break;
    }
    case (_enuDirction_t_==2):
    {
        void LCD_vidDisplayString("SPINNING LEFT");
        
        break;
    }
    case (_enuDirction_t_==3):
    {
        void LCD_vidDisplayString("STOPPED!!");
        
        break;
    }
    default:
        break;
    }

    
}