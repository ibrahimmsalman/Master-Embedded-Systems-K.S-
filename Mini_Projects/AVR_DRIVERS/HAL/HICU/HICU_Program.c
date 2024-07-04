/*
 * HICU_Program.c
 *
 *  Created on: Apr 1, 2024
 *      Author: Admin
 */

/************************LIB*************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_Types.h"
/*********************MCAL************************************/
#include "../../MCAL/GIE/GIE_Interface.h"
#include "../../MCAL/EXTI/EXTI_Interface.h"
#include "../../MCAL/TIMERS/TIMERS_Interface.h"

/****************************HAL*********************************/
#include "HICU_Config.h"
#include "HICU_Interface.h"
#include "HICU_Private.h"
/***********************global variable***************************/
volatile static f32 DC=0;
volatile static f32 frequence=0;

void HICU_voidInit(void){
	EXTI_voidInit();
#if( HICU_ATTACHED_EXTI==ATTACHED_TO_EXTI0)
	EXTI_u8SetInt0SenseControl(RISING_EDGE);
	EXTI_u8Int0SetCallBack(&HICU_voidOpration);
#elif( HICU_ATTACHED_EXTI==ATTACHED_TO_EXTI1)
	EXTI_u8SetInt1SenseControl(RISING_EDGE);
	EXTI_u8Int1SetCallBack(&HICU_voidOpration);
#elif( HICU_ATTACHED_EXTI==ATTACHED_TO_EXTI2)
	EXTI_u8SetInt2SenseControl(RISING_EDGE);
	EXTI_u8Int2SetCallBack(&HICU_voidOpration);
#else
#error "Wrong configuration For EXTI"
#endif
	GIE_voidEnable();
}

void HICU_GetVlues(u32 *ptr_frequence,u8 * ptr_DC){
	*ptr_frequence= (u32)frequence;
	frequence=0;
	*ptr_DC=(u8)DC;
	DC=0;
}
void HICU_voidStart (void){
	//Enable EXTI
}

void HICU_voidStop (void){
	//Disable EXTI
}
/***********************Interrupt*********************************/
static void HICU_voidOpration(void){
	volatile static u8 states=FIRST_RISING;
	volatile static u16 local_u16ReadCycleVarabile=0;
	volatile static u16 local_u16ReadCycleBuffer=0;
	volatile static u32 t_on_us=0;
	volatile static u32 t_off_us=0;
	switch(states){
	case FIRST_RISING:
#if( HICU_ATTACHED_EXTI==ATTACHED_TO_EXTI0)
		EXTI_u8SetInt0SenseControl(FALLING_EDGE);
#elif( HICU_ATTACHED_EXTI==ATTACHED_TO_EXTI1)
		EXTI_u8SetInt1SenseControl(FALLING_EDGE);
#elif( HICU_ATTACHED_EXTI==ATTACHED_TO_EXTI2)
		EXTI_u8SetInt2SenseControl(FALLING_EDGE);
#else
#error "Wrong configuration For EXTI"
#endif
#if( HICU_ATTACHED_TIMER==ATTACHED_TO_TIM0)
		local_u16ReadCycleVarabile=(u8)TIMER0_u8GetTimerCounterValue();
#elif( HICU_ATTACHED_TIMER==ATTACHED_TO_TIM1)
		local_u16ReadCycleVarabile=TIMER1_u8GetTimerCounterValue();
#elif( HICU_ATTACHED_TIMER==ATTACHED_TO_TIM2)
		local_u16ReadCycleVarabile=(u8)TIMER2_u8GetTimerCounterValue();
#else
#error "Wrong configuration For TIMER"
#endif
		states=FALLING;
		break;
	case FALLING:
#if( HICU_ATTACHED_EXTI==ATTACHED_TO_EXTI0)
		EXTI_u8SetInt0SenseControl(RISING_EDGE);
		EXTI_u8Int0SetCallBack(&HICU_voidOpration);
#elif( HICU_ATTACHED_EXTI==ATTACHED_TO_EXTI1)
		EXTI_u8SetInt1SenseControl(RISING_EDGE);
		EXTI_u8Int1SetCallBack(&HICU_voidOpration);
#elif( HICU_ATTACHED_EXTI==ATTACHED_TO_EXTI2)
		EXTI_u8SetInt2SenseControl(RISING_EDGE);
		EXTI_u8Int2SetCallBack(&HICU_voidOpration);
#else
#error "Wrong configuration For EXTI"
#endif
#if( HICU_ATTACHED_TIMER==ATTACHED_TO_TIM0)
		local_u16ReadCycleBuffer=(u8)TIMER0_u8GetTimerCounterValue();
		t_on_us=((u8)(local_u16ReadCycleBuffer-local_u16ReadCycleVarabile))*TICK_TIME_US;
		local_u16ReadCycleVarabile=local_u16ReadCycleBuffer;
#elif( HICU_ATTACHED_TIMER==ATTACHED_TO_TIM1)
		local_u16ReadCycleBuffer=TIMER1_u8GetTimerCounterValue();
		t_on_us=((local_u16ReadCycleBuffer-local_u16ReadCycleVarabile))*TICK_TIME_US;
		local_u16ReadCycleVarabile = local_u16ReadCycleBuffer;
#elif( HICU_ATTACHED_TIMER==ATTACHED_TO_TIM2)
		local_u16ReadCycleBuffer=(u8)TIMER2_u8GetTimerCounterValue();
		t_on_us=((u8)(local_u16ReadCycleBuffer-local_u16ReadCycleVarabile))*TICK_TIME_US;
		local_u16ReadCycleVarabile=local_u16ReadCycleBuffer;
#else
#error "Wrong configuration For TIMER"
#endif
		states=SECOND_RISING;
		break;
	case SECOND_RISING:
#if( HICU_ATTACHED_TIMER==ATTACHED_TO_TIM0)
		local_u16ReadCycleBuffer=(u8)TIMER0_u8GetTimerCounterValue();
		t_off_us=((u8)(local_u16ReadCycleBuffer-local_u16ReadCycleVarabile))*TICK_TIME_US;
#elif( HICU_ATTACHED_TIMER==ATTACHED_TO_TIM1)
		local_u16ReadCycleBuffer=TIMER1_u8GetTimerCounterValue();
		t_off_us=((local_u16ReadCycleBuffer-local_u16ReadCycleVarabile))*TICK_TIME_US;
#elif( HICU_ATTACHED_TIMER==ATTACHED_TO_TIM2)
		local_u16ReadCycleBuffer=(u8)TIMER2_u8GetTimerCounterValue();
		t_off_us=((u8)(local_u16ReadCycleBuffer-local_u16ReadCycleVarabile))*TICK_TIME_US;
#else
#error "Wrong configuration For TIMER"
#endif
		frequence=1000000/(t_on_us+t_off_us);
		DC=((f32)t_on_us/(t_on_us+t_off_us))*100;
		states=FIRST_RISING;
		break;
	default:
		break;
	}

}


