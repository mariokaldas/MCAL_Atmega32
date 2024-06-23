/* SPI driver
 * SPI.c
 *
 *  Created on: Oct 19, 2023
 *      Author: mario kaldas
 */
#include "../MCAL_Atmega32/SPI.h"

#include "../MCAL_Atmega32/AVRIO.h"
#include "../MCAL_Atmega32/gpio.h"


/**************************************************************************
 *                         Functions definition
 * **********************************************************************/

void SPI_initMaster(void){

	/*
	 * Configuring SPI pins:
	 * SCK              : OUTPUT
	 * MOSI             : OUTPUT
	 * MISO             : INPUT
	 * SS(active low)   : OUTPUT
	 * */

	GPIO_setupPinDirection(PORTB_ID,4,PIN_OUTPUT);  /* SS */
	GPIO_setupPinDirection(PORTB_ID,5,PIN_OUTPUT);  /* MOSI */
	GPIO_setupPinDirection(PORTB_ID,6,PIN_INPUT);   /* MISO */
	GPIO_setupPinDirection(PORTB_ID,7,PIN_OUTPUT);  /* SCK */

	SPCR_R.bit.MSTR_bit = 1; /* This is MASTER */
	SPCR_R.bit.SPE_bit =  1; /* SPI enable */
	SPCR_R.bit.SPIE_bit = 0; /* SPI interrupt DISABLED */
	SPCR_R.bit.DORD_bit = 0; /* Data order is MOST-segnificant_bit */
	SPCR_R.bit.CPOL_bit = 0; /* Clock polarity ( Leading is rising ) */
	SPCR_R.bit.CPHA_bit = 0; /* Clock phase ( setup is falling ) */
	SPCR_R.bit.SPR0_bit = 0; /* Clock is Fcpu/4 */
	SPCR_R.bit.SPR1_bit = 0;
	SPSR_R.bit.SPI2X_bit = 0;
}

void SPI_initSlave(void){

	/*
	 * Configuring SPI pins:
	 * SCK              : INPUT
	 * MOSI             : INTPUT
	 * MISO             : OUTPUT
	 * SS(active low)   : INPUT
	 * */

	GPIO_setupPinDirection(PORTB_ID,4,PIN_INPUT);  /* SS */
	GPIO_setupPinDirection(PORTB_ID,5,PIN_INPUT);  /* MOSI */
	GPIO_setupPinDirection(PORTB_ID,6,PIN_OUTPUT);   /* MISO */
	GPIO_setupPinDirection(PORTB_ID,7,PIN_INPUT);  /* SCK */


	SPCR_R.bit.SPE_bit =  1; /* SPI enable */
	SPCR_R.bit.SPIE_bit = 0; /* SPI interrupt DISABLED */
	SPCR_R.bit.DORD_bit = 0; /* Data order is MOST-segnificant_bit */
	SPCR_R.bit.MSTR_bit = 0; /* This is SLAVE */
	SPCR_R.bit.CPOL_bit = 0; /* Clock polarity ( Leading is rising ) */
	SPCR_R.bit.CPHA_bit = 0; /* Clock phase ( setup is falling ) */
	SPCR_R.bit.SPR0_bit = 0; /* Clock is Fcpu/4 */
	SPCR_R.bit.SPR1_bit = 0;
	SPSR_R.bit.SPI2X_bit = 0;
}

uint8 SPI_sendReceiveByte(uint8 data){

	SPDR_R = data;

	while(SPSR_R.bit.SPIF_bit == 0);

	/* The SPIF flag is cleared when reading the SPIF statues register
	   then accessing the data SPDR register */

	return SPDR_R ;
}

void SPI_sendString(uint8* data){

	uint8 i;

	for(i=0; data[i] != '\0';i++){

		SPI_sendReceiveByte(data[i]);
	}
}

void SPI_receiveString(uint8* data){

	uint8 i=0;

	data[i] = SPI_sendReceiveByte(SPI_DEFAULT);

	while( data[i] != '#'){

		i++;
		data[i] = SPI_sendReceiveByte(SPI_DEFAULT);
	}

	data[i] = '\0';
}
