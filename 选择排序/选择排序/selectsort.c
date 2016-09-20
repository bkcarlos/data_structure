#include<stdio.h>
#include<stdlib.h>

// �����������
#include<time.h>


#define MAXSIZE 10

void Select_Sort(int array[], int arrayLen);

void Print_Array(int array[], int arrayLen);

void Swap_IntVal(int *valA, int *valB);

void Test_Bubble_sort();



int main()
{
	Test_Bubble_sort();

	system("pause");
	return 0;
}

void Test_Bubble_sort()
{
	// srand() �ٶȰٿ� http://baike.baidu.com/view/1458234.htm
	srand((unsigned int)time(NULL));

	int array[MAXSIZE] = { 0 };
	for (int i = 0; i < MAXSIZE; ++i)
	{
		array[i] = rand();
	}
	// ��ӡ��ǰ������
	Print_Array(array, MAXSIZE);

	// ����ѡ������
	Select_Sort(array, MAXSIZE);

	// ��ӡ����õ�����
	Print_Array(array, MAXSIZE);

}

void Print_Array(int array[], int arrayLen)
{
	printf("��������< ��ǰ������Ԫ�� >��������������������\n");
	for (int i = 0; i < arrayLen; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void Swap_IntVal(int *valA, int *valB)
{
	int temp = *valA;
	*valA = *valB;
	*valB = temp;
}

void Select_Sort(int array[], int arrayLen)
{

	for (int i = 0; i < arrayLen; ++i)
	{
		int tempIndex = i;
		for (int j = i + 1; j < arrayLen; ++j)
		{
			// ��С����

			if (array[j] < array[tempIndex])
			{
				tempIndex = j;
			}
		}

		if (i != tempIndex)
		{
			Swap_IntVal(array + i, array + tempIndex);
		}
	}
}