/*
 ============================================================================
 Name        : EX2_C_Program_to_Calculate_Factorial_of_a_Number_Using_Recursion.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : C_Program_to_Calculate_Factorial_of_a_Number_Using_Recursion, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int factorial (int n);
int main()
{
	int n;
	printf("Enter positive integer number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d ",&n);
	printf("Factorial of %d = %ld",n, factorial(n));
	return 0;
}
int factorial (int n)
{
	if (n<0)
	{
		printf("Error! please enter positive integer number");
	}

	return n*factorial(n-1);
}
