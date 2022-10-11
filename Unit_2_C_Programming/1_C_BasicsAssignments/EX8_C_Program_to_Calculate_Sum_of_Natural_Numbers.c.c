/*
 ============================================================================
 Name        : c.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX8_C_Program_to_Calculate_Sum_of_Natural_Numbers, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main(void)
{
	int n, i, sum=0;
	printf("Enter your integer number: \n");

	scanf("%d",&n);

	for (i=1; i<=n; ++i)
	{
		sum+=i;
	}
	printf("Sum is %d",sum);
	return 0;
}
