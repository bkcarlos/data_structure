#pragma once
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct _ORDERQUEUE
{
	// 数据
	void ** Data;

	// 数据长度
	int Size;

	// 数据容量
	int Capacity;
}OrderQueue;


// 将开始的位置作为队头，越大的位置作为队尾

// 初始化
int Init_OrderQueue(OrderQueue **queue, int capacity);

// 入队
int Push_OrderQueue(OrderQueue *queue, void *data);

// 出队
int Pop_OrderQueue(OrderQueue *queue);

// 获取对首元素
void *Front_OrderQueue(OrderQueue *queue);

//获取对尾元素
void *Back_OrderQueue(OrderQueue *queue);

// 销毁对列
int Destory_OrderQueue(OrderQueue *queue);

// 队列的大小
int Size_OrderQueue(OrderQueue *queue);