/*
 * MFLASH_Interface.h
 *
 *  Created on: May 23, 2024
 *      Author: Ibrahim Salman
 */

#ifndef MFDI_INTERFACE_H_
#define MFDI_INTERFACE_H_

void MFDI_voidEraseSector(char copy_u8SectorNum);
void MFDI_voidEraseAppSector(void);
void MFDI_voidWrite(int copy_u32Address, short *copy_u16ptData,char copy_u8Length);

#endif /* MFLASH_INTERFACE_H_ */
