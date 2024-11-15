/*
 * gpio.h
 *
 *  Created on: Sep 29, 2023
 *      Author: HP
 */

#ifndef GPIO_H_
#define GPIO_H_
#include "std_types.h"

/************************************ Types Declarations *********************************************/

typedef enum{
	PIN_INPUT , PIN_OUTPUT
}GPIO_PinType;

typedef enum{
	PORT_INPUT , PORT_OUTPUT=0xFF
}GPIO_PortType;


/*********************************************************************************************/

/************************************ Macros Definitions *******************************************/

#define NUMBER_OF_PORTS    4
#define NUMBER_OF_PINS_PER_PORT     8
#define PORTA_NUM    0
#define PORTB_NUM    1
#define PORTC_NUM    2
#define PORTD_NUM    3

#define PIN0_NUM     0
#define PIN1_NUM     1
#define PIN2_NUM     2
#define PIN3_NUM     3
#define PIN4_NUM     4
#define PIN5_NUM     5
#define PIN6_NUM     6
#define PIN7_NUM     7

/***************************************************************************************************/

/************************************ Function Prototypes ******************************************/

void GPIO_setupPinDirection(uint8 port_num , uint8 pin_num , GPIO_PinType direction);
uint8 GPIO_readPin(uint8 port_num , uint8 pin_num);
void GPIO_writePin(uint8 port_num , uint8 pin_num , uint8 value);
void GPIO_setupPortDirection(uint8 port_num, GPIO_PortType direction );
uint8 GPIO_readPort(uint8 port_num);
void GPIO_writePort(uint8 port_num , uint8 value);

/*******************************************************************************************/

#endif /* GPIO_H_ */
