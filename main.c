#include "ACTUATORS.h"
#include "DISPLAY.h"
#include "DETECTORS.h"
#include "APPLICATION.h"

int main(void)
{
    while (1)
    {
        APP_Arr[APP_State]();        
    }
    return 0;
}