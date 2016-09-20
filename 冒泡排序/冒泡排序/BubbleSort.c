#include<stdio.h>
#include<stdlib.h>

// �����������
#include<time.h>


#define MAXSIZE 10

void Bubble_Sort(int array[], int arrayLen);

void Bubble_Sort_Improve1(int array[], int arrayLen);

void Bubble_Sort_Improve2(int array[], int arrayLen);

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

	// ����ð������
	Bubble_Sort_Improve2(array, MAXSIZE);

	// ��ӡ����õ�����
	Print_Array(array, MAXSIZE);

}


void Bubble_Sort(int array[], int arrayLen)
{

	for (int i = 0; i < arrayLen; ++i)
	{
		// ��ѭ��ÿִ��һȦ����������Ĳ��־ͻ�����һ�� ������ѭ���Ĵ���Ϊ arrayLen-1-i
		for (int j = 0; j < arrayLen - 1 - i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}
void Bubble_Sort_Improve1(int array[], int arrayLen)
{
	// ����һ������ָʾ��ǰ�������Ƿ�����
	int disorderly = 1;

	while (disorderly)
	{
		// �ȼ��������Ѿ��������ִ����if(){} �����֤����ǰ������ģ��ٸ��ı�־
		disorderly = 0;
		for (int i = 0; i < arrayLen-1; ++i)
		{
			if (array[i] > array[i + 1])
			{
				disorderly = 1;

				int temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
			}
		}
	}
}

void Bubble_Sort_Improve2(int array[], int arrayLen)
{
	// ����һ������ָʾ��ǰ�����������λ��
	int disorderly = arrayLen-1;

	while (disorderly)
	{
		// ����һ����ʱ��������¼��ǰ������λ��
		int tempDisorderly = 0;
		for (int i = 0; i < disorderly; ++i)
		{
			if (array[i] >array[i + 1])
			{
				tempDisorderly = i;

				Swap_IntVal(array + i, array + i + 1);
			}
		}
		// �����������λ�ø�ֵ������λ�õļ�¼
		disorderly = tempDisorderly;
	}
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




