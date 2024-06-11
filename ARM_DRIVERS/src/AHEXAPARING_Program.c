/*
 * AHEXAPARING_Program.c
 *
 *  Created on: May 26, 2024
 *      Author: Ibrahim Salman
 */

#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"


/******************************* MCAL ***********************************/
#include "../include/MCAL/MFDI/MFDI_Interface.h"
#include "../include/AHEXAPARING_Interface.h"


u32 Global_u32CompleteAddress = 0x08000000;
u16 Global_u16Buffer[100];

static u8 Ascii_u8ToHex(u8 Copy_u8Ascii)
{
	u8 Local_u8Result = 0;
	if((Copy_u8Ascii >= 48) && (Copy_u8Ascii <=57))
	{
		Local_u8Result = Copy_u8Ascii - 48;
	}
	else
	{
		Local_u8Result = Copy_u8Ascii - 55;
	}
	return Local_u8Result;
}

void Hexa_voidParsData(u8 *Copy_u8DataPtr)
{
	u8 Copy_u8CCHighNipple = 0;
	u8 Copy_u8CCLowNipple = 0;
	u8 Copy_u8CCTotal;
	u16 Copy_u16LowPartAddress = 0;
	u16 Copy_16DataHalfWord = 0;

	u8 Local_u8Digit0 = 0;
	u8 Local_u8Digit1 = 0;
	u8 Local_u8Digit2 = 0;
	u8 Local_u8Digit3 = 0;



	Copy_u8CCHighNipple = Ascii_u8ToHex(Copy_u8DataPtr[1]);
	Copy_u8CCLowNipple = Ascii_u8ToHex(Copy_u8DataPtr[2]);
	Copy_u8CCTotal = (Copy_u8CCHighNipple << 4) | (Copy_u8CCLowNipple);

	Local_u8Digit0 = Ascii_u8ToHex(Copy_u8DataPtr[3]);
	Local_u8Digit1 = Ascii_u8ToHex(Copy_u8DataPtr[4]);
	Local_u8Digit2 = Ascii_u8ToHex(Copy_u8DataPtr[5]);
	Local_u8Digit3 = Ascii_u8ToHex(Copy_u8DataPtr[6]);

	Copy_u16LowPartAddress = (Local_u8Digit0 << 12) | (Local_u8Digit1 << 8) | (Local_u8Digit2 << 4) | (Local_u8Digit3);

	Global_u32CompleteAddress &= 0xFFFF0000;
	Global_u32CompleteAddress |= Copy_u16LowPartAddress;

	for(u8 i = 0; i<Copy_u8CCTotal/2 ;i++)
	{
		Local_u8Digit0 = Ascii_u8ToHex(Copy_u8DataPtr[(i * 4) + 9]);
		Local_u8Digit1 = Ascii_u8ToHex(Copy_u8DataPtr[(i * 4) + 10]);
		Local_u8Digit2 = Ascii_u8ToHex(Copy_u8DataPtr[(i * 4) + 11]);
		Local_u8Digit3 = Ascii_u8ToHex(Copy_u8DataPtr[(i * 4) + 12]);
		Copy_16DataHalfWord = (Local_u8Digit2 << 12) | (Local_u8Digit3 << 8) | (Local_u8Digit0 << 4) | (Local_u8Digit1);
		Global_u16Buffer[i] = Copy_16DataHalfWord;
	}
	MFDI_voidWrite(Global_u32CompleteAddress,Global_u16Buffer,Copy_u8CCTotal/2);

}

void Parse_voidRecord(u8 *Copy_u8Record)
{
	switch(Copy_u8Record[8])
	{
	case '0':
		Hexa_voidParsData(Copy_u8Record);
		break;
	case '1': //end of file
		break;
	case '5': //complete address
		break;


	}
}
