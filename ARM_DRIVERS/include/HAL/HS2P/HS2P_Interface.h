/*
 * HS2P_Interface.h
 *
 *  Created on: May 13, 2024
 *      Author: Admin
 */

#ifndef HS2P_INTERFACE_H_
#define HS2P_INTERFACE_H_

typedef enum
{
	ENABLED = 0,
	DISABLED
}ChipState_e;

void S2P_voidInit(void);
void S2P_voidSendByte(char Copy_u8Data);
void S2P_voidChipEnableDisable(ChipState_e Copy_state);
void S2P_voidChipReset(void);




#endif /* HS2P_INTERFACE_H_ */
