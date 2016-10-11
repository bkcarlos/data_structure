#include<stdio.h>
#include<stdlib.h>


typedef struct _LINKQUEUENODE
{
	struct _LINKQUEUENODE *next;
}LinkQueueNode;

typedef struct _LINKQUEUE
{
	LinkQueueNode head;
	int size;
}LinkQueue;

// ��ʼ��
int Init_LinkQueue(LinkQueue ** queue);

// ���
int Push_LinkQueue(LinkQueue * queue, void * Data);

// ���Ӳ���
int Pop_LinkQueue(LinkQueue * queue);

// ���ض��еĴ�С
int Size_LinkQueue(LinkQueue * queue);

// ���ٶ���
int Destroy_LinkQueue(LinkQueue * queue);

// ���ض�β���ݵ�ָ��
void* Back_LinkQueue(LinkQueue * queue);

// ���ض������ݵ�ָ��
void* Front_LinkQueue(LinkQueue * queue);
