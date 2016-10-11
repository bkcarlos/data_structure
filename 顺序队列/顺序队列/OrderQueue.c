#include "OrderQueue.h"



// 将开始的位置作为队头，越大的位置作为队尾

// 初始化
int Init_OrderQueue(OrderQueue **queue, int capacity)
{
	if (queue == NULL)
	{
		exit(-1);
	}

	*queue = (OrderQueue *)malloc(sizeof(OrderQueue));
	if (*queue == NULL)
	{
		exit(-2);
	}

	(*queue)->Data = (void **)malloc(sizeof(void *)*capacity);

	(*queue)->Size = 0;
	(*queue)->Capacity = capacity;

	return 0;
}

// 入队
int Push_OrderQueue(OrderQueue *queue, void *data)
{
	if (queue == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return 0;
	}
	if (queue->Size == queue->Capacity)
	{
		queue->Capacity *= 2;
		void ** newQueue = (void **)malloc(sizeof(void *)*queue->Capacity);
		if (newQueue == NULL)
		{
			return -3;
		}
		memset(newQueue, 0, queue->Capacity);
		memcpy(newQueue, queue->Data, sizeof(void *)*queue->Size);

		free(queue->Data);
		queue->Data = newQueue;
	}
	queue->Data[queue->Size++] = data;

	return 0;
}

// 出队
int Pop_OrderQueue(OrderQueue *queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	if (queue->Size == 0)
	{
		return -2;
	}
	for (int i = 0; i < queue->Size - 1; ++i)
	{
		queue->Data[i] = queue->Data[i + 1];
	}

	queue->Data[--queue->Size] = NULL;

	return 0;
}

// 获取对尾元素
void *Front_OrderQueue(OrderQueue *queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	return  queue->Data[0];
}

void *Back_OrderQueue(OrderQueue *queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	return  queue->Data[queue->Size - 1];
}

int Destory_OrderQueue(OrderQueue *queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	if (queue->Data)
	{
		free(queue->Data);
		queue->Data = NULL;
	}
	free(queue);
	queue = NULL;

	return 0;
}

int Size_OrderQueue(OrderQueue *queue)
{
	if (queue == NULL)
	{
		return -1;
	}
	return queue->Size;
}