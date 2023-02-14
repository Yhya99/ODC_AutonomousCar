#include "APPLICATION.h"
void (*APP_Arr[]) (void) = {APP_vidInitSate,APP_vidStopSate,APP_vidScan,APP_CheckMoving,APP_vidChooseDir,APP_vidSpinRight,APP_vidSpinLift,APP_vidRun};

int main(void)
{
    while (1)
    {
        APP_Arr[APP_enuGitState()]();
        APP_vidShowData();
    }
    return 0;
}
