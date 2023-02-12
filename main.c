#include "ACTUATORS.h"
#include "DISPLAY.h"
#include "DETECTORS.h"
#include "APPLICATION.h"

int main(void)
{
    APP_vidInitSate();
    while (1)
    {
        //displayDirctionState();
        //APP_Arr[_enuState_t]();
        APP_vidRun();

    }
    return 0;
}