#include <stdio.h>

int fib(int n)
{
   if(n==1) return 0;
   else if (n==2) return 1;
   else return fib(n-1) + fib (n-2);
}

void main()
{
   int fibo;
   printf("알고싶은 피보나치 수열: ");
   scanf("%d", &fibo);
   printf("피보나치 수열: %d\n", fib(fibo));
}