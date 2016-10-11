#pragma once
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
int Init_LinkStack(LinkStack **stack)
{
	if (stack == NULL)
	{
		exit(-1);
	}
	*stack = (LinkStack *)malloc(sizeof(LinkStack));
	(*stack)->Head.Next = NULL;
	(*stack)->Size = 0;

	return 0;
}

// ��ջ
int Push_LinkStack(LinkStack *stack, void *Data)
{
	if (stack == NULL)
	{
		return -1;
	}
	if (Data == NULL)
	{
		return -2;
	}
	//
	StackNode *data = (StackNode *)Data;
	//
	data->Next = stack->Head.Next;
	stack->Head.Next = data;
	++stack->Size;

	return 0;
}


// ��ջ
int Pop_LinkStack(LinkStack *stack) 
{
	if (stack == NULL)
	{
		return -1;
	}
	if (stack->Size == 0)
	{
		return -2;
	}
	// 
	stack->Head.Next = stack->Head.Next->Next;
	--stack->Size;
	return 0;
}

void *Top_LinkStack(LinkStack *stack)
{
	if (stack == NULL)
	{
		return NULL;
	}
	//
	return stack->Head.Next;
}

int Size_LinkStack(LinkStack *stack)
{
	if (stack == NULL)
	{
		return 0;
	}
#if 0
	return stack->Size;
#else

	int count = 0;
	StackNode *pCurrent = stack->Head.Next;
	while (pCurrent != NULL)
	{
		++count;
		pCurrent = pCurrent->Next;
	}
	return count;

#endif
}

int Destory_LinkStack(LinkStack *stack)
{
	if (stack == NULL)
	{
		return -1;
	}
	free(stack);
	stack = NULL;
	return 0;
}