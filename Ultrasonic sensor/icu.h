/*
 * Module: ICU_DRIVER
 *
 * File Name: icu.h
 *
 * Description: header file for icu driver
 *
 * Author: Mariam Hamdy
 */
#ifndef ICU_H_
#define ICU_H_

#include "std_types.h"

/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/
typedef enum{
	NO_CLOCK, F_CPU_1,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024,FALLING_EX_CLOCK,RISING_EX_CLOCK
}ICU_ClockType;

typedef enum{
	FALLING , RISING
}ICU_EdgeType;

typedef struct {
	ICU_ClockType clock ;
	ICU_EdgeType edge;
}ICU_ConfigType;

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

void ICU_init(const ICU_ConfigType * Config_Ptr);

void ICU_setCallBack(void(*a_ptr)(void));

void ICU_setEdgeDetectionType(const ICU_EdgeType a_edgeType);

uint16 ICU_getInputCaptureValue(void);

void ICU_clearTimerValue(void);

void ICU_deInit(void);
#endif /* ICU_H_ */
