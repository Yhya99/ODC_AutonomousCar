#include "APPLICATION.h"

_enuState_t APP_enuState = InitSate;

//1
void APP_vidInitSate(void)
{
    ACT_vidInit();
    DISPLAY_vidInit();
    APP_enuState = stopState;
}

//2
void APP_vidStopSate(void)
{
	DISPLAY_vidSetDirection(stopped);
	ACT_vidStop();
	APP_enuState = ScanDirState;
}

//3
//void APP_scan(void)
//{
//    if (DECT_Scan() == 1)
//    {
//    	APP_enuState = CheckMovingState;
//    }
//    else
//    {
//    	APP_enuState =  runState;
//    }
//}

//4
void APP_CheckMoving()
{
    if (Act_isMoving() == 1)
    {
    	APP_enuState = stopState;
    }
    else
    {
    	APP_enuState = ScanDirState;
    }
}

//5
//void APP_vidChooseDir(void)
//{
//    if(DECT_ScanDirction() == left)
//    {
//    	APP_enuState = SpinLiftState;
//    }
//    else if(DECT_ScanDirction() == right)
//    {
//    	APP_enuState = SpinRightState;
//    }
//    else
//    {
//
//    }
//}

//6
void APP_vidSpinRight(void)
{
	DISPLAY_vidSetDirection(right);
    ACT_vidSpinRight();
    APP_enuState = runState;
}

//7
void APP_vidSpinLift(void)
{
	DISPLAY_vidSetDirection(left);
	ACT_vidSpinLeft();
    APP_enuState = runState;
}


//8
void APP_vidRun(void)
{ 
	DISPLAY_vidSetDirection(forward);
    ACT_vidRun();
    APP_enuState= ScanDirState;
}


void APP_vidShowData(void)
{
	DISPALY_vidShowDirection();
}
