
/********************************************************************************/
/*								FILES INCLUSIONS								*/
/********************************************************************************/
/******************LIB*******************/
/******************LIB*******************/
#include "LIB/STD_Types.h"
#include "LIB/BIT_MATH.h"

/*****************MCAL*******************/
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/USART/USART_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"

/*****************HAL*******************/
#include "HAL/LCD/LCD_Interface.h"
/****************Delay******************/
#include "avr/delay.h"

/************Global Variables***********/

/***************Handlers****************/

void RED_LED(void)
{
	DIO_u8TogglePinValue(DIO_PORTA,DIO_PIN0);
}

void GREEN_LED(void)
{
	DIO_u8TogglePinValue(DIO_PORTA,DIO_PIN1);
}

void YELLOW_LED(void)
{
	DIO_u8TogglePinValue(DIO_PORTA,DIO_PIN2);
}

void ALL_LED_ON(void)
{
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_HIGH);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_HIGH);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_HIGH);
}
void ALL_LED_OFF(void)
{
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);
}
void LED_INIT(void)
{
	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN0,DIO_PIN_LOW);

	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN1,DIO_PIN_LOW);

	DIO_u8SetPinDirection(DIO_PORTA,DIO_PIN2,DIO_PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_PORTA,DIO_PIN2,DIO_PIN_LOW);

}

int main(void)
{
	/*Functions Initializations*/
	GIE_voidEnable();
	USART_voidInit();

	u8 Local_u8ReceiveBuffer=0;
	u8 Local_u8RedFlag= 0,Local_u8GreenFlag=0,Local_u8YellowFlag=0;

	USART_u8SendStringAsynch((u8*)"Press (R/G/Y/A/C): ",LED_INIT);


	while(1){
		USART_u8RecevieData(&Local_u8ReceiveBuffer);
		if((Local_u8ReceiveBuffer == 'r') || (Local_u8ReceiveBuffer == 'R') )
		{
			if(Local_u8RedFlag == 0)
			{
				USART_u8SendStringAsynch((u8*)"RED_LED_ON",RED_LED);
				Local_u8RedFlag = 1;
				Local_u8ReceiveBuffer = ((u8*)"full");

			}
			else if(Local_u8RedFlag == 1)
			{
				USART_u8SendStringAsynch((u8*)"RED_LED_OFF",RED_LED);
				Local_u8RedFlag = 0;
				Local_u8ReceiveBuffer = ((u8*)"full");
			}

		}
		else if((Local_u8ReceiveBuffer == 'g') || (Local_u8ReceiveBuffer == 'G'))
		{
			if(Local_u8GreenFlag == 0)
			{
				USART_u8SendStringAsynch((u8*)"GREEN_LED_ON",GREEN_LED);
				Local_u8GreenFlag = 1;
				Local_u8ReceiveBuffer = ((u8*)"full");
			}
			else if(Local_u8GreenFlag == 1)
			{
				USART_u8SendStringAsynch((u8*)"GREEN_LED_OFF",GREEN_LED);
				Local_u8GreenFlag = 0;
				Local_u8ReceiveBuffer = ((u8*)"full");
			}
		}
		else if((Local_u8ReceiveBuffer == 'y') || (Local_u8ReceiveBuffer == 'Y'))
		{
			if(Local_u8YellowFlag == 0)
			{
				USART_u8SendStringAsynch((u8*)"YELLOW_LED_ON",YELLOW_LED);
				Local_u8YellowFlag = 1;
				Local_u8ReceiveBuffer = ((u8*)"full");
			}
			else if(Local_u8YellowFlag == 1)
			{
				USART_u8SendStringAsynch((u8*)"YELLOW_LED_OFF",YELLOW_LED);
				Local_u8YellowFlag = 0;
				Local_u8ReceiveBuffer = ((u8*)"full");
			}
		}
		else if((Local_u8ReceiveBuffer == 'a') || (Local_u8ReceiveBuffer == 'A'))
		{
			USART_u8SendStringAsynch((u8*)"ALL_LED_ON",ALL_LED_ON);
			Local_u8ReceiveBuffer = ((u8*)"full");
		}

	else if((Local_u8ReceiveBuffer == 'c') || (Local_u8ReceiveBuffer == 'c'))
	{
		USART_u8SendStringAsynch((u8*)"ALL_LED_OFF",ALL_LED_OFF);
		Local_u8ReceiveBuffer = ((u8*)"full");
	}
}





return 0;
}

