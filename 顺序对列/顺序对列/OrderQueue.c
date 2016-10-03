#include "OrderQueue.h"
// ��ʼ��
int Init_OrderQueue(void **orderqueue, int capacity)
{
	if (orderqueue == NULL)
	{
		exit(-1);
	}
	// ������ת��Ϊ���ǿ��Բ���������
	OrderQueue **queue = (OrderQueue **)orderqueue;

	while (*queue == NULL)
	{
		// ��֤�ܿ��ٿռ�ɹ�
		*queue = (OrderQueue *)malloc(sizeof(OrderQueue));
	}
	// ����������������
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

// ���
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

	// ������ת��Ϊ���ǿ��Բ���������
	OrderQueue *queue = (OrderQueue *)orderqueue;

	// �������ͳ�����ͬʱ����Ҫ���������Ŀռ�
	if (queue->Size == queue->Capacity)
	{
		queue->Capacity *= 2;
		// ���¿���һ�οռ���������
		void ** newQueue = (void **)malloc(sizeof(void *)*queue->Capacity);
		if (newQueue == NULL)
		{
			return -3;
		}

		// ���¿��ٵĿռ�����
		memset(newQueue, 0, sizeof(void *)*queue->Capacity);

		// ��ԭ�������ݿ��������ڵĿռ���
		memcpy(newQueue, queue->Data, sizeof(void *)*queue->Size);

		// �ͷ�ԭ���Ŀռ�
		free(queue->Data);

		// ������ָ��ָ���¿ռ�
		queue->Data = newQueue;
	}
	// �����ݲ��뵽������
	queue->Data[queue->Size] = data;
	++queue->Size;
	return 0;

}

// ����
int Pop_OrderQueue(void *orderqueue)
{
	if (orderqueue == NULL)
	{
		return -1;
	}

	// ������ת��Ϊ���ǿ��Բ���������
	OrderQueue *queue = (OrderQueue *)orderqueue;

	if (queue->Size == 0)
	{
		return -2;
	}
	// �����в�Ϊ��ʱ������
	for (int i = 0; i < queue->Size - 1; ++i)
	{
		// �����е�Ԫ����ǰ�ƶ�һ��λ�ã���������
		queue->Data[i] = queue->Data[i + 1];
	}
	queue->Data[queue->Size - 1] = NULL;
	--queue->Size;

	return 0;
}

// ��ȡ��βԪ��
void *Back_OrderQueue(void *orderqueue)
{
	if (orderqueue == NULL)
	{
		return NULL;
	}

	// ������ת��Ϊ���ǿ��Բ���������
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

	// ������ת��Ϊ���ǿ��Բ���������
	OrderQueue *queue = (OrderQueue *)orderqueue;
	return queue->Data[0];
}

int Destory_OrderQueue(void *orderqueue)
{
	if (orderqueue == NULL)
	{
		return -1;
	}

	// ������ת��Ϊ���ǿ��Բ���������
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
	// ������ת��Ϊ���ǿ��Բ���������
	OrderQueue *queue = (OrderQueue *)orderqueue;
	return queue->Size;
}