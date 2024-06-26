/*************************************************************************/
/* Project       : IbrahimOS  	                             			 */
/* File          : main.c 			                     				 */
/*************************************************************************/

#include "scheduler.h"

Task_ref Task1, Task2, Task3;
uint8	 Task1LED, Task2LED, Task3LED, Task4LED;

void Task_1(void);

void Task_2(void);

void Task_3(void);

int main(void)
{
	IbrahimOS_errorTypes retval = noError;
	/* HW_Init (Initialize Clock tree, Reset Controller) */
	HW_Init();
	retval |= IbrahimOS_Init();

	Task1.Stack_Size = 1024;
	Task1.pf_TaskEntry = Task_1;
	Task1.Priority = 3;
	Task1.AutoStart = FALSE;
	STRING_copy((uint8*)"Task_1", (uint8*)&Task1.TaskName);

	Task2.Stack_Size = 1024;
	Task2.pf_TaskEntry = Task_2;
	Task2.Priority = 3;
	Task2.AutoStart = FALSE;
	STRING_copy((uint8*)"Task_2", (uint8*)&Task2.TaskName);

	Task3.Stack_Size = 1024;
	Task3.pf_TaskEntry = Task_3;
	Task3.Priority = 3;
	Task3.AutoStart = FALSE;
	STRING_copy((uint8*)"Task_3", (uint8*)&Task3.TaskName);

	retval |= IbrahimOS_CreateTask(&Task1);
	retval |= IbrahimOS_CreateTask(&Task2);
	retval |= IbrahimOS_CreateTask(&Task3);

	IbrahimOS_ActivateTask(&Task1);
	IbrahimOS_ActivateTask(&Task2);
	IbrahimOS_ActivateTask(&Task3);

	IbrahimOS_StartOS();

    while(1){

    }
}

void Task_1(void){
	while(1){
		/* Taskl Code */
		Task1LED ^= 1;
	}
}

void Task_2(void){
	while(1){
		/* Task2 Code */
		Task2LED ^= 1;
	}
}

void Task_3(void){
	while(1){
		/* Task3 Code */
		Task3LED ^= 1;
	}
}
