/*************************************************************************/
/* Project       : IbrahimOS  	                           				 */
/* File          : CortexMX_OS_porting.h 			                     */
/*************************************************************************/
#ifndef INC_CORTEXMX_OS_PORTING_H_
#define INC_CORTEXMX_OS_PORTING_H_

//----------------------------------------------
// Section: Includes
//----------------------------------------------
#include "core_cm3.h"
#include "Platform_Types.h"

/* Stack Top */
extern uint32 _estack, _eheap;
#define MainStackSize 3072

//----------------------------------------------
// Section: Macros definitions
//----------------------------------------------

#define Trigger_OS_PendSV() (SCB->ICSR |= SCB_ICSR_PENDSVSET_Msk)

#define OS_SET_PSP(address)	__asm volatile("mov r0, %0 \n\t msr PSP, r0" : :"r" (address))
#define OS_GET_PSP(address)	__asm volatile("mrs r0, PSP \n\t mov %0, r0 \n\t " : "=r" (address))

#define OS_SWITCH_SP_to_PSP() __asm volatile("mrs r0, CONTROL \n\t orr r0, r0, #0x2 \n\t msr CONTROL, r0")
#define OS_SWITCH_SP_to_MSP() __asm volatile("mrs r0, CONTROL \n\t bic r0, r0, #0x2 \n\t msr CONTROL, r0")

#define OS_SET_CPU_PRIVILEGED() __asm volatile("mrs r0, CONTROL \n\t bic r0, r0, #0x1 \n\t msr CONTROL, r0")
#define OS_SET_CPU_UNPRIVILIGED() __asm volatile("mrs r0, CONTROL \n\t orr r0, r0, #0x1 \n\t msr CONTROL, r0")

void HW_Init(void);
void Start_Ticker(void);

#endif /* INC_CORTEXMX_OS_PORTING_H_ */
