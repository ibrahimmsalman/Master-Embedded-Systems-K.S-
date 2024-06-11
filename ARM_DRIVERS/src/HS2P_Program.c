/*
 * S2P_Program.c
 *
 *  Created on: May 12, 2024
 *      Author: Admin
 */

/************************************************************************/
/*							FILES INCLUSIONS							*/
/************************************************************************/
/*******************************LIB**************************************/
#include "../include/LIB/STD_Types.h"
#include "../include/LIB/BIT_MATH.h"
/*******************************MCAL*************************************/
#include "HAL/HS2P/HS2P_Config.h"
#include "HAL/HS2P/HS2P_Interface.h"
#include "HAL/HS2P/HS2P_Private.h"

#include "../include/MCAL/MGPIO/MGPIO_Interface.h"
#include "../include/MCAL/MSYSTICK/MSYSTICK_Interface.h"

/****************************HAL***************************/

void S2P_voidInit(void)
{
	/*Pin Config*/
	MGPIO_voidSetPinMode(S2P_DS_PORT,S2P_DS_PIN,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(S2P_DS_PORT,S2P_DS_PIN,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(S2P_SH_CLK_PORT,S2P_SH_CLK_PIN,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(S2P_SH_CLK_PORT,S2P_SH_CLK_PIN,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(S2P_STRG_CLK_PORT,S2P_STRG_CLK_PIN,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(S2P_STRG_CLK_PORT,S2P_STRG_CLK_PIN,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(S2P_RST_PORT,S2P_RST_PIN,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(S2P_RST_PORT,S2P_RST_PIN,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);

	MGPIO_voidSetPinMode(S2P_ENABLE_PORT,S2P_ENABLE_PIN,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(S2P_ENABLE_PORT,S2P_ENABLE_PIN,GPIO_PUSH_PULL,GPIO_MEDIUM_SPEED);

}
void S2P_voidSendByte(char Copy_u8Data)
{
	u16 Local_u8BitValue;

	for(s8 i = 15; i>=0; i--)
	{
		Local_u8BitValue = GET_BIT(Copy_u8Data,i);
		MGPIO_voidSetPinValue(S2P_DS_PORT,S2P_DS_PIN,Local_u8BitValue);

		/*SET PULSE*/
		MGPIO_voidSetPinValue(S2P_SH_CLK_PORT,S2P_SH_CLK_PIN,GPIO_PIN_HIGH);
		MSYSTICK_voidSetBusyWait(4);

		MGPIO_voidSetPinValue(S2P_SH_CLK_PORT,S2P_SH_CLK_PIN,GPIO_PIN_LOW);
		MSYSTICK_voidSetBusyWait(4);
	}

	/*ENABLE PULSE*/
	MGPIO_voidSetPinValue(S2P_STRG_CLK_PORT,S2P_STRG_CLK_PIN,GPIO_PIN_HIGH);
	MSYSTICK_voidSetBusyWait(4);

	MGPIO_voidSetPinValue(S2P_STRG_CLK_PORT,S2P_STRG_CLK_PIN,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait(4);

}

void S2P_voidChipEnableDisable(ChipState_e Copy_state)
{
	switch(Copy_state)
	{
	case ENABLED:
		MGPIO_voidSetPinValue(S2P_ENABLE_PORT,S2P_ENABLE_PIN,GPIO_PIN_LOW);
		break;
	case DISABLED:
		MGPIO_voidSetPinValue(S2P_ENABLE_PORT,S2P_ENABLE_PIN,GPIO_PIN_HIGH);
		break;
	}
}

void S2P_voidChipReset(void)
{
	MGPIO_voidSetPinValue(S2P_RST_PORT,S2P_RST_PIN,GPIO_PIN_LOW);
	MSYSTICK_voidSetBusyWait(2000000);
	MGPIO_voidSetPinValue(S2P_RST_PORT,S2P_RST_PIN,GPIO_PIN_HIGH);


}



