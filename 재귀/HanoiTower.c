#include <stdio.h>

void hanoi(int n, char a, char b, char c)
{
   if (n==1) printf("���� %d�� %c���� %c���� �ű��.\n", n, a, c);
   else {
      hanoi(n-1, a, c, b); // n-1 �� ������ A->B �� �̵�
      printf("���� %d�� %c���� %c���� �ű��.\n", n, a, c); // n��°(�عٴ�) ������ A->C�� �̵�
      hanoi(n-1, b, a, c); // n-1 �� ������ B->C�� �̵�
   }
}

void main()
{
   hanoi(5, 'A', 'B', 'C');
}