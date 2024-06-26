/*************************************************************************/
/* Project       : IbrahimOS  	                           				 */
/* File          : scheduler.c 			                           		 */
/* Version       : V1                                                    */
/*************************************************************************/

#include "scheduler.h"
#include "IbrahimOS_FIFO.h"

static struct{
	Task_ref *OS_Tasks[MAX_NO_TASKS]; /* Scheduling Table */
	uint8  NoOfActiveTasks;
	uint32 _S_MSP_OS;
	uint32 _E_MSP_OS;
	uint32 PSP_Task_Locator;
	Task_ref *CurrentTask;
	Task_ref *NextTask;
	enum{
		OS_Suspended,
		OS_Running,
		OS_Error
	}OS_ModeID;
}OS_Control;

typedef enum{
	SVC_ActivateTask,
	SVC_TerminateTask,
	SVC_TaskWaitingTime
}SVC_ID;

static FIFO_Buf_t Ready_QUEUE;
static Task_ref *Ready_QUEUE_FIFO[MAX_NO_TASKS];
static Task_ref IDLE_TASK;

static void IbrahimOS_IdleTask(void);
static void IbrahimOS_Create_TaskStack(Task_ref* newTask);
static void IbrahimOS_UpdateSchedulerTable(void);
static void IbrahimOS_BubbleSort(void);
static void IbrahimOS_DecideNextTask(void);

void IbrahimOS_Set_SVC (SVC_ID ID){
	switch(ID){
	case SVC_ActivateTask:
		__asm ("svc #0x00");
		break;
	case SVC_TerminateTask:
		__asm ("svc #0x01");
		break;
	case SVC_TaskWaitingTime:
		__asm ("svc #0x02");
		break;
	}
}

static void IbrahimOS_DecideNextTask(void){
	/* If Ready Queue is empty && OS_Control->CurrentTask != Suspended */
	if(Ready_QUEUE.counter == 0 && OS_Control.CurrentTask->TaskState != Suspended){
	OS_Control.CurrentTask->TaskState = Running;

	/* Add the current task again (Round Robin) */
	FIFO_enqueue(&Ready_QUEUE, OS_Control.CurrentTask);
	OS_Control.NextTask = OS_Control.CurrentTask;
	}
	else{
		FIFO_dequeue(&Ready_QUEUE, &OS_Control.NextTask);
		OS_Control.NextTask->TaskState = Running;

		/* Update Ready Queue (To keep round robin algorithm) */
		if((OS_Control.CurrentTask->Priority == OS_Control.NextTask->Priority) && (OS_Control.CurrentTask->TaskState != Suspended)){
			FIFO_enqueue(&Ready_QUEUE, OS_Control.CurrentTask);
			OS_Control.CurrentTask->TaskState = Ready;
		}
	}
}

/* Used to execute specific OS Services */
void IbrahimOS_SVC_services (uint32 *StackFramePointer){
	/* OS_SVC_Set Stack -> r0 -> argument0 = StackFramePointer
	   OS_SVC_Set : r0,r1,r2,r3,r12,LR,PC,xPSR */
	uint8 SVC_number;
	SVC_number = *((uint8*)((uint8*)(StackFramePointer[6])) - 2);
	switch(SVC_number){
	case SVC_ActivateTask:
		/* Update Scheduler Table and Ready Queue */
		IbrahimOS_UpdateSchedulerTable();

		/* If OS is in running state -> Decide what next task */
		if(OS_Control.OS_ModeID == OS_Running){
			if(STRING_compare_caseSensitive((uint8*)OS_Control.CurrentTask->TaskName, (uint8*)"idletask") != 0){
				IbrahimOS_DecideNextTask();

				/* Switch/Restore Context */
				Trigger_OS_PendSV();
			}
		}

		/*Trigger OS PendSV (Switch context/restore) */

		break;
	case SVC_TerminateTask:
		__asm ("svc #0x01");
		break;
	case SVC_TaskWaitingTime:
		__asm ("svc #0x02");
		break;
	}
}

