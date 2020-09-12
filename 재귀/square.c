#include <stdio.h>

int sqaure(int x, int n); // 계수 x, 차수 n

void main()
{
   int Gyesu, Chasu;
   printf("Gyesu: ");
   scanf("%d", &Gyesu);
   printf("Chasu: ");
   scanf("%d", &Chasu);

   int sqaure_total = sqaure(Gyesu, Chasu);
   printf("SQAURE: %d\n", sqaure_total);
}

int sqaure(int x, int n)
{
   if(n == 0) return 1; // sqaure로 끝까지 나누면 n=1인 상태에서, (n-1)/2에서 0이 되어 1을 리턴한다.
   else if (n % 2 == 0) return sqaure(x*x, n/2);
   else return x * sqaure(x*x, (n-1)/2);
}