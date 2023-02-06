#ifndef _MCAL_TMR1_PRIVATE_H_
#define _MCAL_TMR1_PRIVATE_H_

#define TMR1     ((_strTMR1_t*)0x36)

typedef struct
{
      u8 WGM1_01:2;
      u8 RESERVED:2;
      u8 COM1B:2;
      u8 COM1A:2;
}_strTCCR1A_t;

typedef union
{
      u8 u8REG;
      _strTCCR1A_t strBITS;   
}_uniTCCR1A_t;

typedef struct
{
      u8 CS1:3;
      u8 WGM1_23:2;
      u8 RESERVED:1;
      u8 ICES1:1;
      u8 ICNC1:1;
}_strTCCR1B_t;

typedef union
{
      u8 u8REG;
      _strTCCR1B_t strBITS;   
}_uniTCCR1B_t;

typedef struct
{
      u8 RESERVED:6;
      u8 FOC1B:1;
      u8 FOC1A:1;
}_strTCCR1C_t;

typedef union
{
      u8 u8REG;
      _strTCCR1C_t strBITS;   
}_uniTCCR1C_t;

typedef struct
{
      u8 TOIE1:1;
      u8 OCIE1A:1;
      u8 OCIE1B:1;
      u8 RESERVED:2;
      u8 ICIE1:1;
}_strTIMSK1_t;

typedef union
{
      u8 u8REG;
      _strTIMSK1_t strBITS;   
}_uniTIMSK1_t;
      
typedef struct
{
      u8 TOV1:1;
      u8 OCF1A:1;
      u8 OCF1B:1;
      u8 RESERVED:2;
      u8 ICF1:1;
}_strTIFR1_t;


typedef union
{
      u8 u8REG;
      _strTIFR1_t strBITS;   
}_uniTIFR1_t;

typedef struct
{
     volatile _uniTIFR1_t    TIFR1; // 0x36
     	 	  u8             RESERVED1[56];
     volatile _uniTIMSK1_t   TIMSK1; //0x6f
     	 	  u8             RESERVED2[16];
     volatile _uniTCCR1A_t   TCCR1A; //0x80
     volatile _uniTCCR1B_t   TCCR1B;
     volatile _uniTCCR1C_t   TCCR1C;
     	 	  u8             RESERVED3;
	 volatile u8             TCNT1L;
	 volatile u8             TCNT1H;
	 volatile u8             ICR1L;
	 volatile u8             ICR1H;
	 volatile u8             OCR1AL;
	 volatile u8             OCR1AH;
	 volatile u8             OCR1BL;
	 volatile u8             OCR1BH;
}_strTMR1_t;


#endif
