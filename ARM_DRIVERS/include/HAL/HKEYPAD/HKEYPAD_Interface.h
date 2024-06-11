/*
 * KEYPAD_Interface.h
 *
 *  Created on: Mar 20, 2024
 *      Author: ahmed
 */

#ifndef HAL_KEYPAD_KEYPAD_INTERFACE_H_
#define HAL_KEYPAD_KEYPAD_INTERFACE_H_

/**********************PROTO************************/
void KPD_Init(void);
u8 KPD_u8GetPressed(void);
/******************************MACROS************/
#define  NOTPRESSED          0xFF

#endif /* HAL_KEYPAD_KEYPAD_INTERFACE_H_ */
