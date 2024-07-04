/*
 * STEPPER_Interface.h
 *
 *  Created on: Mar 21, 2024
 *      Author: Admin
 */

#ifndef HAL_STEPPER_STEPPER_INTERFACE_H_
#define HAL_STEPPER_STEPPER_INTERFACE_H_

/*********FUNCTIONS PROTOTYPES****/
void STEPPER_voidInit(void);
void STEPPER_voidRotate(u8 copy_u8Direction);





/*********USER MACROS*********/
#define NORTH				0
#define EASTERN_NORTH		1

#define EAST				2
#define EASTERN_SOUTH		3

#define SOUTH				4
#define WESTERN_SOUTH		5

#define WEST				6
#define WESTERN_NORTH		7

#endif /* HAL_STEPPER_STEPPER_INTERFACE_H_ */
