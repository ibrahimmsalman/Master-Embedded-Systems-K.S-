/*
 ============================================================================
 Name        : C_Function_to_take_an_Array_and_revers_its_elements.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : C_Function_to_take_an_Array_and_revers_its_elements, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[10];
    int size, i;

    printf("Enter size of the array: ");
    fflush(stdout); fflush(stdin);
    scanf("%d", &size);

    printf("Enter elements in array: ");
    fflush(stdout); fflush(stdin);
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nArray in reverse order: ");
    for(i = size-1; i>=0; i--)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
