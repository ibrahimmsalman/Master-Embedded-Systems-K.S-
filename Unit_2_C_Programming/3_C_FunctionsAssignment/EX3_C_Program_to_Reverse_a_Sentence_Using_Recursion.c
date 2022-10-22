/*
 ============================================================================
 Name        : EX3_C_Program_to_Reverse_a_Sentence_Using_Recursion.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description :C_Program_to_Reverse_a_Sentence_Using_Recursion, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void reverseSentence();

//Main Function
int main()
{

	printf ("Enter a sentence: ");
	fflush(stdin);	fflush(stdout);
	reverseSentence();

	return 0;
}
void reverseSentence()
{
	char c;
	scanf("%c", &c);
	if (c != '\n')
	{
		reverseSentence();
		printf("%c", c);
	}

}