void PendSV_Handler(void){
	/* Save context of current task */
	/* 1- Get the current task PSP */
	OS_GET_PSP(OS_Control.CurrentTask->Current_PSP);

	/* 2- Use the PSP to store R4 to R11 */
	OS_Control.CurrentTask->Current_PSP--;
	__asm volatile ("mov %0, r4" : "=r" (*(OS_Control.CurrentTask->Current_PSP)));
	OS_Control.CurrentTask->Current_PSP--;
	__asm volatile ("mov %0, r5" : "=r" (*(OS_Control.CurrentTask->Current_PSP)));
	OS_Control.CurrentTask->Current_PSP--;
	__asm volatile ("mov %0, r6" : "=r" (*(OS_Control.CurrentTask->Current_PSP)));
	OS_Control.CurrentTask->Current_PSP--;
	__asm volatile ("mov %0, r7" : "=r" (*(OS_Control.CurrentTask->Current_PSP)));
	OS_Control.CurrentTask->Current_PSP--;
	__asm volatile ("mov %0, r8" : "=r" (*(OS_Control.CurrentTask->Current_PSP)));
	OS_Control.CurrentTask->Current_PSP--;
	__asm volatile ("mov %0, r9" : "=r" (*(OS_Control.CurrentTask->Current_PSP)));
	OS_Control.CurrentTask->Current_PSP--;
	__asm volatile ("mov %0, r10" : "=r" (*(OS_Control.CurrentTask->Current_PSP)));
	OS_Control.CurrentTask->Current_PSP--;
	__asm volatile ("mov %0, r11" : "=r" (*(OS_Control.CurrentTask->Current_PSP)));

	/* Restore context of next task */
	OS_Control.CurrentTask = OS_Control.NextTask;
	OS_Control.NextTask = NULL;

	SCB->ICSR |= SCB_ICSR_PENDSVCLR_Msk;
}

static void IbrahimOS_UpdateSchedulerTable(void){
	Task_ref *temp = NULL;
	Task_ref *pTask, *pNextTask;
	uint8 i = 0;

	/* Bubble sort Scheduler Table */
	IbrahimOS_BubbleSort();

	/* Free Ready Queue */
	while(FIFO_dequeue(&Ready_QUEUE, &temp) != FIFO_EMPTY);

	/* Update Ready Queue */
	while(i < OS_Control.NoOfActiveTasks){
		pTask = OS_Control.OS_Tasks[i];
		pNextTask = OS_Control.OS_Tasks[i + 1];

		if(pTask->TaskState != Suspended){
			/* In case we reached to the end of available OSTasks */
			if(pNextTask->TaskState == Suspended){
				FIFO_enqueue(&Ready_QUEUE, pTask);
				pTask->TaskState = Ready;
				break;
			}
			/* Check for priority */
			if(pTask->Priority < pNextTask->Priority){
				/* Current task have higher priority */
				FIFO_enqueue(&Ready_QUEUE, pTask);
				pTask->TaskState = Ready;
				break;
			}
			else if(pTask->Priority == pNextTask->Priority){
				/* If both tasks have the same priority
				 * Push pTask to ready state
				 * Make the pTask = pNextTask and pNextTask++
				 */
				FIFO_enqueue(&Ready_QUEUE, pTask);
				pTask->TaskState = Ready;
			}
			else if(pTask->Priority > pNextTask->Priority){
				/* Not allowed to happen because we already did bubble sort */
				break;
			}
		}
		i++;
	}
}

static void IbrahimOS_BubbleSort(void){
	uint8 i, j, n;
	Task_ref *temp;
	n = OS_Control.NoOfActiveTasks;
	for(i = 0; i < (n - 1); i++){
		for(j = 0; j < (n - i - 1); j++){
			if(OS_Control.OS_Tasks[j]->Priority > OS_Control.OS_Tasks[j+1]->Priority){
				temp = OS_Control.OS_Tasks[j];
				OS_Control.OS_Tasks[j] = OS_Control.OS_Tasks[j+1];
				OS_Control.OS_Tasks[j+1] = temp;
			}
		}
	}
}

void IbrahimOS_Create_MainStack(void){
	OS_Control._S_MSP_OS = (uint32)&_estack;
	OS_Control._E_MSP_OS = OS_Control._S_MSP_OS - MainStackSize;
	/* Allign 8 Bytes spaces between Main Stack and PSP Stack */
	OS_Control.PSP_Task_Locator = OS_Control._E_MSP_OS - 8;
}

