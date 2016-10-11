#include "QueueStack.h"

// 初始化栈
int Init_QueueStack(QueueStack **stack, int capacity)
{
	if (stack == NULL)
	{
		exit(-1);
	}
	// 开辟一个栈的结点
	*stack = (QueueStack *)malloc(sizeof(QueueStack));
	if (*stack == NULL)
	{
		exit(-2);
	}
	// 为栈的数据域开辟空间
	(*stack)->data = (void **)malloc(sizeof(void *)*capacity);
	if ((*stack)->data == NULL)
	{
		exit(-3);
	}
	// 将栈开辟的数据域的空间置零
	memset((*stack)->data, 0, sizeof(void *)*capacity);
	(*stack)->capacity = capacity;
	(*stack)->size = 0;
	return 0;
}

//入栈
int Push_QueueStack(QueueStack *stack, void *data)
{
	if (stack == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -2;
	}
	if (stack->size == stack->capacity)
	{
		void **newData = (void **)malloc(sizeof(void *)*stack->capacity * 2);
		if (newData == NULL)
		{
			return -3;
		}
		stack->capacity *= 2;
		// 将栈开辟的数据域的空间置零
		memset(newData, 0, stack->capacity);
		// 拷贝原来的数据到新的数据域
		memcpy(newData, stack->data, stack->capacity / 2);
		// 释放原来的空间
		free(stack->data);
		stack->data = newData;
	}
	stack->data[stack->size] = data;
	++stack->size;
	return 0;
}

int Pop_QueueStack(QueueStack *stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	if (stack->size == 0)
	{
		return -2;
	}
	// 将数据的最后一位置空，同时使长度减一
	stack->data[--stack->size] = NULL;
	return 0;
}

void * Top_QueueStack(QueueStack *stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	if (stack->size == 0)
	{
		return NULL;
	}
	return stack->data[stack->size - 1];
}

int Destory_QueueStack(QueueStack *stack)
{
	if (stack == NULL)
	{
		return -1;
	}

	if (stack->data == NULL)
	{
		free(stack->data);
	}

	free(stack);
	stack = NULL;
	return 0;
}

int Size_QueueStack(QueueStack *stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	return stack->size;
}