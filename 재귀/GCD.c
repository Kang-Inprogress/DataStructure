#include <stdio.h>

int gcd(int n, int m)
{
   if (n > m) // n=������, m=ū��
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
   printf("�ִ� ������� �˰� ���� �� ���� �־��(�������� ����): ");
   int m, n;
   scanf("%d %d", m, n);
   int GCD = gcd(n, m);
   printf("�ִ� �����: %d", GCD);
}