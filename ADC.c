/* ADC driver
 * ADC.c
 *
 *  Created on: Oct 9, 2023
 *  	Author: mario kaldas
 */

#include "ADC.h"

#include"avr/interrupt.h"
#include "AVRIO.h"


/***************************************************************************
                          Global variables
****************************************************************************/
volatile uint16 g_channelReading;

/**************************************************************************
 *                    Interrupt service routine
 * ***********************************************************************/
ISR(ADC_vect){

	g_channelReading = ADC_R;
}//end ISR

/*************************************************************************
 *                           Functions definition
 * **********************************************************************/


void ADC_init(const ADC_configType* ptr){

	ADMUX_R.bit.REFS_bit = ptr->Vref; /* Adjust reference voltage to VCC */
	ADMUX_R.bit.ADLAR_bit = 0; /* Turn off ADC left adjust result */
	ADMUX_R.bit.MUX_bit = 0; /* Initialize channel */

	ADCSRA_R.bit.ADEN_bit = 1; /* Enable module */
#ifdef POLLING
	ADCSRA_R.bit.ADIE_bit = 0; /* Turn off interrupt */
#endif

#ifdef INTERRUPT
	ADCSRA_R.bit.ADIE_bit = 1; /* Turn on interrupt */
#endif
	ADCSRA_R.bit.ADPS_bit = ptr->prescaler; /* Adjust pre-scaler to 128 */

}//end ADC_init

#ifdef POLLING
uint16 ADC_readChannel(uint8 ch_num){

	ADMUX_R.bit.MUX_bit = ch_num; /* Insert desired channel number */

	ADCSRA_R.bit.ADSC_bit = 1; /* Start conversion */

	while(ADCSRA_R.bit.ADIF_bit == 0); /* Polling till conversion ends */

	ADCSRA_R.bit.ADIF_bit = 1; /* clear flag */

	return ADC_R;

}//end ADC_readChannel
#endif

#ifdef INTERRUPT
void ADC_readChannel(uint8 ch_num){

	ADMUX_R.bit.MUX_bit = ch_num; /* Insert desired channel number */

	ADCSRA_R.bit.ADSC_bit = 1; /* Start conversion */


}//end ADC_readChannel
#endif
