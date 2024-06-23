/* UART driver
 * UART.c
 *
 *  Created on: Oct 16, 2023
 *      Author: mario kaldas
 */

#include "../MCAL_Atmega32/UART.h"

#include<avr/interrupt.h>
#include "../MCAL_Atmega32/AVRIO.h"

#define POLLING

/**************************************************************************
 *                            Global variables
 * ***********************************************************************/
#ifdef INTERRUPT
uint8 g_receivedByte = '$';
#endif
/**************************************************************************
 *                       INTERRUPT SERVICE ROUTINE
 * ***********************************************************************/
#ifdef INTERRUPT
ISR(USART_RXC_vect){

	g_receivedByte = UDR_R;
}
#endif
/**************************************************************************
 *                       Functions definition
 * ***********************************************************************/

void UART_init(UART_configType* configurations){

	/* DO NOT ACCESS (URSEL) BIT UNDER ANY CONDITION */

	uint16 ubrr_value;

	UCSRA_R.bit.U2X_bit = 1; /* Double speed */
#ifdef INTERRUPT
	UCSRB_R.bit.RXCIE_bit = 1; /* Receive Complete interrupt enable */
#endif
	UCSRB_R.bit.RXEN_bit = 1; /* Receiver enable */

	UCSRB_R.bit.TXEN_bit = 1; /* Transmitter enable */

	UCSRC_R.bit.UMSEL_bit = 0; /* Asynchronous */

	UCSRC_R.bit.UPM_bit = configurations->parity; /* Select parity-bit mode */

	UCSRC_R.bit.USBS_bit = configurations->stop; /* Select stop_bit mode */

	UCSRC_R.bit.UCSZ_bit = configurations->bit_data; /* select number of data bits */

	ubrr_value =  (uint16)(((float) F_CPU/((uint32)8 * (configurations->baudRate)))-1);

	UBRRH_R.bit.UBRR_bit = ubrr_value>>8;

	UBRRL_R = ubrr_value;
}


void UART_sendByte(const uint8 data){

	/* Stuck in loop till the data register is empty */
	while(UCSRA_R.bit.UDRE_bit == 0);

	/* As data register is empty i can send a byte */
	UDR_R = data;
}

uint8 UART_receiveByte(void){

#ifdef POLLING
	while(UCSRA_R.bit.RXC_bit == 0);

	return UDR_R;
#endif

#ifdef INTERRUPT
	return g_receivedByte;
#endif
}

void UART_sendString(const uint8 *str){

	uint8 i;

	for(i=0; str[i] != '\0';i++){
		UART_sendByte(str[i]);
	}
}

void UART_receiveString(uint8 *str){

	uint8 i=0;

	str[i] = UART_receiveByte();

	while(str[i] != '#'){

		i++;
		str[i] = UART_receiveByte();
	}

	str[i] = '\0';
}


