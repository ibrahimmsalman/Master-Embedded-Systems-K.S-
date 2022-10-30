/*
 ============================================================================
 Name        : EX4_C_Program_to_Store_Information_of_Students_Using_Structure.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX4_C_Program_to_Store_Information_of_Students_Using_Structure, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct S_StudentInformation
{
	char name [50] ;
	int rollNumber ;
	float marks ;
};

struct S_StudentInformation ReadStudentInformation();
void printStudentInfo (struct S_StudentInformation StudentInfo);

int main ()
{
	struct S_StudentInformation StudentInfo ;
	struct S_StudentInformation StudentsData [10];
	int NumOfStudents = 10, i ;

	printf ("Enter the information of 10 Students:\n");
	for(i=0; i<NumOfStudents; ++i)
	{
		printf ("Enter the information of %d Student:\n",i+1);
		StudentInfo = ReadStudentInformation() ;
				StudentsData [i] = StudentInfo ;
			}

			printf ("\nDisplaying the information of the students:\n");

			for ( i=0; i<NumOfStudents; ++i)
			{
				printStudentInfo (StudentsData [i]);
			}

			return 0;
}

struct S_StudentInformation ReadStudentInformation( )
{
	struct S_StudentInformation StudentInfo;

	printf ("\nEnter the student name: ");
	fflush (stdin); fflush(stdout);
	scanf ("%s", StudentInfo.name );

	printf ("\nEnter the student's roll number: ");
	fflush (stdin); fflush(stdout);
	scanf ("%d", &StudentInfo.rollNumber );

	printf ("\nEnter the students marks: ");
	fflush (stdin); fflush(stdout);
	scanf ("%f", &StudentInfo.marks);

	return StudentInfo ;
}

void printStudentInfo (struct S_StudentInformation StudentInfo)
{
	printf ("\nStudent name: %s", StudentInfo.name );
	printf ("\nStudent's roll number: %d", StudentInfo.rollNumber);
	printf ("\nStudent's marks: %.2f", StudentInfo.marks);
}

