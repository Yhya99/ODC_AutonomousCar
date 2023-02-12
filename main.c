#include "ACTUATORS.h"
#include "DISPLAY.h"
#include "DETECTORS.h"
#include "APPLICATION.h"

int main(void)
{
    while (1)
    {
        //displayDirctionState();
        //APP_Arr[_enuState_t]();
        APP_vidInitSate();
        APP_vidRun();
    }
    return 0;
}