IbrahimOS_errorTypes IbrahimOS_Init(void){
	IbrahimOS_errorTypes retval = noError;
	/* Update OS Mode -> OS_Suspended */
	OS_Control.OS_ModeID = OS_Suspended;

	/* Specify the Main Stack for OS */
	IbrahimOS_Create_MainStack();

	/* Create OS Ready Queue */
	if(FIFO_init(&Ready_QUEUE, Ready_QUEUE_FIFO, MAX_NO_TASKS) != FIFO_NO_ERROR){
		retval |= readyQueueInitError;
	}

	/* Configure IDLE Task */
	if(!retval){ /* No error */
		STRING_copy((uint8*)"idletask", (uint8*)&(IDLE_TASK.TaskName));
		IDLE_TASK.Priority = 255; // Max value for uint8 = highest priority
		IDLE_TASK.pf_TaskEntry = IbrahimOS_IdleTask;
		IDLE_TASK.Stack_Size = 300;
		retval |= IbrahimOS_CreateTask(&IDLE_TASK);
	}

	return retval;
}

static void IbrahimOS_IdleTask(){
	while(1){
		__asm ("NOP");
	}
}

IbrahimOS_errorTypes IbrahimOS_CreateTask(Task_ref* newTask){
	IbrahimOS_errorTypes retval = noError;

	/* Check if task stack size exceeds the PSP Stack */
	newTask->_S_PSP_Task = OS_Control.PSP_Task_Locator;
	newTask->_E_PSP_Task = newTask->_S_PSP_Task - newTask->Stack_Size;
	if(newTask->_E_PSP_Task < (uint32)&_eheap){
		return taskExceededStackSize;
	}

	/* Create the task stack area in PSP */
	IbrahimOS_Create_TaskStack(newTask);

	/* Allign 8Bytes spaces between Task PSP and new one */
	if(!retval){ /* No error */
		OS_Control.PSP_Task_Locator = newTask->_E_PSP_Task - 8;
	}

	/* Task State Update */
	if(newTask->AutoStart == enabled){
		newTask->TaskState = Ready;
	}
	else{
		newTask->TaskState = Suspended;
	}

	return retval;
}

static void IbrahimOS_Create_TaskStack(Task_ref* newTask){
	/*
	 * Task Frame
	 * ==========
	 * CPU Saved registers
	 *
	 * xPSR
	 * PC (Next instruction to be executed in the task)
	 * LR (return register which is saved in CPU before switching)
	 * r12
	 * r4
	 * r3
	 * r2
	 * r1
	 * r0
	 * ==========
	 * Manually Saved/Restored registers
	 *
	 * r5
	 * r6
	 * r7
	 * r8
	 * r9
	 * r10
	 * r11
	 */
	uint8 index;

	newTask->Current_PSP = (uint32*)newTask->_S_PSP_Task;

	/* xPSR dummy value -> T = 1 to avoid bus faults */
	newTask->Current_PSP--;
	*(newTask->Current_PSP) = 0x01000000;

	/* PC dummy value -> Start at task entry point*/
	newTask->Current_PSP--;
	*(newTask->Current_PSP) = (uint32)newTask->pf_TaskEntry;

	/* LR dummy value -> Return to thread mode with PSP */
	newTask->Current_PSP--;
	*(newTask->Current_PSP) = 0xFFFFFFFD;

	/* Zero CPU registers r0 -> r12 */
	for(index = 0; index < 13; index++){
		newTask->Current_PSP--;
		*(newTask->Current_PSP) = 0;
	}
}

IbrahimOS_errorTypes IbrahimOS_ActivateTask(Task_ref* pTask){
	IbrahimOS_errorTypes retval = noError;

	/* Change Task State */
	pTask->TaskState = Waiting;

	IbrahimOS_Set_SVC(SVC_ActivateTask);

	return retval;
}

IbrahimOS_errorTypes IbrahimOS_TerminateTask(Task_ref* pTask){
	IbrahimOS_errorTypes retval = noError;

	/* Change Task State */
	pTask->TaskState = Suspended;

	IbrahimOS_Set_SVC(SVC_TerminateTask);

	return retval;
}
