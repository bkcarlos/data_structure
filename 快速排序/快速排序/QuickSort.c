#include<stdio.h>
#include<stdlib.h>

// �����������
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
	Quick_Sort(array,MAXSIZE);

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
	// �����еıȹؼ���С��Ԫ�أ��ƶ����ؼ��ֵ���ߣ��ȹؼ��ִ��Ԫ���ƶ����ؼ��ֵ��ұ�
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
	// ���ؼ��ֲ�����ص�λ��
	array[right] = pivotkey;
	// ���عؼ��ֵ�λ�ã������´�ѭ��
	return right;
}


void Quick_Sort1(int array[], int low, int height)
{
	// ��low �� height  ���� Ϊ����ĵݹ��ʵ���ṩ����
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
		// ���ؼ��ֲ�����ص�λ��
		array[right] = pivotkey;

		Quick_Sort1(array, low, right - 1);
		Quick_Sort1(array, right + 1, height);
	}
}

// ������
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
// ���ְ취����ά���ٿ� https://zh.wikipedia.org/wiki/%E5%BF%AB%E9%80%9F%E6%8E%92%E5%BA%8F#C.E8.AA.9E.E8.A8.80
void quick_sort2(int arr[], const int len) {
	if (len <= 0)
		return; // ����lenΪ��ֵʱ����
	// r[]ģ��ջ ,pΪջ��Ԫ�ص�����, r[p++] Ϊpush, r[--p] Ϊpop�� ȡ��Ԫ��
	Range *r= (Range *)malloc(sizeof(Range)*len);// ��Ϊvs ��֧��c99 ���ԣ�ֻ�ܶ�̬�����ˣ�֧��c99�Ŀ���ʹ�� Range r[len];
	if (r == NULL)
		return;
	int p = 0;
	// ģ��ջ����ջ
	r[p++] = new_Range(0, len - 1);
	while (p) 
	{
		// ģ��ջ�ĳ�ջ
		Range range = r[--p];

		// ????
		if (range.start >= range.end)
			continue;

		int mid = arr[range.end];

		int left = range.start, right = range.end - 1;

		while (left < right) 
		{
			// �ҵ���һ����С��mid��Ԫ��
			while (arr[left] < mid && left < right)
				left++;
			// �ҵ���һ��������mid��Ԫ��
			while (arr[right] >= mid && left < right)
				right--;

			swap(&arr[left], &arr[right]);
		}

		// ��������Ԫ��Խ��
		if (arr[left] >= arr[range.end])
		{
			swap(&arr[left], &arr[range.end]);
		}

		else
		{ 
			// ���left ָ��û��Խ��
			left++;
		}
		// �������������ֵķ�Χ��ջ
		r[p++] = new_Range(range.start, left - 1);
		r[p++] = new_Range(left + 1, range.end);
	}

	free(r);
}