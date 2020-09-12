#include <stdio.h>


// 전역 변수
int pos = 0; // 배열의 원소위치를 가르킴. 배열은 pos-1 이 가장 뒤의 데이터임
int arrlength = 10;

void append(int *arr, int item)
{
   if (pos == arrlength) {printf("가득 찼으므로 실행되지 않았습니다.\n"); return;} // "pos == sizeof(arr)/sizeof(int)" 는 pos == 10 과 같다. 다 찼다는 말
   arr[pos] = item;
   pos += 1;
   printf("값 %d이(가) 추가되었습니다.\n", item);
}

void replace(int *arr, int item, int l_pos)
{
   if(pos == 0) {printf("리스트에 데이터가 존재하지 않습니다.\n"); return;}
   arr[l_pos] = item;
   printf("값 %d가 %d번째 데이터에 덮어써졌습니다.\n", item, l_pos+1);
}

void clear(int *arr, int l_pos) // l_pos 에는 전역변수 pos의 값이 들어왔다.
{
   // int length = sizeof(arr)/sizeof(int);
   // for(int i=0; i < length; i++)
   // {
   //    arr[i] = 0;
   // }
   // pos = 0;
   if (l_pos == 0) arr[l_pos] = -1;
   else {
      clear(arr, l_pos-1);
      arr[l_pos] = -1;
   }
   pos = 0;
}

void delete(int *arr, int l_pos)
{
   if (pos == 0) {printf("비어 있으므로 실행되지 않았습니다.\n");return;}
   for(int i=l_pos; i < pos; i++)
   {
      arr[i] = arr[i+1];
   }
   pos--;
}

void addFirst(int *arr, int item)
{
   if (pos == arrlength) {printf("삽입할 공간이 충분하지 않습니다.\n"); return;} // 나머지 원소들을 이동할 자리가 없어서 fail
   else {
      arr[pos] = 1; // 생성 되었다고 친다
      pos++;
      for(int i = pos; i > 0; i--)
      {
         arr[i] = arr[i-1];
      }
      arr[0] = item;
      printf("데이터 %d이(가) 맨 처음으로 삽입되었습니다. 나머지 데이터들은 한 칸씩 옮겨졌습니다.\n", item);
   }
}

int getEntry(int *arr) // pos위치의 원소 반환
{
   return arr[pos-1];
}

int isEmpty()
{
   if (pos == 0) return 1;
   else return -1;
}

int isFull(int *arr)
{
   if (pos == sizeof(arr)/sizeof(int)) return 1;
   else return -1;
}

void display(int *arr)
{
   printf("##### 리스트 안의 데이터 #####\n");
   for(int i=0; i<pos; i++)
   {
      printf("[%d/10]번째 데이터: %d\n", i+1, arr[i]);
   }
}

void initList(int *arr) // 배열의 재설정이 가능하게 할것임
{
   for (int i = pos; i >= 0; i--) // 탈곡기
   {
      arr[i] = -1;
   }
   pos = 0;
   printf("배열 초기화 완료\n");
}

void main()
{
   // linear list 선형 리스트
   
   int arr[arrlength]; // 총 요소개수는 sizeof(arr)/sizeof(int)로 구한다
   printf("리스트안의 들어갈수 있는 요소 개수 %d, 크기가 %dByte 인 배열 생성 완료.\n", sizeof(arr)/sizeof(int), sizeof(arr));
   while (1)
   {
      printf("1:add, 2: replace, 3: clear, 4: delete, 5: addFirst, 6: getEntry, 7: getLength, 8: isEmpty, 9: isFull, 10: display, 11: initList(주의! 초기화)\n서비스를 선택하십시오:");
      int ServiceNum, input_value, l_pos, booleanflag;
      scanf("%d",&ServiceNum);
      switch (ServiceNum)
      {
      case 1:
         printf("현재 리스트에 추가할 정수: ");
         scanf("%d", &input_value);
         append(arr, input_value);
         break;
      case 2:
         printf("현재 리스트에 대체할 정수: ");
         scanf("%d", &input_value);
         printf("추가할 위치: ");
         scanf("%d", &l_pos);
         replace(arr, input_value, l_pos-1);
         break;
      case 3:
         clear(arr, pos);
         printf("데이터 비우기 완료\n");
         break;
      case 4:
         printf("지울 데이터의 순서: ");
         scanf("%d", &l_pos);
         delete(arr, l_pos-1);
         break;
      case 5:
         printf("배열의 맨 처음에 삽입할 데이터:");
         scanf("%d", &input_value);
         addFirst(arr, input_value);
         break;
      case 6:
         input_value = getEntry(arr);
         printf("pos위치의 데이터: %d\n", input_value);
         break;
      case 7: // getLength
         printf("현재 데이터의 길이 [%d/%d]\n", pos, arrlength);
         break;
      case 8:
         booleanflag = isEmpty();
         if (booleanflag == 1) printf("비어있습니다.\n");
         else printf("데이터가 존재합니다.\n");
         break;
      case 9:
         booleanflag = isFull(arr);
         if (booleanflag == 1) printf("데이터가 가득찼습니다.\n");
         else printf("여유공간이 있습니다.\n");
         break;
      case 10:
         display(arr);
         break;
      case 11: // initList
         initList(arr);
         break;
      default:
         printf("원하는 서비스에 알맞은 문자를 입력하세요.\n");
         break;
      }
   }
}