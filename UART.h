/* UART driver
 * UART.h
 *
 *  Created on: Oct 16, 2023
 *      Author: mario kaldas
 */

#ifndef UART_H_
#define UART_H_

#include "../MCAL_Atmega32/std_types.h"


/*****************************************************************************
 *                             Types declaration
 ****************************************************************************/

typedef enum{

	FIVE_BIT,SIX_BIT,SEVEN_BIT,EIGHT_BIT,NINE_BIT=7
}UART_bitData_type;


typedef enum{

	NO_PARITY,EVEN_PARITY = 2,ODD_PARITY = 3
}UART_parityBit_type;


typedef enum{

	ONE_STOP,TWO_STOP
}UART_stopBit_type;


typedef struct{

	UART_bitData_type bit_data;
	UART_parityBit_type parity;
	UART_stopBit_type stop;
	uint16 baudRate;
}UART_configType;
/*****************************************************************************
 *                          Functions prototypes
 * **************************************************************************/

void UART_init(UART_configType* configurations);

void UART_sendByte(const uint8 data);

uint8 UART_receiveByte(void);

void UART_sendString(const uint8 *str);

void UART_receiveString(uint8 *str); /* Receive until # */

#endif /* UART_H_ */
