#include <stdio.h>

int Result(int n, int *input);

void main()
{
    printf("how many enter: ");
    int count;
    scanf("%d", &count);

    int input[count];
    for(int i=0; i<count; i++)
    {
      printf("Enter number:");
      scanf("%d", &input[i]);
    }
   int maxVal = Result(count-1, input);
   printf("Maximum Value: %d", maxVal);
}

int Result(int c, int *input) // 배열을 포인터로 가져옴
{
   if(c == 0) return input[0];
   else
   {
      int maxVal = Result(c-1, input);
      if(input[c] < maxVal) return maxVal;
      else return input[c];
   }
}
