#include "QueueStack.h"


// 初始化栈
int Init_QueueStack(void **queuestack, int capacity)
{
	if (queuestack == NULL)
	{
		exit(-1);
	}
	// 定义一个栈结构体的指针
	QueueStack *stack = (QueueStack *)malloc(sizeof(QueueStack));

	// 判断开辟内存是否成功
	if (stack == NULL)
	{
		exit(-2);
	}

	// 为stack 开辟一段堆内存
	stack->Stack = (void **)malloc(sizeof(void *)*capacity);

	// 判断开辟内存是否成功
	if (stack->Stack == NULL)
	{
		exit(-2);
	}

	// 写入相关的变化
	stack->Capacity = capacity;
	stack->Size = 0;

	// 将开辟出来的空间置零
	memset(stack->Stack, 0, sizeof(void *)*stack->Capacity);

	*queuestack = stack;
	return 0;
}

//入栈
int Push_QueueStack(void *queuestack, void *data)
{
	// 对传入的参数做判断
	if (queuestack == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -2;
	}

	// 将指针转化为我们可以操作的类型
	QueueStack *stack = (QueueStack *)queuestack;
	if (stack->Size == stack->Capacity)
	{
		// 当数据域的长度不够时，进行动态开辟
		void ** newStack = (void **)malloc(stack->Capacity * 2);
		if (newStack == NULL)
		{
			return -3;
		}
		// 将开辟的空间全部置零
		memset(newStack, 0, sizeof(void *)* stack->Capacity * 2);

		// 将原来的数据拷贝到新的栈
		memcpy(newStack, stack->Stack, sizeof(void *)*stack->Capacity);

		// 释放原来栈的空间
		free(stack->Stack);

		// 将栈的数据域指向新的位置
		stack->Stack = newStack;
		stack->Capacity *= 2;
	}

	// 将数据加入到栈的数据域中 
	stack->Stack[stack->Size] = data;
	++stack->Size;

	return 0;
}

int Pop_QueueStack(void *queuestack)
{
	if (queuestack == NULL)
	{
		return -1;
	}

	// 将指针转化为我们可以操作的类型
	QueueStack *stack = (QueueStack *)queuestack;

	// 数据域没数据没法出栈
	if (stack->Size == 0)
	{
		return -2;
	}
	else
	{
		// 先将长度减一
		--stack->Size;

		// 将最后一个元素的位置空
		stack->Stack[stack->Size] = NULL;
	}
	return 0;

}

void * Top_QueueStack(void *queuestack)
{
	if (queuestack == NULL)
	{
		return NULL;
	}

	// 将指针转化为我们可以操作的类型
	QueueStack *stack = (QueueStack *)queuestack;

	// 数据域没数据没法出栈
	if (stack->Size == 0)
	{
		return NULL;
	}
	else
	{
		return stack->Stack[stack->Size - 1];
	}
}

int Destory_QueueStack(void *queuestack)
{
	if (queuestack == NULL)
	{
		return -1;
	}

	// 将指针转化为我们可以操作的类型
	QueueStack *stack = (QueueStack *)queuestack;

	if (stack->Stack != NULL)
	{
		// 不知道这段内存的位置（栈内存还是堆内存） 里面存储的是地址 由使用者自己管理
		//free(stack->Stack);

		stack->Stack = NULL;
		stack->Size = 0;
		stack->Capacity = 0;
	}
	free(stack);

	return 0;
}

int Size_QueueStack(void *queuestack)
{
	if (queuestack == NULL)
	{
		return -1;
	}

	// 将指针转化为我们可以操作的类型
	QueueStack *stack = (QueueStack *)queuestack;

	return stack->Size;

}