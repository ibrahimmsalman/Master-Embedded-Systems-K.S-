/*
 ============================================================================
 Name        : Q6_C_program_check_if_a_given_number_entered_by_the_user_is_power_of_3.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : Q6_C_program_check_if_a_given_number_entered_by_the_user_is_power_of_3, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int checkPowerof3 (int number);

int main ()
{
	unsigned int number;
	printf ("Enter an integer number:\r\n");
	fflush(stdin);	fflush(stdout);
	scanf ("%d", &number);

	checkPowerof3(number) ? printf("%d ==> 0", number) : printf("%d ==> 1", number) ;

	return 0;
}

int checkPowerof3 (int number)
{
	double i = log (number)/log(3) ;
	return i == trunc(i);

}
