//#include "DETECTORS.h"
//#include "SERVO_interface.h"
//#include "ULTRASONIC_interface.h"
//
//const _strSERVO_t DECT_strSERVO =
//{
//    //write withch channel
//}
//
//u8 DECT_Scan(void)
//{
//    u8 obstacles ;
//    ULTRASONIC_vidInit();
//    if (ULTRASONIC_u16CalculateDistance() > min_distant)
//    { obstacles = 0;}
//    else
//    { obstacles = 1;}
//    return obstacles;
//}
//
//_DECT_enumDirection_t DECT_ScanDirction(void)
//{
//    _DECT_enumDirection_t DECT_enumDirection
//    SERVO_vidInit(&DECT_strSERVO);
//    void SERVO_vidWrite(&DECT_strSERVO,0);
//    ULTRASONIC_vidInit(void);
//    u8 Right_distance = ULTRASONIC_u16CalculateDistance();
//    SERVO_vidInit(&DECT_strSERVO);
//    void SERVO_vidWrite(&DECT_strSERVO,180);
//    ULTRASONIC_vidInit(void);
//    u8 Left_distance = ULTRASONIC_u16CalculateDistance();
//
//    if (Right_distance > distance)
//    {
//        _DECT_enumDirection_t = RIGHT;
//    }
//    elif (Left_distance> distance)
//    {
//        _DECT_enumDirection_t = LEFT;
//    }
//    else
//    {
//       _DECT_enumDirection_t = Direction_ERROR;
//    }
//    return _DECT_enumDirection_t;
//}
