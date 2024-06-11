/*
 * MSYSTICK_Program.c
 *
 *  Created on: Apr 30, 2024
 *      Author: Admin
 */

/************************************************************************************************/
/*										FILE INCLUSION											*/
/************************************************************************************************/
/***********************LIB*************************/
/************************************************************************************************/
/*										FILE INCLUSION											*/
/************************************************************************************************/
/***********************LIB*************************/
#include "../include/LIB/BIT_Math.h"
#include "../include/LIB/STD_Types.h"

/***********************MCAL*************************/
#include "../include/MCAL/MSYSTICK/MSYSTICK_Config.h"
#include "../include/MCAL/MSYSTICK/MSYSTICK_Interface.h"
#include "../include/MCAL/MSYSTICK/MSYSTICK_Private.h"
#include "../include/MCAL/MRCC/MRCC_Interface.h"

static PtrToFunc_void MSYSTICK_callBack = NULL;
static u8 Global_u8StateFlag = NULL;

/************************************************************************/
/*						   FUNCTIONS DEFINITIONS						*/
/************************************************************************/

static u32 MSYSTICK_PdMS(u16 copy_u16TimePeriod)
{
	u32 Local_u32TicksNumber, AHB_Clock;
	u16 AHB_Prescaler;

	AHB_Prescaler = MRCC_voidGetAHBPrescaler();

	AHB_Clock = SYSTEM_CLOCK/AHB_Prescaler;

	Local_u32TicksNumber = ( (copy_u16TimePeriod) * ((AHB_Clock) / (1000)) );

	return Local_u32TicksNumber;
}

static u32 MSYSTICK_PdUS(u16 copy_u16TimePeriod)
{
	u32 Local_u32TicksNumber, AHB_Clock;
	u16 AHB_Prescaler;

	AHB_Prescaler = MRCC_voidGetAHBPrescaler();

	AHB_Clock = SYSTEM_CLOCK/AHB_Prescaler;

	Local_u32TicksNumber = ((copy_u16TimePeriod) * ((AHB_Clock) / (1000000)) );

	return Local_u32TicksNumber;

}

static u16 MSYSTICK_GetPeriod(u32 copy_u32TicksNumber)
{
	u32 AHB_Clock;
	u32 Local_u32TickPeriod;
	u16 Local_u16TimePeriod;
	u8 AHB_Prescaler;


	AHB_Prescaler = MRCC_voidGetAHBPrescaler();

	AHB_Clock = SYSTEM_CLOCK/AHB_Prescaler;

	Local_u16TimePeriod = copy_u32TicksNumber * Local_u32TickPeriod;

	return Local_u16TimePeriod;
}


void MSYSTICK_voidInit(void)
{
	/*Choose CLK_SRC for Systick*/
	#if	CLK_SRC == SYSTICK_AHB_PRESCALER_BY_1
		SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_CLKSOURCE);

	#elif CLK_SRC == SYSTICK_AHB_PRESCALER_BY_8
		CLR_BIT(SYSTICK->STK_CTRL,STK_CTRL_CLKSOURCE);
	#else
		#error "Wrong CLK_SRC Configuration Parameters"
	#endif

	/*disable Interrupt*/
	CLR_BIT(SYSTICK->STK_CTRL,STK_CTRL_TICKINT);
}


void MSYSTICK_voidSetBusyWait(u32 copy_u32Ticks)
{
	/* Load the Value -> Load Register*/
	SYSTICK->STK_LOAD = copy_u32Ticks;

	/*Enable the timer*/
	SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_ENABLE);

	/*Wait for flag & Cleared by be reading*/
	while(GET_BIT(SYSTICK->STK_CTRL,STK_CTRL_COUNTFLAG) == SYSTICK_COUNTING);

	/*Clear Registers*/
	SYSTICK->STK_LOAD = CLEAR_VALUE;
	SYSTICK->STK_VAL = CLEAR_VALUE;
}

