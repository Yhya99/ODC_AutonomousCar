#ifndef _APP_APPLICATION_H_ 
#define _APP_APPLICATION_H_

#include "Types.h"
#include "BIT_MATH.h"

u8 is_moving = 0;
u8 distance= 10;
u8 APP_state = InitSate;

typedef enum
{
	InitSate = 0,
	stopState = 1,
	runState,
	ScanDirState,
	CheckMovingState,
} _enuState_t;

void APP_vidInitSate(void);
void APP_vidStopSate(void);
void APP_vidScan(void);
void APP_vidChooseDir(void);
void APP_vidRun(void);
void APP_scan(void);
void APP_isMoving(void);

void (*APP_Arr[]) (void) = {APP_vidInitSate,APP_vidStopSate,APP_vidScan,APP_vidChooseDir,APP_vidRun}
#endif