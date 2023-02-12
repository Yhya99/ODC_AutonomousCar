#include "APPLICATION.h"

//1
void APP_vidInitSate(void)
{
    ACT_vidInit();
    LCD_vidInit();
    _enuState_t = stopState;
}

//2
void APP_vidStopSate(void)
{
_enuDirction_t_=stoped;
ACT_vidStop();
 _enuState_t = ScanDirState;
 
}

//3
void APP_scan(void)
{
    if (DECT_Scan() == 1)
    {
        _enuState_t = CheckMovingState;
    }
    else 
    {
        _enuState_t =  runState;
    }
}

//4
void APP_CheckMoving()
{
    if (Act_isMoving == 1) 
    { 
        _enuState_t = stopState;
    }
    else 
    {
        _enuState_t = ScanDirState;
    }
}

//5
void APP_vidChooseDir(void)
{
    if(DECT_ScanDirction() == left)
    {
        _enuState_t = APP_vidSpinLift;
    }
    else if(DECT_ScanDirction() == right)
    {
        _enuState_t = APP_vidSpinRight;
    }
    else
    {

    }
}

//6
void APP_vidSpinRight(void)
{   
    _enuDirction_t_=right;
    ACT_vidSpinRight();
    _enuState_t = runState;
    
}

//7
void APP_vidSpinLift(void)
{
    _enuDirction_t_=left;
    ACT_vidSpinLeft();
    _enuState_t = runState;
    

}


//8
void APP_vidRun(void)
{ 
    _enuDirction_t_=forward;
    ACT_vidRun();
    _enuState_t= ScanDirState;
    
}


