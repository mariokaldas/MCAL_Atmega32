/* TWI driver
 * TWI.h
 *
 *  Created on: Oct 21, 2023
 *      Author: mario kaldas
 */

#ifndef TWI_H_
#define TWI_H_

#include "../MCAL_Atmega32/std_types.h"


/***************************************************************************
 *                            Types declaration
 * *************************************************************************/

typedef struct{

	uint8 address;
	uint32 SCL_FREQ;
}TWI_configType;

/***************************************************************************
 *                                Definitions
 * *************************************************************************/

#define TWI_STATUS_START                 0x08
#define TWI_STATUS_REPEATED_START        0x10
#define TWI_STATUS_MT_SLA_W_ACK          0x18 /* Master transmitted ( slave address + write request ) ACK received */
#define TWI_STATUS_MT_SLA_W_NACK         0x20 /* Master transmitted ( slave address + write request ) NACK received */
#define TWI_STATUS_MT_DATA_ACK           0x28 /* Master transmitted data and ACK received */
#define TWI_STATUS_MT_DATA_NACK          0x30 /* Master transmitted data and NACK received */
#define TWI_STATUS_ARBITRATION_LOST      0x38 /* Arbitration lost ( slave address write request ) or data */
#define TWI_STATUS_MT_SLA_R_ACK          0x40 /* Master transmitted ( slave address + read request ) ACK received */
#define TWI_STATUS_MT_SLA_R_NACK         0x48 /* Master transmitted ( slave address + read request ) NACK received */
#define TWI_STATUS_MR_DATA_ACK           0x50 /* Master received data with ACK */
#define TWI_STATUS_MR_DATA_NACK          0x58 /* Master received data with NACK */

/***************************************************************************
 *                           Functions prototypes
 * *************************************************************************/

void TWI_init(TWI_configType* configurations);
void TWI_start(void);
void TWI_stop(void);
void TWI_writeByte(uint8 data);
uint8 TWI_readByteWithACK(void);
uint8 TWI_readByteWithNACK(void);
uint8 TWI_getStatus(void);


#endif /* TWI_H_ */
