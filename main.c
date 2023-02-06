#define F_CPU 16000000UL

#include "SERVO_interface.h"
#include "util/delay.h"
#include "LCD_interface.h"
#include "MOTOR_interface.h"
#include "ULTRASONIC_interface.h"

const _strSERVO_t mySERVO1 = {SERVO_CHANNEL_1};
const _strSERVO_t mySERVO2 = {SERVO_CHANNEL_2};
const _strMOTORCONFIG_t Motor1 =
{
		GPIOD,
		PIN0,
		GPIOD,
		PIN1,
		GPIOD,
		PIN6
};
const _strMOTORCONFIG_t Motor2 =
{
		GPIOD,
		PIN2,
		GPIOD,
		PIN3,
		GPIOD,
		PIN5
};

int main(void)
{
	LCD_vidInit();
	LCD_vidDisplayString("HELLO WORLD!");
	SERVO_vidInit(&mySERVO1);
	SERVO_vidInit(&mySERVO2);
	MOTOR_voidInit(&Motor1);
	MOTOR_voidInit(&Motor2);
	MOTOR_vidSetSpeed(&Motor1,30);
	MOTOR_vidSetSpeed(&Motor2,70);
	MOTOR_vidMoveForward(&Motor1);
	MOTOR_vidMoveReverse(&Motor2);
	SERVO_vidWrite(&mySERVO1,90);
	SERVO_vidWrite(&mySERVO2,0);
	_delay_ms(1000);
	SERVO_vidWrite(&mySERVO1,0);
	SERVO_vidWrite(&mySERVO2,180);
	_delay_ms(1000);
	SERVO_vidWrite(&mySERVO1,180);
	SERVO_vidWrite(&mySERVO2,90);
	_delay_ms(1000);

	ULTRASONIC_vidInit();
	while(1)
	{
		LCD_vidClearScreen();
		LCD_vidDisplayNumber(172);
		_delay_ms(1000);
	}
return 0;
}
