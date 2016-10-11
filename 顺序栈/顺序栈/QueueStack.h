#pragma once

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct _QUEUESTACK
{
	// 栈的数据
	void **data;

	// 栈的数据长度
	int size;

	// 栈的容量
	int capacity;
}QueueStack;

// 初始化栈
int Init_QueueStack(QueueStack **stack, int capacity);

//入栈
int Push_QueueStack(QueueStack *stack, void *data);

// 出栈
int Pop_QueueStack(QueueStack *stack);

// 栈顶
void * Top_QueueStack(QueueStack *stack);

// 销毁栈
int Destory_QueueStack(QueueStack *stack);

// 栈的大小
int Size_QueueStack(QueueStack *stack);