/* Pulse width modulation driver
 * PWM.h
 *
 *  Created on: Oct 13, 2023
 *      Author: mario kaldas
 */

#ifndef PWM_H_
#define PWM_H_

#include "../MCAL_Atmega32/std_types.h"



void PWM_timer0_start(uint8 duty_cycle);

#endif /* PWM_H_ */
