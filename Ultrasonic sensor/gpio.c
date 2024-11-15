/*
 * Module : GPIO_Driver
 *
 * File Name: gpio.c
 *
 * Description : Source file for the AVR GPIO driver
 *
 * Author: Mariam Hamdy
 */


#include "gpio.h"
#include <avr/io.h>
#include "common_macros.h"

/* function to setup the direction of the required pin (input / output) */

void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num,GPIO_PinType direction) {

	if ((port_num >= NUMBER_OF_PORTS) || (pin_num >= NUMBER_OF_PINS_PER_PORT)) {

		/* DO NOTHING */
	} else {
		switch (port_num) {
		case PORTA_NUM:
			if (direction == PIN_INPUT) {
				CLEAR_BIT(DDRA, pin_num);
			} else if (direction == PIN_OUTPUT) {
				SET_BIT(DDRA, pin_num);
			}
			break;
		case PORTB_NUM:
			if (direction == PIN_INPUT) {
				CLEAR_BIT(DDRB, pin_num);
			} else if (direction == PIN_OUTPUT) {
				SET_BIT(DDRB, pin_num);
			}
			break;
		case PORTC_NUM:
			if (direction == PIN_INPUT) {
				CLEAR_BIT(DDRC, pin_num);
			} else if (direction == PIN_OUTPUT) {
				SET_BIT(DDRC, pin_num);
			}
			break;
		case PORTD_NUM:
			if (direction == PIN_INPUT) {
				CLEAR_BIT(DDRD, pin_num);
			} else if (direction == PIN_OUTPUT) {
				SET_BIT(DDRD, pin_num);
			}
			break;
		}
	}

}

/* function to write the value (logic high or logic low ) on the required pin  */

void GPIO_writePin(uint8 port_num, uint8 pin_num, uint8 value) {
	if ((port_num >= NUMBER_OF_PORTS) || (pin_num >= NUMBER_OF_PINS_PER_PORT)) {

		/*Do nothing*/
	} else {
		switch (port_num) {
		case PORTA_NUM:
			if (value == LOGIC_HIGH)
				SET_BIT(PORTA, pin_num);
			else
				CLEAR_BIT(PORTA, pin_num);
			break;
		case PORTB_NUM:
			if (value == LOGIC_HIGH)
				SET_BIT(PORTB, pin_num);
			else
				CLEAR_BIT(PORTB, pin_num);
			break;
		case PORTC_NUM:
			if (value == LOGIC_HIGH)
				SET_BIT(PORTC, pin_num);
			else
				CLEAR_BIT(PORTC, pin_num);
			break;
		case PORTD_NUM:
			if (value == LOGIC_HIGH)
				SET_BIT(PORTD, pin_num);
			else
				CLEAR_BIT(PORTD, pin_num);
			break;
		}
	}
}

/* function to read and return the value for the required pin (logic high or logic low) */

uint8 GPIO_readPin(uint8 port_num, uint8 pin_num) {
	if ((port_num >= NUMBER_OF_PORTS) || (pin_num >= NUMBER_OF_PINS_PER_PORT)) {
		return LOGIC_LOW;
	} else {
		switch (port_num) {
		case PORTA_NUM:
			if (BIT_IS_SET(PINA, pin_num))
				return LOGIC_HIGH;
			else
				return LOGIC_LOW;
			break;
		case PORTB_NUM:
			if (BIT_IS_SET(PINB, pin_num))
				return LOGIC_HIGH;
			else
				return LOGIC_LOW;
			break;
		case PORTC_NUM:
			if (BIT_IS_SET(PINC, pin_num))
				return LOGIC_HIGH;
			else
				return LOGIC_LOW;
			break;

		case PORTD_NUM:
			if (BIT_IS_SET(PIND, pin_num))
				return LOGIC_HIGH;
			else
				return LOGIC_LOW;
			break;

		}

	}
  return LOGIC_LOW;
}

/* function to setup the direction of the required port (input / output)*/

void GPIO_setupPortDirection(uint8 port_num, GPIO_PortType direction) {
	if ((port_num >= NUMBER_OF_PORTS)) {
		/*Do nothing */
	} else {
		switch (port_num) {
		case PORTA_NUM:
			DDRA = direction;
			break;
		case PORTB_NUM:
			DDRB = direction;
			break;

		case PORTC_NUM:
			DDRC = direction;
			break;

		case PORTD_NUM:
			DDRD = direction;
			break;

		}
	}
}


/* function to write the value on the required port (logic low / logic high)*/

void GPIO_writePort(uint8 port_num, uint8 value) {

	if ((port_num >= NUMBER_OF_PORTS)) {
		/*Do nothing */
	} else {
		switch (port_num) {
		case PORTA_NUM:
			PORTA = value;
			break;
		case PORTB_NUM:
			PORTB = value;
			break;
		case PORTC_NUM:
			PORTC = value;
			break;
		case PORTD_NUM:
			PORTD = value;
			break;

		}
	}
}

/* function to read and return the value for the required port (logic high or logic low) */

uint8 GPIO_readPort(uint8 port_num ){
	uint8 value = LOGIC_LOW;
	if ((port_num >= NUMBER_OF_PORTS)) {
			/*Do nothing*/
		} else {
			switch(port_num){
			case PORTA_NUM:
				value = PINA;
				break;
			case PORTB_NUM:
							value = PINB;
							break;
			case PORTC_NUM:
							value = PINC;
							break;
			case PORTD_NUM:
							value = PIND;
							break;
			}
		}
	return value;
}
