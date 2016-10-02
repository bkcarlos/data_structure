#include "QueueStack.h"


// ��ʼ��ջ
int Init_QueueStack(void **queuestack, int capacity)
{
	if (queuestack == NULL)
	{
		exit(-1);
	}
	// ����һ��ջ�ṹ���ָ��
	QueueStack *stack = (QueueStack *)malloc(sizeof(QueueStack));

	// �жϿ����ڴ��Ƿ�ɹ�
	if (stack == NULL)
	{
		exit(-2);
	}

	// Ϊstack ����һ�ζ��ڴ�
	stack->Stack = (void **)malloc(sizeof(void *)*capacity);

	// �жϿ����ڴ��Ƿ�ɹ�
	if (stack->Stack == NULL)
	{
		exit(-2);
	}

	// д����صı仯
	stack->Capacity = capacity;
	stack->Size = 0;

	// �����ٳ����Ŀռ�����
	memset(stack->Stack, 0, sizeof(void *)*stack->Capacity);

	*queuestack = stack;
	return 0;
}

//��ջ
int Push_QueueStack(void *queuestack, void *data)
{
	// �Դ���Ĳ������ж�
	if (queuestack == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -2;
	}

	// ��ָ��ת��Ϊ���ǿ��Բ���������
	QueueStack *stack = (QueueStack *)queuestack;
	if (stack->Size == stack->Capacity)
	{
		// ��������ĳ��Ȳ���ʱ�����ж�̬����
		void ** newStack = (void **)malloc(stack->Capacity * 2);
		if (newStack == NULL)
		{
			return -3;
		}
		// �����ٵĿռ�ȫ������
		memset(newStack, 0, sizeof(void *)* stack->Capacity * 2);

		// ��ԭ�������ݿ������µ�ջ
		memcpy(newStack, stack->Stack, sizeof(void *)*stack->Capacity);

		// �ͷ�ԭ��ջ�Ŀռ�
		free(stack->Stack);

		// ��ջ��������ָ���µ�λ��
		stack->Stack = newStack;
		stack->Capacity *= 2;
	}

	// �����ݼ��뵽ջ���������� 
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

	// ��ָ��ת��Ϊ���ǿ��Բ���������
	QueueStack *stack = (QueueStack *)queuestack;

	// ������û����û����ջ
	if (stack->Size == 0)
	{
		return -2;
	}
	else
	{
		// �Ƚ����ȼ�һ
		--stack->Size;

		// �����һ��Ԫ�ص�λ�ÿ�
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

	// ��ָ��ת��Ϊ���ǿ��Բ���������
	QueueStack *stack = (QueueStack *)queuestack;

	// ������û����û����ջ
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

	// ��ָ��ת��Ϊ���ǿ��Բ���������
	QueueStack *stack = (QueueStack *)queuestack;

	if (stack->Stack != NULL)
	{
		// ��֪������ڴ��λ�ã�ջ�ڴ滹�Ƕ��ڴ棩 ����洢���ǵ�ַ ��ʹ�����Լ�����
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

	// ��ָ��ת��Ϊ���ǿ��Բ���������
	QueueStack *stack = (QueueStack *)queuestack;

	return stack->Size;

}