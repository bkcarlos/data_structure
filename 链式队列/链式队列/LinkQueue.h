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

// 初始化
int Init_LinkQueue(void **Queue);

// 入队列
int Push_LinkQueue(void *Queue, void *Data);

// 出队列
int Pop_LinkQueue(void *Queue);

// 队列中元素的个数
int Size_LinkQueue(void *Queue);

// 销毁队列
int Destroy_LinkQueue(void *Queue);

// 返回对头元素
void* Front_LinkQueue(void *Queue);

// 放回对尾元素
void* Back_LinkQueue(void *Queue);