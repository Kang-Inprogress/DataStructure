#include <stdio.h>

void printBinary(int n)
{
   if (n<2) printf("%d", n);
   else  {
      printBinary(n/2);
      printf("%d", n%2);
   }
}

void main()
{
   printf("2진수로 변환할 수: ");
   int num;
   scanf("%d", &num);
   printBinary(num);
}