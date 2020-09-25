#include <stdio.h>
#define MAX_DEGREE 10
#define MAX(a,b) ((a>=b)? a : b)

typedef struct
{
   int degree; // 항의 갯수 정도
   float coef[MAX_DEGREE]; // 계수가 들어가 있다
} polynomial;

polynomial addpoly(polynomial A, polynomial B)
{
   polynomial C; // 결과값을 넣을 변수
   int A_index = 0, B_index = 0, C_index = 0;

   int A_degree = A.degree, B_degree = B.degree;
   C.degree = MAX(A_degree, B_degree);

   while (A_index <= A.degree && B_index <= B.degree) // 차수가 0가 될때까지 반복
   {
      if (A_degree > B_degree) // A의 차수가 더 클경우 A의 차수와 계수를 넣는다
      {
         C.coef[C_index++] = A.coef[A_index++];
         A_degree--;
      }
      else if (A_degree == B_degree)
      {
         C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
         A_degree--; B_degree--;
      }
      else
      {
         C.coef[C_index++] = B.coef[B_index++];
         B_degree--;
      }
   }
   return C;
}

void printPoly(polynomial P)
{
   int i, degree;
   degree = P.degree;
   
   for (i=0; i<P.degree; i++)
      printf("%3.0fx^%d", P.coef[i], degree--);
   printf("\n");
}

void main()
{
   polynomial A = {4, {8, 0, 7, 1}};
   polynomial B = {4, {10, 3, 0, 1}};


   polynomial C = addpoly(A, B);

   printf("\n A(x)="); printPoly(A);
   printf("\n B(x)="); printPoly(B);
   printf("\n C(x)="); printPoly(C);

   getchar();
}