/*
 * BUZZER_Interface.h
 *
 *  Created on: Apr 7, 2024
 *      Author: Ibrahim
 */

#ifndef HAL_BUZZER_BUZZER_INTERFACE_H_
#define HAL_BUZZER_BUZZER_INTERFACE_H_

// Port Defines
#define  BUZ_PORTA  0
#define  BUZ_PORTB  1
#define  BUZ_PORTC  2
#define  BUZ_PORTD  3


// PIN Defines
#define BUZ_PIN0   0
#define BUZ_PIN1   1
#define BUZ_PIN2   2
#define BUZ_PIN3   3
#define BUZ_PIN4   4
#define BUZ_PIN5   5
#define BUZ_PIN6   6
#define BUZ_PIN7   7

#define ACTIVE_HIGH    1
#define ACTIVE_LOW     0


/**************************************************************/
/*					BUZZER TYPE STRUCT						  */
/**************************************************************/
typedef struct{

	u8 Port         ;
	u8 Pin          ;
	u8 Active_State ;

}BUZ_Type;


/**************************************************************/
/*					FUNCTIONS PROTOTYPES					  */
/**************************************************************/
void BUZ_voidInit( BUZ_Type BUZ_Configuration);
void BUZ_voidOn( BUZ_Type BUZ_Configuration);
void BUZ_voidOff( BUZ_Type BUZ_Configuration);
void BUZ_voidToggle( BUZ_Type BUZ_Configuration);


#endif /* HAL_BUZZER_BUZZER_INTERFACE_H_ */
