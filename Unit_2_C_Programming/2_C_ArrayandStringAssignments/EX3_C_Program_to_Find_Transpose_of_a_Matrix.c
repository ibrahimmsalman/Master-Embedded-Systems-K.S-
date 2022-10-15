/*
 ============================================================================
 Name        : EX3_C_Program_to_Find_Transpose_of_a_Matrix.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX3_C_Program_to_Find_Transpose_of_a_Matrix, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, j, r, c, a[3][3], b[3][3];
	printf("Enter number of rows and columns of the matrix \n");
	scanf("%d %d\n",&r,&c);
	for (i=0; i<r; ++i)
	{
		for(j=0; j<c; ++j)
		{
			printf("Enter the element of the matrix [%d][%d] \n", i+1, j+1);
			fflush(stdin); fflush(stdout);
			scanf("%d", &a[i][j]);
		}
	}
	printf("Matrix is \n");
	for (i=0; i<r; ++i)
		{
			for(j=0; j<c; ++j)
			{
				printf("%d",a[i][j]);
				fflush(stdin); fflush(stdout);
				scanf("%d", &a[i][j]);
			    if (j==c-1)
			    {
			    	printf("\n\n");
			    }
			}
		}
	for (i=0; i<r; ++i)
		{
			for(j=0; j<c; ++j)
			{
				b[j][i] = a[i][j];
			}
		}
	printf("Transpose of Matrix \n");
	for (i=0; i<c; ++i)
	{
		for (j=0; j<r; ++j)
		{
			printf("%d \n",b[i][j]);
			if (j==r-1)
			{
				printf("\n\n");
			}
		}
	}
	return 0;
}
