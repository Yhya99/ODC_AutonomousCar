#ifndef _HAL_LCD_INTERFACE_H_
#define _HAL_LCD_INTERFACE_H_

#include "types.h"

void LCD_vidInit(void);
void LCD_vidDisplayCharacter(u8 u8Char);
void LCD_vidDisplayString(u8 *u8PtrString);
void LCD_vidDisplayNumber(u32 u32Number);
void LCD_vidClearScreen(void);
void LCD_vidMoveCurserLeft(void);
void LCD_vidMoveCursor(u8 u8Line, u8 u8Position);

#endif
