/*
 * Modeule: Ultrasonic_DRIVER
 *
 * File Name: measure_distance.c
 *
 * Description: source file for ultrasonic driver exercise
 *
 * Author: Mariam Hamdy
 */

#include <avr/io.h>
#include <util/delay.h>
#include "ultrasonic.h"
#include "lcd.h"

int main(void){
	uint16 distanceObject =0;
	SREG |=(1<<7);

	Ultrasonic_init();
	LCD_init();
    LCD_displayString("Distance =  ");
	while(1){
        distanceObject= Ultrasonic_readDistance();
        LCD_moveCursor(0,11);
    	 LCD_intgerToString(distanceObject);
    	 if(distanceObject < 100){
    		 LCD_displayCharacter(' ');
    	 }
    	 LCD_displayString("cm");
    	 _delay_ms(100);

	}


}
