/*
 * SRTOS_Private.h
 *
 *  Created on: 30 Apr 2024
 *      Author: User
 */

#ifndef SRTOS_PRIVATE_H_
#define SRTOS_PRIVATE_H_


/****************************************************************************/
/*						TASK STRUCTURE									*/
/****************************************************************************/
typedef enum
{
	susbend = 1,
	resume
}State_e;


typedef struct{
	u32 Task_periodicity		;
	PtrToFunc_void Task_Func	;
	State_e T_state				;
}TCB_t;



/************************************************************************************************/
/*									PRIVATE FUNCTIONS 											*/
/************************************************************************************************/

static void SRTOS_voidSchedular(void);

#define SUSBEND		1
#define RESUME		2



#endif /* SRTOS_PRIVATE_H_ */
