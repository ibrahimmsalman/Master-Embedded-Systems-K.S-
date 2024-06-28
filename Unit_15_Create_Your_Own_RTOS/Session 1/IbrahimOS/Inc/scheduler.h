/*************************************************************************/
/* Project       : IbrahimOS  	                                       	 */
/* File          : scheduler.h 			                           		 */
/* Version       : V1                                                    */
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
	taskExceededStackSize
}IbrahimOS_errorTypes;

typedef struct{
	const char TaskName[30];
	boolean AutoStart;
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

//----------------------------------------------
// Section: Macros Configuration References
//----------------------------------------------
#define MAX_NO_TASKS	100


/*
 * =============================================
 * APIs Supported by "Scheduler"
 * =============================================
 */

/**=============================================
 * @Fn			- 
 * @brief 		- 
 * @param [in] 	- 
 * @retval 		- 
 * Note			- 
 */
IbrahimOS_errorTypes IbrahimOS_Init(void);
IbrahimOS_errorTypes IbrahimOS_CreateTask(Task_ref* newTask);

#endif /* INC_SCHEDULER_H_ */
