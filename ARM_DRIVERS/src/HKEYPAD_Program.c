/*
 * KEYPAD_Program.c
 *
 *  Created on: Mar 20, 2024
 *      Author: ahmed
 */


/************************************************************************/
/*							FILES INCLUSIONS							*/
/************************************************************************/
/*******************************LIB**************************************/
#include "../include/LIB/BIT_MATH.h"
#include "../include/LIB/STD_Types.h"


/*******************************MCAL*************************************/
#include "HAL/HKEYPAD/HKEYPAD_Config.h"
#include "HAL/HKEYPAD/HKEYPAD_Interface.h"
#include "HAL/HKEYPAD/HKEYPAD_Private.h"


#include "../include/MCAL/MGPIO/MGPIO_Interface.h"

/****************************HAL***************************/



void KPD_Init(void)
{
	/***Connect PUll Up For Rowws Pins*/
	/*DIO_u8GetConnectPullUp(KPD_PORT,KPD_R0,DIO_PIN_HIGH);
	DIO_u8GetConnectPullUp(KPD_PORT,KPD_R1,DIO_PIN_HIGH);
	DIO_u8GetConnectPullUp(KPD_PORT,KPD_R2,DIO_PIN_HIGH);
	DIO_u8GetConnectPullUp(KPD_PORT,KPD_R3,DIO_PIN_HIGH);*/

	/*Connect the colums pins as output high*/
	/*DIO_u8SetPinDirection(KPD_PORT,KPD_C0,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_C1,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_C2,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(KPD_PORT,KPD_C3,DIO_PIN_OUTPUT);


	DIO_u8SetPinValue(KPD_PORT,KPD_C0,DIO_PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_C1,DIO_PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_C2,DIO_PIN_HIGH);
	DIO_u8SetPinValue(KPD_PORT,KPD_C3,DIO_PIN_HIGH);
*/

	MGPIO_voidSetPinMode(KPD_PORT,KPD_R0,GPIO_INPUT);
	MGPIO_voidSetPinInputMode(KPD_PORT,KPD_R0,GPIO_PULLUP);

	MGPIO_voidSetPinMode(KPD_PORT,KPD_R1,GPIO_INPUT);
	MGPIO_voidSetPinInputMode(KPD_PORT,KPD_R1,GPIO_PULLUP);

	MGPIO_voidSetPinMode(KPD_PORT,KPD_R2,GPIO_INPUT);
	MGPIO_voidSetPinInputMode(KPD_PORT,KPD_R2,GPIO_PULLUP);

	MGPIO_voidSetPinMode(KPD_PORT,KPD_R3,GPIO_INPUT);
	MGPIO_voidSetPinInputMode(KPD_PORT,KPD_R3,GPIO_PULLUP);


	MGPIO_voidSetPinMode(KPD_PORT,KPD_C0,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(KPD_PORT,KPD_C0,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(KPD_PORT,KPD_C1,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(KPD_PORT,KPD_C1,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(KPD_PORT,KPD_C2,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(KPD_PORT,KPD_C2,GPIO_PUSH_PULL,GPIO_LOW_SPEED);

	MGPIO_voidSetPinMode(KPD_PORT,KPD_C3,GPIO_OUTPUT);
	MGPIO_voidSetPinOutputMode(KPD_PORT,KPD_C3,GPIO_PUSH_PULL,GPIO_LOW_SPEED);



	MGPIO_voidSetPinValue(KPD_PORT,KPD_C0,GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(KPD_PORT,KPD_C1,GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(KPD_PORT,KPD_C2,GPIO_PIN_LOW);
	MGPIO_voidSetPinValue(KPD_PORT,KPD_C3,GPIO_PIN_LOW);


}
u8 KPD_u8GetPressed(void)
{
	u8 Local_u8ReturnData=NOTPRESSED;
	u8 Local_u8GetPressed;
	u8 Local_u8Col;
	u8 Local_u8Row;
	for(Local_u8Col=KPD_COL_INT ; Local_u8Col< KPD_COL_END+1 ; Local_u8Col++)
	{
		MGPIO_voidSetPinValue(KPD_PORT, Local_u8Col,GPIO_PIN_LOW);
		for(Local_u8Row=KPD_ROW_INT ; Local_u8Row<KPD_ROW_END+1 ; Local_u8Row++)
		{
			MGPIO_voidGetPinValue(KPD_PORT, Local_u8Row,&Local_u8GetPressed);
			if(Local_u8GetPressed==0)
			{
				//_delay_ms(50);
				/*for(u64 c=0;c<50000;c++)
				{

				}*/
				MGPIO_voidGetPinValue(KPD_PORT, Local_u8Row,&Local_u8GetPressed);
				if(Local_u8GetPressed==0)
				{
					Local_u8ReturnData= KPD_u8Buttoms[Local_u8Row-KPD_ROW_INT][Local_u8Col-KPD_COL_INT];
				}
				MGPIO_voidGetPinValue(KPD_PORT, Local_u8Row,&Local_u8GetPressed);
				while(GPIO_PIN_LOW == Local_u8GetPressed)
				{
					MGPIO_voidGetPinValue(KPD_PORT, Local_u8Row,&Local_u8GetPressed);

				}
				break;
			}


		}
		MGPIO_voidSetPinValue(KPD_PORT, Local_u8Col,GPIO_PIN_HIGH);

	}
	return Local_u8ReturnData;
}
