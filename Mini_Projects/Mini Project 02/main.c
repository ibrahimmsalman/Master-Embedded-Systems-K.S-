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

u8 customChar[] = { 0x04, 0x0A, 0x04, 0x1F, 0x04, 0x04, 0x0A, 0x11 };

int main(void) {

	u8 Local_u8Pressed = NOTPRESSED;
	s8 loc_col_pos = LCD_COLUMN0;
	s8 loc_row_pos = LCD_ROW0;

	LCD_voidInit();
	KPD_Init();
	// set hamoksha in r0 and c0 in start of lcd
	LCD_voidSendCustomCharacter(customChar, 1, loc_row_pos, loc_col_pos);

	while (1) {
		/* hamoksha move up using 8 , down 2 , left 4 , right 6 */
		Local_u8Pressed = KPD_u8GetPressed();
		if (Local_u8Pressed != NOTPRESSED) {
			switch (Local_u8Pressed) {
			case '2':/* move down */
				loc_row_pos = LCD_ROW1;
				break;
			case '8': /* move up */
				loc_row_pos = LCD_ROW0;
				break;
			case '4': /* move left */
				loc_col_pos--;
				break;
			case '6': /* move right */
				loc_col_pos++;
				break;
			default:
				break;
			}
			LCD_voidClearScreen();
			if (loc_col_pos < LCD_COLUMN0) {
				loc_col_pos = LCD_COLUMN0;
			} else if (loc_col_pos > LCD_COLUMN15) {
				loc_col_pos = LCD_COLUMN15;
			} else { /* NOTHING */ }
			LCD_voidSendCustomCharacter(customChar, 1, loc_row_pos, loc_col_pos);

			Local_u8Pressed = NOTPRESSED;

		}

	}

	return 0;
}