void MSYSTICK_voidSetBusyWait_ms(u16 copy_u16TimePeriod)
{
	u64 copy_u32Ticks=0;
	/*Time Ticks Calculations*/
	copy_u32Ticks= MSYSTICK_PdMS(copy_u16TimePeriod);
	/* Load the Value -> Load Register*/
	SYSTICK->STK_LOAD = copy_u32Ticks;

	/*Enable the timer*/
	SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_ENABLE);

	/*Wait for flag & Cleared by be reading*/
	while(GET_BIT(SYSTICK->STK_CTRL,STK_CTRL_COUNTFLAG) == SYSTICK_COUNTING);

	/*Clear Registers*/
	SYSTICK->STK_LOAD = CLEAR_VALUE;
	SYSTICK->STK_VAL = CLEAR_VALUE;
}


void MSYSTICK_voidSetBusyWait_us(u32 copy_u32TimePeriod)
{
	u32 copy_u32Ticks;
	/*Time Ticks Calculations*/
	copy_u32Ticks= MSYSTICK_PdUS(copy_u32TimePeriod);
	/* Load the Value -> Load Register*/
	SYSTICK->STK_LOAD = copy_u32Ticks;

	/*Enable the timer*/
	SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_ENABLE);

	/*Wait for flag & Cleared by be reading*/
	while(GET_BIT(SYSTICK->STK_CTRL,STK_CTRL_COUNTFLAG) == SYSTICK_COUNTING);

	/*Clear Registers*/
	SYSTICK->STK_LOAD = CLEAR_VALUE;
	SYSTICK->STK_VAL = CLEAR_VALUE;
}


void MSYSTICK_voidSetSingleInterval(u32 copy_u32Ticks,PtrToFunc_void copy_callBackFunc)
{
	/*Load ticks to Load Register*/
	SYSTICK->STK_LOAD = copy_u32Ticks;

	/*Enable Timer*/
	SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_ENABLE);

	/*Save function address*/
	MSYSTICK_callBack= copy_callBackFunc;

	/*assign global variable as single*/
	Global_u8StateFlag = SINGLE;

	/*Enable Interrupt*/
	SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_TICKINT);
}

void MSYSTICK_voidSetSingleInterval_ms(u16 copy_u16TimePeriod,PtrToFunc_void copy_callBackFunc)
{
	u64 copy_u32Ticks;
	/*Time Ticks Calculations*/
	copy_u32Ticks= MSYSTICK_PdMS(copy_u16TimePeriod);

	/*Load ticks to Load Register*/
	SYSTICK->STK_LOAD = copy_u32Ticks;

	/*Enable Timer*/
	SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_ENABLE);

	/*Save function address*/
	MSYSTICK_callBack= copy_callBackFunc;

	/*assign global variable as single*/
	Global_u8StateFlag = SINGLE;

	/*Enable Interrupt*/
	SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_TICKINT);
}


void MSYSTICK_voidSetSingleInterval_us(u32 copy_u32TimePeriod,PtrToFunc_void copy_callBackFunc)
{
	u32 copy_u32Ticks;
	/*Time Ticks Calculations*/
	copy_u32Ticks= MSYSTICK_PdUS(copy_u32TimePeriod);

	/*Load ticks to Load Register*/
	SYSTICK->STK_LOAD = copy_u32Ticks;

	/*Enable Timer*/
	SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_ENABLE);

	/*Save function address*/
	MSYSTICK_callBack= copy_callBackFunc;

	/*assign global variable as single*/
	Global_u8StateFlag = SINGLE;

	/*Enable Interrupt*/
	SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_TICKINT);
}

