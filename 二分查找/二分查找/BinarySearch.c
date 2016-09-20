#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAXSIZE 10

int binary_search(int array[], int low, int height, int searchKey);

void test();

void Quick_Sort(int array[], int low, int height);


int main()
{
	test();

	system("pause");
	return 0;


}

#if 0
int binary_search(int array[], int low, int height, int searchKey)
{
	if (height < low)
		return -1;

	// 为了避免溢出
	int mid = low + (height - low) / 2;

	if (searchKey < array[mid])
		return binary_search(array, low, mid - 1, searchKey);
	if (searchKey > array[mid])
		return binary_search(array, mid + 1, height, searchKey);

	return low;
}

#else
int binary_search(int array[], int low, int height, int searchKey)
{
	while (low <= height)
	{
		int mid = low + (height - low) / 2;

		if (searchKey > array[mid])
		{
			low = mid + 1;
		}
		else if(searchKey < array[mid])
		{
			height = mid - 1;
		}
		else
		{
			return low;
		}

	}
	return -1;
}
#endif

void test()
{

	srand((unsigned int)time(NULL) + 1);

	int array[MAXSIZE];
	for (int i = 0; i < MAXSIZE; ++i)
	{
		array[i] = rand();
		printf("%d ", array[i]);
	}

	printf("\n");

	Quick_Sort(array, 0, MAXSIZE - 1);
	int searchKey = 0;
	scanf("%d", &searchKey);
	int ret = binary_search2(array, 0, MAXSIZE - 1, searchKey);
	printf("%d\n", ret);
}


void Quick_Sort(int array[], int low, int height)
{
	// 将low 和 height  缓存 为后面的递归的实现提供界限
	int right = low, left = height;

	if (low < height)
	{
		int pivotkey = array[right];
		while (right < left)
		{
			while (right < left && array[left] >= pivotkey)
				--left;
			if (right < left)
			{
				array[right++] = array[left];
			}

			while (right < left && array[right] < pivotkey)
				++right;
			if (right < left)
			{
				array[left--] = array[right];
			}
		}
		// 将关键字插入想关的位置
		array[right] = pivotkey;

		Quick_Sort(array, low, right - 1);
		Quick_Sort(array, right + 1, height);
	}
}
