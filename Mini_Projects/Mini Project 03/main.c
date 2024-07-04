/*
 * main.c
 *
 *  Created on: Mar 18, 2024
 *      Author: Ibrahim Salman
 */


/******************LIB*******************/
#include "LIB/STD_Types.h"
#include "LIB/BIT_MATH.h"

/*****************MCAL*******************/
#include "MCAL/DIO/DIO_Interface.h"

/*****************HAL*******************/
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/STEPPER/STEPPER_Interface.h"
#include "HAL/KPD/KPD_Interface.h"
/*************Delay***************/
#include "util/delay.h"

//#define F_CPU 8000000UL

int main(void){
	LCD_voidInit();
	KPD_Init();

	u8 Local_u8Pressed = NOTPRESSED , Local_u8Number,Local_u8RepEnter = 0;
	u16 Local_u16ConNum;
	u8 COL=0,ROW=LCD_ROW0;
	LCD_voidSetPosition(ROW,COL);
	LCD_voidSendString("ENTER PASSWORD");
	while(1)
	{
		Local_u8Pressed = KPD_u8GetPressed();
		if(Local_u8Pressed != NOTPRESSED && Local_u8Pressed != '=')
		{

			LCD_voidSetPosition(LCD_ROW1,COL);
			COL++;
			LCD_voidSendData('*');
			Local_u8Number = (Local_u8Pressed - '0');
			if(0 == Local_u8RepEnter )
			{
				Local_u16ConNum = Local_u8Number;

				Local_u8RepEnter = 1;
			}
			else if( 1 == Local_u8RepEnter && Local_u8Number != 0)
			{
				Local_u16ConNum = ((Local_u16ConNum *10) + Local_u8Number);
			}
			else if( 1 == Local_u8RepEnter && Local_u8Number == 0)
			{
				Local_u16ConNum *= 10;
			}
		}
		else if(Local_u8Pressed != NOTPRESSED && Local_u8Pressed == '=')
		{
			if(Local_u16ConNum == 2024)
			{
				_delay_ms(500);
				LCD_voidClearScreen();
				_delay_ms(500);
				LCD_voidSetPosition(LCD_ROW0,0);
				LCD_voidSendString("WELCOME HOME");
				Local_u16ConNum = 0;
				Local_u8Number = 0;
				Local_u8Pressed = NOTPRESSED;
				Local_u8RepEnter = 0;
				COL = 0;
			}
			else if(Local_u16ConNum != 2024)
			{
				_delay_ms(500);
				LCD_voidClearScreen();
				_delay_ms(500);
				LCD_voidSetPosition(LCD_ROW0,0);
				LCD_voidSendString("INCORRECT PASSWORD");
				_delay_ms(2000);
				LCD_voidClearScreen();
				_delay_ms(500);
				LCD_voidSetPosition(LCD_ROW0,0);
				LCD_voidSendString("ENTER PASSWORD");
				Local_u16ConNum = 0;
				Local_u8Number = 0;
				Local_u8Pressed = NOTPRESSED;
				Local_u8RepEnter=0;
				COL = 0;
			}
		}

	}

}
