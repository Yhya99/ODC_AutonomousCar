#ifndef _APP_DETECTORS_H_  
#define _APP_DETECTORS_H_

#include "Types.h"
#include "BIT_MATH.h"
typedef enum
{
    RIGHT,
    LEFT,
    Direction_ERROR
}_DECT_enumDirection_t;

void DECT_vidInit(void);

u8 DECT_Scan(void);
_DECT_enumDirection_t DECT_ScanDirction(void);

#endif
