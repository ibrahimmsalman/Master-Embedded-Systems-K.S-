
/******************LIB*******************/
#include "LIB/STD_Types.h"
#include "LIB/BIT_MATH.h"

/*****************MCAL*******************/
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"

/*****************HAL*******************/
#include "HAL/LCD/LCD_Interface.h"
/*****************Delay*****************/
#include "avr/delay.h"

/*****************Handler***************/

/*void func(void)
{
}
 */
//#define F_CPU 8000000UL

/**************** ISRs ******************/
void INT0_func(void);
void INT1_func(void);

int main(void)
{
	/**************** Initialize pins ******************/
	// interrupts
	DIO_u8SetPinDirection(DIO_PORTD , DIO_PIN2 , DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTD , DIO_PIN3 , DIO_PIN_INPUT);

	DIO_u8SetPinValue(DIO_PORTD , DIO_PIN2 , DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTD , DIO_PIN3 , DIO_PIN_LOW);


	// LEDs
	DIO_u8SetPinDirection(DIO_PORTA , DIO_PIN0 , DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA , DIO_PIN1 , DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA , DIO_PIN2 , DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTA , DIO_PIN3 , DIO_PIN_OUTPUT);

	/**************** Initialize Interrupts ******************/
	GIE_voidEnable();
	EXTI_voidInit();
	LCD_voidInit();

	while(1)
	{
		LCD_voidSetPosition(0 , 0);
		LCD_voidSendString((u8 *) "Welcome to MP4!");

		LCD_voidSetPosition(1 , 2);
		LCD_voidSendString((u8 *) "Wazeefa-Tech.");

		EXTI_u8Int0SetCallBack(INT0_func);
		EXTI_u8Int1SetCallBack(INT1_func);
	}

	return 0;
}

void INT0_func(void){
	GIE_voidEnable();
	LCD_voidClearScreen();

	LCD_voidSetPosition(0 , 5);
	LCD_voidSendString((u8 *) "EXTI 0");

	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN0 , DIO_PIN_HIGH);
	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN1 , DIO_PIN_HIGH);
	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN2 , DIO_PIN_HIGH);
	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN3 , DIO_PIN_HIGH);

	_delay_ms(2000);

	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN0 , DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN1 , DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN2 , DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN3 , DIO_PIN_LOW);

	LCD_voidClearScreen();
}

void INT1_func(void){
	GIE_voidEnable();
	LCD_voidClearScreen();

	LCD_voidSetPosition(0 , 5);
	LCD_voidSendString((u8 *) "EXTI 1");

	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN0 , DIO_PIN_HIGH);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN0 , DIO_PIN_LOW);

	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN1 , DIO_PIN_HIGH);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN1 , DIO_PIN_LOW);

	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN2 , DIO_PIN_HIGH);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN2 , DIO_PIN_LOW);

	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN3 , DIO_PIN_HIGH);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_PORTA , DIO_PIN3 , DIO_PIN_LOW);

	LCD_voidClearScreen();
}
