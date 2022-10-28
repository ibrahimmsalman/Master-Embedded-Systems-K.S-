/*
 ============================================================================
 Name        : C_Function_to_Sum_Numbers_From_1_To_100_Without_Loop.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : C_Function_to_Sum_Numbers_From_1_To_100_Without_Loop, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int i = 0, sum = 0;

int main()
{
	if (i <= 100)
	{
		sum += i;
		i++;
		main();
	}
		printf("\nSum of Numbers from 0 to 100 is: %d ", sum);

	return 0;
}
