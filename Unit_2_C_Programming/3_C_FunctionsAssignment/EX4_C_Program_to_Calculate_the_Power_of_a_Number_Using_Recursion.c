/*
 ============================================================================
 Name        : EX4_C_Program_to_Calculate_the_Power_of_a_Number_Using_Recursion.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : C_Program_to_Calculate_the_Power_of_a_Number_Using_Recursion, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int power(int number, int Power) ;

/* Main Function */
int main ()
{
	int number, Power ;

	printf ("Enter base number: ");
	fflush(stdin);	fflush(stdout);
	scanf ("%d", &number);

	printf ("Enter power number(Positive integer: ");
	fflush(stdin);	fflush(stdout);
	scanf ("%d", &Power);
	printf ("%d^%d = %d", number, Power, power(number, Power));

	return 0;
}
int power(int number, int Power)
{
	if (Power == 0)
		return 1;				/* case power of zero */
	else if (Power == 1)
		return number;			/* case of power one */
	else
		return (number * power(number, Power-1));		/* power calculation */
}
