/*
 ============================================================================
 Name        : Q5_C_program_is_used_to_find_the_4th_least_significant_bit_in_a_specific_number_entered.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description :Q5_C_program_is_used_to_find_the_4th_least_significant_bit_in_a_specific_number_entered, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int number;
	int numOfIntegerBits = 31;
	int newNumber;

	printf("Enter an integer number in decimal format:\n");
	fflush(stdin); fflush(stdout);
	scanf("%d", &number);

	printf("The %d in binary number system is:\n", number);

	for (; numOfIntegerBits >= 0; numOfIntegerBits--)
	{
		newNumber = number >> numOfIntegerBits;

		if (newNumber & 1)
			printf("1");
		else
			printf("0");
	}

	newNumber = number>>3;

	if(newNumber & 1)
		printf("\nThe 4th least significant bit is 1");
	else
		printf("\nThe 4th least significant bit is 0");
	return 0;

}
