#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct _ORDERQUEUE
{
	// ����
	void ** Data;

	// ���ݳ���
	int Size;

	// ��������
	int Capacity;
}OrderQueue;


// ����ʼ��λ����Ϊ��ͷ��Խ���λ����Ϊ��β

// ��ʼ��
int Init_OrderQueue(OrderQueue **queue, int capacity);

// ���
int Push_OrderQueue(OrderQueue *queue, void *data);

// ����
int Pop_OrderQueue(OrderQueue *queue);

// ��ȡ����Ԫ��
void *Front_OrderQueue(OrderQueue *queue);

//��ȡ��βԪ��
void *Back_OrderQueue(OrderQueue *queue);

// ���ٶ���
int Destory_OrderQueue(OrderQueue *queue);

// ���еĴ�С
int Size_OrderQueue(OrderQueue *queue);