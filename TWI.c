/* TWI driver
 * TWI.c
 *
 *  Created on: Oct 21, 2023
 *      Author: mario kaldas
 */
#include "../MCAL_Atmega32/TWI.h"

#include<avr/io.h>

#include "../MCAL_Atmega32/AVRIO.h"
#include "../MCAL_Atmega32/common_macros.h"

/**************************************************************************
 *                        Functions definitions
 * ************************************************************************/

void TWI_init(TWI_configType* configurations){

	uint8 TWBR_value;

	TWBR_value = (((F_CPU/configurations->SCL_FREQ)-16)/8);

	TWBR_R = TWBR_value; /* TWI with 250kHZ and TWPS = 00 and FCPU = 8MHZ */
	TWSR_R.bit.TWPS_bit = 0; /* For adjusting clock and pre-scaler ( assumed ) */
	TWAR_R.bit.TWA_bit = configurations->address;  /* My address */
	TWCR_R.bit.TWEN_bit = 1; /* TWI enable module */
}

void TWI_start(void){

	TWCR_R.Byte = 4; /* Remove previous actions but leave enable-module = 1 */
	TWCR_R.bit.TWSTA_bit = 1; /* Enable start bit */
	TWCR_R.bit.TWINT_bit = 1; /* Clear flag from any previous action */

	while(TWCR_R.bit.TWINT_bit == 0); /* Start bit is sent */
}

void TWI_stop(void){

	TWCR_R.Byte = 4; /* Remove previous actions but leave enable-module = 1 */
	TWCR_R.bit.TWSTO_bit = 1; /* Enable start bit */
	TWCR_R.bit.TWINT_bit = 1; /* Clear flag from any previous action */

}

void TWI_writeByte(uint8 data){

	TWDR_R = data;

	TWCR_R.Byte = 4; /* Remove previous actions but leave enable-module = 1 */
	TWCR_R.bit.TWINT_bit = 1; /* Clear flag from any previous action */

	while(TWCR_R.bit.TWINT_bit == 0); /* Data is sent */
}

uint8 TWI_readByteWithACK(void){

	TWCR_R.Byte = 4; /* Remove previous actions but leave enable-module = 1 */
	TWCR_R.bit.TWEA_bit = 1; /* Enable ACK bit */
	TWCR_R.bit.TWINT_bit = 1; /* Clear flag from any previous action */

	while(TWCR_R.bit.TWINT_bit == 0); /* Data is received */

	return TWDR_R;
}

uint8 TWI_readByteWithNACK(void){

	TWCR_R.Byte = 4; /* Remove previous actions but leave enable-module = 1 */
	TWCR_R.bit.TWINT_bit = 1; /* Clear flag from any previous action */

	while(TWCR_R.bit.TWINT_bit == 0); /* Data is received */

	return TWDR_R;
}

uint8 TWI_getStatus(void){

	return TWSR_R.bit.TWS_bit <<3 ;/* because of standard statues values */
}
