#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct _STACKNODE
{
	struct _STACKNODE *Next;
}StackNode;



typedef struct _LINKSTACK
{
	// ջ�����ݣ���ʵ�ǵ�ַ��
	StackNode Head;
	// ջ�ĳ���
	int Size;
}LinkStack;

//��ʼ��
int Init_LinkStack(void **linkstack)
{
	if (linkstack == NULL)
	{
		exit(-1);
	}

	// ���������ͽ���ת�������ں���Ĳ��� 
	LinkStack **stack = (LinkStack **)linkstack;
	
	// ���ջ�Ƿ��Ѿ��п��õ��ڴ�
	if (*stack == NULL)
	{
		*stack = (LinkStack *)malloc(sizeof(LinkStack));
	}
	// �Կ��ٿռ�ļ��
	if (*stack == NULL)
	{
		exit(-2);
	}
	
	// �����ݺͳ��ȳ�ʼ��
	(*stack)->Head.Next = NULL;
	(*stack)->Size = 0;

	return 0;
}


// ��ջ
int Push_LinkStack(void *linkstack, void *Data)
{
	if (linkstack == NULL)
	{
		return -1;
	}
	if (Data == NULL)
	{
		return -2;
	}

	// ���������ͽ���ת�������ں���Ĳ��� 
	LinkStack *stack = (LinkStack *)linkstack;
	StackNode *data = (StackNode *)Data;
	
	data->Next = stack->Head.Next;
	stack->Head.Next = data;
	++stack->Size;

	return 0;
}


// ��ջ
int Pop_LinkStack(void *linkstack)
{
	if (linkstack == NULL)
	{
		return -1;
	}
	// ���������ͽ���ת�������ں���Ĳ��� 
	LinkStack *stack = (LinkStack *)linkstack;
#if 0	
	// ջΪ�գ����ܳ�ջ
	if (stack->Size == 0)
	{
		return -2;
	}
	else
	{
		stack->Head.Next = stack->Head.Next->Next;
		--stack->Size;
	}
#else
	if (stack->Head.Next != NULL)
	{
		stack->Head.Next = stack->Head.Next->Next;
		--stack->Size;
	}
#endif
	return 0;
}

void *Top_LinkStack(void *linkstack)
{
	if (linkstack == NULL)
	{
		return NULL;
	}
	// ���������ͽ���ת�������ں���Ĳ��� 
	LinkStack *stack = (LinkStack *)linkstack;

	return stack->Head.Next;

}

int Size_LinkStack(void *linkstack)
{
	if (linkstack == NULL)
	{
		return 0;
	}
	// ���������ͽ���ת�������ں���Ĳ��� 
	LinkStack *stack = (LinkStack *)linkstack;
	return stack->Size;
}

int Destory_LinkStack(void *linkstack)
{
	if (linkstack == NULL)
	{
		return -1;
	}
	// ���������ͽ���ת�������ں���Ĳ��� 
	LinkStack *stack = (LinkStack *)linkstack;

	if (stack->Head.Next != NULL)
	{
		stack->Head.Next = NULL;
	}
	stack->Size = 0;
	return 0;
}