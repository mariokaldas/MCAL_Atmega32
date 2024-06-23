/* Input capturing unit driver
 * ICU.c
 *
 *  Created on: Oct 12, 2023
 *      Author: mario kaldas
 */
#include "../MCAL_Atmega32/ICU.h"

#include<avr/interrupt.h>
#include "../MCAL_Atmega32/AVRIO.h"

/************************************************************************
 *                          Global variables
 ***********************************************************************/

static volatile void (*g_callBackPtr)(void) = NULL_PTR;

/************************************************************************
 *                        Interrupt service routine
 ***********************************************************************/

ISR(TIMER1_CAPT_vect){

	if(g_callBackPtr != NULL_PTR)
	(*g_callBackPtr)();
}

/************************************************************************
 *                          Functions definition
 ***********************************************************************/
void ICU_init(ICU_configType * ptr){

	DDRD_R.bit.DDRD6_bit = 0;

	TCCR1A_R.bit.FOC1A_bit = 1; /* NON-PWM mode */
	TCCR1A_R.bit.FOC1B_bit = 1;

	TCCR1B_R.bit.CS1_bit = ptr->clock ; /* Adjust clock and pre-scaler */

	TCCR1B_R.bit.ICES1_bit = ptr->edge ; /* Selecting edge */

	TCNT1_R = 0; /* Initialize counter */

	ICR1_R = 0; /* Initialize data register */

	TIMSK_R.bit.TICIE1_bit = 1;

}//end ICU_init

void ICU_setCallBack(void (*ptr)(void)){
	g_callBackPtr = ptr;
}

void ICU_setEdgeDetectionType(ICU_edgeConfig edgeType){

	TCCR1B_R.bit.ICES1_bit = edgeType;

}

uint16 ICU_getInputCaptureValue(void){

	return ICR1_R;
}

void ICU_clearTimer(void){

	TCNT1_R = 0;
}

void ICU_deInit(void){

	TCCR1A_R.Byte = 0;
	TCCR1B_R.bit.CS1_bit = 0;
	TCNT1_R = 0;
	ICR1_R = 0;

	TIMSK_R.bit.TICIE1_bit = 0;

	g_callBackPtr = NULL_PTR;
}
