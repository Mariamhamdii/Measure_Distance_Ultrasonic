/*
 * Module: ICU_DRIVER
 *
 * File Name: icu.c
 *
 * Description: source file for icu driver
 *
 * Author: Mariam Hamdy
 */
#include <avr/io.h>
#include <avr/interrupt.h>
#include "icu.h"
#include "gpio.h"

static volatile void (*g_callBackPtr)(void) = NULL_PTR;

ISR(TIMER1_CAPT_vect){
	if(g_callBackPtr != NULL_PTR){
		(*g_callBackPtr)();
	}
}

void ICU_init(const ICU_ConfigType * Config_Ptr){
    GPIO_setupPinDirection(PORTD_NUM,PIN6_NUM,PIN_INPUT);
	TCCR1A =(1<<FOC1A)|(1<<FOC1B);
	TCCR1B = (TCCR1B & 0xBF)|((Config_Ptr ->edge)<<6);
	TCCR1B =(TCCR1B & 0xF8)|(Config_Ptr ->clock);
	TCNT1 =0;
    ICR1 =0;
    TIMSK |=(1<<TICIE1);

}

void ICU_setCallBack(void(*a_ptr)(void)){
	g_callBackPtr = a_ptr;
}

void ICU_setEdgeDetectionType(const ICU_EdgeType a_edgeType){
	TCCR1B = (TCCR1B & 0xBF)|(a_edgeType<<6);
}

uint16 ICU_getInputCaptureValue(void){
	return ICR1;
}

void ICU_clearTimerValue(void){
	TCNT1 =0;
}

void ICU_deInit(void){
	TCCR1A =0;
	TCCR1B =0;
	TIMSK &=~(1<<TICIE1);
	TCNT1 =0;
	ICR1=0;
	g_callBackPtr = NULL_PTR;

}
