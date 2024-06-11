/*
 * SRTOS_Interface.h
 *
 *  Created on: 30 Apr 2024
 *      Author: User
 */

#ifndef SRTOS_INTERFACE_H_
#define SRTOS_INTERFACE_H_



/************************************************************************************************/
/*									FUNCTIONS API's												*/
/************************************************************************************************/

void SRTOS_voidInit(void);
void SRTOS_voidStartSchedular(void);
ReturnType_State_t SRTOS_u8CreateTask(u8 copy_u8TaskPriority,u32 copy_u32Periodicity,PtrToFunc_void copy_TaskFunc);
ReturnType_State_t SRTOS_u8DeleteTask(u8 copy_u8TaskPriority);
void SRTOS_u8SusbendTask(u8 copy_u8TaskPriority);
void SRTOS_u8ResumeTask(u8 copy_u8TaskPriority);


#endif /* SRTOS_INTERFACE_H_ */
