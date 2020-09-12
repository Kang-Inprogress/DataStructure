#include <stdio.h>

int gcd(int n, int m)
{
   if (n > m) // n=작은수, m=큰수
   {
      int tmp = n;
      n = m;
      m = tmp;
   }
   if (m%n==0) return n;
   else {
      gcd(m, m%n);
   }
}

void main()
{
   printf("최대 공약수를 알고 싶은 수 둘을 넣어라(공백으로 구분): ");
   int m, n;
   scanf("%d %d", m, n);
   int GCD = gcd(n, m);
   printf("최대 공약수: %d", GCD);
}