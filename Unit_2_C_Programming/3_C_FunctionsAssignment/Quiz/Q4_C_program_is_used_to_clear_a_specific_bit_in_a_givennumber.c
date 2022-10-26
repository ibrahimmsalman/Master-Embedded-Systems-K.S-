/*
 ============================================================================
 Name        : Q4_C_program_is_used_to_clear_a_specific_bit_in_a_givennumber.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : Q4_C_program_is_used_to_clear_a_specific_bit_in_a_given_number, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int clearbit (int number, int BitNumber);

int main()
{
	int number, BitNumber;

	printf("Enter any number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &number);

	printf("Enter nth bit to clear (0-31): ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &BitNumber);

	printf("\nBit cleared successfully.\n\n");

	printf("Number before clearing %d bit: %d (in decimal).\n", BitNumber, number);
	printf("Number after clearing %d bit: %d (in decimal).\n", BitNumber, clearbit (number, BitNumber));

	return 0;

}

int clearbit (int number, int BitNumber)
{
	int result ;

 	result = number & (~(1 << BitNumber));
 	return result ;
}
