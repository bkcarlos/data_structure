#include<stdio.h>
#include<stdlib.h>

// 引入随机函数
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
	// srand() 百度百科 http://baike.baidu.com/view/1458234.htm
	srand((unsigned int)time(NULL));

	int array[MAXSIZE] = { 0 };
	for (int i = 0; i < MAXSIZE; ++i)
	{
		array[i] = rand();
	}
	// 打印当前的数组
	Print_Array(array, MAXSIZE);

	// 调用冒泡排序
	Bubble_Sort_Improve2(array, MAXSIZE);

	// 打印排序好的数组
	Print_Array(array, MAXSIZE);

}


void Bubble_Sort(int array[], int arrayLen)
{

	for (int i = 0; i < arrayLen; ++i)
	{
		// 内循环每执行一圈，后面有序的部分就会增加一个 所以内循环的次数为 arrayLen-1-i
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
	// 定义一个变量指示当前的数组是否有序
	int disorderly = 1;

	while (disorderly)
	{
		// 先假设数组已经有序，如果执行了if(){} 语句则证明当前是无序的，再更改标志
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
	// 定义一个变量指示当前的数组无序的位置
	int disorderly = arrayLen-1;

	while (disorderly)
	{
		// 利用一个零时变量来记录当前的无序位置
		int tempDisorderly = 0;
		for (int i = 0; i < disorderly; ++i)
		{
			if (array[i] >array[i + 1])
			{
				tempDisorderly = i;

				Swap_IntVal(array + i, array + i + 1);
			}
		}
		// 将最后的无序的位置赋值给无序位置的记录
		disorderly = tempDisorderly;
	}
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




