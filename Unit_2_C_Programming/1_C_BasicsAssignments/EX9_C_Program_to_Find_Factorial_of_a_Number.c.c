/*
 ============================================================================
 Name        : c.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX9_C_Program_to_Find_Factorial_of_a_Number, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	int n, i;
	unsigned long long f=1;
	printf("Enter your positive integer number: \n");
	scanf("%d",&n);
	if(n<0)
	{
		printf("Error you entered negative number!");
	}
	else
	{
		for(i=1; i<=n; ++i)
		{
			f*=i;
		}
		printf("Factorial of %d is %llu",n,f);
	}

return 0;
}
