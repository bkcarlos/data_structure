#include "LinkQueue.h"

// 初始化
int Init_LinkQueue(LinkQueue ** queue)
{
	// 对传入的参数进行检测
	if (queue == NULL)
		exit(-1); // 为什么不返回错误码了，初始化不成功，后面的操作都会错

				  // 开辟一个LinkQueue结构体，
	*queue = (LinkQueue *)malloc(sizeof(LinkQueue));

	if (*queue == NULL)
	{
		exit(-2);// 原因同exit(-1);
	}

	// 对开辟的空间的值初始化
	(*queue)->head.next = NULL;
	(*queue)->size = 0;

	return 0;
}

// 入对
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
	++queue->size;

	return 0;
}

// 出队操作
int Pop_LinkQueue(LinkQueue * queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	// 出队时，一定要检查队列的长度，当对列为空时，对对列进行出队的操作，或出BUG
	if (queue->size == 0)
	{
		return -2;
	}

	// 需要找到最后一个元素的前一个元素，将它的指针指向 NULL
	LinkQueueNode *pCurrent = queue->head.next;
	LinkQueueNode *pPre = &(queue->head);
	while (pCurrent->next != NULL)
	{
		pPre = pCurrent;
		pCurrent = pCurrent->next;
	}

	// 将最后一个元素的前面一个元素的指针置空
	pPre->next = NULL;

	// 维护对列的长度
	--queue->size;
	return 0;
}

// 返回对列的大小
int Size_LinkQueue(LinkQueue * queue)
{
	if (queue == NULL)
	{
		return -1;
	}

	return queue->size;
}

// 销毁队列
int Destroy_LinkQueue(LinkQueue * queue)
{
	if (queue == NULL)
		return -1;

	// 即使知道queue不可能为空，但是还是对它做一次检测
	if (queue != NULL)
		free(queue);
	queue = NULL;

	return 0;
}

// 返回对尾数据的指针
void* Back_LinkQueue(LinkQueue * queue)
{
	if (queue == NULL)
		return NULL;

	return queue->head.next;
}

// 返回队首数据的指针
void* Front_LinkQueue(LinkQueue * queue)
{
	if (queue == NULL)
	{
		return NULL;
	}

	LinkQueueNode *pCurrent = queue->head.next;

	// 找到最后一个元素
	// pCurrent !=NULL 保证了 可以对 pCurrent->next 的取值，同理在其他地方也需要这样的检测
	while (pCurrent != NULL && pCurrent->next != NULL)
	{
		pCurrent = pCurrent->next;
	}
	return pCurrent;
}
