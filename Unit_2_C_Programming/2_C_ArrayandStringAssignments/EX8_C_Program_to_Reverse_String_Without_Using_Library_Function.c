/*
 ============================================================================
 Name        : EX8_C_Program_to_Reverse_String_Without_Using_Library_Function.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX8_C_Program_to_Reverse_String_Without_Using_Library_Function, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int i=0, j=0;
	char a[1000], b;
	printf("Enter your string \n");
	gets (a);
	i=0, j=strlen(a) - 1;
	while (i < j)
	{
		b = a[i];
		a[i] = a[j];
		a[j] = b;
		i++;
		j--;
	}
	printf("Reverse of string is %s",a);
	return 0;
}
