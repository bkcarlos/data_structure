#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// 如果开始需要大一些的容量，请修改这里
#define  MAXCAPACITY  10


#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

typedef struct _DYNAMICARRAY
{
	// 数据存储 
	void **Array;

	// 数组的容量
	int Capacity;

	// 数组现有数据的长度
	int ArrayLen;
}DynamicArray;

// 比较函数指针
// data1 > data2  return -1;
// data1 = data2  return 0;
// data1 < data2  return 1
typedef int(*COMPARE)(void *Data1, void *Data2);

// 遍历函数指针
typedef void(*TRAVERSAL)(void *Val);


// 开辟数组的容量
int Init_DynamicArray(void **DArray);

// 在数组末尾插入数据
int pushBack_DynamicArray(void *DArray, void *Data);

// 指定位置插入
void InsertByPos(void *DArray, int Pos, void *Val);


//  指定位置删除
int eraseByPos_DynamicArray(void *DArray, int Pos);

// 头删
int eraseFront_DynamicArray(void *DArray);


// 尾删
int eraseBack_DynamicArray(void *DArray);

// 得到指定位置的元素
void * GetByPos_DynamicArray(void *DArray, int Pos);

// 查看数组中某个值是否存在
int  GetByVal_DynamicArray(void *DArray, void *Val, COMPARE compare);

// 返回动态数组的大小
int Size_DynamicArray(void *DArray);

// 放回动态数组的容量
int Capacity_DynamicArray(void *DArray);

// 遍历数组
void Traversal_DynamicArray(void *DArray, TRAVERSAL traversal);

// 逆置数组
int Inverted_DynamicArray(void *DArray);


void Quick_Sort(void  **array, int low, int height, COMPARE compare);

// 动态数组排序
int Sort__DynamicArray(void *DArray, COMPARE compare);

// 销毁数组
int Destroy__DynamicArray(void *DArray);


#endif // !DYNAMICARRAY_H






