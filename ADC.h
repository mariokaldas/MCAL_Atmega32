/* ADC driver
 * ADC.h
 *
 *  Created on: Oct 9, 2023
 *      Author: mario kaldas
 */

#ifndef ADC_H_
#define ADC_H_

#include "../MCAL_Atmega32/std_types.h"


/**************************************************************************
                                     Definitions
****************************************************************************/

#define ADC_V_REF 5
#define ADC_MAX_VALUE 1023

#define POLLING
/****************************************************************************
 *                            Type declarations
 * **************************************************************************/

typedef enum {
	AREF,AVCC,INTERNAL256=3
}ADC_ReferenceVoltage;


typedef enum {
	FACTOR2=1,FACTOR4,FACTOR8,FACTOR16,FACTOR32,FACTOR64,FACTOR128
}ADC_Prescaler;

typedef struct{

	ADC_ReferenceVoltage Vref;
	ADC_Prescaler prescaler;

}ADC_configType;

/***************************************************************************
 *                               Function prototypes
 * *************************************************************************/

void ADC_init(const ADC_configType* ptr);

#ifdef POLLING
uint16 ADC_readChannel(uint8 ch_num);
#endif

#ifdef INTERRUPT
void ADC_readChannel(uint8 ch_num);
#endif


#endif /* ADC_H_ */
