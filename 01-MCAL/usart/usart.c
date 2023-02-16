/*
 * usart.c
 *
 *  Created on: Jul 21, 2019
 *      Author: mohamed
 */
#include "BIT_math.h"
#include "Types.h"
#include "usart.h"
#include "usart_atmega328p_reg.h"
void init_usart(u32_t baud_rate)
{
	u16_t baud;
	/*async mode */
	/*Parity Mode Disabled*/
	CLR_BIT(UCSR0C , UPM1);
	CLR_BIT(UCSR0C , UPM0);
	/*conf stop bit 1 stop bit*/
	CLR_BIT(UCSR0C , USBS);
	/*conf data size*/
	CLR_BIT(UCSR0B,UCSZ02);
	SET_BIT(UCSR0C,UCSZ1);
	SET_BIT(UCSR0C,UCSZ0);
	// use normal speed
	CLR_BIT(UCSR0A , U2X0);
	baud = (F_CPU/(16UL*baud_rate))-1;
    UBRR0H = (u8_t)(baud>>8);
	UBRR0L = (u8_t)baud;
	/*enable transmitter and receiver*/
	SET_BIT(UCSR0B,RXEN0);
	SET_BIT(UCSR0B,TXEN0);
}
void usart_write_char(u8_t chr)
{
    // wait for buffer to be embty
	while (GET_BIT(UCSR0A , UDRE0) == 0 );
	/* Put data into buffer, sends the data */
	UDR0 = chr;
}
void usart_write_text(u8_t* txt)
{
   u8_t i = 0;
   while(txt[i] != '\0')
   {
	   usart_write_char(txt[i]);
	   i++;
   }
}
u8_t usart_read_char(void)
{
	/* Wait for data to be received */
	while ( GET_BIT(UCSR0A , RXC0) == 0 );
	return UDR0;
}
bool_t usart_data_available(void)
{
  // 0 means not data
  // 1 means data
   return GET_BIT(UCSR0A , RXC0);
}

void usart_write_number(u32_t u32Number)
{
	u8 u8arr[32];
	sprintf(u8arr, "%d", u32Number);
	usart_write_text(u8arr);
}
