#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// �����ʼ��Ҫ��һЩ�����������޸�����
#define  MAXCAPACITY  10


#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

typedef struct _DYNAMICARRAY
{
	// ���ݴ洢 
	void **Array;

	// ���������
	int Capacity;

	// �����������ݵĳ���
	int ArrayLen;
}DynamicArray;

// �ȽϺ���ָ��
// data1 > data2  return -1;
// data1 = data2  return 0;
// data1 < data2  return 1
typedef int(*COMPARE)(void *Data1, void *Data2);

// ��������ָ��
typedef void(*TRAVERSAL)(void *Val);


// �������������
int Init_DynamicArray(void **DArray);

// ������ĩβ��������
int pushBack_DynamicArray(void *DArray, void *Data);

// ָ��λ�ò���
void InsertByPos(void *DArray, int Pos, void *Val);


//  ָ��λ��ɾ��
int eraseByPos_DynamicArray(void *DArray, int Pos);

// ͷɾ
int eraseFront_DynamicArray(void *DArray);


// βɾ
int eraseBack_DynamicArray(void *DArray);

// �õ�ָ��λ�õ�Ԫ��
void * GetByPos_DynamicArray(void *DArray, int Pos);

// �鿴������ĳ��ֵ�Ƿ����
int  GetByVal_DynamicArray(void *DArray, void *Val, COMPARE compare);

// ���ض�̬����Ĵ�С
int Size_DynamicArray(void *DArray);

// �Żض�̬���������
int Capacity_DynamicArray(void *DArray);

// ��������
void Traversal_DynamicArray(void *DArray, TRAVERSAL traversal);

// ��������
int Inverted_DynamicArray(void *DArray);


void Quick_Sort(void  **array, int low, int height, COMPARE compare);

// ��̬��������
int Sort__DynamicArray(void *DArray, COMPARE compare);

// ��������
int Destroy__DynamicArray(void *DArray);


#endif // !DYNAMICARRAY_H






