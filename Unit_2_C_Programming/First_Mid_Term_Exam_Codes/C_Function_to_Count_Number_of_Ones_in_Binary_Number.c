/*
 ============================================================================
 Name        : C_Function_to_Count_Number_of_Ones_in_Binary_Number.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : C_Function_to_Count_Number_of_Ones_in_Binary_Number, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

unsigned int countSetBits(unsigned int n);

int main()
{
    int i;

    printf("Enter any number: ");
    fflush(stdout); fflush(stdin);
    scanf("%d", &i);

    printf("%d", countSetBits(i));
    return 0;
}

unsigned int countSetBits(unsigned int n)
{
	unsigned int count = 0;
	while (n)
	{
		count += n & 1;
		n >>= 1;
	}
	return count;
}
