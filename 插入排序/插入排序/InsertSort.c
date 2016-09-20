#include<stdio.h>
#include<stdlib.h>

// �����������
#include<time.h>
#include"binarySearch.h"

#define MAXSIZE 10

void Insert_Sort(int array[], int arrayLen);

void Insert_Sort_Improve1(int array[], int arrayLen);

void Insert_Sort_Improve2(int array[], int arrayLen);

void Insert_binary_Sort(int array[], int arrayLen);


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
	Insert_binary_Sort(array, MAXSIZE);

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

void Insert_Sort(int array[], int arrayLen)
{
	// �ɴ�С
	// ����һ��Ԫ�أ�0����Ϊ����ģ���ڶ���Ԫ�أ�1����ʼ
	for (int i = 1; i < arrayLen; ++i)
	{
		// �ӿ�ʼ�Ƚ�
		for (int j = 0; j < i; ++j)
		{
			// �ҵ���һ ������ ��ǰ���ݵ�ֵ
			if (array[j] < array[i])
			{
				int tempInsertNum = array[i];
				int k = i;
				
				// �����е�Ԫ������ƶ�һ��
				while( k >= 0 && k > j)
				{
					array[k] = array[k - 1];
					--k;
				}
				// ��Ԫ�ز���������
				array[k] = tempInsertNum;
				// �Ѿ��ɹ����� ��ִ����һ����ѭ��
				break;
			}
		}
	}
}



void Insert_Sort_Improve1(int array[], int arrayLen)
{
	// �ɴ�С
	// ����һ��Ԫ�أ�0����Ϊ����ģ���ڶ���Ԫ�أ�1����ʼ
	for (int i = 1; i < arrayLen; ++i)
	{
		// �����array[i]<= array[i-1] ��ǰ���������array[i] ����ǰ����
		if (array[i] > array[i - 1])
		{
			int tempInsertNum = array[i];
			int j = i - 1;
			while (j >= 0 && array[j] < tempInsertNum)
			{
				// һ�߱Ƚϣ�һ���ƶ�
				array[j + 1] = array[j];
				-- j;
			}

			// ��ִ����һ�� -- j
			array[j + 1] = tempInsertNum;
		}
	}
}

void Insert_Sort_Improve2(int array[], int arrayLen)
{
	for (int i = 1; i < arrayLen; ++i)
	{
		// �����array[j] >= array[j+1] ��ǰ���������array[j+1] ����ǰ����
		for (int j = i - 1; j >= 0 && array[j + 1] > array[j]; --j)
		{
			Swap_IntVal(array + j + 1, array + j);
		}
	}
}


void Insert_binary_Sort(int array[], int arrayLen)
{
	int InsertPos = 0;
	int i = 1;
	while (i < arrayLen)
	{
		int InsertNum = array[i];
		InsertPos = binary_search(array, 0, i - 1, array[i]);

		for (int j = i - 1; j >= InsertPos; --j)
		{
			array[j + 1] = array[j];
		}
		array[InsertPos] = InsertNum;

		++i;
	}
}