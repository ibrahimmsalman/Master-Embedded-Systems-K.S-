/*
 ============================================================================
 Name        : EX3_C_Program_to_Print_a_String_in_Reverse_Using_a_Pointer.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX3_C_Program_to_Print_a_String_in_Reverse_Using_a_Pointer, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char str[50];
	char revstr[50];
	char *pstr = str;
	char *prevstr = revstr;

	int i = -1;

	printf("Input a string : ");
	fflush(stdin); fflush(stdout);
	scanf("%s", str);

	while (*pstr)
	{
		pstr++;
		i++;
	}

	while (i>=0)
	{
		pstr--;
		*prevstr = *pstr;
		prevstr++;
		--i;
	}

	*prevstr = '\0';

		printf("Reverse of the string is : %s\n\n", revstr);

	return 0;
}
