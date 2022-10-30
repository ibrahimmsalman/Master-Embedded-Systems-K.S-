/*
 ============================================================================
 Name        : EX2_C_Program_to_Add_Two_Distances_Systems_Using_Structure.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : EX2_C_Program_to_Add_Two_Distances_Systems_Using_Structure, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct distance
{
	int feet;
	float inch;
}d1,d2,sum;

int main()
{
	printf("Enter first distance \n");
	printf("Enter feet \n");
	fflush(stdin); fflush(stdout);
	scanf("%d",&d1.feet);

	printf("Enter inch \n");
	fflush(stdin); fflush(stdout);
	scanf("%f",&d1.inch);

	printf("Enter second distance \n");
		printf("Enter feet \n");
		fflush(stdin); fflush(stdout);
		scanf("%d",&d2.feet);

		printf("Enter inch \n");
		fflush(stdin); fflush(stdout);
		scanf("%f",&d2.inch);

		sum.feet = d1.feet + d2.feet;
        sum.inch = d1.inch + d2.inch;

        if(sum.inch>12)
        {
        	sum.inch = sum.inch-12;
        	++sum.feet;
        }
		printf("sum of distance is %d   %.1f", sum.feet, sum.inch);

		return 0;
}

