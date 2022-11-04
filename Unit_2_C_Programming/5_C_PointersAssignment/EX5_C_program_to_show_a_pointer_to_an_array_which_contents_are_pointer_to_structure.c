/*
 ============================================================================
 Name        : EX5_C_program_to_show_a_pointer_to_an_array_which_contents_are_pointer_to_structure.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX5_C_program_to_show_a_pointer_to_an_array_which_contents_are_pointer_to_structure, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	struct SEmployee
	{
		char* name;
		int id;
	};

		struct SEmployee emp1 = {"Ibrahim",1000}, emp2 = {"Ali",1001}, emp3 = {"Salman",1002};

		struct SEmployee *arr[]={&emp1,&emp2,&emp3};

		struct SEmployee*(*P_arr_emp)[3]= &arr;

		printf(" Employee Name : %s \n",(*(*P_arr_emp))->name);
		printf(" Employee ID :  %d \n",(*(*P_arr_emp))->id);

	return 0;
}
