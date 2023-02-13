/*
 * queue.h
 *
 *  Created on: ١٣‏/٠٢‏/٢٠٢٣
 *      Author: Ibrahim Salman
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdio.h>
#include <stdlib.h>
#include"string.h"
#define DPRINTF(...) {fflush(stdin);\
		fflush(stdout);\
		printf(__VA_ARGS__);\
		fflush(stdin);\
		fflush(stdout);}
typedef struct {     // student information structure
	char fname[50];
	char lname[50];
	int roll;
	float GPA;
	 int cid[10];
} st;
st buffer[100];   // the buffer contains students data
typedef struct{
	st *head;
	st *tail;
	st *base;
	int counter;
	int length;
} x;
typedef enum{
	fifo_no_error,
	fifo_full,
	fifo_empty,
	fifo_null,
	fifo_error

} fifo_buffer_state;
// functions
int check_roll(x*fifo,int x);                   // to check if roll number is exist before or not
fifo_buffer_state fifo_init(x*fifo,st* buf,int lenght); // initialize buffer
fifo_buffer_state add_student_file();                   // add students info using text file
fifo_buffer_state add_student_manually(x*fifo);               // add student manually
fifo_buffer_state find_r1(x*fifo);                      // find student data using Roll number
fifo_buffer_state find_fn(x*fifo);                    // find student data using first name
fifo_buffer_state find_c(x*fifo);                     // display students info registered by course id
fifo_buffer_state tot_s(x*fifo);                     // total number of student
fifo_buffer_state del_s(x*fifo);                    // delete student by roll num
fifo_buffer_state shift_buffer(int index,x*fifo);  // to shift buffer and override on location wanted to be deleted
fifo_buffer_state up_s(x*fifo);                    // update student by roll num
fifo_buffer_state show_s(x*fifo);                 // show all information


#endif /* QUEUE_H_ */
