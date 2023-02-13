/*
 * queue.c
 *
 *  Created on: ١٣‏/٠٢‏/٢٠٢٣
 *      Author: Ibrahim Salman
 */

#include"queue.h"

fifo_buffer_state fifo_init(x*fifo,st* buf,int lenght)
{
	if(!fifo || !buf)
	{
		return fifo_null;
	}
	fifo->base=buf;
	fifo->head=buf;
	fifo->tail=buf;
	fifo->length=lenght;
	fifo->counter=0;
	return fifo_no_error;
}
int check_roll(x*fifo,int x)  // to check if roll number is exist before or not
{ int y;
st* ptr=fifo->base;

for(y=0;y<(fifo->counter);y++)
{
	if(ptr->roll==x)
	{
		return 0;
	}
	ptr++;
}
return 1;
}
fifo_buffer_state add_student_manually(x*fifo)
{    int temp_int,y, x;
char temp_str[30];
if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
{
	DPRINTF("database not exist  \n");
	return fifo_null;
}
if(fifo->counter==fifo->length)   // check if full
{
	DPRINTF("[ERROR] data base is full\n");
	return fifo_full;
}
DPRINTF("--------------------------------------------\n");
DPRINTF("Add Student Details \n");
DPRINTF("--------------------------------------------\n");
DPRINTF("Enter the Roll Number\n");
gets(temp_str);
temp_int =atoi(temp_str);
if(check_roll(fifo,temp_int)==0)
{
	DPRINTF("[ERROR] Roll Number is already taken before \n");
	return fifo_error;
}
fifo->head->roll=atoi(temp_str);
DPRINTF("Enter First name of the student:\n");
gets(fifo->head->fname);
DPRINTF("Enter Last name of the student:\n");
gets(fifo->head->lname);
DPRINTF("Enter the GPA you obtained\n");
gets(temp_str);
fifo->head->GPA=atof(temp_str);
DPRINTF("Enter the course id of each course\n");
for(x=0;x<5;x++)
{
	DPRINTF("course %d id :\n",x+1);
	gets(temp_str);
	y=atoi(temp_str);
	if(y>0 && y<30)              // check if course id is available id
	{
		fifo->head->cid[x]=y;
		continue;
	}
	DPRINTF("[ERROR] course id is not correct\n");
	x--;
}
fifo->head++;
fifo->counter++;
DPRINTF("[INFO] Student Details are added successfully \n");
DPRINTF("--------------------------------------------\n");
DPRINTF("[INFO] the total number of students is : %d\n",fifo->counter);
DPRINTF("[INFO] you can add up to %d students \n",fifo->length);
DPRINTF("[INFO] you can add more about %d students \n",fifo->length - fifo->counter);
DPRINTF("--------------------------------------------\n");
return fifo_no_error;
}
fifo_buffer_state show_s(x*fifo)  // show all students information
{   st *current_stuednt =fifo->base;
int x,y;
if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
{
	DPRINTF("database not exist  \n");
	return fifo_null;
}
if(fifo->counter==0)         // check if is empty
{
	DPRINTF("--------------------------------------------\n");
	DPRINTF("[ERROR] database is empty \n");

	return fifo_empty;
}
for(x=0;x< fifo->counter;x++)   // show students data
{
	DPRINTF("--------------------------------------------\n");
	DPRINTF("Student Roll number : %d\n",current_stuednt->roll);
	DPRINTF("Student first name : %s\n",current_stuednt->fname);
	DPRINTF("Student last name : %s\n",current_stuednt->lname);
	DPRINTF("Student GPA : %.2f\n",current_stuednt->GPA);
	for(y=0;y<5;y++)
	{
		DPRINTF("course %d id : %d \n",y+1,current_stuednt->cid[y]);
	}
	current_stuednt++;
}
DPRINTF("--------------------------------------------\n");
DPRINTF("total number of students : %d\n",fifo->counter);
return fifo_no_error;
}
fifo_buffer_state find_r1(x*fifo)  // find student data using Roll number
{    char temp_str[30];
int temp_roll;
st *current_stuednt =fifo->base;
int x,y;
if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
{
	DPRINTF("database not exist  \n");
	return fifo_null;
}
if(fifo->counter==0)         // check if is empty
{
	DPRINTF("[ERROR] database is empty \n");
	DPRINTF("--------------------------------------------\n");
	return fifo_empty;
}
DPRINTF("Enter student roll number  \n");
gets(temp_str);
temp_roll=atoi(temp_str);

for(x=0;x< fifo->counter;x++)   // loop to get the roll number
{   if(current_stuednt->roll==temp_roll)
{
	DPRINTF("--------------------------------------------\n");
	DPRINTF("Student Roll number : %d\n",current_stuednt->roll);
	DPRINTF("Student first name : %s\n",current_stuednt->fname);
	DPRINTF("Student last name : %s\n",current_stuednt->lname);
	DPRINTF("Student GPA : %.2f\n",current_stuednt->GPA);
	for(y=0;y<5;y++)
	{
		DPRINTF("course %d id : %d \n",y+1,current_stuednt->cid[y]);
	}
	return fifo_no_error;
}
current_stuednt++;
}
DPRINTF("--------------------------------------------\n");
DPRINTF("[ERROR] Roll number is not found\n");                 // loop finished and roll not found
DPRINTF("--------------------------------------------\n");
return fifo_error;
}
fifo_buffer_state find_fn(x*fifo)                   // find student data using first name
{   char temp_str[30];
int flag=0;
st *current_stuednt =fifo->base;
int x,y;
if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
{
	DPRINTF("database not exist  \n");
	return fifo_null;
}
if(fifo->counter==0)         // check if is empty
{  DPRINTF("[ERROR] database is empty \n");
DPRINTF("--------------------------------------------\n");
return fifo_empty;
}
DPRINTF("Enter student first name   \n");
gets(temp_str);
for(x=0;x< fifo->counter;x++)   // loop to get the roll number
{   if(strcmpi(current_stuednt->fname,temp_str)==0) //compare strings without case sensitive
{
	DPRINTF("--------------------------------------------\n");
	DPRINTF("Student Roll number : %d\n",current_stuednt->roll);
	DPRINTF("Student first name : %s\n",current_stuednt->fname);
	DPRINTF("Student last name : %s\n",current_stuednt->lname);
	DPRINTF("Student GPA : %.2f\n",current_stuednt->GPA);
	for(y=0;y<5;y++)
	{
		DPRINTF("course %d id : %d \n",y+1,current_stuednt->cid[y]);
	}
	DPRINTF("--------------------------------------------\n");
	flag=1;        // flag to know the first name found at least 1 time
}
current_stuednt++;
}
if(flag==0)
{
	DPRINTF("--------------------------------------------\n");
	DPRINTF("[ERROR] No first name matched this name\n");                 // loop finished and roll not found
	DPRINTF("--------------------------------------------\n");
	return fifo_error;
}
return fifo_no_error;
}
fifo_buffer_state find_c(x*fifo)  // display students info registered by course id
{        char temp_str[30];
int temp_course_id;
st *current_stuednt =fifo->base;
int x,y,z,flag=0;
if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
{
	DPRINTF("database not exist  \n");
	return fifo_null;
}
if(fifo->counter==0)         // check if is empty
{
	DPRINTF("[ERROR] database is empty \n");
	DPRINTF("--------------------------------------------\n");
	return fifo_empty;
}
DPRINTF("Enter course id number  \n");
gets(temp_str);
temp_course_id=atoi(temp_str);
for(x=0;x< fifo->counter;x++)   // loop to get the course id

{   for(z=0;z<5;z++)
{
	if(current_stuednt->cid[z]==temp_course_id)  // if course id matches
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("Student Roll number : %d\n",current_stuednt->roll);
		DPRINTF("Student first name : %s\n",current_stuednt->fname);
		DPRINTF("Student last name : %s\n",current_stuednt->lname);
		DPRINTF("Student GPA : %.2f\n",current_stuednt->GPA);
		for(y=0;y<5;y++)
		{  DPRINTF("course %d id : %d \n",y+1,current_stuednt->cid[y]);}
		flag=1; // found at least one student
	}
}
current_stuednt++;
}
if(flag==0)
{
	DPRINTF("--------------------------------------------\n");
	DPRINTF("[ERROR] no student registered \n");                 // loop finished and students not found
	DPRINTF("--------------------------------------------\n");
	return fifo_error;
}
return fifo_no_error;
}
fifo_buffer_state tot_s(x*fifo)                     // total number of student
{

	if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
	{
		DPRINTF("database not exist  \n");
		return fifo_null;
	}
	if(fifo->counter==0)         // check if is empty
	{
		DPRINTF("[ERROR] database is empty \n");
		DPRINTF("--------------------------------------------\n");
		return fifo_empty;
	}
	DPRINTF("--------------------------------------------\n");
	DPRINTF("[INFO] the total number of students is : %d\n",fifo->counter);
	DPRINTF("[INFO] you can add up to %d students \n",fifo->length);
	DPRINTF("[INFO] you can add more about %d students \n",fifo->length - fifo->counter);
	DPRINTF("--------------------------------------------\n");
	return fifo_no_error;
}
fifo_buffer_state del_s(x*fifo)                   // delete student by roll num
{   char temp_str[30];
int x,y,temp_roll,index=0;
st *current_stuednt=fifo->base;
if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
{
	DPRINTF("database not exist  \n");
	return fifo_null;
}
if(fifo->counter==0)         // check if is empty
{
	DPRINTF("[ERROR] database is empty \n");
	DPRINTF("--------------------------------------------\n");
	return fifo_empty;
}
DPRINTF("Enter student roll number  \n");
gets(temp_str);
temp_roll=atoi(temp_str);

for(x=0;x< fifo->counter;x++)   // loop to get the roll number
{   if(current_stuednt->roll==temp_roll)
{
	DPRINTF("--------------------------------------------\n");
	DPRINTF("Student Roll number : %d\n",current_stuednt->roll);
	DPRINTF("Student first name : %s\n",current_stuednt->fname);
	DPRINTF("Student last name : %s\n",current_stuednt->lname);
	DPRINTF("Student GPA : %.2f\n",current_stuednt->GPA);
	for(y=0;y<5;y++)
	{
		DPRINTF("course %d id : %d \n",y+1,current_stuednt->cid[y]);
	}
	DPRINTF("--------------------------------------------\n");
	DPRINTF("Delete student 1-yes 2-No \n");
	DPRINTF("--------------------------------------------\n");
	gets(temp_str);
	temp_roll=atoi(temp_str);
	if(temp_roll==1){
		shift_buffer(index,fifo);  // to shift buffer and override on location wanted to be deleted
		fifo->head--;
		fifo->counter--;
		return fifo_no_error;
	}
	else if(temp_roll==0)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("--------Process canceled-------\n");
		return fifo_no_error;
	}
	else
	{   DPRINTF("--------------------------------------------\n");
	DPRINTF("[ERROR]wrong choice ..\n Uncompleted process...\n back to main menu .....  \n");
	return fifo_no_error;
	}
}
current_stuednt++;
index++;                //to find location in the buffer
}
DPRINTF("--------------------------------------------\n");
DPRINTF("[ERROR] Roll number is not found\n");                 // loop finished and roll not found
DPRINTF("--------------------------------------------\n");
return fifo_error;
}
fifo_buffer_state shift_buffer(int index,x*fifo) // to shift buffer and override on location wanted to be deleted
{
	int x;
	for(x=index;x<fifo->counter;x++)
	{
		buffer[x]=buffer[x+1];
	}
	DPRINTF("--------------------------------------------\n");
	DPRINTF("student deleted successfully\n");
	DPRINTF("--------------------------------------------\n");
	return fifo_no_error;
}
fifo_buffer_state up_s(x*fifo)                   // update student by roll num
{
	char temp_str[30];
	int x,y,i,j,temp_option, temp_roll;
	st *current_stuednt =fifo->base;
	if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
	{
		DPRINTF("database not exist  \n");
		return fifo_null;
	}
	if(fifo->counter==0)         // check if is empty
	{
		DPRINTF("[ERROR] database is empty \n");
		DPRINTF("--------------------------------------------\n");
		return fifo_empty;
	}
	DPRINTF("Enter student roll number  \n");
	gets(temp_str);
	temp_roll=atoi(temp_str);

	for(x=0;x< fifo->counter;x++)   // loop to get the roll number
	{   if(current_stuednt->roll==temp_roll)
	{
		DPRINTF("--------------------------------------------\n");
		DPRINTF("Student Roll number : %d\n",current_stuednt->roll);
		DPRINTF("Student first name : %s\n",current_stuednt->fname);
		DPRINTF("Student last name : %s\n",current_stuednt->lname);
		DPRINTF("Student GPA : %.2f\n",current_stuednt->GPA);
		for(y=0;y<5;y++)
		{
			DPRINTF("course %d id : %d \n",y+1,current_stuednt->cid[y]);
		}
		DPRINTF("--------------------------------------------\n");
		DPRINTF("Enter option to update data\n");
		DPRINTF("1- first name\n");
		DPRINTF("2- last name \n");
		DPRINTF("3- GPA\n");
		DPRINTF("4- courses \n");
		DPRINTF("--------------------------------------------\n");
		gets(temp_str);
		temp_option=atoi(temp_str);
		switch(temp_option)
		{
		case 1 :
		{
			DPRINTF("Enter New first name\n");
			gets(current_stuednt->fname);
			break;
		}
		case 2 :
		{
			DPRINTF("Enter New second name\n");
			gets(current_stuednt->lname);
			break;

		}
		case 3 :
		{
			DPRINTF("Enter New GPA \n");
			gets(temp_str);
			current_stuednt->GPA=atof(temp_str);
			break;

		}
		case 4 :
		{
			DPRINTF("Enter the course id of each course\n");
			for(i=0;i<5;i++)
			{
				DPRINTF("course %d id :\n",i+1);
				gets(temp_str);
				j=atoi(temp_str);
				if(j>0 && j<30)              // check if course id is available id
				{
					current_stuednt->cid[i]=j;
					continue;
				}
				DPRINTF("[ERROR] course id is not correct\n");
				i--;
			}
			break;

		}
		default :
		{
			DPRINTF("[ERROR] wrong choice \n");
			return fifo_error;
		}
		}
		// print student information after update
		DPRINTF("--------------------------------------------\n");
		DPRINTF("information updated successfully \n");
		DPRINTF("Student information after update \n");
		DPRINTF("--------------------------------------------\n");
		DPRINTF("Student Roll number : %d\n",current_stuednt->roll);
		DPRINTF("Student first name : %s\n",current_stuednt->fname);
		DPRINTF("Student last name : %s\n",current_stuednt->lname);
		DPRINTF("Student GPA : %.2f\n",current_stuednt->GPA);
		for(y=0;y<5;y++)
		{
			DPRINTF("course %d id : %d \n",y+1,current_stuednt->cid[y]);
		}
		return fifo_no_error;
	}
	current_stuednt++;
	}
	DPRINTF("--------------------------------------------\n");
	DPRINTF("[ERROR] Roll number is not found\n");                 // loop finished and roll not found
	DPRINTF("--------------------------------------------\n");
	return fifo_error;
}
fifo_buffer_state add_student_file(x*fifo)                   // add students info using text file
{
	char f_name[50];
	char l_name[50];
	int roll_num,cid[5],x,file_count=0,flag=0;
	float GPA;
	int line =0;
	if(!fifo->base || !fifo->head || !fifo->tail )  // check queue is exist or not
	{
		DPRINTF("database not exist  \n");
		return fifo_null;
	}
	if(fifo->counter==fifo->length)   // check if full
	{
		DPRINTF("[ERROR] data base is full\n");
		return fifo_full;
	}
	FILE *p_file = fopen("text.txt","r");
	if(p_file==NULL)
	{
		DPRINTF("------------------------------ \n");
		DPRINTF("[ERROR] File not found \n");
		return fifo_error;
	}


	// reading from file

	while( fscanf(p_file,"%d %s %s %f %d %d %d %d %d [^\n]", &roll_num, f_name,l_name,&GPA,&cid[0],&cid[1],&cid[2],&cid[3],&cid[4])!=EOF)
	{
		if(fifo->counter==fifo->length)
		{   DPRINTF("----------------------------\n");
		DPRINTF("[ERROR] data base is full\n");
		DPRINTF("[INFO] students added : %d\n",file_count);
		DPRINTF("[INFO] remaining students due to size or errors are :%d\n",line-file_count);

		return fifo_full;
		}
		if(check_roll(fifo,roll_num)==0)
		{
			DPRINTF("[ERROR] IN line %d : Roll Number is already taken before \n",line);
			line++;
			continue; // to skip this student
		}
		fifo->head->roll=roll_num;
		fifo->head->GPA=GPA;
		strcpy(fifo->head->fname,f_name);
		strcpy(fifo->head->lname,l_name);
		for(x=0;x<5;x++)
		{
			flag=0;
			if(cid[x]<0 || cid[x]>30)
			{
				flag=1;    // that there is non-valid course id
				break;
			}
			fifo->head->cid[x]=cid[x];
		}
		if(flag==1)  // non valid course id
		{
			DPRINTF("[ERROR] IN line %d : non valid course id we will skip this student \n",line);
			line++;
			continue; // to skip this student
		}
		fifo->head++;
		fifo->counter++;
		line++;
		file_count++;    // to record successful records

	}
	DPRINTF("\nEnd of file.\n");

	// close connection
	fclose(p_file);
	DPRINTF("[INFO] students added : %d\n",file_count);
	DPRINTF("[INFO] remaining students due to errors are :%d\n",line-file_count);
	return fifo_error;
}
