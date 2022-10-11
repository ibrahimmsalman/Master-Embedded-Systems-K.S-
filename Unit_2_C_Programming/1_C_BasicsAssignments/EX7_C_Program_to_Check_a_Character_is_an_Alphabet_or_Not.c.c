/*
 ============================================================================
 Name        : c.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX7_C_Program_to_Check_a_Character_is_an_Alphabet_or_Not, Ansi-style
 ============================================================================
 */

#include <stdio.h>

int main()
{
	char c;

	printf("Enter your character: \n");

	scanf("%c",&c);

	if((c>='a' && c<='z') || (c>='A' && c<='Z'))
	{
	printf("%c is an alphabet",c);
	}

	else
	{
	printf("%c is not an alphabet",c);
	}
	return 0;
}
