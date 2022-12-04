#include "uart.h"
unsigned char string_buffer[100] = "learn-in-depth:<Ibrahim>";
unsigned char const string_buffer_2[100] = "to create a rodata section";
void main(void)
{
//versatilePB physical Board
Uart_Send_string(string_buffer);
}