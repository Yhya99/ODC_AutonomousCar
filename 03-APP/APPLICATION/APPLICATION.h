#ifndef _APP_APPLICATION_H_ 
#define _APP_APPLICATION_H_

#include "Types.h"


#include "ACTUATORS.h"
#include "DETECTORS.h"
#include "DISPLAY.h"


typedef enum
{
	InitSate =0,
	stopState =1,
	ScanDirState=2,
	CheckMovingState=3,
	ChooseDirState=4,
	SpinRightState=5,
	SpinLiftState=6,
	runState=7
} _enuState_t;

_enuState_t APP_enuGitState(void);
//0
void APP_vidInitSate(void);
//1
void APP_vidStopSate(void);
//2
void APP_vidScan(void);
//3
void APP_CheckMoving(void);
//4
void APP_vidChooseDir(void);
//5
void APP_vidSpinRight(void);
//6
void APP_vidSpinLift(void);
//7
void APP_vidRun(void);

//showing data on display
void APP_vidShowData(void);


#endif
