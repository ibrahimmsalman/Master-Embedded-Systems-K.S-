/*
 * KEYPAD_Config.h
 *
 *  Created on: Mar 20, 2024
 *      Author: ahmed
 */

#ifndef HAL_KEYPAD_KEYPAD_CONFIG_H_
#define HAL_KEYPAD_KEYPAD_CONFIG_H_

#define KPD_ROW_INT          GPIO_PIN12
#define KPD_ROW_END          GPIO_PIN15


#define KPD_COL_INT          GPIO_PIN7
#define KPD_COL_END          GPIO_PIN10

#define KPD_PORT             GPIO_PORTB

#define KPD_R0             GPIO_PIN12
#define KPD_R1             GPIO_PIN13
#define KPD_R2             GPIO_PIN14
#define KPD_R3             GPIO_PIN15


#define KPD_C0             GPIO_PIN7
#define KPD_C1             GPIO_PIN8
#define KPD_C2             GPIO_PIN9
#define KPD_C3             GPIO_PIN10


u8  KPD_u8Buttoms[4][4]=
{
		{'7','8','9','/'},
		{'4','5','6','*'},
		{'1','2','3','-'},
		{'?','0','=','+'}

};


#endif /* HAL_KEYPAD_KEYPAD_CONFIG_H_ */
