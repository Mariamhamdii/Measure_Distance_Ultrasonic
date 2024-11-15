/*
 * Modeule: LCD_Driver
 *
 * File Name: lcd.c
 *
 * Description: source file for LCD driver
 *
 * Author: Mariam Hamdy
 */


#include <util/delay.h>
#include "common_macros.h"
#include "gpio.h"
#include "lcd.h"

void LCD_sendCommand(uint8 command){
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_NUM, LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_NUM, LOGIC_HIGH);
	_delay_ms(1);
#if(LCD_DATA_MODE == 4)
	GPIO_writePin(LCD_DATA_PATH_PORT_ID,PIN3_NUM,GET_BIT(command,4));
	GPIO_writePin(LCD_DATA_PATH_PORT_ID,PIN4_NUM,GET_BIT(command,5));
	GPIO_writePin(LCD_DATA_PATH_PORT_ID,PIN5_NUM,GET_BIT(command,6));
	GPIO_writePin(LCD_DATA_PATH_PORT_ID,PIN6_NUM,GET_BIT(command,7));
	_delay_ms(1);
	 GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_NUM, LOGIC_LOW);
	 _delay_ms(1);
	 GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_NUM, LOGIC_HIGH);
	 _delay_ms(1);
	GPIO_writePin(LCD_DATA_PATH_PORT_ID, PIN3_NUM, GET_BIT(command, 0));
	GPIO_writePin(LCD_DATA_PATH_PORT_ID, PIN4_NUM, GET_BIT(command, 1));
	GPIO_writePin(LCD_DATA_PATH_PORT_ID, PIN5_NUM, GET_BIT(command, 2));
	GPIO_writePin(LCD_DATA_PATH_PORT_ID, PIN6_NUM, GET_BIT(command, 3));
	_delay_ms(1);
	GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_NUM, LOGIC_LOW);
	_delay_ms(1);

#elif(LCD_DATA_MODE == 8)
    GPIO_writePort( LCD_DATA_PATH_PORT_ID, command);
    _delay_ms(1);
    GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_NUM, LOGIC_LOW);
    _delay_ms(1);
#endif
}

void LCD_init(void){
 GPIO_setupPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_NUM, PIN_OUTPUT);
 GPIO_setupPinDirection(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_NUM, PIN_OUTPUT);

 _delay_ms(20);

 #if(LCD_DATA_MODE == 4)
 GPIO_setupPinDirection(LCD_DATA_PATH_PORT_ID,PIN3_NUM, PIN_OUTPUT);
 GPIO_setupPinDirection(LCD_DATA_PATH_PORT_ID,PIN4_NUM, PIN_OUTPUT);
 GPIO_setupPinDirection(LCD_DATA_PATH_PORT_ID,PIN5_NUM, PIN_OUTPUT);
 GPIO_setupPinDirection(LCD_DATA_PATH_PORT_ID,PIN6_NUM, PIN_OUTPUT);
 LCD_sendCommand( LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
 LCD_sendCommand( LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

 LCD_sendCommand(LCD_TWO_LINES_4_BIT_MODE);

#elif(LCD_DATA_MODE == 8)
 GPIO_setupPortDirection(LCD_DATA_PATH_PORT_ID, PORT_OUTPUT);
 LCD_sendCommand(LCD_TWO_LINES_8_BIT_MODE);
#endif

 LCD_sendCommand(LCD_CLEAR_DISPLAY_SCREEN );
 LCD_sendCommand(LCD_CURSOR_OFF);


}
void LCD_displayCharacter(uint8 data){
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_NUM, LOGIC_HIGH);
		_delay_ms(1);
		GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_NUM, LOGIC_HIGH);
		_delay_ms(1);
#if(LCD_DATA_MODE == 4)
	GPIO_writePin(LCD_DATA_PATH_PORT_ID,PIN3_NUM,GET_BIT(data,4));
	GPIO_writePin(LCD_DATA_PATH_PORT_ID,PIN4_NUM,GET_BIT(data,5));
	GPIO_writePin(LCD_DATA_PATH_PORT_ID,PIN5_NUM,GET_BIT(data,6));
	GPIO_writePin(LCD_DATA_PATH_PORT_ID,PIN6_NUM,GET_BIT(data,7));
	_delay_ms(1);
	 GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_NUM, LOGIC_LOW);
	 _delay_ms(1);
	 GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_NUM, LOGIC_HIGH);
	 _delay_ms(1);
	GPIO_writePin(LCD_DATA_PATH_PORT_ID, PIN3_NUM, GET_BIT(data, 0));
	GPIO_writePin(LCD_DATA_PATH_PORT_ID, PIN4_NUM, GET_BIT(data, 1));
	GPIO_writePin(LCD_DATA_PATH_PORT_ID, PIN5_NUM, GET_BIT(data, 2));
	GPIO_writePin(LCD_DATA_PATH_PORT_ID, PIN6_NUM, GET_BIT(data, 3));
	_delay_ms(1);
	GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_NUM, LOGIC_LOW);
	_delay_ms(1);

#elif(LCD_DATA_MODE == 8)
    GPIO_writePort( LCD_DATA_PATH_PORT_ID, data);
    _delay_ms(1);
    GPIO_writePin(LCD_ENABLE_PORT_ID, LCD_ENABLE_PIN_NUM, LOGIC_LOW);
    _delay_ms(1);
#endif



}
void LCD_displayString(uint8 *str){
	uint8 i=0;
	while(str[i] != '\0'){
		 LCD_displayCharacter(str[i]);
		 i++;
	}

}

void LCD_moveCursor(uint8 row , uint8 col){
	uint8 lcd_address;
	switch(row){
	case 0: lcd_address = col;
	break;
	case 1: lcd_address = col + 0x40;
	break;
	case 2: lcd_address = col + 0x10;
	break;
	case 3: lcd_address = col + 0x50;
	break;
	}
	LCD_sendCommand(lcd_address | LCD_SET_CURSOR_LOCATION);
}

void LCD_displayStringRowColumn(uint8 row , uint8 col, uint8 *str){
	LCD_moveCursor(row, col);
	LCD_displayString(str);
}

void LCD_clearScreen(void){
	LCD_sendCommand(LCD_CLEAR_DISPLAY_SCREEN);
}

void LCD_intgerToString(int num){
	char buff[16];
	itoa(num,buff,10);
	LCD_displayString(buff);

}
