/*
 ============================================================================
 Name        : EX1_Prime_Numbers_between_two_Intervals_by_Making_User_Defiend_Function.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX1_Prime_Numbers_between_two_Intervals_by_Making_User_Defiend_Function, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int check_prime_numbers(int num);

// Main Function

int main()
{
	int first_num, second_num, i, f;
	printf("Enter two numbers(intervals) : ");
	fflush(stdin); fflush(stdout);
	scanf("%d %d", &first_num, &second_num);
	printf("prime numbers between %d and %d are ",first_num, second_num);
	for(i=first_num+1; i<second_num; ++i)
	{
		f = check_prime_numbers(i);
		if(f == 0)
			printf("%d ",i);
	}
	return 0;
}

int check_prime_numbers(int num) // User defined function to get prime numbers

{
	int j, f = 0;
	for(j=2; j<=num/2; ++j)
	{
		if(num%j==0)
		{
			f=1;
			break;
		}
	}
	return f;
}
