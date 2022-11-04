/*
 ============================================================================
 Name        : EX1_Write_a_program_in_C_to_demonstrate_how_to_handle_the_pointers.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX1_Write_a_program_in_C_to_demonstrate_how_to_handle_the_pointers, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
int *ab;
int m;

printf("How to handle pointers in the program \n");

m=29;
printf("The address of m ;",&m);
printf("The value of m ;",m);

ab=&m;
printf("Assign pointer ab with address of m \n");
printf("The address of pointer ab ;",ab);
printf("The value of pointer ab ;",*ab);

m=34;
printf("Assign m with value 34 \n");
printf("The address of pointer ab ;",ab);
printf("The content of pointer ;",*ab);

*ab=7;
printf("Assign pointer ab with value 7 \n");
printf("The address of m ;",&m);
printf("The value of m ;",m);

	return 0;
}
