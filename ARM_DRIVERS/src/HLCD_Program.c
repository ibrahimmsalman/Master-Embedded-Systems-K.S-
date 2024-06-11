/*
 * LCD_Program.c
 *
 *  Created on: Mar 19, 2024
 *      Author: Ibrahim Refaey
 */

/************************************************************************/
/*							FILES INCLUSIONS							*/
/************************************************************************/
/*******************************LIB**************************************/

#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"


/*******************************MCAL*************************************/
#include "../include/MCAL/MGPIO/MGPIO_Interface.h"
#include "../include/MCAL/MSYSTICK/MSYSTICK_Interface.h"

/****************************HAL***************************/
#include "HAL/HLCD/HLCD_Config.h"
#include "HAL/HLCD/HLCD_Interface.h"
#include "HAL/HLCD/HLCD_Private.h"

/********************Functions Definitions*****************/
void LCD_voidInit(void)
{
	/************Set the control pins to be output**********/
	/*DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_EN_PIN,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_RW_PIN,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(LCD_CTRL_PORT,LCD_RS_PIN,DIO_PIN_OUTPUT);*/


	MGPIO_voidSetPinMode(LCD_CTRL_PORT,LCD_EN_PIN,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LCD_CTRL_PORT,LCD_EN_PIN,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(LCD_CTRL_PORT,LCD_RW_PIN,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LCD_CTRL_PORT,LCD_RW_PIN,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(LCD_CTRL_PORT,LCD_RS_PIN,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LCD_CTRL_PORT,LCD_RS_PIN,GPIO_PUSH_PULL,GPIO_LOW_SPEED);
	/*Waiting for more than 30ms*/
	MSYSTICK_voidDelayms(2);

	//_delay_ms(40);
	/*for(u32 c=0;c<50000;c++ )
	{

	}*/

#if LCD_MODE == LCD_EIGHT_BIT
	//DIO_u8SetPortDirection(LCD_DATA_PORT,DIO_PORT_OUTPUT);
	MGPIO_voidSetPinMode(LCD_DATA_PORT,GPIO_PIN0,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LCD_CTRL_PORT,GPIO_PIN0,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(LCD_DATA_PORT,GPIO_PIN1,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LCD_DATA_PORT,GPIO_PIN1,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(LCD_DATA_PORT,GPIO_PIN2,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LCD_DATA_PORT,GPIO_PIN2,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(LCD_DATA_PORT,GPIO_PIN3,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LCD_DATA_PORT,GPIO_PIN3,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(LCD_DATA_PORT,GPIO_PIN4,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LCD_DATA_PORT,GPIO_PIN4,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(LCD_DATA_PORT,GPIO_PIN5,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LCD_DATA_PORT,GPIO_PIN5,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(LCD_DATA_PORT,GPIO_PIN6,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LCD_DATA_PORT,GPIO_PIN6,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(LCD_DATA_PORT,GPIO_PIN7,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(LCD_DATA_PORT,GPIO_PIN7,GPIO_PUSH_PULL,GPIO_LOW_SPEED);




	/*Send the function set command: N->1 (2 lines) ,F-> 0 (5*7 char font)*/
	LCD_voidSendCommand(0x38);

	/*delay 39 us*/
	// 	_delay_us(40);

	/*Display ON/OFF control*/
	LCD_voidSendCommand(0x0C);


	/*delay 39 us*/
	//_delay_us(40);

	/*Display clear control*/
	LCD_voidSendCommand(0x01);



#elif LCD_MODE == LCD_FOUR_BIT
	DIO_u8SetPortDirection(LCD_DATA_PORT,0b1111);

	LCD_voidSendCommand(0x28);

	/*delay 39 us*/
	_delay_us(40);

	/*Display ON/OFF control*/
	LCD_voidSendCommand(0x0C);

	/*delay 39 us*/
	_delay_us(40);

	/*Display clear control*/
	LCD_voidSendCommand(0x01);

#else
#error "Wrong LCD_MODE Configuration parameter"
#endif
}




void LCD_voidSendCommand(u8 copy_u8Command)
{
	MSYSTICK_voidDelayms(2);

	/*for(u32 c=0;c<10000;c++ )
	{

	}*/

	/*Set the RS pin to be low*/
	//DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_PIN_LOW);

	MGPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,GPIO_PIN_LOW);
	/*Set the RW pin to be low*/
	//DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_PIN_LOW);

	MGPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,GPIO_PIN_LOW);
#if LCD_MODE == LCD_EIGHT_BIT
	//DIO_u8SetPortValue(LCD_DATA_PORT,copy_u8Command);

	MGPIO_voidSetPinValue(LCD_DATA_PORT,GPIO_PIN0,GET_BIT(copy_u8Command,0));
	MGPIO_voidSetPinValue(LCD_DATA_PORT,GPIO_PIN1,GET_BIT(copy_u8Command,1));
	MGPIO_voidSetPinValue(LCD_DATA_PORT,GPIO_PIN2,GET_BIT(copy_u8Command,2));
	MGPIO_voidSetPinValue(LCD_DATA_PORT,GPIO_PIN3,GET_BIT(copy_u8Command,3));
	MGPIO_voidSetPinValue(LCD_DATA_PORT,GPIO_PIN4,GET_BIT(copy_u8Command,4));
	MGPIO_voidSetPinValue(LCD_DATA_PORT,GPIO_PIN5,GET_BIT(copy_u8Command,5));
	MGPIO_voidSetPinValue(LCD_DATA_PORT,GPIO_PIN6,GET_BIT(copy_u8Command,6));
	MGPIO_voidSetPinValue(LCD_DATA_PORT,GPIO_PIN7,GET_BIT(copy_u8Command,7));


	//DIO_u8SetPortValue(LCD_DATA_PORT,copy_u8Command );

#elif LCD_MODE == LCD_FOUR_BIT
	DIO_u8SetPortValue(LCD_DATA_PORT,(copy_u8Command &0xF0));

	/*set the EN pin to high: 1 to read, waiting 2 msec and then make it low again*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_PIN_HIGH);

	/*Wait 2 msec*/
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_PIN_LOW);

	DIO_u8SetPortValue(LCD_DATA_PORT,((copy_u8Command<<4)&0xF0));


#else
#error "Wrong LCD_MODE Configuration parameter"
#endif

	/*set the EN pin to high: 1 to read, waiting 2 msec and then make it low again*/
	//DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_PIN_HIGH);

	MGPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,GPIO_PIN_HIGH);

	/*Wait 2 msec*/
	MSYSTICK_voidDelayms(2);

	//_delay_ms(2);
	//for(  u32 c=0;c<2000;c++ )
	//{

	//}
	//DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_PIN_LOW);

	MGPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,GPIO_PIN_LOW);


}

void LCD_voidSendData(u8 copy_u8Data)
{
	MSYSTICK_voidDelayms(2);

	//for(u32 c=0;c<2000;c++ )
	//{

	//}
	/*Set the RS pin to be low*/
	//DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,DIO_PIN_HIGH);


	MGPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RS_PIN,GPIO_PIN_HIGH);


	/*Set the RW pin to be low*/
	//DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,DIO_PIN_LOW);

	MGPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_RW_PIN,GPIO_PIN_LOW);


#if LCD_MODE == LCD_EIGHT_BIT
	//DIO_u8SetPortValue(LCD_DATA_PORT,copy_u8Data);

	MGPIO_voidSetPinValue(LCD_DATA_PORT,GPIO_PIN0,GET_BIT(copy_u8Data,0));
	MGPIO_voidSetPinValue(LCD_DATA_PORT,GPIO_PIN1,GET_BIT(copy_u8Data,1));
	MGPIO_voidSetPinValue(LCD_DATA_PORT,GPIO_PIN2,GET_BIT(copy_u8Data,2));
	MGPIO_voidSetPinValue(LCD_DATA_PORT,GPIO_PIN3,GET_BIT(copy_u8Data,3));
	MGPIO_voidSetPinValue(LCD_DATA_PORT,GPIO_PIN4,GET_BIT(copy_u8Data,4));
	MGPIO_voidSetPinValue(LCD_DATA_PORT,GPIO_PIN5,GET_BIT(copy_u8Data,5));
	MGPIO_voidSetPinValue(LCD_DATA_PORT,GPIO_PIN6,GET_BIT(copy_u8Data,6));
	MGPIO_voidSetPinValue(LCD_DATA_PORT,GPIO_PIN7,GET_BIT(copy_u8Data,7));

#elif LCD_MODE == LCD_FOUR_BIT
	DIO_u8SetPortValue(LCD_DATA_PORT,(copy_u8Data &0xF0));

	/*set the EN pin to high: 1 to read, waiting 2 msec and then make it low again*/
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_PIN_HIGH);

	/*Wait 2 msec*/
	_delay_ms(2);
	DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_PIN_LOW);

	DIO_u8SetPortValue(LCD_DATA_PORT,((copy_u8Data<<4)&0xF0));


#else
#error "Wrong LCD_MODE Configuration parameter"
#endif

	/*set the EN pin to high: 1 to read, waiting 2 msec and then make it low again*/
	//DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_PIN_HIGH);

	MGPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,GPIO_PIN_HIGH);

	MSYSTICK_voidDelayms(2);
	/*Wait 2 msec*/
	//_delay_ms(2);
	//for( u32 c=0;c<2000;c++ )
	//{

	//}

	//DIO_u8SetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,DIO_PIN_LOW);


	MGPIO_voidSetPinValue(LCD_CTRL_PORT,LCD_EN_PIN,GPIO_PIN_LOW);


}

