#include <stdio.h>


// ���� ����
int pos = 0; // �迭�� ������ġ�� ����Ŵ. �迭�� pos-1 �� ���� ���� ��������
int arrlength = 10;

void append(int *arr, int item)
{
   if (pos == arrlength) {printf("���� á���Ƿ� ������� �ʾҽ��ϴ�.\n"); return;} // "pos == sizeof(arr)/sizeof(int)" �� pos == 10 �� ����. �� á�ٴ� ��
   arr[pos] = item;
   pos += 1;
   printf("�� %d��(��) �߰��Ǿ����ϴ�.\n", item);
}

void replace(int *arr, int item, int l_pos)
{
   if(pos == 0) {printf("����Ʈ�� �����Ͱ� �������� �ʽ��ϴ�.\n"); return;}
   arr[l_pos] = item;
   printf("�� %d�� %d��° �����Ϳ� ����������ϴ�.\n", item, l_pos+1);
}

void clear(int *arr, int l_pos) // l_pos ���� �������� pos�� ���� ���Դ�.
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
   if (pos == 0) {printf("��� �����Ƿ� ������� �ʾҽ��ϴ�.\n");return;}
   for(int i=l_pos; i < pos; i++)
   {
      arr[i] = arr[i+1];
   }
   pos--;
}

void addFirst(int *arr, int item)
{
   if (pos == arrlength) {printf("������ ������ ������� �ʽ��ϴ�.\n"); return;} // ������ ���ҵ��� �̵��� �ڸ��� ��� fail
   else {
      arr[pos] = 1; // ���� �Ǿ��ٰ� ģ��
      pos++;
      for(int i = pos; i > 0; i--)
      {
         arr[i] = arr[i-1];
      }
      arr[0] = item;
      printf("������ %d��(��) �� ó������ ���ԵǾ����ϴ�. ������ �����͵��� �� ĭ�� �Ű������ϴ�.\n", item);
   }
}

int getEntry(int *arr) // pos��ġ�� ���� ��ȯ
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
   printf("##### ����Ʈ ���� ������ #####\n");
   for(int i=0; i<pos; i++)
   {
      printf("[%d/10]��° ������: %d\n", i+1, arr[i]);
   }
}

void initList(int *arr) // �迭�� �缳���� �����ϰ� �Ұ���
{
   for (int i = pos; i >= 0; i--) // Ż���
   {
      arr[i] = -1;
   }
   pos = 0;
   printf("�迭 �ʱ�ȭ �Ϸ�\n");
}

void main()
{
   // linear list ���� ����Ʈ
   
   int arr[arrlength]; // �� ��Ұ����� sizeof(arr)/sizeof(int)�� ���Ѵ�
   printf("����Ʈ���� ���� �ִ� ��� ���� %d, ũ�Ⱑ %dByte �� �迭 ���� �Ϸ�.\n", sizeof(arr)/sizeof(int), sizeof(arr));
   while (1)
   {
      printf("1:add, 2: replace, 3: clear, 4: delete, 5: addFirst, 6: getEntry, 7: getLength, 8: isEmpty, 9: isFull, 10: display, 11: initList(����! �ʱ�ȭ)\n���񽺸� �����Ͻʽÿ�:");
      int ServiceNum, input_value, l_pos, booleanflag;
      scanf("%d",&ServiceNum);
      switch (ServiceNum)
      {
      case 1:
         printf("���� ����Ʈ�� �߰��� ����: ");
         scanf("%d", &input_value);
         append(arr, input_value);
         break;
      case 2:
         printf("���� ����Ʈ�� ��ü�� ����: ");
         scanf("%d", &input_value);
         printf("�߰��� ��ġ: ");
         scanf("%d", &l_pos);
         replace(arr, input_value, l_pos-1);
         break;
      case 3:
         clear(arr, pos);
         printf("������ ���� �Ϸ�\n");
         break;
      case 4:
         printf("���� �������� ����: ");
         scanf("%d", &l_pos);
         delete(arr, l_pos-1);
         break;
      case 5:
         printf("�迭�� �� ó���� ������ ������:");
         scanf("%d", &input_value);
         addFirst(arr, input_value);
         break;
      case 6:
         input_value = getEntry(arr);
         printf("pos��ġ�� ������: %d\n", input_value);
         break;
      case 7: // getLength
         printf("���� �������� ���� [%d/%d]\n", pos, arrlength);
         break;
      case 8:
         booleanflag = isEmpty();
         if (booleanflag == 1) printf("����ֽ��ϴ�.\n");
         else printf("�����Ͱ� �����մϴ�.\n");
         break;
      case 9:
         booleanflag = isFull(arr);
         if (booleanflag == 1) printf("�����Ͱ� ����á���ϴ�.\n");
         else printf("���������� �ֽ��ϴ�.\n");
         break;
      case 10:
         display(arr);
         break;
      case 11: // initList
         initList(arr);
         break;
      default:
         printf("���ϴ� ���񽺿� �˸��� ���ڸ� �Է��ϼ���.\n");
         break;
      }
   }
}