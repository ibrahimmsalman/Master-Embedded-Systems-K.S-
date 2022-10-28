/*
 ============================================================================
 Name        : C_Function_to_take_an_Integer_Number_and_Calculate_its_Square_Root.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : C_Function_to_take_an_Integer_Number_and_Calculate_its_Square_Root, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <math.h>

int main()
{
    double num, root;

    printf("Enter any number to find square root: ");
    fflush(stdout); fflush(stdin);
    scanf("%lf", &num);

    root = sqrt(num);

    printf("Square root of %.0lf = %.3lf", num, root);

    return 0;
}
