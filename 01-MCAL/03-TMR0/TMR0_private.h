#ifndef _MCAL_TMR0_PRIVATE_H_
#define _MCAL_TMR0_PRIVATE_H_

#define TMR0 	((_strTMR0_t*)0x44)

typedef struct
{
	u8 WGM0_01:2;
	u8 reserved:2;
	u8 COM0B:2;
	u8 COM0A:2;
}_strTCCR0A_t;

typedef union
{
	u8 			 u8REG;
	_strTCCR0A_t strBITS;	
}_uniTCCR0A_t;

typedef struct
{
	u8 CS0:3;
	u8 WGM0_2:1;
	u8 reserved:2;
	u8 FOC0A:1;
	u8 FOC0B:1;
}_strTCCR0B_t;

typedef union
{
	u8 			 u8REG;
	_strTCCR0B_t strBITS;	
}_uniTCCR0B_t;


typedef struct
{
	u8 TOIE0:1;
	u8 OCIE0A:1;
	u8 OCIE0B:1;	
}_strTIMSK0_t;

typedef union
{
	u8 			 u8REG;
	_strTIMSK0_t strBITS;	
}_uniTIMSK0_t;

typedef struct
{
	volatile _uniTCCR0A_t	TCCR0A;
	volatile _uniTCCR0B_t	TCCR0B;
	volatile u8				TCNT0;
	volatile u8				OCR0A;
	volatile u8				OCR0B;
			 u8 			reserved[37];
	volatile _uniTIMSK0_t	TIMSK0;
}_strTMR0_t;

#endif
