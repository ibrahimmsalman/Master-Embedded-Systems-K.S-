/*
 * I2C_Interface.h
 *
 *  Created on: Apr 3, 2024
 *      Author: Admin
 */

#ifndef MCAL_TWI_TWI_INTERFACE_H_
#define MCAL_TWI_TWI_INTERFACE_H_

/**************************************************/
/*				TWI ERROR STATUS				  */
/**************************************************/

typedef enum
{
	NoError,
	StartConditionErr,
	RepeatedStartError,
	SlaveAddressWithWriteErr,
	SlaveAddressWithReadErr,
	MasterWriteByteErr,
	MasterReadByteErr,
	SlaveWriteByteErr,
	SlaveReadByteErr,
	StopConditionErr
}TWI_ErrStatus;


/**************************************************/
/*			TWI	FUNCTIONS PROTOTYPES			  */
/**************************************************/

void TWI_voidInitMaster(u8 Copy_u8Address);

void TWI_voidInitSlave(u8 Copy_u8Address);

TWI_ErrStatus TWI_SendStartCondition(void);

TWI_ErrStatus TWI_SendRepeatedStart(void);

TWI_ErrStatus TWI_SendSlaveAddressWithWrite(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_SendSlaveAddressWithRead(u8 Copy_u8SlaveAddress);

TWI_ErrStatus TWI_MasterWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrStatus TWI_MasterReadDataByte(u8* Copy_pu8DataByte);

TWI_ErrStatus TWI_SlaveWriteDataByte(u8 Copy_u8DataByte);

TWI_ErrStatus TWI_SlaveReadDataByte(u8* Copy_pu8DataByte);


void TWI_SendStopCondition(void);


#endif /* MCAL_TWI_TWI_INTERFACE_H_ */
