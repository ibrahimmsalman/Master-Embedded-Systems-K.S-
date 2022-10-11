/*
 ============================================================================
 Name        : mainþ.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX3_C_Program_to_Check_a_Number_Is_Even, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int num;
	fflush(stdin); fflush(stdout);
	printf("Enter your number: \n");
	scanf("%d",&num);
	if(num%2 ==0)
		printf("Your number %d is even",num);
	else
		printf("Your number %d is odd",num);
	return 0;
}
