/********************************************************************************/
/*								FILES INCLUSIONS								*/
/********************************************************************************/
/******************LIB*******************/
//#include <avr/io.h>
#include <util/delay.h>
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"
#include "string.h"

/*****************MCAL*******************/
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/TIMERS/TIMERS_Interface.h"
#include "MCAL/USART/USART_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"
#include "MCAL/TWI/TWI_Interface.h"
/*****************HAL*******************/
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KPD/KPD_Interface.h"
#include "HAL/DCMOTOR/DCMOTOR_Interface.h"
#include "HAL/STEPPER/STEPPER_Interface.h"
#include "HAL/LM35/LM35_Interface.h"
#include "HAL/EEPROM/EEPROM_Interface.h"
/*************GENERAL MACROS*************/

/***********GENERAL VARIABLES************/

/*************HANDLERS*******************/

int main(void)
{
	/**************************************************************************/
	/*						1- LOCAL VARIABLES								  */
	/**************************************************************************/
	u8 Local_u8ReadData[5]= "";
	u8 Local_u8CreatePass[5] = "";
	u8 Local_u8EnteredPass[5] = "";
	u8 Local_u8keyPressed;
	u32 Local_u32Tries=0;

	/**************************************************************************/
	/*					2- MODULES INITIALIZATIONS							  */
	/**************************************************************************/

	EEPROM_voidInit();
	LCD_voidInit();
	KPD_Init();

	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN0,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN1,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN5,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN6,DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTC,DIO_PIN7,DIO_PIN_OUTPUT);

	DIO_u8SetPortDirection(DIO_PORTD,DIO_PORT_OUTPUT);
	DIO_u8SetPortDirection(DIO_PORTB,DIO_PORT_OUTPUT);
	DIO_u8SetPortDirection(DIO_PORTA,DIO_PORT_OUTPUT);




	/**************************************************************************/
	/*				 			3- APPLICATION								  */
	/**************************************************************************/

	LCD_voidClearScreen();
	LCD_voidSetPosition(0,0);
	LCD_voidSendString((u8*) "CREATE PASSWORD");
	LCD_voidSetPosition(1,0);
	LCD_voidSendString((u8*) "PASS:");
	for(u8 i = 0;i<4;i++)
	{
		Local_u8CreatePass[i] = KPD_u8GetPressed();
		while(Local_u8CreatePass[i] == 0xff);
		LCD_voidSetPosition(1,5+i);
		LCD_voidSendString((u8*) "*");
		_delay_ms(50);
	}
	Local_u8CreatePass[4] = '\0';



	do {
		Local_u8keyPressed = KPD_u8GetPressed();
	} while (Local_u8keyPressed != '=');


	for(int i=0 ; i<5 ; i++)
	{
		EEPROM_voidSendDataByte(Local_u8CreatePass[i],i);
		_delay_ms(50);
	}
	LCD_voidClearScreen();
	LCD_voidSetPosition(0,0);
	LCD_voidSendString((u8*) "PASSWORD SAVED");
	_delay_ms(2000);
	while(1){



		LCD_voidClearScreen();
		LCD_voidSetPosition(0,0);
		LCD_voidSendString((u8*) "ENTER PASSWORD");
		LCD_voidSetPosition(1,0);
		LCD_voidSendString((u8*) "PASS:");
		for(u8 i = 0;i<4;i++)
		{

			Local_u8EnteredPass[i] = KPD_u8GetPressed();
			while(Local_u8EnteredPass[i] == 0xff);
			LCD_voidSetPosition(1,5+i);
			LCD_voidSendString((u8*) "*");
			_delay_ms(50);
		}
		Local_u8EnteredPass[4] = '\0';


		do
		{
			Local_u8keyPressed = KPD_u8GetPressed();
		}
		while (Local_u8keyPressed != '=');

		for(int i=0 ; i<5 ; i++){
			Local_u8ReadData[i]=EEPROM_u8ReadDataByte(i);
			_delay_ms(50);
		}

		if(Local_u32Tries<2)
		{

			if(strcmp(Local_u8EnteredPass,Local_u8ReadData)==0)
			{
				LCD_voidClearScreen();
				LCD_voidSendString((u8*) "WELCOME HOME");
				_delay_ms(2000);
			}

			else{
				LCD_voidClearScreen();
				LCD_voidSendString((u8*) "WRONG PASSWORD");
				LCD_voidSetPosition(0,4);
				LCD_voidSendString((u8*) "TRY AGAIN");
				_delay_ms(2000);
				Local_u32Tries++;

			}
		}

		else
		{
			LCD_voidClearScreen();
			LCD_voidSetPosition(0,0);
			LCD_voidSendString((u8*) "WRONG PASSWORD");
			LCD_voidSetPosition(0,0);
			LCD_voidSendString((u8*) "ATTEMPTS ARE OVER");
			_delay_ms(3000);

			LCD_voidClearScreen();
			LCD_voidSetPosition(0,0);
			LCD_voidSendString((u8*) "WAIT 5 SECONDS");
			_delay_ms(5000);

			Local_u32Tries=0;
		}

	}

	return 0;
}
