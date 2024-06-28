/*************************************************************************/
/* Project       : IbrahimOS  	                                       	 */
/* File          : scheduler.h 			                           		 */
/*************************************************************************/
#ifndef INC_SCHEDULER_H_
#define INC_SCHEDULER_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "CortexMX_OS_porting.h"
#include "string_lib.h"

//----------------------------------------------
// Section: User type definitions
//----------------------------------------------
typedef enum{
	noError,
	readyQueueInitError,
	taskExceededStackSize,
	MutexReachedMaxNoOfUsers,
	MutexIsAlreadyAcquired
}IbrahimOS_errorTypes;

typedef struct{
	const char TaskName[30];
	enum{
		Autostart_Disabled,
		Autostart_Enabled
	}AutoStart;
	uint8 Priority;
	void (*pf_TaskEntry)(void); /* Pointer to Task C Function*/

	uint32 Stack_Size;
	uint32 _S_PSP_Task;	 /* Not entered by the user */
	uint32 _E_PSP_Task;	 /* Not entered by the user */
	uint32* Current_PSP; /* Not entered by the user */

	enum{
		Suspended,
		Running,
		Waiting,
		Ready
	}TaskState;

	struct{
		enum{
			enabled,
			disabled
		}Task_Block_State;
		uint32 Ticks_Count;
	}TimeWaiting;
}Task_ref;

typedef struct{
	uint8 *pPayload;
	uint32 PayloadSize;
	Task_ref* CurrentTUser;
	Task_ref* NextTUser;
	char MutexName[30];
	struct{
		enum{
			PriorityCeiling_enabled,
			PriorityCeiling_disabled
		}state;
		uint8 Ceiling_Priority;
		uint8 old_priority;
	}PriorityCeiling;
}Mutex_ref;

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------
#define MAX_NO_TASKS	100


/*
 * =============================================
 * APIs Supported by "IbrahimOS"
 * =============================================
 */

/**=============================================
 * @Fn			- IbrahimOS_Init
 * @brief 		- Initializes the OS control and buffers
 * @retval 		- Returns noError if no error happened or an error code if an error occured
 * Note			- Must be called before using any of the OS APIs
 */
IbrahimOS_errorTypes IbrahimOS_Init(void);

/**=============================================
 * @Fn			- IbrahimOS_CreateTask
 * @brief 		- Creates the task object in the OS and initializes the task's stack area
 * @param [in] 	- newTask: Pointer to the task's configuration
 * @retval 		- Returns noError if no error happened or an error code if an error occured
 * Note			- Should only be called after calling "IbrahimOS_Init"
 */
IbrahimOS_errorTypes IbrahimOS_CreateTask(Task_ref* newTask);

/**=============================================
 * @Fn			- IbrahimOS_ActivateTask
 * @brief 		- Sends a task to the ready queue to be scheduled
 * @param [in] 	- pTask: Pointer to the task's configuration
 * @retval 		- None
 * Note			- Should only be called after calling "IbrahimOS_CreateTask"
 */
void IbrahimOS_ActivateTask(Task_ref* pTask);

/**=============================================
 * @Fn			- IbrahimOS_TerminateTask
 * @brief 		- Sends a task to the suspended state
 * @param [in] 	- pTask: Pointer to the task's configuration
 * @retval 		- None
 * Note			- Should only be called after calling "IbrahimOS_CreateTask"
 */
void IbrahimOS_TerminateTask(Task_ref* pTask);

/**=============================================
 * @Fn			- IbrahimOS_StartOS
 * @brief 		- Starts the OS scheduler to begin running tasks
 * @retval 		- None
 * Note			- Should only be called after calling "IbrahimOS_Init" and creating & activating tasks
 */
void IbrahimOS_StartOS(void);

/**=============================================
 * @Fn			- IbrahimOS_TaskWait
 * @brief 		- Sends a tasks to the waiting state for a specific amount of Ticks
 * @param [in] 	- Ticks: The amount of ticks the task should be suspended before running again
 * @param [in] 	- pTask: Pointer to the task's configuration
 * @retval 		- Returns noError if no error happened or an error code if an error occured
 * Note			- None
 */
void IbrahimOS_TaskWait(uint32 Ticks, Task_ref* pTask);

/**=============================================
 * @Fn			- IbrahimOS_AcquireMutex
 * @brief 		- Tries to acquire a mutex if available
 * @param [in] 	- pMutex: Pointer to the Mutex to be locked
 * @param [in] 	- pTask: Pointer to the task's configuration
 * @retval 		- Returns noError if no error happened or an error code if an error occured
 * Note			- A Mutex can be hold by 2 tasks only at the same time (as in a queue)
 */
IbrahimOS_errorTypes IbrahimOS_AcquireMutex(Mutex_ref* pMutex, Task_ref* pTask);

/**=============================================
 * @Fn			- IbrahimOS_ReleaseMutex
 * @brief 		- Releases a mutex and starts the next task that is in the queue (if found)
 * @param [in] 	- pMutex: Pointer to the Mutex to be locked
 * @retval 		- None
 * Note			- A mutex can only be released by the same task that acquired it
 */
void IbrahimOS_ReleaseMutex(Mutex_ref* pMutex);

#endif /* INC_SCHEDULER_H_ */
