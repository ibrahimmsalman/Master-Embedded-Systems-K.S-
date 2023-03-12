/*
 * ATmega32.h
 *
 *  Created on: March 12, 2023
 *      Author: Ibrahim Salman
 */
//---------------------------------------------------------------------
//Includes
//---------------------------------------------------------------------

#include "Platform_Types.h"

#ifndef INC_ATMEGA32_H_
#define INC_ATMEGA32_H_

//---------------------------------------------------------------------
//Base Addresses for Memories
//---------------------------------------------------------------------

#define FLASH_Memory									0x00
#define SRAM											0x60

//---------------------------------------------------------------------
//Base Addresses Peripherals
//---------------------------------------------------------------------

#define GPIOA_Base										0x39
#define GPIOB_Base										0x36
#define GPIOC_Base										0x33
#define GPIOD_Base										0x30

#define USART_Base										0x29

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//Peripheral registers
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:GPIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{

	volatile	union {
		volatile uint8 PIN;
		struct {
			volatile uint8 PIN0 :1;
			volatile uint8 PIN1 :1;
			volatile uint8 PIN2 :1;
			volatile uint8 PIN3 :1;
			volatile uint8 PIN4 :1;
			volatile uint8 PIN5 :1;
			volatile uint8 PIN6 :1;
			volatile uint8 PIN7 :1;
		}bits;
	}PIN;

	volatile	union {
		volatile uint8 DDR;
		struct {
			volatile uint8 DD0 :1;
			volatile uint8 DD1 :1;
			volatile uint8 DD2 :1;
			volatile uint8 DD3 :1;
			volatile uint8 DD4 :1;
			volatile uint8 DD5 :1;
			volatile uint8 DD6 :1;
			volatile uint8 DD7 :1;
		}bits;
	}DDR;

	volatile	union {
		volatile uint8 PORT;
		struct {
			volatile uint8 PORT0 :1;
			volatile uint8 PORT1 :1;
			volatile uint8 PORT2 :1;
			volatile uint8 PORT3 :1;
			volatile uint8 PORT4 :1;
			volatile uint8 PORT5 :1;
			volatile uint8 PORT6 :1;
			volatile uint8 PORT7 :1;
		}bits;
	}PORT;
}GPIO_typedef;

//-*-*-*-*-*-*-*-*-*-*-*
//Peripheral register:USART
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct{


	volatile uint8 UBRRL;

	volatile	union {
		volatile uint8 UCSRB;
		struct {
			volatile uint8 TXB8 	:1;
			volatile uint8 RXB8 	:1;
			volatile uint8 UCSZ2    :1;
			volatile uint8 TXEN     :1;
			volatile uint8 RXEN     :1;
			volatile uint8 UDRIE    :1;
			volatile uint8 TXCIE    :1;
			volatile uint8 RXCIE    :1;
		}bits;
	}UCSRB;

	volatile	union {
		volatile uint8 UCSRA;
		struct {
			volatile uint8 MPCM :1;
			volatile uint8 U2X  :1;
			volatile uint8 PE   :1;
			volatile uint8 DOR  :1;
			volatile uint8 FE   :1;
			volatile uint8 UDRE :1;
			volatile uint8 TXC  :1;
			volatile uint8 RXC  :1;
		}bits;
	}UCSRA;

	volatile uint8 UDR;

}USART_typedef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*

#define GPIOA 							((GPIO_typedef *)(GPIOA_Base))
#define GPIOB 							((GPIO_typedef *)(GPIOB_Base))
#define GPIOC 							((GPIO_typedef *)(GPIOC_Base))
#define GPIOD 							((GPIO_typedef *)(GPIOD_Base))

#define USART							((USART_typedef *)(USART_Base))
//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
//-*-*-*-*-*-*-*-*-*-*-*-
//USART Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#define UBRRH							*((uint8 *)(0x40))

#define UCSRC							*((uint8 *)(0x40))
#define UCPOL							0
#define UCSZ0							1
#define UCSZ1							2
#define USBS							3
#define UPM0							4
#define UPM1							5
#define UMSEL							6
#define URSEL							7



//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

#endif /* INC_ATMEGA32_H_ */