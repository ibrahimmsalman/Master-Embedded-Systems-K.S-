/*
 * MSPI_Interface.h
 *
 *  Created on: May 13, 2024
 *      Author: Admin
 */

#ifndef MSPI_INTERFACE_H_
#define MSPI_INTERFACE_H_

void MSPI_VoidInit(void);

void MSPI_voidTranceive (u8 Copy_u8TransmitData , u8 * Copy_u8ReceiveData);

void SPI_u8BufferTranceiverAsynch (u8 * Copy_u8TData , u8 * Copy_u8RData, u8 Copy_u8BufferSize);
void SPI_u8BufferTranceiverSynch (u8 * Copy_u8TData , u8 * Copy_u8RData , u8 Copy_u8BufferSize);




#endif /* MSPI_INTERFACE_H_ */
