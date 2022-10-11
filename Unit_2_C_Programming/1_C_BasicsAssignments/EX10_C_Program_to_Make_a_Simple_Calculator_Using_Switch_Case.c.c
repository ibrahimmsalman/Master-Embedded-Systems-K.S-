/*
 ============================================================================
 Name        : c.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description :EX10_C_Program_to_Make_a_Simple_Calculator_Using_Switch_Case, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	float n1, n2;
	char c;
    printf("Enter your operation(+,-,*,/): ");
    scanf("%c",&c);
    printf("Enter your numbers : ");
    scanf("%f %f",&n1,&n2);
	switch(c)
	{
	case '+':
	printf("%.2f + %.2f = %.2f",n1, n2, n1+n2);
	break;
	case '-':
	printf("%.2f - %.2f = %.2f",n1, n2, n1-n2);
	break;
	case '*':
	printf("%.2f * %.2f = %.2f",n1, n2, n1*n2);
	break;
	case '/':
	printf("%.2f / %.2f = %.2f",n1, n2, n1/n2);
	break;
	default:
	printf("Error operation is not correct!");
	}
	return 0;
}
