
/********************************************************************************/
/*								FILES INCLUSIONS								*/
/********************************************************************************/
/******************LIB*******************/
/******************LIB*******************/
#include "LIB/STD_Types.h"
#include "LIB/BIT_MATH.h"

/*****************MCAL*******************/
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/USART/USART_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/TIMERS/TIMERS_Interface.h"
/*****************HAL*******************/
#include "HAL/LCD/LCD_Interface.h"
/****************Delay******************/
#include "avr/delay.h"
/************Global Macros**************/
#define OVER_TICKS 122

/************Global Variables***********/
u8 Global_u8Sec = 0, Global_u8Min=0, Global_u8Hrs=0, Global_u8Counter=0, Global_PauseFlag=0;

/***************Handlers****************/

void Timer_Function(void)
{
	if(Global_PauseFlag == 0)
	{
		Global_u8Counter ++;
		if(Global_u8Counter == OVER_TICKS)
		{
			Global_u8Counter = 0;
			Global_u8Sec++;
		}

		if(Global_u8Sec == 60)
		{
			Global_u8Min++;
			Global_u8Sec=0;
		}

		if(Global_u8Min == 60)
		{
			Global_u8Hrs++;
			Global_u8Min=0;
		}
		if(Global_u8Hrs == 24)
		{
			Global_u8Hrs=0;
		}
	}
	else
	{

	}
}

void Resume_Button(void)
{
	Global_PauseFlag=0;

}

void Reset_Button(void)
{
	Global_u8Sec = 0;
	Global_u8Min = 0;
	Global_u8Hrs = 0;
	Global_u8Counter = 0;
	Global_PauseFlag=0;
}

void Pause_Button(void)
{
	Global_PauseFlag=1;
}

int main(){

	/*Functions Initialize*/
	GIE_voidEnable();
	EXTI_voidInit();
	TIMER0_voidInit();

	/*Functions Set call back*/

	EXTI_u8Int0SetCallBack(Reset_Button);
	EXTI_u8Int1SetCallBack(Pause_Button);
	EXTI_u8Int2SetCallBack(Resume_Button);
	TIMER_u8SetCallBack(Timer_Function,TIMER0_OVF_VECTOR_ID);

	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN3,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN4,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN5,DIO_PIN_OUTPUT);

	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN3,DIO_PIN_OUTPUT);

	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN2,DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTD,DIO_PIN3,DIO_PIN_INPUT);


	while(1){

		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
		DIO_u8SetPortValue(DIO_PORTC, (Global_u8Sec % 10) );

		_delay_ms(1);

		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
		DIO_u8SetPortValue(DIO_PORTC, (Global_u8Sec / 10) );

		_delay_ms(1);

		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
		DIO_u8SetPortValue(DIO_PORTC, (Global_u8Min % 10) );

		_delay_ms(1);

		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_HIGH);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
		DIO_u8SetPortValue(DIO_PORTC, (Global_u8Min / 10) );

		_delay_ms(10);

		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_HIGH);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);
		DIO_u8SetPortValue(DIO_PORTC, (Global_u8Hrs % 10) );

		_delay_ms(1);

		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN3,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN4,DIO_PIN_LOW);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_HIGH);
		DIO_u8SetPortValue(DIO_PORTC, (Global_u8Hrs / 10) );

		_delay_ms(1);
		DIO_u8SetPinValue(DIO_PORTA,DIO_PIN5,DIO_PIN_LOW);

	}

	return 0;
}

