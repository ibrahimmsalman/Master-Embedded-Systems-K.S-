/*
 ============================================================================
 Name        : C_Function_to_Print_All_Prime_Numbers_Between_Two_Numbers.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : C_Function_to_Print_All_Prime_Numbers_Between_Two_Numbers, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main ()
{
   int num1, num2, i, j, f;

   printf("Enter two numbers: ");
   fflush(stdout); fflush(stdin);
   scanf("%d %d", &num1, &num2);

   printf("Prime numbers between %d and %d are:\n", num1, num2);

   for (i = num1 + 1; i < num2; ++i)
   {
      f = 0;
      for (j = 2; j <= i/2; ++j)
      {
         if (i % j == 0)
         {
            f = 1;
            break;
         }
      }
      if (f == 0)
          printf("%d ", i);
   }
   return 0;
}
