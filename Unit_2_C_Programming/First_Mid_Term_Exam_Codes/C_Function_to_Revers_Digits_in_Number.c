/*
 ============================================================================
 Name        : C_Function_to_Revers_Digits_in_Number.c
 Author      : Ibrahim Salman
 Version     :
 Copyright   : 
 Description : C_Function_to_Revers_Digits_in_Number, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n, r = 0;

  printf("Enter a number to reverse\n");
  fflush(stdout); fflush(stdin);
  scanf("%d", &n);

  while (n != 0)
  {
    r = r * 10;
    r = r + n%10;
    n = n/10;
  }

  printf("Reverse of the number = %d\n", r);

  return 0;
}
