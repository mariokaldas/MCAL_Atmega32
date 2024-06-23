/* Pulse width modulation driver
 * PWM.c
 *
 *  Created on: Oct 13, 2023
 *      Author: mario kaldas
 */

#include "../MCAL_Atmega32/PWM.h"

#include "../MCAL_Atmega32/AVRIO.h"

void PWM_timer0_start(uint8 duty_cycle){

	uint8 dutyCycle_percentege;

TCCR0_R.bit.WGM00_bit = 1; /* NON-PWM */
TCCR0_R.bit.WGM01_bit = 1;

TCCR0_R.bit.COM01_bit = 1; /* NON-INVERTING MODE */

TCCR0_R.bit.CS01_bit = 1; /* Setup pre-scaler Fcpu/8  */

DDRB_R.bit.DDRB3_bit = 1; /* OC0 pin is output */

/* The generated PWM signal is 500 HZ */

TCNT0_R = 0; /* Initialize counter */

dutyCycle_percentege = (uint8)((uint32)(duty_cycle*255)/100);

OCR0_R = dutyCycle_percentege;
}
