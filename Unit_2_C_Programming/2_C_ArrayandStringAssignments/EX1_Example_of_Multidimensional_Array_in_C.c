/*
 ============================================================================
 Name        : EX1_Example_of_Multidimensional_Array_in_C.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   :
 Description :EX1_Example_of_Multidimensional_Array_in_C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
	float a[2][2], b[2][2], c[2][2];
	int i, j;
	printf("Enter the element of first matrix\n");

	for (i=0; i<2; ++i)
	{
		for (j=0; j<2; ++j)
		{
			printf("Enter the element %d %d ",i+1, j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f", &a[i][j]);
		}
	}

	printf("Enter the elements of second materix\n");

	for (i=0; i<2; ++i)
	{
		for (j=0; j<2; ++j)
		{
			printf("Enter the element %d %d",i+1, j+1);
			fflush(stdin); fflush(stdout);
			scanf("%f", &b[i][j]);
		}
	}

	for (i=0; i<2; ++i)
	{
		for (j=0; j<2; ++j)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}

	printf("Sum of matrix");

	for (i=0; i<2; ++i)
	{
		for (j=0; j<2; ++j)
		{
			printf("%f\t", c[i][j]);
			if(j==1)
			{
				printf("\n");
			}
		}
	}
	return 0;
}
