#include "../../03-APP/ACTUATORS/ACTUATORS.h"

#include "MOTOR_interface.h"
#include "util/delay.h"

u8 u8isMoving = 0;
_strMOTORCONFIG_t ACT_strMotor1=
{
    GPIOD,
    PIN4,
    GPIOD,
    PIN7,
    GPIOD,
    PIN6
};

_strMOTORCONFIG_t ACT_strMotor2=
{
    GPIOD,
    PIN2,
    GPIOD,
    PIN3,
    GPIOD,
    PIN5
};
void ACT_vidInit(void)
{
    u8 u8Speed =80;
    MOTOR_vidInit(&ACT_strMotor1);
    MOTOR_vidInit(&ACT_strMotor2);
    MOTOR_vidSetSpeed(&ACT_strMotor1, 250);
    MOTOR_vidSetSpeed(&ACT_strMotor2, 250);
}

u8 Act_isMoving ()
{
   return u8isMoving;
}

void ACT_vidStop(void)
{
    MOTOR_vidStop(&ACT_strMotor1);
    MOTOR_vidStop(&ACT_strMotor2);
    u8isMoving = 0;
}

void ACT_vidRun(void)
{
    MOTOR_vidMoveForward(&ACT_strMotor1);
    MOTOR_vidMoveForward(&ACT_strMotor2);
    u8isMoving = 1;
}

void ACT_vidSpinLeft(void){
    MOTOR_vidMoveForward(&ACT_strMotor2);
    MOTOR_vidMoveReverse(&ACT_strMotor1);
    _delay_ms(375);
    MOTOR_vidStop(&ACT_strMotor1);
    MOTOR_vidStop(&ACT_strMotor2);
}

void ACT_vidSpinRight(void) {
    MOTOR_vidMoveForward(&ACT_strMotor1);
    MOTOR_vidMoveReverse(&ACT_strMotor2);
    _delay_ms(375);
    MOTOR_vidStop(&ACT_strMotor1);
    MOTOR_vidStop(&ACT_strMotor2);
}

    
