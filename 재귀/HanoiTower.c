#include <stdio.h>

void hanoi(int n, char a, char b, char c)
{
   if (n==1) printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, a, c);
   else {
      hanoi(n-1, a, c, b); // n-1 개 원판을 A->B 로 이동
      printf("원판 %d을 %c에서 %c으로 옮긴다.\n", n, a, c); // n번째(밑바닥) 원판을 A->C로 이동
      hanoi(n-1, b, a, c); // n-1 개 원판을 B->C로 이동
   }
}

void main()
{
   hanoi(5, 'A', 'B', 'C');
}