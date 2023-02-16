#include "APPLICATION.h"
#include "ULTRASONIC_interface.h"
#include "LCD_interface.h"
#include "util/delay.h"
_enuState_t APP_enuState = InitSate;

//1
_enuState_t APP_enuGitState(void)
{
	return APP_enuState;
}
void APP_vidInitSate(void)
{
    ACT_vidInit();
    DECT_vidInit();
    DISPLAY_vidInit();
    APP_enuState = stopState;
    LCD_vidClearScreen();
	LCD_vidDisplayString("INIT state");
//	_delay_ms(10);

}

//2
void APP_vidStopSate(void)
{
	DISPLAY_vidSetDirection(DISPLAY_STOPPED);
	ACT_vidStop();
	APP_enuState = ScanDirState;
	LCD_vidClearScreen();
	LCD_vidDisplayString("Stopped state");
//	_delay_ms(10);

}

//3
void APP_vidScan(void)
{
	LCD_vidClearScreen();
	LCD_vidDisplayString("Scan state");
//	_delay_ms(10);

    if (DECT_Scan() == 1)
    {
    	APP_enuState = CheckMovingState;
    }
    else
    {
    	APP_enuState =  runState;
    }
}

//4
void APP_CheckMoving()
{
	LCD_vidClearScreen();
	LCD_vidDisplayString("check moving state");
//	_delay_ms(10);

    if (Act_isMoving() == 1)
    {
    	APP_enuState = stopState;
    }
    else
    {
    	APP_enuState = ChooseDirState;
    }
}

//5
void APP_vidChooseDir(void)
{
    LCD_vidClearScreen();
    LCD_vidDisplayString("Scan direction state");
//    _delay_ms(10);
    _DECT_enumDirection_t enuDirectionScaned = DECT_ScanDirction();
    if(enuDirectionScaned == LEFT)
    {
    	APP_enuState = SpinLiftState;
    }
    else if(enuDirectionScaned == RIGHT)
    {
    	APP_enuState = SpinRightState;
    }
    else
    {

    }
}

//6
void APP_vidSpinRight(void)
{
	DISPLAY_vidSetDirection(DISPLAY_RIGHT);
    ACT_vidSpinRight();
    APP_enuState = runState;
    LCD_vidClearScreen();
    LCD_vidDisplayString("Spiniing Right state");

}

//7
void APP_vidSpinLift(void)
{
	DISPLAY_vidSetDirection(DISPLAY_LEFT);
	ACT_vidSpinLeft();
    APP_enuState = runState;
    LCD_vidClearScreen();
    LCD_vidDisplayString("Spiniing left state");

}


//8
void APP_vidRun(void)
{ 
	DISPLAY_vidSetDirection(DISPLAY_FORWARD);
    ACT_vidRun();
    APP_enuState= ScanDirState;
    LCD_vidClearScreen();
    LCD_vidDisplayString("Running state");

}


void APP_vidShowData(void)
{
	DISPALY_vidShowDirection();
}
