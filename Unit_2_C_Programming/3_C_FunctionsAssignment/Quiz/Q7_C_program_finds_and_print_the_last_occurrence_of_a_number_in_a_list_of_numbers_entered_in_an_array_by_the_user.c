/*
 ============================================================================
 Name        : Q7_C_program_finds_and_print_the_last_occurrence_of_a_number_in_a_list_of_numbers_entered_in_an_array_by_the_user.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : C_program_finds_and_print_the_last_occurrence_of_a_number_in_a_list_of_numbers_entered_in_an_array_by_the_user, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void find_lastindex(int arr[],int num);

int main()
{
	int arr[10]={10,20,5,8,9,20,5,45,90,10};
	int x;
	printf("Enter your search number:\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&x);

	find_lastindex(arr,x);

}

void find_lastindex (int arr[],int num)
{
	int i, k=-1;
	for(i=0;i<10;i++)
	{
		if(num==arr[i])
			k=i;
		else
			continue;

	}

	printf("\nThe index of %d is: %d", num, k);

}
