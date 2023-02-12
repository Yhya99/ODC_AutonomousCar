#ifndef _APP_ACTUATORS_H_
#define _APP_ACTUATORS_H_

#include "Types.h"

void ACT_vidInit(void);
u8 Act_isMoving (void);
void ACT_vidStop(void);
void ACT_vidRun(void);
void ACT_vidSpinLeft(void);
void ACT_vidSpinRight(void);

#endif
