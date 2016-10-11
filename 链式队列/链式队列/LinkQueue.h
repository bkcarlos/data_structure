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

// 初始化
int Init_LinkQueue(LinkQueue ** queue);

// 入对
int Push_LinkQueue(LinkQueue * queue, void * Data);

// 出队操作
int Pop_LinkQueue(LinkQueue * queue);

// 返回对列的大小
int Size_LinkQueue(LinkQueue * queue);

// 销毁队列
int Destroy_LinkQueue(LinkQueue * queue);

// 返回对尾数据的指针
void* Back_LinkQueue(LinkQueue * queue);

// 返回队首数据的指针
void* Front_LinkQueue(LinkQueue * queue);
