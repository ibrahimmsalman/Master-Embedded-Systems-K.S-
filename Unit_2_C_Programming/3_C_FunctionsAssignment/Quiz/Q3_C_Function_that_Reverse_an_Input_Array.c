/*
 ============================================================================
 Name        : Q3_C_Function_that_Reverse_an_Input_Array.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : Q3_C_Function_that_Reverse_an_Input_Array, Ansi-style
 ============================================================================
 */

#include <stdio.h>

void inputArray(int arr[], int size);
void printArray(int arr[], int size);
void reverseArray(int arr[], int size);

int main()
{
	int arr[100], size;

	printf ("Enter the size of array: ");
	fflush (stdout); fflush (stdin);
	scanf ("%d", &size);

	printf ("Enter %d element of array : ", size);
	fflush (stdout); fflush (stdin);
	inputArray(arr, size);

	printf ("\nThe array elements before reverse are: ");
	printArray (arr, size);

	reverseArray(arr, size);

	printf("\nThe array elements after reverse: ");
	printArray (arr, size);

	return 0;
}

void inputArray(int arr[], int size)
{
	int i;

	for (i = 0; i < size; ++i)
	{
		scanf("%d",&arr[i]);
	}
}

void printArray(int arr[], int size)
{
	int i;

	for (i = 0; i < size; ++i)
	{
		printf("%d ",arr[i]);
	}
}

void reverseArray(int arr[], int size)
{
	int i,j, temp;
	for (i = 0, j = size-1; i <= j; i++, j--)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}
