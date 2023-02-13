/*
 * main.c
 *
 *  Created on: ١٣‏/٠٢‏/٢٠٢٣
 *      Author: Ibrahim Salman
 */
#include "queue.h"

int main(void) {
	int temp;
	x buffer_controller;  // that controls student buffer
	fifo_init(&buffer_controller,buffer,100);

	DPRINTF("Welcome to the Student Management System\n");
	while(1)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("Choose The Task that you want to perform\n");
		DPRINTF("1. Add the Student Details Manually\n");
		DPRINTF("2. Add the Student Details From Text File\n");
		DPRINTF("3. Find the Student Details by Roll Number\n");
		DPRINTF("4. Find the Student Details by First Name\n");
		DPRINTF("5. Find the Student Details by Course ID\n");
		DPRINTF("6. Find the Total number of Students\n");
		DPRINTF("7. Delete the Student Details by Roll Number \n");
		DPRINTF("8. Update the Student Details by Roll Number \n");
		DPRINTF("9. Show all information\n");
		DPRINTF(" Enter your choice to perform the task\n");
		scanf("%d",&temp);
		switch(temp)
		{
		case 1 :
		{
			add_student_manually(&buffer_controller);
			break;
		}
		case 2 :
		{
			add_student_file(&buffer_controller);
			break;
		}
		case 3 :
		{
			find_r1(&buffer_controller);
			break;
		}
		case 4 :
		{
			find_fn(&buffer_controller);
			break;
		}
		case 5 :
		{
			find_c(&buffer_controller);
			break;
		}
		case 6 :
		{
			tot_s(&buffer_controller);
			break;
		}
		case 7 :
		{
			del_s(&buffer_controller);
			break;
		}
		case 8 :
		{
			up_s(&buffer_controller);
			break;
		}
		case 9 :
		{
			show_s(&buffer_controller);
			break;
		}
		default :
		{
			DPRINTF("Wrong choice\n");

		}
		}

	}

}

