/*
 * Modeule: Ultrasonic_DRIVER
 *
 * File Name: ultrasonic.c
 *
 * Description: source file for ultrasonic driver
 *
 * Author: Mariam Hamdy
 */

#include <util/delay.h>
#include "icu.h"
#include "ultrasonic.h"
#include "gpio.h"

uint8 g_edge_count =0;
uint16 g_pulseTime =0;
void Ultrasonic_init(void){
	ICU_ConfigType ICU_Config={F_CPU_8,RISING};
	ICU_init(&ICU_Config);
	ICU_setCallBack(Ultrasonic_edgeProcessing);
	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,PIN_OUTPUT);
}

void Ultrasonic_Trigger(void){
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN,LOGIC_LOW);
}


uint16 Ultrasonic_readDistance(void){
	uint16 distance =0;
	Ultrasonic_Trigger();
	distance = (g_pulseTime / 58);
	return distance;

}
void Ultrasonic_edgeProcessing(void){
	g_edge_count++;
	if(g_edge_count == 1){
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edge_count == 2){
		g_pulseTime = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(RISING);
		ICU_clearTimerValue();
		g_edge_count =0;
	}
}
