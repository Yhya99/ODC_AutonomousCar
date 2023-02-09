#include "ACTUATORS.h"
#iclude "MOTOR_interface.h"


static u8 u8isMoving = 0;

u8 Act_isMoving ()
{
   return u8isMoving
}

void ACT_vidStop(void)
{
    MOTOR_vidStop(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
    MOTOR_vidStop(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
    u8isMoving =0;
}

void ACT_vidRun(void)
{
    MOTOR_vidMoveForward(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
    MOTOR_vidMoveForward(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
    u8isMoving =1;
}

void ACT_leftSpin(){
    MOTOR_vidMoveForward(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
    MOTOR_vidMoveReverse(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
    _delay_ms(500);
    MOTOR_vidStop(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
    MOTOR_vidStop(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
}

void ACT_rightSpin() {
    MOTOR_vidMoveForward(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
    MOTOR_vidMoveReverse(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
    _delay_ms(500);
    MOTOR_vidStop(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
    MOTOR_vidStop(const _strMOTORCONFIG_t *PTR_strMOTORConfig);
}

    