/*
 * Modeule: Ultrasonic_Driver
 *
 * File Name: ultrasonic.h
 *
 * Description: header file for ultrasonic driver
 *
 * Author: Mariam Hamdy
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_

#include "std_types.h"
#include "gpio.h"


/*******************************************************************************
 *                      Macros Definitions                                     *
 *******************************************************************************/

#define ULTRASONIC_TRIGGER_PORT             PORTB_NUM
#define ULTRASONIC_TRIGGER_PIN              PIN5_NUM




/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void Ultrasonic_init(void);

void Ultrasonic_Trigger(void);

uint16 Ultrasonic_readDistance(void);

void Ultrasonic_edgeProcessing(void);



#endif /* ULTRASONIC_H_ */
