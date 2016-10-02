
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct _QUEUESTACK
{
	// ջ������
	void **Stack;

	// ջ�����ݳ���
	int Size;

	// ջ������
	int Capacity;
}QueueStack;


// ��ʼ��ջ
int Init_QueueStack(void **queuestack, int capacity);

//��ջ
int Push_QueueStack(void *queuestack, void *data);

// ��ջ
int Pop_QueueStack(void *queuestack);

// ��ȡջ��
void * Top_QueueStack(void *queuestack);

// ����ջ
int Destory_QueueStack(void *queuestack);

// ����ջ�Ĵ�С
int Size_QueueStack(void *queuestack);
