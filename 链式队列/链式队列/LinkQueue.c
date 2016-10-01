#include "LinkQueue.h"

// ��ʼ��
int Init_LinkQueue(void ** Queue)
{
	// �Դ���Ĳ������м��
	if (Queue == NULL)
		exit(-1); // Ϊʲô�����ش������ˣ���ʼ�����ɹ�������Ĳ��������

	// ����һ��LinkQueue�ṹ�壬
	LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));

	if (queue == NULL)
	{
		exit(-2);// ԭ��ͬexit(-1);
	}

	// �Կ��ٵĿռ��ֵ��ʼ��
	queue->head.next = NULL;
	queue->size = 0;

	// ָ���ļ�Ӹ�ֵ
	*Queue = queue;

	return 0;
}

// ���
int Push_LinkQueue(void * Queue, void * Data)
{
	if (Queue == NULL)
	{
		return -1;
	}
	if (Data == NULL)
	{
		return -2;
	}
	
	// ������Ĳ���Queueת��Ϊ���Ա����ǲ���������LinkQueue *queue,��ʵ�ڴ����β�ʱ��ʵ�ξ���LinkQueue *��
	LinkQueue *queue = (LinkQueue *)Queue;
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
	++ queue->size;

	return 0;
}

// ���Ӳ���
int Pop_LinkQueue(void * Queue)
{
	if (Queue == NULL)
	{
		return -1;
	}
	
	LinkQueue *queue = (LinkQueue *)Queue;
	
	// ����ʱ��һ��Ҫ�����еĳ��ȣ�������Ϊ��ʱ���Զ��н��г��ӵĲ��������BUG
	if (queue->size == 0)
	{
		return -2;
	}
	
	LinkQueueNode *pCurrent = queue->head.next;
	
	// Ϊʲô��Ҫ�����ôԶ
	/*
	 * ���ֻд���� pCurrent != NULL ��ô���ָ�뽫�ƶ������һ��Ԫ�صĺ��棬��ô����˵����֪���ᷢ��ʲô���
	 * ֻ��� pCurrent->next != NULL ָ�뽫ָ�����һ��Ԫ�أ�����pCurrent->next = NULL���� pCurrent = NULL;�������õ�,
	 * ������һ�¾���pCurrent->next->next != NULL�ļ�⣬�����Ҫ�Ǳ�֤��ָ�����ͣ����ͷ�ĺ���һ��Ԫ�ص�λ���ϣ���֤������Ԫ��ָ���ÿ�
	 */
	while (pCurrent != NULL && pCurrent->next != NULL && pCurrent->next->next!=NULL)
	{
		pCurrent = pCurrent->next;
	}

	// �����һ��Ԫ�ص�ǰ��һ��Ԫ�ص�ָ���ÿ�
	pCurrent->next = NULL;

	// ά�����еĳ���
	-- queue->size;
	
	// ��Ϊ֮��queue->head->next �ÿգ������Ὣqueue->head�ÿգ���ô���ʶ���ʱ��Ҳ���Է���һ��Ԫ�� 
	if (queue->size == 0)
	{
		queue->head.next = NULL;
	}

	return 0;
}

// ���ض��еĴ�С
int Size_LinkQueue(void * Queue)
{
	if (Queue == NULL)
	{
		return -1;
	}

	LinkQueue *queue = (LinkQueue *)Queue;

	return queue->size;
}

// ���ٶ���
int Destroy_LinkQueue(void * Queue)
{
	if (Queue == NULL)
		return -1;

	LinkQueue *queue = (LinkQueue *)Queue;
	
	// ��ʹ֪��queue������Ϊ�գ����ǻ��Ƕ�����һ�μ��
	if(queue!=NULL)
	 free(queue);

	return 0;
}

// ���ض�β���ݵ�ָ��
void* Back_LinkQueue(void * Queue)
{
	if (Queue == NULL)
		return NULL;
	LinkQueue *queue = (LinkQueue *)Queue;
	return queue->head.next;
}

// ���ض������ݵ�ָ��
void* Front_LinkQueue(void * Queue)
{
	if (Queue == NULL)
	{
		return NULL;
	}
	LinkQueue *queue = (LinkQueue *)Queue;

	/*if (queue->size == 0)
	{
		return NULL;
	}*/
	LinkQueueNode *pCurrent = queue->head.next;

	while (pCurrent != NULL && pCurrent->next != NULL)
	{
		pCurrent = pCurrent->next;
	}
	return pCurrent;
}
