/*
 ============================================================================
 Name        : EX7_C_Program_to_Find_the_Length_of_a_String.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX7_C_Program_to_Find_the_Length_of_a_String, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int i;
	char c, a[1000];
	printf("Enter your string \n");
	fflush(stdin); fflush(stdout);
	gets(a);
	printf("Length of  string = %d",strlen(a));
	return 0;
}
