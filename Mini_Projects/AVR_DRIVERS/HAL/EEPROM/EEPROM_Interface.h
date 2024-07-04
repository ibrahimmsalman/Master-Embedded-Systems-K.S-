/*
 * E2PROM_Interface.h
 *
 *  Created on: Mar 31, 2024
 *      Author: Admin
 */

#ifndef HAL_E2PROM_E2PROM_INTERFACE_H_
#define HAL_E2PROM_E2PROM_INTERFACE_H_

void EEPROM_voidInit(void);
void EEPROM_voidSendDataByte(u8 Copy_u8DataByte , u16 Copy_u16Address);
u8 EEPROM_u8ReadDataByte(u16 Copy_u16Adderss);

#endif /* HAL_E2PROM_INTERFACE_H_ */
