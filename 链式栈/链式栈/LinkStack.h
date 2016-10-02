#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct _STACKNODE
{
	struct _STACKNODE *Next;
}StackNode;



typedef struct _LINKSTACK
{
	// 栈的数据（其实是地址）
	StackNode Head;
	// 栈的长度
	int Size;
}LinkStack;

//初始化
int Init_LinkStack(void **linkstack)
{
	if (linkstack == NULL)
	{
		exit(-1);
	}

	// 将数据类型进行转化，便于后面的操作 
	LinkStack **stack = (LinkStack **)linkstack;
	
	// 检查栈是否已经有可用的内存
	if (*stack == NULL)
	{
		*stack = (LinkStack *)malloc(sizeof(LinkStack));
	}
	// 对开辟空间的检测
	if (*stack == NULL)
	{
		exit(-2);
	}
	
	// 将数据和长度初始化
	(*stack)->Head.Next = NULL;
	(*stack)->Size = 0;

	return 0;
}


// 入栈
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

	// 将数据类型进行转化，便于后面的操作 
	LinkStack *stack = (LinkStack *)linkstack;
	StackNode *data = (StackNode *)Data;
	
	data->Next = stack->Head.Next;
	stack->Head.Next = data;
	++stack->Size;

	return 0;
}


// 出栈
int Pop_LinkStack(void *linkstack)
{
	if (linkstack == NULL)
	{
		return -1;
	}
	// 将数据类型进行转化，便于后面的操作 
	LinkStack *stack = (LinkStack *)linkstack;
#if 0	
	// 栈为空，不能出栈
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
	// 将数据类型进行转化，便于后面的操作 
	LinkStack *stack = (LinkStack *)linkstack;

	return stack->Head.Next;

}

int Size_LinkStack(void *linkstack)
{
	if (linkstack == NULL)
	{
		return 0;
	}
	// 将数据类型进行转化，便于后面的操作 
	LinkStack *stack = (LinkStack *)linkstack;
	return stack->Size;
}

int Destory_LinkStack(void *linkstack)
{
	if (linkstack == NULL)
	{
		return -1;
	}
	// 将数据类型进行转化，便于后面的操作 
	LinkStack *stack = (LinkStack *)linkstack;

	if (stack->Head.Next != NULL)
	{
		stack->Head.Next = NULL;
	}
	stack->Size = 0;
	return 0;
}