/*
 ============================================================================
 Name        : c.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char c;
	printf("Enter your character: \n");
	scanf("%c",&c);
	if(c=='a' || c=='e' || c=='i' || c=='o' || c=='A' || c=='E' || c=='I' || c=='O')
	printf("Character %c is Vowel",c);
	else
		printf("Character %c is consonant",c);
	return 0;
}
