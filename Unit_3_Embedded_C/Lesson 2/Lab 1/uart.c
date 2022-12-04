#include "uart.h"
//uart registers
#define UART0DR  *((volatile unsigned int* const)((unsigned int *)0x101f1000))
void Uart_Send_string (unsigned char *P_tx_string)
{
  while(*P_tx_string != '\0')
  {
    /* Loop until end of string */
	UART0DR = (unsigned int)(*P_tx_string); /* Transmit Char */
	P_tx_string++; /* Next Char */
  } 
}