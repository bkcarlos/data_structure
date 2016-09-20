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

// ��ʼ��
int Init_IntDynamicArray(IntDynamicArray **Array, int Capacity);

// ����
int Insert_IntDynamicArray(IntDynamicArray *Array, int Data, int Pos);

// ɾ��
int EraseByPos_IntDynamicArray(IntDynamicArray *Array, int Pos);

// �޸�
int Modif_IntDynamicArray(IntDynamicArray *Array, int Pos, int Data);

// ͨ��λ�ò���
int SeekByPos_IntDynamicArray(IntDynamicArray *Array, int Pos);

// ���ҵ�һ�γ���ĳֵ��λ��
int SeekByVal_IntDynamicArray(IntDynamicArray *Array, int Val);

// ��ӡ��̬����
void Print_IntDynamicArray(IntDynamicArray *Array);

// ���鳤��
int Size_IntDynamicArray(IntDynamicArray *Array);

// ��������
int Capacity_IntDynamicArray(IntDynamicArray *Array);

// ����
int Destroy_IntDynamicArray(IntDynamicArray *Array);

#endif // !DYNAMICARRAY_H

