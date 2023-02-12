#include "APPLICATION.h"

int main(void)
{
    APP_vidInitSate();
    while (1)
    {
        //APP_Arr[_enuState_t]();
        APP_vidRun();
        APP_vidShowData();
    }
    return 0;
}
