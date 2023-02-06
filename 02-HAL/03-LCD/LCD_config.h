#ifndef _HAL_LCD_CONFIG_H_
#define _HAL_LCD_CONFIG_H_


/* Options: EIGHT_BIT,  FOUR_BIT */
#define LCD_MODE                    FOUR_BIT

/* Options: LOW_NIBBLE , HIGH_NIBBLE*/
#define NIBBLE_MODE                 LOW_NIBBLE

/* Options: GPIOB, GPIOC, GPIOD*/
#define LCD_DATA_PORT               GPIOC

/* Options: GPIOB, GPIOC, GPIOD*/
#define LCD_RS_PORT                 GPIOB

/* Options: PIN0........PIN7*/
#define LCD_RS_PIN                  PIN4

/* Options: GPIOB, GPIOC, GPIOD*/
#define LCD_RW_PORT                 GPIOB

/* Options: PIN0........PIN7*/
#define LCD_RW_PIN                  PIN5

/* Options: GPIOB, GPIOC, GPIOD*/
#define LCD_EN_PORT                 GPIOB

/* Options: PIN0........PIN7*/
#define LCD_EN_PIN                  PIN3
#endif

