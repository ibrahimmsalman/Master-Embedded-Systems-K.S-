/******************LIB*******************/
#include <util/delay.h>
#include "LIB/BIT_MATH.h"
#include "LIB/STD_TYPES.h"

/*****************MCAL*******************/
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"
#include "MCAL/TIMERS/TIMERS_Interface.h"
#include "MCAL/USART/USART_Interface.h"
#include "MCAL/SPI/SPI_Interface.h"

/*****************HAL*******************/
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/KPD/KPD_Interface.h"
#include "HAL/DCMOTOR/DCMOTOR_Interface.h"
#include "HAL/STEPPER/STEPPER_Interface.h"
#include "HAL/LM35/LM35_Interface.h"

/********************************************************************************/
/***********Global Variables************/
u8 global_u8DIOReceive = 0, global_u8SPIReceive = 0;

/*************GLOBAL MACROS*************/


/**************Handlers*****************/


int main(void)
{
	SPI_VoidInit();

	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN4, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN5, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN6, DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTB, DIO_PIN7, DIO_PIN_OUTPUT);

	DIO_u8SetPinDirection(DIO_PORTC , DIO_PIN3 , DIO_PIN_OUTPUT) ;
	DIO_u8SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_PIN_INPUT);


	while(1)
	{

		DIO_u8GetPinValue(DIO_PORTA, DIO_PIN0, &global_u8DIOReceive);

		SPI_u8Tranceive(global_u8DIOReceive, &global_u8SPIReceive);

	}

	return 0;
}

