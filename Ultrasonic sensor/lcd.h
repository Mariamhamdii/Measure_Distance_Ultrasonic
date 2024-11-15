/*
 * Modeule: LCD_Driver
 *
 * File Name: lcd.h
 *
 * Description: header file for LCD driver
 *
 * Author: Mariam Hamdy
 */
#ifndef LCD_H_
#define LCD_H_
#include "std_types.h"
#include "gpio.h"
/********************************************Macros Definitions*********************************************/
#define LCD_DATA_MODE     8

#if((LCD_DATA_MODE != 4) && (LCD_DATA_MODE != 8))
#error "Number of bits should be equal 4 or 8 "
#endif


#define LCD_RS_PORT_ID         PORTB_NUM
#define LCD_RS_PIN_NUM         PIN0_NUM

#define LCD_ENABLE_PORT_ID     PORTB_NUM
#define LCD_ENABLE_PIN_NUM     PIN1_NUM

#define LCD_DATA_PATH_PORT_ID    PORTA_NUM

#if(LCD_DATA_MODE == 4)
#define LCD_DATA_PATH_PIN3_NUM   PIN3_NUM
#define LCD_DATA_PATH_PIN4_NUM   PIN4_NUM
#define LCD_DATA_PATH_PIN5_NUM   PIN5_NUM
#define LCD_DATA_PATH_PIN6_NUM   PIN6_NUM
#endif

/* LCD Commands*/

#define LCD_CLEAR_DISPLAY_SCREEN             0x01
#define LCD_RETURN_HOME                      0x02
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_TWO_LINES_8_BIT_MODE             0x38
#define LCD_TWO_LINES_4_BIT_MODE             0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_SET_CURSOR_LOCATION              0x80

/********************************************Function Prototypes *******************************************/

void LCD_sendCommand(uint8 command);

void LCD_init(void);

void LCD_displayCharacter(uint8 data);

void LCD_displayString(uint8 *str);

void LCD_moveCursor(uint8 col , uint8 row);

void LCD_displayStringRowColumn(uint8 row , uint8 col, uint8 *str);

void LCD_clearScreen(void);

void LCD_intgerToString(int num);

#endif /* LCD_H_ */
