/*
 ============================================================================
 Name        : Q1_C_Program_Takes_String_From_The_User_And_Check_If_It_The_Same.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : Q1_C_Program_Takes_String_From_The_User_And_Check_If_It_The_Same, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <string.h>

int main()
{
	char arr1[100], arr2[100];
	int result;
	printf("Enter a string : ");
	fflush(stdout);
	gets(arr1);


	printf("Enter your username : ");
	fflush(stdout);
	gets(arr2);

	result = stricmp(arr1, arr2);
	if (result == 0)
		printf("Identical");
	else
		printf("Different");

	return 0;
}
