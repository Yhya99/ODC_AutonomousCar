#include "Types.h"
#include "BIT_MATH.h"
#include "APPLICATION.h"

//1
void APP_vidInitSate(void)
{
// motor config
 MOTOR_voidInit(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
 MOTOR_vidSetSpeed(const _strMOTORCONFIG_t *PTR_strMOTORConfig, u8 u8Speed);
 MOTOR_voidInit(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
 MOTOR_vidSetSpeed(const _strMOTORCONFIG_t *PTR_strMOTORConfig, u8 u8Speed);
// lcd
 LCD_vidInit(void)
 _enuState_t = stopState;
}

//2
void APP_vidStopSate(void)
{
 MOTOR_vidSetSpeed(const _strMOTORCONFIG_t *PTR_strMOTORConfig, u8 u8Speed = 0);
 MOTOR_vidSetSpeed(const _strMOTORCONFIG_t *PTR_strMOTORConfig, u8 u8Speed = 0);
 state = ScanDirState;
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
    if(DECT_ScanDirction() == LEFT)
    {
        _enuState_t = APP_vidSpinLift;
    }else if(DECT_ScanDirction() == RIGHT)
    {
        _enuState_t = APP_vidSpinRight;
    }else
    {

    }
}

//6
void APP_vidSpinRight(void)
{
    ACT_vidSpinRight();
    _enuState_t = runState;
}

//7
void APP_vidSpinLift(void)
{
    ACT_vidSpinLeft();
    _enuState_t = runState;
}



void APP_vidRun(void)
{ 
    ACT_vidRun();
    _enuState_t= ScanDirState;
}


