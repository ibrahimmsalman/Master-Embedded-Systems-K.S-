/*
 * E2PROM_Interface.h
 *
 *  Created on: Mar 31, 2024
 *      Author: Admin
 */

#ifndef HAL_E2PROM_E2PROM_INTERFACE_H_
#define HAL_E2PROM_E2PROM_INTERFACE_H_

TWI_ErrStatus EEPROM_voidSendDataByte(u16 Copy_u16LocationAddress, u8 Copy_u8DataByte);

TWI_ErrStatus EEPROM_u8ReadDataByte(u16 Copy_u16LocationAddress, u8* Copy_u8ReadDataByte);

#endif /* HAL_E2PROM_INTERFACE_H_ */
