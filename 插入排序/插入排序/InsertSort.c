#include<stdio.h>
#include<stdlib.h>

// 引入随机函数
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
	// srand() 百度百科 http://baike.baidu.com/view/1458234.htm
	srand((unsigned int)time(NULL));

	int array[MAXSIZE] = { 0 };
	for (int i = 0; i < MAXSIZE; ++i)
	{
		array[i] = rand();
	}
	// 打印当前的数组
	Print_Array(array, MAXSIZE);

	// 调用选择排序
	Insert_binary_Sort(array, MAXSIZE);

	// 打印排序好的数组
	Print_Array(array, MAXSIZE);

}

void Print_Array(int array[], int arrayLen)
{
	printf("…………< 当前的数组元素 >…………………………\n");
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
	// 由大到小
	// 将第一个元素（0）视为有序的，则第二个元素（1）开始
	for (int i = 1; i < arrayLen; ++i)
	{
		// 从开始比较
		for (int j = 0; j < i; ++j)
		{
			// 找到第一 不大于 当前数据的值
			if (array[j] < array[i])
			{
				int tempInsertNum = array[i];
				int k = i;
				
				// 将所有的元素向后移动一个
				while( k >= 0 && k > j)
				{
					array[k] = array[k - 1];
					--k;
				}
				// 将元素插入数组中
				array[k] = tempInsertNum;
				// 已经成功插入 ，执行下一次外循环
				break;
			}
		}
	}
}



void Insert_Sort_Improve1(int array[], int arrayLen)
{
	// 由大到小
	// 将第一个元素（0）视为有序的，则第二个元素（1）开始
	for (int i = 1; i < arrayLen; ++i)
	{
		// 如果是array[i]<= array[i-1] 则前面的数都比array[i] 大，则当前有序
		if (array[i] > array[i - 1])
		{
			int tempInsertNum = array[i];
			int j = i - 1;
			while (j >= 0 && array[j] < tempInsertNum)
			{
				// 一边比较，一边移动
				array[j + 1] = array[j];
				-- j;
			}

			// 多执行了一次 -- j
			array[j + 1] = tempInsertNum;
		}
	}
}

void Insert_Sort_Improve2(int array[], int arrayLen)
{
	for (int i = 1; i < arrayLen; ++i)
	{
		// 如果是array[j] >= array[j+1] 则前面的数都比array[j+1] 大，则当前有序
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