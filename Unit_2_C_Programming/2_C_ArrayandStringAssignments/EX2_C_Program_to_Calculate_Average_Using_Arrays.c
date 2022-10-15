/*
 ============================================================================
 Name        : EX2_C_Program_to_Calculate_Average_Using_Arrays.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i, n;
	float a [10], sum=0.0, avg;
	printf("Enter array elements \n");
	if (n>0 || n<=10)
	{
		for (i=0; i<10; ++i)
					{
						printf("Enter element number [%d] \n",i+1);
				        fflush(stdin); fflush(stdout);
				        scanf("%f",&a[i]);
				        sum+=a[i];
					}
			avg=sum/n;
			printf("Average= %f ",avg);
    }
	else
	{
       printf("Error number should be range of 1 to 10");
	}
	return 0;
}
