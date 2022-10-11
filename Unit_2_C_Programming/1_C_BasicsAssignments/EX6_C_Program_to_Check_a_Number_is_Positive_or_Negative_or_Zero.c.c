/*
 ============================================================================
 Name        : c.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX6_C_Program_to_Check_a_Number_is_Positive_or_Negative_or_Zero, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	double num;
	printf("Enter your number :\n");
	scanf("%lf",&num);
	if(num>0)
		printf("%lf is positive",num);

	else if(num<0)
		printf("%lf is negative",num);

	else
		printf("%lf is zero",num);
	return 0;
}
