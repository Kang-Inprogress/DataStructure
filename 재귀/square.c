#include <stdio.h>

int sqaure(int x, int n); // ��� x, ���� n

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
   if(n == 0) return 1; // sqaure�� ������ ������ n=1�� ���¿���, (n-1)/2���� 0�� �Ǿ� 1�� �����Ѵ�.
   else if (n % 2 == 0) return sqaure(x*x, n/2);
   else return x * sqaure(x*x, (n-1)/2);
}