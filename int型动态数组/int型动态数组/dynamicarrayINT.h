#ifndef DYNAMICARRAYINT_H
#define DYNAMICARRAYINT_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h> // memcpy


typedef struct _INT_DYNAMICARRAY
{
	int *array;
	int arrayLen;
	int capacity;
}IntDynamicArray;

// 初始化
int Init_IntDynamicArray(IntDynamicArray **Array, int Capacity);

// 插入
int Insert_IntDynamicArray(IntDynamicArray *Array, int Data, int Pos);

// 删除
int EraseByPos_IntDynamicArray(IntDynamicArray *Array, int Pos);

// 修改
int Modif_IntDynamicArray(IntDynamicArray *Array, int Pos, int Data);

// 通过位置查找
int SeekByPos_IntDynamicArray(IntDynamicArray *Array, int Pos);

// 查找第一次出现某值的位置
int SeekByVal_IntDynamicArray(IntDynamicArray *Array, int Val);

// 打印动态数组
void Print_IntDynamicArray(IntDynamicArray *Array);

// 数组长度
int Size_IntDynamicArray(IntDynamicArray *Array);

// 数组容量
int Capacity_IntDynamicArray(IntDynamicArray *Array);

// 销毁
int Destroy_IntDynamicArray(IntDynamicArray *Array);

#endif // !DYNAMICARRAY_H

