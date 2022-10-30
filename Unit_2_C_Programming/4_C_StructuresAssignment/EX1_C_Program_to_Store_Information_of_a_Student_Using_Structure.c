/*
 ============================================================================
 Name        : EX1_C_Program_to_Store_Information_of_a_Student_Using_Structure.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX1_C_Program_to_Store_Information_of_a_Student_Using_Structure, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct S_StudentInformation
{
	char name[100];
	int roll_number;
	float marks;
};

struct S_StudentInformation ReadStudentInformation();
void printStudentInfo (struct S_StudentInformation StudentInfo);

int main()
{
	struct S_StudentInformation StudentInfo;
		StudentInfo = ReadStudentInformation() ;
		printStudentInfo(StudentInfo);

		return 0;

}

struct S_StudentInformation ReadStudentInformation()
{
	struct S_StudentInformation StudentInfo;
	printf ("Enter the student information: \n");
		printf ("Enter the student name: ");
		fflush (stdin); fflush(stdout);
		scanf ("%s", &StudentInfo.name );

		printf ("\nEnter the student's roll number: ");
		fflush (stdin); fflush(stdout);
		scanf ("%d", &StudentInfo.roll_number );

		printf ("\nEnter the students marks: ");
		fflush (stdin); fflush(stdout);
		scanf ("%f", &StudentInfo.marks);

		return StudentInfo ;

}

void printStudentInfo (struct S_StudentInformation StudentInfo)
{

	printf ("\nDisplaying the student's Information: \n");

	printf ("Student name: %s", StudentInfo.name);

	printf ("\nStudent's roll number: %d", StudentInfo.roll_number);

	printf ("\nStudent's marks: %.2f", StudentInfo.marks);

}
