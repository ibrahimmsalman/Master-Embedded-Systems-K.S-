/*
 * HICU_Interface.h
 *
 *  Created on: Apr 1, 2024
 *      Author: Admin
 */

#ifndef HAL_HICU_HICU_INTERFACE_H_
#define HAL_HICU_HICU_INTERFACE_H_

void HICU_voidInit(void);
void HICU_GetVlues (u32 *ptr_u32frequence , u8 * ptr_u8DC);
void HICU_voidStart	(void);
void HICU_voidStop	(void);


#endif /* HAL_HICU_HICU_INTERFACE_H_ */
