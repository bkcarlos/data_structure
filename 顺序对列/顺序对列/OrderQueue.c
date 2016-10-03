#include "OrderQueue.h"
// 初始化
int Init_OrderQueue(void **orderqueue, int capacity)
{
	if (orderqueue == NULL)
	{
		exit(-1);
	}
	// 将数据转化为我们可以操作的类型
	OrderQueue **queue = (OrderQueue **)orderqueue;

	while (*queue == NULL)
	{
		// 保证能开辟空间成功
		*queue = (OrderQueue *)malloc(sizeof(OrderQueue));
	}
	// 开辟数据区的容量
	(*queue)->Data = (void **)malloc(sizeof(void *)*capacity);
	memset((*queue)->Data, 0, sizeof(void *)*capacity);

	if ((*queue)->Data == NULL)
	{
		exit(-2);
	}

	(*queue)->Capacity = capacity;
	(*queue)->Size = 0;

	return 0;
}

// 入队
int Push_OrderQueue(void *orderqueue, void *data)
{
	if (orderqueue == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -2;
	}

	// 将数据转化为我们可以操作的类型
	OrderQueue *queue = (OrderQueue *)orderqueue;

	// 当容量和长度相同时，需要开辟其他的空间
	if (queue->Size == queue->Capacity)
	{
		queue->Capacity *= 2;
		// 重新开辟一段空间来存数据
		void ** newQueue = (void **)malloc(sizeof(void *)*queue->Capacity);
		if (newQueue == NULL)
		{
			return -3;
		}

		// 将新开辟的空间置零
		memset(newQueue, 0, sizeof(void *)*queue->Capacity);

		// 将原来的数据拷贝到现在的空间来
		memcpy(newQueue, queue->Data, sizeof(void *)*queue->Size);

		// 释放原来的空间
		free(queue->Data);

		// 将数据指针指向新空间
		queue->Data = newQueue;
	}
	// 将数据插入到队列中
	queue->Data[queue->Size] = data;
	++queue->Size;
	return 0;

}

// 出队
int Pop_OrderQueue(void *orderqueue)
{
	if (orderqueue == NULL)
	{
		return -1;
	}

	// 将数据转化为我们可以操作的类型
	OrderQueue *queue = (OrderQueue *)orderqueue;

	if (queue->Size == 0)
	{
		return -2;
	}
	// 当队列不为空时，出队
	for (int i = 0; i < queue->Size - 1; ++i)
	{
		// 将所有的元素向前移动一个位置，避免假溢出
		queue->Data[i] = queue->Data[i + 1];
	}
	queue->Data[queue->Size - 1] = NULL;
	--queue->Size;

	return 0;
}

// 获取对尾元素
void *Back_OrderQueue(void *orderqueue)
{
	if (orderqueue == NULL)
	{
		return NULL;
	}

	// 将数据转化为我们可以操作的类型
	OrderQueue *queue = (OrderQueue *)orderqueue;
	if (queue->Size == 0)
	{
		return NULL;
	}
	return queue->Data[queue->Size - 1];
}

void *Front_OrderQueue(void *orderqueue)
{
	if (orderqueue == NULL)
	{
		return NULL;
	}

	// 将数据转化为我们可以操作的类型
	OrderQueue *queue = (OrderQueue *)orderqueue;
	return queue->Data[0];
}

int Destory_OrderQueue(void *orderqueue)
{
	if (orderqueue == NULL)
	{
		return -1;
	}

	// 将数据转化为我们可以操作的类型
	OrderQueue *queue = (OrderQueue *)orderqueue;

	if (queue->Data != NULL)
	{
		free(queue->Data);
		queue->Data = NULL;
	}
	free(queue);

	return 0;
}

int Size_OrderQueue(void *orderqueue)
{
	if (orderqueue == NULL)
	{
		return -1;
	}
	// 将数据转化为我们可以操作的类型
	OrderQueue *queue = (OrderQueue *)orderqueue;
	return queue->Size;
}