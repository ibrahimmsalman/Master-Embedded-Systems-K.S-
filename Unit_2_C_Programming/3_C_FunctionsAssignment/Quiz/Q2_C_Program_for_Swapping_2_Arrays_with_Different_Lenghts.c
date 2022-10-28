/*
 ============================================================================
 Name        : Q2_C_Program_for_Swapping_2_Arrays_with_Different_Lenghts.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : Q2_C_Program_for_Swapping_2_Arrays_with_Different_Lenghts, Ansi-style
 ============================================================================
 */

#include <stdio.h>

#define MAX_SIZE 100

void inputArray(int arr[], int size);
void printArray(int arr[], int size);
void swapArray(int firstArr[], int secondArr[]);

int main()
{
	int firstArr[MAX_SIZE];
	int secoundArr[MAX_SIZE];
	int sizeOfFirstArray, sizeOfSecondArray;

	printf("Enter size of First array (max 100) : ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&sizeOfFirstArray);

	printf("Enter size of Second array (max 100) : ");
	fflush(stdout); fflush(stdin);
	scanf("%d",&sizeOfSecondArray);

	printf("Enter %d elements in first array: ",sizeOfFirstArray);
	fflush(stdout); fflush(stdin);
	inputArray(firstArr, sizeOfFirstArray);

	printf("Enter %d elements in second array: ",sizeOfSecondArray);
	fflush(stdout); fflush(stdin);
	inputArray(secoundArr, sizeOfSecondArray);

	printf("\nFirst array before swapping: ");
	fflush(stdout);
	printArray(firstArr, sizeOfFirstArray);

	printf("\nSecond array before swapping: ");
	fflush(stdout);
	printArray(secoundArr, sizeOfSecondArray);

	swapArray(firstArr, secoundArr);

	printf("\n\nFirst array after swapping: ");
	fflush(stdout);
	printArray(firstArr, sizeOfFirstArray);

	printf("\nSecond array after swapping: ");
	fflush(stdout);
	printArray(secoundArr, sizeOfSecondArray);


	return 0;
}

void inputArray(int arr[], int size)
{
	int i;

	for (i = 0; i < size; ++i)
	{
		scanf("%d", &arr[i]);
	}
}

void printArray(int arr[], int size)
{
	int i;

	for (i = 0; i < size; ++i)
	{
		printf("%d ", arr[i]);
	}
}

void swapArray(int firstArr[], int secondArr[])
{
	int i;
	int tempArr[MAX_SIZE];
	for (i = 0; i < MAX_SIZE; ++i)
	{

		tempArr[i] = firstArr[i];
		firstArr[i] = secondArr[i];
		secondArr[i] = tempArr[i];

	}
}
