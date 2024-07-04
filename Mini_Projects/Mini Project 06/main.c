
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
u8 BlockCustomChar[] = {
		0x1F,
		0x1F,
		0x1F,
		0x1F,
		0x1F,
		0x1F,
		0x1F,
		0x1F
		};

u8 CarCustomChar[] = {
		0x00,
		0x00,
		0x00,
		0x00,
		0x04,
		0x0E,
		0x0A,
		0x00
};
/***************Handlers****************/

int main(){
	u8 COL=1,Local_u8Flag=0;
	/*Initialize Functions*/
	GIE_voidEnable();
	TIMER0_voidInit();
	LCD_voidInit();



	LCD_voidClearScreen();
	LCD_voidSetPosition(LCD_ROW0,0);
	LCD_voidSendString((u8*)"Hello! Fast & Furious 10:");

	LCD_voidSendCustomCharacter(BlockCustomChar,1,LCD_ROW1,0);
	LCD_voidSendCustomCharacter(BlockCustomChar,2,LCD_ROW1,39);
	LCD_voidSendCustomCharacter(CarCustomChar,3,LCD_ROW1,COL);

	_delay_ms(1000);


	DIO_u8SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_PIN_OUTPUT);


	while(1)
	{

		if(0 == Local_u8Flag)
		{
			LCD_voidClearScreen();
			TIMER0_voidSetFastPWM(64);
			LCD_voidSendString((u8*)"Car Speed : LOW");
			LCD_voidSendCustomCharacter(BlockCustomChar,1,LCD_ROW1,0);
			LCD_voidSendCustomCharacter(BlockCustomChar,2,LCD_ROW1,39);
			LCD_voidSendCustomCharacter(CarCustomChar,3,LCD_ROW1,COL);
			_delay_ms(400);
			COL++;
			if(COL == 8 || COL == 38)
			{
				if(Local_u8Flag == 0 && COL == 8)
				{
					Local_u8Flag = 1;
				}
				else
				{
					Local_u8Flag=3;
				}
			}
		}
		else if(1 == Local_u8Flag)
		{
			LCD_voidClearScreen();
			TIMER0_voidSetFastPWM(128);
			LCD_voidSendString((u8*)"Car Speed : MEDIUM");
			LCD_voidSendCustomCharacter(BlockCustomChar,1,LCD_ROW1,0);
			LCD_voidSendCustomCharacter(BlockCustomChar,2,LCD_ROW1,39);
			LCD_voidSendCustomCharacter(CarCustomChar,3,LCD_ROW1,COL);
			_delay_ms(200);
			COL++;
			if(COL == 16 || COL == 32)
			{
				if(COL==16)
				{
					Local_u8Flag = 2;
				}
				else if(COL == 32)
				{
					Local_u8Flag = 0;
				}
			}
		}
		else if(2 == Local_u8Flag)
		{
			LCD_voidClearScreen();
			TIMER0_voidSetFastPWM(254);
			LCD_voidSendString((u8*)"Car Speed : HIGH");
			LCD_voidSendCustomCharacter(BlockCustomChar,1,LCD_ROW1,0);
			LCD_voidSendCustomCharacter(BlockCustomChar,2,LCD_ROW1,39);
			LCD_voidSendCustomCharacter(CarCustomChar,3,LCD_ROW1,COL);
			_delay_ms(100);
			COL++;
			if(COL == 24)
			{
				Local_u8Flag = 1;
			}
		}
		else if(3 == Local_u8Flag)
		{
			LCD_voidClearScreen();
			TIMER0_voidSetFastPWM(0);
			LCD_voidSendString((u8*)"Car Speed : STOP");
			LCD_voidSendCustomCharacter(BlockCustomChar,1,LCD_ROW1,0);
			LCD_voidSendCustomCharacter(BlockCustomChar,2,LCD_ROW1,39);
			LCD_voidSendCustomCharacter(CarCustomChar,3,LCD_ROW1,38);
			Local_u8Flag = 4;
		}

	}

	return 0;
}

