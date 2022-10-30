/*
 ============================================================================
 Name        : EX3_C_Program_to_Add_Two_Complex_Numbers_by_Passing_Structure_to_a_Function.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX3_C_Program_to_Add_Two_Complex_Numbers_by_Passing_Structure_to_a_Function, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct S_ComplexNumber
{
	float R;
	float I;
};

struct S_ComplexNumber ReadComplexNumber();
struct S_ComplexNumber AddTwoComplexNumbers(struct S_ComplexNumber FirstNumber, struct S_ComplexNumber SecoundNumber);
void PrintComplexNumber(struct S_ComplexNumber Result);

int main()
{
	struct S_ComplexNumber FirstComlpexNumber, SecoundComplexNumber, Result;
	printf("For 1st complex number");
		FirstComlpexNumber = ReadComplexNumber();

		printf("For 2st complex number");
		SecoundComplexNumber = ReadComplexNumber();

		Result = AddTwoComplexNumbers(FirstComlpexNumber, SecoundComplexNumber);

		PrintComplexNumber(Result);

		return 0;
}

struct S_ComplexNumber ReadComplexNumber()
{
	struct S_ComplexNumber Complex;

	printf("\nEnter real and imaginary respectively:");
	fflush(stdin); fflush(stdout);
	scanf("%f %f", &Complex.R, &Complex.I);

	return Complex;
}

struct S_ComplexNumber AddTwoComplexNumbers(struct S_ComplexNumber FirstNumber, struct S_ComplexNumber SecoundNumber)
{
	struct S_ComplexNumber Result;

	Result.R = FirstNumber.R + SecoundNumber.R;
	Result.I = FirstNumber.I + SecoundNumber.I;

	return Result;
}

void PrintComplexNumber(struct S_ComplexNumber Result)
{
	printf("Sum = %0.1f +%0.1fi ", Result.R, Result.I);
}
