/*
 ============================================================================
 Name        : EX4_C_program_to_print_the_elements_of_an_array_in_reverse.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX4_C_program_to_print_the_elements_of_an_array_in_reverse, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, i, arr[10];
	int *parr;

	printf("Enter number of elements of the array (max 10) \n");
    fflush(stdin); fflush(stdout);
    scanf("%d",&n);

    parr = &arr;
	printf("Enter elements of the array (max 10) \n");
	for (i=0; i<n; ++i)
	{
		printf("Enter element of the array number %d \n",i+1);
		scanf("%d",parr);
		parr++;
	}

	parr = &arr[n-1];

	printf("Elements of the array in reverse \n");
	for(i=n; i>0; --i)
	{
		printf("Element of the array in reverse number %d %d\n",i, *parr);
		parr--;
	}

	return 0;
}
