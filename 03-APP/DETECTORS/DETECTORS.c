#include "DETECTORS.h"
#include "SERVO_interface.h"
#include "ULTRASONIC_interface.h"
#include "util/delay.h"

u8 min_distant = 14;
const _strSERVO_t DECT_strSERVO =
{
		SERVO_CHANNEL_1
};

void DECT_vidInit(void)
{
	ULTRASONIC_vidInit();
	SERVO_vidInit(&DECT_strSERVO);
	SERVO_vidWrite(&DECT_strSERVO,90);

}
u8 DECT_Scan(void)
{
    u8 obstacles = 0;
    if (ULTRASONIC_doubleGetDistance() > min_distant)
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
    SERVO_vidWrite(&DECT_strSERVO,0);
    _delay_ms(1000);
    u16 Right_distance = ULTRASONIC_doubleGetDistance();
    _delay_ms(50);
    SERVO_vidWrite(&DECT_strSERVO,180);
    _delay_ms(1000);
    u16 Left_distance = ULTRASONIC_doubleGetDistance();
    _delay_ms(50);
    if (Right_distance > min_distant)
    {
    	enumDirection = RIGHT;
    }
    else if (Left_distance > min_distant)
    {
    	enumDirection = LEFT;
    }
    else
    {
    	enumDirection = Direction_ERROR;
    }
    SERVO_vidWrite(&DECT_strSERVO,90);
    _delay_ms(500);
    return enumDirection;
}
