#include<stdio.h>
#include<stdlib.h>

// 引入随机函数
#include<time.h>


#define MAXSIZE 10

void Quick_Sort(int array[], int arrayLen);

void Quick_Sort1(int array[], int low, int height);

void quick_sort2(int arr[], const int len);

void Sort(int array[], int low, int height);

int partition(int array[], int right, int left);

void Print_Array(int array[], int arrayLen);

void swap(int *x, int *y);

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
	Quick_Sort(array,MAXSIZE);

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


void Quick_Sort(int array[], int arrayLen)
{
	//Sort(array, 0, arrayLen-1);
	quick_sort2(array, arrayLen);
}


void Sort(int array[],  int low, int height)
{
	if (low < height)
	{
		int retPivotkey = partition(array, low, height);
		Sort(array, low, retPivotkey - 1);
		Sort(array, retPivotkey + 1, height);
	}
}


int partition(int array[], int right, int left)
{
	// 将所有的比关键字小的元素，移动到关键字的左边，比关键字大的元素移动到关键字的右边
	int pivotkey = array[right];
	while (right < left)
	{
		while ( right < left && array[left] >= pivotkey)
			-- left;
		if ( right < left)
		{
			array[right++] = array[left];
		}

		while (right < left && array[right] < pivotkey)
			++ right;
		if (right < left)
		{
			array[left--]=array[right] ;
		}
	}
	// 将关键字插入想关的位置
	array[right] = pivotkey;
	// 返回关键字的位置，便于下次循环
	return right;
}


void Quick_Sort1(int array[], int low, int height)
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

		Quick_Sort1(array, low, right - 1);
		Quick_Sort1(array, right + 1, height);
	}
}

// 迭代法
typedef struct _Range {
	int start, end;
} Range;

Range new_Range(int s, int e) {
	Range r;
	r.start = s;
	r.end = e;
	return r;
}

void swap(int *x, int *y) {
	int t = *x;
	*x = *y;
	*y = t;
}
// 这种办法来自维基百科 https://zh.wikipedia.org/wiki/%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F#C.E8.AA.9E.E8.A8.80
void quick_sort2(int arr[], const int len) {
	if (len <= 0)
		return; // 避免len为负值时出错
	// r[]模拟栈 ,p为栈中元素的数量, r[p++] 为push, r[--p] 为pop且 取得元素
	Range *r= (Range *)malloc(sizeof(Range)*len);// 因为vs 不支持c99 所以，只能动态开辟了，支持c99的可以使用 Range r[len];
	if (r == NULL)
		return;
	int p = 0;
	// 模拟栈的入栈
	r[p++] = new_Range(0, len - 1);
	while (p) 
	{
		// 模拟栈的出栈
		Range range = r[--p];

		// ????
		if (range.start >= range.end)
			continue;

		int mid = arr[range.end];

		int left = range.start, right = range.end - 1;

		while (left < right) 
		{
			// 找到第一个不小于mid的元素
			while (arr[left] < mid && left < right)
				left++;
			// 找到第一个不大于mid的元素
			while (arr[right] >= mid && left < right)
				right--;

			swap(&arr[left], &arr[right]);
		}

		// 避免数组元素越界
		if (arr[left] >= arr[range.end])
		{
			swap(&arr[left], &arr[range.end]);
		}

		else
		{ 
			// 如果left 指针没有越界
			left++;
		}
		// 将左右两个部分的范围入栈
		r[p++] = new_Range(range.start, left - 1);
		r[p++] = new_Range(left + 1, range.end);
	}

	free(r);
}