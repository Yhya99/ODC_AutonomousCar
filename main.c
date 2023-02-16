#define F_CPU 16000000UL


#include "APPLICATION.h"
void (*APP_Arr[]) (void) = {APP_vidInitSate,APP_vidStopSate,APP_vidScan,APP_CheckMoving,APP_vidChooseDir,APP_vidSpinRight,APP_vidSpinLift,APP_vidRun};


//#include "DIO_interface.h"
//#include "usart.h"
//#include "DETECTORS.h"
//#include "ULTRASONIC_interface.h"
//#include "TMR1_private.h"
//#include "DIO_interface.h"
#include "util/delay.h"

int main(void)
{
//	init_usart(19200);
	while (1)
    {
		(*APP_Arr[APP_enuGitState()])();
//		APP_vidShowData();
		_delay_ms(10);
    }
    return 0;
}

