#include "LinkQueue.h"

// 初始化
int Init_LinkQueue(void ** Queue)
{
	// 对传入的参数进行检测
	if (Queue == NULL)
		exit(-1); // 为什么不返回错误码了，初始化不成功，后面的操作都会错

	// 开辟一个LinkQueue结构体，
	LinkQueue *queue = (LinkQueue *)malloc(sizeof(LinkQueue));

	if (queue == NULL)
	{
		exit(-2);// 原因同exit(-1);
	}

	// 对开辟的空间的值初始化
	queue->head.next = NULL;
	queue->size = 0;

	// 指针间的间接赋值
	*Queue = queue;

	return 0;
}

// 入对
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
	
	// 将传入的参数Queue转化为可以被我们操作的类型LinkQueue *queue,其实在传递形参时，实参就是LinkQueue *；
	LinkQueue *queue = (LinkQueue *)Queue;
	// 转化数据
	LinkQueueNode *data = (LinkQueueNode *)Data;

	/*
	 * 这个为什么这样就可以把数据连接起来
	 * 把链表头结点这边看做队列的对尾，每次入队都是对对尾的操作，
	 * 我们前面是定义了一个 linkQueue 类型的结构体，里面含有有个 head ，入队就是对head指向的修改
	 * 为了将 head 原来后面的数据串起来，所以首先需要用 data 的 next 域来接收head的next域
	 * 最后将 head 指向 data
	*/
	data->next = queue->head.next;
	queue->head.next = data;

	// 链式对列维护了一个长度变量，入队是长度加一
	++ queue->size;

	return 0;
}

// 出队操作
int Pop_LinkQueue(void * Queue)
{
	if (Queue == NULL)
	{
		return -1;
	}
	
	LinkQueue *queue = (LinkQueue *)Queue;
	
	// 出队时，一定要检查队列的长度，当对列为空时，对对列进行出队的操作，或出BUG
	if (queue->size == 0)
	{
		return -2;
	}
	
	LinkQueueNode *pCurrent = queue->head.next;
	
	// 为什么需要检查怎么远
	/*
	 * 如果只写条件 pCurrent != NULL 那么最后指针将移动到最后一个元素的后面，那么不用说，就知道会发生什么情况
	 * 只检测 pCurrent->next != NULL 指针将指向最后一个元素，后面pCurrent->next = NULL或者 pCurrent = NULL;都是无用的,
	 * 在讨论一下就是pCurrent->next->next != NULL的检测，这个主要是保证让指针最后停到对头的后面一个元素的位置上，保证将最后的元素指针置空
	 */
	while (pCurrent != NULL && pCurrent->next != NULL && pCurrent->next->next!=NULL)
	{
		pCurrent = pCurrent->next;
	}

	// 将最后一个元素的前面一个元素的指针置空
	pCurrent->next = NULL;

	// 维护对列的长度
	-- queue->size;
	
	// 因为之后将queue->head->next 置空，而不会将queue->head置空，那么访问对列时，也可以访问一个元素 
	if (queue->size == 0)
	{
		queue->head.next = NULL;
	}

	return 0;
}

// 返回对列的大小
int Size_LinkQueue(void * Queue)
{
	if (Queue == NULL)
	{
		return -1;
	}

	LinkQueue *queue = (LinkQueue *)Queue;

	return queue->size;
}

// 销毁队列
int Destroy_LinkQueue(void * Queue)
{
	if (Queue == NULL)
		return -1;

	LinkQueue *queue = (LinkQueue *)Queue;
	
	// 即使知道queue不可能为空，但是还是对它做一次检测
	if(queue!=NULL)
	 free(queue);

	return 0;
}

// 返回对尾数据的指针
void* Back_LinkQueue(void * Queue)
{
	if (Queue == NULL)
		return NULL;
	LinkQueue *queue = (LinkQueue *)Queue;
	return queue->head.next;
}

// 返回队首数据的指针
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
