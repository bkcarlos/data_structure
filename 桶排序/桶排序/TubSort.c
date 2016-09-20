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

/* 函数的参数说明
 * int array[] 需要进行排序的原数组
 * int ArrayLen 待排序的数组的数据域的宽度
 */
void TubSort(int array[], int ArrayLen)
{
	// 开辟一个比数据界限（ArrayLen)大一个的数组来存储每个元素出现的次数
	++ArrayLen;

	int *arr = (int *)malloc(sizeof(int)*ArrayLen);
	if (arr == NULL)
		return;
	for (int i = 0; i < ArrayLen; ++i)
		arr[i] = 0;
	// 扫描数组中的每个数据，统计出现的次数
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