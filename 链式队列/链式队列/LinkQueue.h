#include<stdio.h>
#include<stdlib.h>


typedef struct _LINKQUEUENODE
{
	struct _LINKQUEUENODE *next;
}LinkQueueNode;

typedef struct _LINKQUEUE
{
	LinkQueueNode *head;
	int size;
}LinkQueue;

// ��ʼ��
int Init_LinkQueue(void **Queue);

// �����
int Push_LinkQueue(void *Queue, void *Data);

// ������
int Pop_LinkQueue(void *Queue);

// ������Ԫ�صĸ���
int Size_LinkQueue(void *Queue);

// ���ٶ���
int Destroy_LinkQueue(void *Queue);

// ���ض�ͷԪ��
void* Front_LinkQueue(void *Queue);

// �Żض�βԪ��
void* Back_LinkQueue(void *Queue);