/*
 ============================================================================
 Name        : EX6_C_Program_to_Find_The_Frequency_of_Characters_in_a_String.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX6_C_Program_to_Find_The_Frequency_of_Characters_in_a_String, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, c=0;
	char a[1000], ch;
	printf("Enter your string \n");
	gets(a);
	printf("Enter a character to find frequency \n");
	fflush(stdin); fflush(stdout);
	scanf("%c",&ch);
	for (i=0; a[i]!='\0'; ++i)
	{
		while (ch == a[i])
		{
			++c;
		}
	}
	printf("Frequency of %c = %d",ch, c);
	return 0;
}
