
/******************LIB*******************/
#include "LIB/STD_Types.h"
#include "LIB/BIT_MATH.h"


/*****************MCAL*******************/
#include "MCAL/GIE/GIE_Interface.h"
#include "MCAL/EXTI/EXTI_Interface.h"
#include "MCAL/DIO/DIO_Interface.h"
#include "MCAL/ADC/ADC_Interface.h"


/*****************HAL*******************/
#include "HAL/LCD/LCD_Interface.h"
#include "HAL/LM35/LM35_Interface.h"
#include "HAL/DCMOTOR/DCMOTOR_Interface.h"

/*****************Delay*****************/
#include "avr/delay.h"

/***********Global Variables************/
u8 Global_u8TempValueRoom1;
u8 Global_u8TempValueRoom2;


/**************Handlers*****************/
void Room1(void)
{
	/**************Temperature**********************/
	LCD_voidClearScreen();
	LCD_voidSendString((u8*)"Welcome, Room1");
	LCD_voidSetPosition(1,0);
	LCD_voidSendString((u8*)"Temperature: ");
	LCD_voidSetPosition(1,12);


	Global_u8TempValueRoom1 =LM35_u16GetTempReading(CHANNEL0);

	if(Global_u8TempValueRoom1<10)
	{
		LCD_voidSetPosition(1,12);
		LCD_voidSendString((u8*)" ");
		LCD_voidSendNumber(Global_u8TempValueRoom1);
	}

	else
	{
		LCD_voidSetPosition(1,12);
		LCD_voidSendNumber(Global_u8TempValueRoom1);
	}

	_delay_ms(2000);
}

void Room2(void)
{
	/**************Temperature**********************/
	LCD_voidClearScreen();
	LCD_voidSendString((u8*)"Welcome, Room2");
	LCD_voidSetPosition(1,0);
	LCD_voidSendString((u8*)"Temperature: ");
	LCD_voidSetPosition(1,12);


	Global_u8TempValueRoom2 =LM35_u16GetTempReading(CHANNEL4);

	if(Global_u8TempValueRoom2<10)
	{
		LCD_voidSetPosition(1,12);
		LCD_voidSendString((u8*)" ");
		LCD_voidSendNumber(Global_u8TempValueRoom2);
	}

	else
	{
		LCD_voidSetPosition(1,12);
		LCD_voidSendNumber(Global_u8TempValueRoom2);
	}

	_delay_ms(2000);
}



int main(void)
{
	GIE_voidEnable();
	EXTI_voidInit();

	LCD_voidInit();
	LM35_voidInit();
	MOTOR_voidInit();

	/*Print welcome message*/
	LCD_voidClearScreen();
	LCD_voidSendString((u8*)"Welcome to MP5!");

	_delay_ms(2000);
	LCD_voidClearScreen();


	EXTI_u8Int1SetCallBack(Room1);
	EXTI_u8Int2SetCallBack(Room2);

	/***************************************************************/
	while(1)
	{
		MOTOR_voidCounterClockWise();
		LCD_voidClearScreen();
		LCD_voidSendString((u8*)"Motor: CCW");
		_delay_ms(3000);
		MOTOR_voidClockWise();
		LCD_voidClearScreen();
		LCD_voidSendString((u8*)"Motor: CW");
		_delay_ms(3000);
	}
	return 0;
}
