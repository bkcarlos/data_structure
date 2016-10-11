#include "LinkQueue.h"

// ��ʼ��
int Init_LinkQueue(LinkQueue ** queue)
{
	// �Դ���Ĳ������м��
	if (queue == NULL)
		exit(-1); // Ϊʲô�����ش������ˣ���ʼ�����ɹ�������Ĳ��������

				  // ����һ��LinkQueue�ṹ�壬
	*queue = (LinkQueue *)malloc(sizeof(LinkQueue));

	if (*queue == NULL)
	{
		exit(-2);// ԭ��ͬexit(-1);
	}

	// �Կ��ٵĿռ��ֵ��ʼ��
	(*queue)->head.next = NULL;
	(*queue)->size = 0;

	return 0;
}

// ���
int Push_LinkQueue(LinkQueue * queue, void * Data)
{
	if (queue == NULL)
	{
		return -1;
	}
	if (Data == NULL)
	{
		return -2;
	}


	// ת������
	LinkQueueNode *data = (LinkQueueNode *)Data;

	/*
	* ���Ϊʲô�����Ϳ��԰�������������
	* ������ͷ�����߿������еĶ�β��ÿ����Ӷ��ǶԶ�β�Ĳ�����
	* ����ǰ���Ƕ�����һ�� linkQueue ���͵Ľṹ�壬���溬���и� head ����Ӿ��Ƕ�headָ����޸�
	* Ϊ�˽� head ԭ����������ݴ�����������������Ҫ�� data �� next ��������head��next��
	* ��� head ָ�� data
	*/
	data->next = queue->head.next;
	queue->head.next = data;

	// ��ʽ����ά����һ�����ȱ���������ǳ��ȼ�һ
	++queue->size;

	return 0;
}

// ���Ӳ���
int Pop_LinkQueue(LinkQueue * queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	// ����ʱ��һ��Ҫ�����еĳ��ȣ�������Ϊ��ʱ���Զ��н��г��ӵĲ��������BUG
	if (queue->size == 0)
	{
		return -2;
	}

	// ��Ҫ�ҵ����һ��Ԫ�ص�ǰһ��Ԫ�أ�������ָ��ָ�� NULL
	LinkQueueNode *pCurrent = queue->head.next;
	LinkQueueNode *pPre = &(queue->head);
	while (pCurrent->next != NULL)
	{
		pPre = pCurrent;
		pCurrent = pCurrent->next;
	}

	// �����һ��Ԫ�ص�ǰ��һ��Ԫ�ص�ָ���ÿ�
	pPre->next = NULL;

	// ά�����еĳ���
	--queue->size;
	return 0;
}

// ���ض��еĴ�С
int Size_LinkQueue(LinkQueue * queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	return queue->size;
}

// ���ٶ���
int Destroy_LinkQueue(LinkQueue * queue)
{
	if (queue == NULL)
		return -1;

	// ��ʹ֪��queue������Ϊ�գ����ǻ��Ƕ�����һ�μ��
	if (queue != NULL)
		free(queue);
	queue = NULL;

	return 0;
}

// ���ض�β���ݵ�ָ��
void* Back_LinkQueue(LinkQueue * queue)
{
	if (queue == NULL)
		return NULL;

	return queue->head.next;
}

// ���ض������ݵ�ָ��
void* Front_LinkQueue(LinkQueue * queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	LinkQueueNode *pCurrent = queue->head.next;

	// �ҵ����һ��Ԫ��
	// pCurrent !=NULL ��֤�� ���Զ� pCurrent->next ��ȡֵ��ͬ���������ط�Ҳ��Ҫ�����ļ��
	while (pCurrent != NULL && pCurrent->next != NULL)
	{
		pCurrent = pCurrent->next;
	}
	return pCurrent;
}
