/*
 ============================================================================
 Name        : C_Function_to_Take_a_Number_and_Sum_all_Digits.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : C_Function_to_Take_a_Number_and_Sum_all_Digits, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int main()
{
int n, i, sum=0, r;
printf("Enter your number: \n");
fflush(stdin); fflush(stdout);
scanf("%d", &n);
while(n != 0)
   {
       r = n % 10;
       sum += r;
       n = n / 10;
   }

   printf("sum = %d", sum);
	return 0;
}
