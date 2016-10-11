#include "QueueStack.h"

// ��ʼ��ջ
int Init_QueueStack(QueueStack **stack, int capacity)
{
	if (stack == NULL)
	{
		exit(-1);
	}
	// ����һ��ջ�Ľ��
	*stack = (QueueStack *)malloc(sizeof(QueueStack));
	if (*stack == NULL)
	{
		exit(-2);
	}
	// Ϊջ�������򿪱ٿռ�
	(*stack)->data = (void **)malloc(sizeof(void *)*capacity);
	if ((*stack)->data == NULL)
	{
		exit(-3);
	}
	// ��ջ���ٵ�������Ŀռ�����
	memset((*stack)->data, 0, sizeof(void *)*capacity);
	(*stack)->capacity = capacity;
	(*stack)->size = 0;
	return 0;
}

//��ջ
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
		// ��ջ���ٵ�������Ŀռ�����
		memset(newData, 0, stack->capacity);
		// ����ԭ�������ݵ��µ�������
		memcpy(newData, stack->data, stack->capacity / 2);
		// �ͷ�ԭ���Ŀռ�
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
	// �����ݵ����һλ�ÿգ�ͬʱʹ���ȼ�һ
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