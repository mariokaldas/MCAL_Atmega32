/*
 * Module : TIMER1
 *
 * File name : timer1.h
 *
 * Description : header file for timer1 module
 *
 * Author: Mario kaldas
 */

#ifndef MCAL_TIMER1_H_
#define MCAL_TIMER1_H_

#include "../MCAL_Atmega32/std_types.h"

/****************************************************************************
 *                            IMPORTANT NOTES
 ****************************************************************************/
/*
 * - If you want to use both units in PWM :
 * write TOP value in ICR1 and compare values in OCR1A and OCR1B
 * and then you obviously CANNOT use ICR1 ( INPUT CAPTURING UNIT )
 *
 *
 * - If you want to use one PWM unit (UNITB):
 *  write TOP value in OCR1A and compare value in OCR1B
 *  and pin OC1A will be HIGH always
 *
 *
 *  TO SUM UP
 *  - You can use PWM unit B and ICU but OC1A will be HIGH
 *  - You can use PWM unit A AND B but you CANNOT use ICU
 *
 *
 *
 *	- Equation of frequency of generated PWM :
 *	please edit it before using PWM
 *
 *	F(PWM) = Fcpu/N(1+TOP)
 *
 *	Most common:
 *	Fcpu = 1MHZ	  TOP = 0xFF   N = 8   >>>>  500HZ
 *
 * */


/***************************************************************************
 *                              Definitions
 ****************************************************************************/

#define TIMER1_CMP_DEFAULT          0xFFFF
#define TIMER1_DUTY_CYCLE_A_DEFAULT 0
#define TIMER1_DUTY_CYCLE_B_DEFAULT 0

/***************************************************************************
 *                            Types declaration
 ****************************************************************************/

typedef enum{

	NORMAL,
	COMPARE,
	PWM_B, /* PWM unitB only */
	PWM_AB /* PWM both units  */
}TIMER1_MODE_type;

typedef enum{

	STOP,FACTOR1,FACTOR8,FACTOR64,FACTOR256,FACTOR1024
}TIMER1_prescaler_type;


typedef struct{

	TIMER1_MODE_type mode;
	TIMER1_prescaler_type prescaler; /* in case normal and compare modes */
	uint16 initial_value;

	/* In case compare mode AND it's TOP value in case PWM_B AND TOP value in PWM_AB */
	uint16 compare_value;
	float32 UNITA_dutyCycle;
	float32 UNITB_dutyCycle;

}TIMER1_configType;
/***************************************************************************
 *                            Functions prototype
 ****************************************************************************/

void TIMER1_init(TIMER1_configType* configurations);
void TIMER1_deInit(void);
void TIMER1_setCallBack(volatile void(*ptr)(void));

#endif /* MCAL_TIMER1_H_ */