void LCD_voidSendString(const u8* copy_pu8String)
{
	for(u8 local_u8Iterator = 0; copy_pu8String[local_u8Iterator] != '\0';local_u8Iterator++)
	{
		LCD_voidSendData(copy_pu8String[local_u8Iterator]);
	}
}


void LCD_voidSetPosition(u8 copy_u8XPosition,u8 copy_u8YPosition)
{
	u8 Local_u8Address = 0;
	if(copy_u8XPosition == LCD_ROW0)
	{
		Local_u8Address = copy_u8YPosition;
	}
	else if(copy_u8XPosition == LCD_ROW1)
	{
		Local_u8Address = copy_u8YPosition + DDRAM_OFFSET;
	}
	else
	{

	}

	SET_BIT(Local_u8Address,7);
	LCD_voidSendCommand(Local_u8Address);
}

void LCD_voidSendNumber(s64 copy_s32Number)
{
	u64 reversed = 1;
	if (copy_s32Number == 0)
	{
		LCD_voidSendData('0');
	}
	else
	{
		if(copy_s32Number <0)
		{
			LCD_voidSendData('-');
			copy_s32Number *=-1;
		}
		else
		{
			while(copy_s32Number!= 0)
			{
				reversed = (reversed*10) + (copy_s32Number%10);
				copy_s32Number/=10;
			}
			while(reversed != 1)
			{
				LCD_voidSendData(reversed%10 +'0');
				reversed/=10;
			}
		}
	}
}

void LCD_voidSendCustomCharacter(u8* copy_pu8CharacterArray,u8 copy_u8PatternNumber,u8 copy_u8XPosition,u8 copy_u8YPosition)
{
	u8 Local_u8CGRAMAddress = 0 ,Local_u8LoopCounter;

	/*Calculating CGRAM Address*/
	Local_u8CGRAMAddress = copy_u8PatternNumber*8;

	/*Make the 6th bit from address to be high and sending cmd to LCD*/
	SET_BIT(Local_u8CGRAMAddress,6);

	LCD_voidSendCommand(Local_u8CGRAMAddress);

	for(Local_u8LoopCounter = 0; Local_u8LoopCounter<8 ; Local_u8LoopCounter++)
	{
		LCD_voidSendData(copy_pu8CharacterArray[Local_u8LoopCounter]);
	}
	LCD_voidSetPosition( copy_u8XPosition,copy_u8YPosition);

	/*Displaying the pattern from CGRAM*/
	LCD_voidSendData(copy_u8PatternNumber);
}

void LCD_voidClearScreen(void)
{
	LCD_voidSendCommand(0x01);
}

