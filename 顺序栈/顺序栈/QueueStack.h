
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct _QUEUESTACK
{
	// 栈的数据
	void **Stack;

	// 栈的数据长度
	int Size;

	// 栈的容量
	int Capacity;
}QueueStack;


// 初始化栈
int Init_QueueStack(void **queuestack, int capacity);

//入栈
int Push_QueueStack(void *queuestack, void *data);

// 出栈
int Pop_QueueStack(void *queuestack);

// 获取栈顶
void * Top_QueueStack(void *queuestack);

// 销毁栈
int Destory_QueueStack(void *queuestack);

// 返回栈的大小
int Size_QueueStack(void *queuestack);
