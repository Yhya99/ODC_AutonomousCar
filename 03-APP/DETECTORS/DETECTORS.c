#include "DETECTORS.h"
#include "SERVO_interface.h"
#include "ULTRASONIC_interface.h"

u8 min_distant = 10;
const _strSERVO_t DECT_strSERVO =
{
		SERVO_CHANNEL_1
};

u8 DECT_Scan(void)
{
    u8 obstacles ;
    ULTRASONIC_vidInit();
    if (ULTRASONIC_u16CalculateDistance() > min_distant)
    {
    	obstacles = 0;
    }
    else
    {
    	obstacles = 1;
    }
    return obstacles;
}

_DECT_enumDirection_t DECT_ScanDirction(void)
{
    _DECT_enumDirection_t enumDirection;
    SERVO_vidInit(&DECT_strSERVO);
    SERVO_vidWrite(&DECT_strSERVO,0);
    ULTRASONIC_vidInit();
    u8 Right_distance = ULTRASONIC_u16CalculateDistance();
    SERVO_vidInit(&DECT_strSERVO);
    SERVO_vidWrite(&DECT_strSERVO,180);
    ULTRASONIC_vidInit();
    u8 Left_distance = ULTRASONIC_u16CalculateDistance();

    if (Right_distance > min_distant)
    {
    	enumDirection = RIGHT;
    }
    else if (Left_distance> min_distant)
    {
    	enumDirection = LEFT;
    }
    else
    {
    	enumDirection = Direction_ERROR;
    }
    return enumDirection;
}
