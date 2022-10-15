/*
 ============================================================================
 Name        : EX5_C_Program_to_Search_an_Element_in_Array.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX5_C_Program_to_Search_an_Element_in_Array, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n, e, a[10];
	printf("Enter number of elements of the matrix \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	for (i=0; i<n; ++i)
	{
		printf("Enter the element [%d] \n",i+1);
		fflush(stdin); fflush(stdout);
		scanf("%d", &a[i]);
	}
	printf("Enter number of elements to be searched \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&e);
	i=0;
	while (i<n && e !=a [i]);
	{
	 i++;
	}
	if (i<n)
	{
		printf("Number found at location %d", i+1);
	}
	else
	{
		printf("Number not found");
	}

	return 0;
}
