/*
 ============================================================================
 Name        : EX2_C_Program_to_Print_All_Alphabets_Using_a_pointer.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX2_C_Program_to_Print_All_Alphabets_Using_a_pointer, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char alpha[27];
	int i;
	char *palpha;
	palpha = alpha;

	for(i=0; i<26; i++)
	{
		*palpha = i + 'A';
		palpha++;
	}

	palpha = alpha;

		printf(" The Alphabets are : \n");

		for (i = 0; i < 26; ++i)
		{
			printf(" %c ", *palpha);
			palpha++;
		}

	return 0;
}