void MSYSTICK_voidSetPeriodicInterval(u32 copy_u32Ticks,PtrToFunc_void copy_callBackFunc)
{
	/*Load ticks to Load Register*/
	SYSTICK->STK_LOAD = copy_u32Ticks;

	/*Enable Timer*/
	SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_ENABLE);

	/*Save function address*/
	MSYSTICK_callBack= copy_callBackFunc;

	/*assign global variable as single*/
	Global_u8StateFlag = PERIODIC;

	/*Enable Interrupt*/
	SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_TICKINT);
}

void MSYSTICK_voidSetPeriodicInterval_ms(u16 copy_u16TimePeriod,PtrToFunc_void copy_callBackFunc)
{
	u32 copy_u32Ticks;
	/*Time Ticks Calculations*/
	copy_u32Ticks= MSYSTICK_PdMS(copy_u16TimePeriod);

	/*Load ticks to Load Register*/
	SYSTICK->STK_LOAD = copy_u32Ticks;

	/*Enable Timer*/
	SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_ENABLE);

	/*Save function address*/
	MSYSTICK_callBack= copy_callBackFunc;

	/*assign global variable as single*/
	Global_u8StateFlag = PERIODIC;

	/*Enable Interrupt*/
	SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_TICKINT);
}

void MSYSTICK_voidSetPeriodicInterval_us(u32 copy_u32TimePeriod,PtrToFunc_void copy_callBackFunc)
{
	u32 copy_u32Ticks;
	/*Time Ticks Calculations*/
	copy_u32Ticks= MSYSTICK_PdUS(copy_u32TimePeriod);

	/*Load ticks to Load Register*/
	SYSTICK->STK_LOAD = copy_u32Ticks;

	/*Enable Timer*/
	SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_ENABLE);

	/*Save function address*/
	MSYSTICK_callBack= copy_callBackFunc;

	/*assign global variable as single*/
	Global_u8StateFlag = PERIODIC;

	/*Enable Interrupt*/
	SET_BIT(SYSTICK->STK_CTRL,STK_CTRL_TICKINT);
}

u32 MSYSTICK_u32GetElapsedTime(void)
{
	return ((SYSTICK->STK_LOAD) - (SYSTICK->STK_VAL));
}

u16 MSYSTICK_u16GetElapsedTime_ms(void)
{
	u32 Local_u32Ticks;
	u16 Local_u16TimePeriod;
	Local_u32Ticks = (SYSTICK->STK_LOAD) - (SYSTICK->STK_VAL);
	Local_u16TimePeriod = MSYSTICK_GetPeriod(Local_u32Ticks);
	Local_u16TimePeriod *=1000;
	return (Local_u16TimePeriod);
}

u32 MSYSTICK_u32GetRemainingTime(void)
{
	return ((SYSTICK->STK_VAL));
}

u16 MSYSTICK_u16GetRemainingTime_ms(void)
{
	u32 Local_u32Ticks;
	u16 Local_u16TimePeriod;
	Local_u32Ticks = (SYSTICK->STK_VAL);
	Local_u16TimePeriod = MSYSTICK_GetPeriod(Local_u32Ticks);
	Local_u16TimePeriod *=1000;
	return (Local_u16TimePeriod);
}

void SysTick_Handler(void)
{
	if(MSYSTICK_callBack != NULL)
	{
		u8 Local_u8StateFlag = 0;
		if(Global_u8StateFlag == SINGLE)
		{
			/*Stop Timer*/
			CLR_BIT(SYSTICK->STK_CTRL,STK_CTRL_ENABLE);
			/*Disable Interrupt*/
			CLR_BIT(SYSTICK->STK_CTRL,STK_CTRL_TICKINT);
			/*Clear Registers*/
			SYSTICK->STK_LOAD = CLEAR_VALUE;
			SYSTICK->STK_VAL = CLEAR_VALUE;
		}
		else
		{

		}

		/*Invoke Function*/
		MSYSTICK_callBack();

		/*Clear Flag*/
		Local_u8StateFlag= GET_BIT(SYSTICK->STK_CTRL,STK_CTRL_COUNTFLAG);
	}

}
