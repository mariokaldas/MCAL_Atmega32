/*
 * Module : TIMER1
 *
 * File name : timer1.c
 *
 * Description : source file for timer1 module
 *
 * Author: Mario kaldas
 */

#include "../MCAL_Atmega32/timer1.h"

#include"avr/interrupt.h"
#include "../MCAL_Atmega32/AVRIO.h"


/****************************************************************************
 *                           Global variables
 ****************************************************************************/

volatile static void (*g_callBackptr)(void) = NULL_PTR;

/****************************************************************************
 *                        INTERRUPT SERVICE ROUTINE
 ****************************************************************************/

ISR(TIMER1_OVF_vect){
	(*g_callBackptr)();
}

ISR(TIMER1_COMPA_vect){
	(*g_callBackptr)();
}

ISR(TIMER1_COMPB_vect){}

/****************************************************************************
 *                         Functions definition
 ****************************************************************************/

void TIMER1_init(TIMER1_configType* configurations){

	uint16 dutyCycle_A,dutyCycle_B;

	switch(configurations->mode){

	case NORMAL:
		TCCR1A_R.bit.COM1A_bit = 0; /* Normal (non-PWM) */
		TCCR1A_R.bit.COM1B_bit = 0; /* Normal (non-PWM) */
		TCCR1A_R.bit.FOC1A_bit = 1; /* non-PWM */
		TCCR1A_R.bit.FOC1B_bit = 1; /* non-PWM */
		TCCR1A_R.bit.WGM10_bit = 0; /* Overflow mode */
		TCCR1A_R.bit.WGM11_bit = 0; /* Overflow mode */
		TCCR1B_R.bit.WGM12_bit = 0; /* Overflow mode */
		TCCR1B_R.bit.WGM13_bit = 0; /* Overflow mode */
		TIMSK_R.bit.TOIE1_bit = 1;  /* Enable interrupt for overflow mode */
		break;

	case COMPARE:
		TCCR1A_R.bit.COM1A_bit = 0; /* Normal (non-PWM) */
		TCCR1A_R.bit.COM1B_bit = 0; /* Normal (non-PWM) */
		TCCR1A_R.bit.FOC1A_bit = 1; /* non-PWM */
		TCCR1A_R.bit.FOC1B_bit = 1; /* non-PWM */
		TCCR1A_R.bit.WGM10_bit = 0; /* Compare mode */
		TCCR1A_R.bit.WGM11_bit = 0; /* Compare mode */
		TCCR1B_R.bit.WGM12_bit = 1; /* Compare mode */
		TCCR1B_R.bit.WGM13_bit = 0; /* Compare mode */
		TIMSK_R.bit.OCIE1A_bit = 1; /* Enable interrupt for compare mode unit A */
		TIMSK_R.bit.OCIE1B_bit = 1; /* Enable interrupt for compare mode unit B */

		OCR1A_R = configurations->compare_value; /* Adjusting compare value */
		break;

	case PWM_B:

		DDRD_R.bit.DDRD4_bit = 1; /* PD4 output pin UNITB */

		TCCR1A_R.bit.COM1A_bit = 2;  /* PWM non-inverting mode */
		TCCR1A_R.bit.COM1B_bit = 2;  /* PWM non-inverting mode */
		TCCR1A_R.bit.FOC1A_bit = 0; /* PWM */
		TCCR1A_R.bit.FOC1B_bit = 0; /* PWM */
		TCCR1A_R.bit.WGM10_bit = 1; /* PWM mode TOP = OCR1A */
		TCCR1A_R.bit.WGM11_bit = 1; /* PWM mode */
		TCCR1B_R.bit.WGM12_bit = 1; /* PWM mode */
		TCCR1B_R.bit.WGM13_bit = 1; /* PWM mode */

		OCR1A_R = configurations->compare_value;
		dutyCycle_B = (uint16)(((uint32)(configurations->UNITB_dutyCycle)*OCR1A_R)/100);

		OCR1B_R = dutyCycle_B; /* Adjusting duty cycle for PWM unit B */
		break;

	case PWM_AB:

		DDRD_R.bit.DDRD4_bit = 1; /* PD4 output pin UNITB */
		DDRD_R.bit.DDRD5_bit = 1; /* PD4 output pin UNITA */

		TCCR1A_R.bit.COM1A_bit = 2;  /* PWM non-inverting mode */
		TCCR1A_R.bit.COM1B_bit = 2;  /* PWM non-inverting mode */
		TCCR1A_R.bit.FOC1A_bit = 0; /* PWM */
		TCCR1A_R.bit.FOC1B_bit = 0; /* PWM */
		TCCR1A_R.bit.WGM10_bit = 0; /* PWM mode TOP = ICR1 */
		TCCR1A_R.bit.WGM11_bit = 1; /* PWM mode */
		TCCR1B_R.bit.WGM12_bit = 1; /* PWM mode */
		TCCR1B_R.bit.WGM13_bit = 1; /* PWM mode */

		ICR1_R = configurations->compare_value; /* Adjusting TOP value for PWM unit A and B */
		dutyCycle_A = (uint16)(((float32)(configurations->UNITA_dutyCycle)*ICR1_R)/100);
		dutyCycle_B = (uint16)(((float32)(configurations->UNITB_dutyCycle)*ICR1_R)/100);

		OCR1A_R = dutyCycle_A; /* Adjusting duty cycle for PWM unit A */
		OCR1B_R = dutyCycle_B; /* Adjusting duty cycle for PWM unit B */
		break;
	}

	/* Adjusting the pre-scaler */
	TCCR1B_R.bit.CS1_bit = configurations->prescaler;

	/* Adjusting initial value */
	TCNT1_R = configurations->initial_value;
}


void TIMER1_deInit(void){

	/* No clock source ( disable timer1 ) */
	TCCR1B_R.bit.CS1_bit = 0;
}


void TIMER1_setCallBack(volatile void(*ptr)(void)){

	g_callBackptr = ptr;
}
