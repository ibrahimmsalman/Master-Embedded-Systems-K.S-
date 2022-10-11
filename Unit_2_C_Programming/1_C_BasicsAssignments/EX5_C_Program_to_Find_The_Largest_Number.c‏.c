/*
 ============================================================================
 Name        : cþ.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX5_C_Program_to_Find_The_Largest_Number, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	float num1,num2,num3;
	printf("Enter first number: \n");
	scanf("%f",&num1);
	printf("Enter second number: \n");
	scanf("%f",&num2);
	printf("Enter third number: \n");
	scanf("%f",&num3);
	if (num1>=num2 && num1>=num3)
		printf("%f is the largest number",num1);

	if (num2>=num1 && num2>=num3)
		printf("%f is the largest number",num2);

	if (num3>=num1 && num3>=2)
		printf("%f is the largest number",num3);

	return 0;
}
