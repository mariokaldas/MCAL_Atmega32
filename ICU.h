/* Input capturing unit driver
 * ICU.h
 *
 *  Created on: Oct 12, 2023
 *      Author: mario kaldas
 */

#ifndef ICU_H_
#define ICU_H_

#include "../MCAL_Atmega32/std_types.h"

/*************************************************************************
 *                             Types declarations
 * ***********************************************************************/
typedef enum{
	TIMER_STOP,FACTOR1,FACTOR8,FACTOR64,FACTOR256,FACTOR1024
}ICU_clockConfig;

typedef enum{
	FALLING,RISING
}ICU_edgeConfig;

typedef struct{
	ICU_clockConfig clock;
	ICU_edgeConfig edge;
}ICU_configType;

/*************************************************************************
 *                             Functions prototype
 * ***********************************************************************/
void ICU_init(ICU_configType * ptr);

void ICU_setCallBack(void (*ptr)(void));

void ICU_setEdgeDetectionType(ICU_edgeConfig edgeType);

uint16 ICU_getInputCaptureValue(void);

void ICU_clearTimer(void);

void ICU_deInit(void);

#endif /* ICU_H_ */
