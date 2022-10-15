/*
 ============================================================================
 Name        : EX4_C_Program_to_Insert_an_Element_in_an_Array.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX4_C_Program_to_Insert_an_Element_in_an_Array, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[100], i, n, l, ele;
	printf("Enter number of elements \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	for (i=0; i<n; i++)
	{
		fflush(stdin); fflush(stdout);
		scanf("%d",&a[i]);
	}
	printf("Enter the element to be inserted \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&ele);
	printf("Enter the location \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&l);
	for (i=n; i>=l; i--)
		{
			a[i] = a[i-1];
		}
	n++;
	a[l - l] = ele;
	for (i=0; i<n; i++)
			{
		       printf("n %d",a[i]);
			}
	return 0;
}
