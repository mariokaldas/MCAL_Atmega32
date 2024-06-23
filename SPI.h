/* SPI driver
 * SPI.h
 *
 *  Created on: Oct 19, 2023
 *      Author: mario kaldas
 */

#ifndef SPI_H_
#define SPI_H_

#include "../MCAL_Atmega32/std_types.h"

/*************************************************************************
 *                                Definitions
 * ***********************************************************************/

#define SPI_DEFAULT 0xFF

/*************************************************************************
 *                           Functions prototype
 * ***********************************************************************/


void SPI_initMaster(void);
void SPI_initSlave(void);
uint8 SPI_sendReceiveByte(uint8 data);
void SPI_sendString(uint8* data);
void SPI_receiveString(uint8* data);

#endif /* SPI_H_ */
