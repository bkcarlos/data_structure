#include<stdio.h>
#include<stdlib.h>

#define MAXSIZE 100

void TubSort(int array[], int ArrayLen);
void test();


int main()
{
	test();
	
	system("pause");
	return 0;
}
void test()
{
	int array[MAXSIZE] = { 1,2,3,4,5,6,7,8,9,11,
		11,12,3,4,5,6,7,8,9,11 ,
		11,12,3,4,5,6,7,8,9,11,
		11,12,3,4,5,6,7,8,9,11,
		11,12,3,4,5,6,7,8,9,11,
		11,12,3,4,5,6,7,8,9,11,
		11,12,3,4,5,6,7,8,9,11,
		11,12,3,4,5,6,7,8,9,11 ,
		11,12,3,4,5,6,7,8,9,11,
		11,12,3,4,5,6,7,8,9,11,
	};

	TubSort(array, 12);
}

/* �����Ĳ���˵��
 * int array[] ��Ҫ���������ԭ����
 * int ArrayLen ������������������Ŀ��
 */
void TubSort(int array[], int ArrayLen)
{
	// ����һ�������ݽ��ޣ�ArrayLen)��һ�����������洢ÿ��Ԫ�س��ֵĴ���
	++ArrayLen;

	int *arr = (int *)malloc(sizeof(int)*ArrayLen);
	if (arr == NULL)
		return;
	for (int i = 0; i < ArrayLen; ++i)
		arr[i] = 0;
	// ɨ�������е�ÿ�����ݣ�ͳ�Ƴ��ֵĴ���
	for (int i = 0; i < MAXSIZE; ++i)
	{
		arr[array[i]]++;
	}
	for (int i = 0; i < ArrayLen; ++i)
	{
		for (int j = 0; j < arr[i]; ++j)
		{
			printf("%d ", i);
		}
		printf("\n");
	}
	free(arr);
}