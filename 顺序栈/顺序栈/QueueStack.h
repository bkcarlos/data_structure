#pragma once

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct _QUEUESTACK
{
	// ջ������
	void **data;

	// ջ�����ݳ���
	int size;

	// ջ������
	int capacity;
}QueueStack;

// ��ʼ��ջ
int Init_QueueStack(QueueStack **stack, int capacity);

//��ջ
int Push_QueueStack(QueueStack *stack, void *data);

// ��ջ
int Pop_QueueStack(QueueStack *stack);

// ջ��
void * Top_QueueStack(QueueStack *stack);

// ����ջ
int Destory_QueueStack(QueueStack *stack);

// ջ�Ĵ�С
int Size_QueueStack(QueueStack *stack);