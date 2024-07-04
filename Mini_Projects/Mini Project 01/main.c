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

	u8 Local_u8Pressed = NOTPRESSED , Local_u8Operation;
	u8 COL=0,ROW=LCD_ROW0,Local_u8Flag=0;
	u8 Local_u8Number = 0,RepEnter1=0,RepEnter2=0,Repflag=0;
	u16 Local_u16ConNum=0,Local_u16FirstNum=0 , Local_u16SecNum=0;

	while(1)
	{
		Local_u8Pressed = KPD_u8GetPressed();
		if(Local_u8Pressed != NOTPRESSED && Local_u8Pressed != '=' && Local_u8Pressed != '?')
		{
			LCD_voidSendData(Local_u8Pressed);
			if( (Local_u8Pressed == '+' || Local_u8Pressed == '-' || Local_u8Pressed == '*' || Local_u8Pressed == '/') && (0 == Repflag) )
			{
				Local_u8Operation = Local_u8Pressed;
				Local_u8Pressed = 0xAF;
				Local_u8Flag = 1;
			}
			else if( (Local_u8Pressed == '+' || Local_u8Pressed == '-' || Local_u8Pressed == '*' || Local_u8Pressed == '/') && (1 == Repflag) )
			{
				Local_u16FirstNum = Local_u16ConNum;
				Local_u8Operation = Local_u8Pressed;
				Local_u8Pressed = 0xAF;
				Local_u8Flag = 1;
			}

			if(0 == Local_u8Flag)
			{
				Local_u8Number = (Local_u8Pressed - '0');
				if(0 == RepEnter1 && 0 == Local_u8Flag && Local_u8Pressed != 0xAF)
				{
					Local_u16FirstNum = Local_u8Number;
					RepEnter1 = 1;
				}
				else if(1 == RepEnter1 && 0 == Local_u8Flag && Local_u8Pressed != 0 )
				{
					Local_u16FirstNum = ((Local_u16FirstNum*10) + Local_u8Number);
				}
				else if(1 == RepEnter1 && 0 == Local_u8Flag && Local_u8Pressed == 0 )
				{
					Local_u16FirstNum *= 10;
				}
			}
			else if(1 == Local_u8Flag)
			{
				Local_u8Number = (Local_u8Pressed - '0');
				if(0 == RepEnter2 && 1 == Local_u8Flag && Local_u8Pressed != 0xAF)
				{
					Local_u16SecNum = Local_u8Number;
					RepEnter2 = 1;
				}
				else if(1 == RepEnter2 && 1 == Local_u8Flag && Local_u8Pressed != 0 )
				{
					Local_u16SecNum = ((Local_u16SecNum*10) + Local_u8Number);
				}
				else if(1 == RepEnter2 && 1 == Local_u8Flag && Local_u8Pressed == 0 )
				{
					Local_u16SecNum *= 10;
				}

			}
		}
		else if(Local_u8Pressed != NOTPRESSED && Local_u8Pressed == '=' && Local_u8Pressed != '?')
		{
			_delay_ms(200);
			LCD_voidClearScreen();
			_delay_ms(200);
			ROW=LCD_ROW0;
			COL=0;
			LCD_voidSetPosition(ROW,COL);
			if(Local_u8Operation == '+')
			{
				Local_u16ConNum = Local_u16FirstNum + Local_u16SecNum;
				LCD_voidSendNumber(Local_u16ConNum);

			}
			else if(Local_u8Operation == '-')
			{
				if(Local_u16FirstNum > Local_u16SecNum)
				{
					Local_u16ConNum = Local_u16FirstNum - Local_u16SecNum;
					LCD_voidSendNumber(Local_u16ConNum);
				}
				else
				{
					Local_u16ConNum = Local_u16SecNum - Local_u16FirstNum;
					LCD_voidSendData('-');
					LCD_voidSendNumber(Local_u16ConNum);
				}

			}
			else if(Local_u8Operation == '*')
			{
				Local_u16ConNum = Local_u16FirstNum * Local_u16SecNum;
				LCD_voidSendNumber(Local_u16ConNum);

			}
			else if(Local_u8Operation == '/')
			{
				Local_u16ConNum = Local_u16FirstNum / Local_u16SecNum;
				LCD_voidSendNumber(Local_u16ConNum);
			}
			Local_u8Pressed = NOTPRESSED;
			Local_u16FirstNum=0;
			Local_u16SecNum=0;
			Local_u8Operation=0;
			Local_u8Flag = 0;
			RepEnter1=0;
			RepEnter2=0;
			Repflag= 1;

		}
		else if(Local_u8Pressed != NOTPRESSED && Local_u8Pressed == '?')
		{
			_delay_ms(200);
			LCD_voidClearScreen();
			_delay_ms(200);
			ROW=LCD_ROW0;
			COL=0;
			LCD_voidSetPosition(ROW	,COL);
			Local_u8Pressed = NOTPRESSED;
			Local_u16FirstNum=0;
			Local_u16ConNum=0;
			Local_u16SecNum=0;
			Local_u8Operation=0;
			Local_u8Flag = 0;
			Repflag = 0;
		}

	}
	return 0;
}
