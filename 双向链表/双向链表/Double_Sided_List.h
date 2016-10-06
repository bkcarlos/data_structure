#pragma once
#include <stdio.h>
#include<stdlib.h>



typedef struct _DOUBLE_LIST_NODE
{
	// 定义双向链表的前驱和后继
	struct _DOUBLE_LIST_NODE *Pre;
	struct _DOUBLE_LIST_NODE  *Next;
}DoubleListNode, *DoubleSidedList;

/* 单循环链表的13个基本操作 */
// 初始化
int Init_DoubleSidedList(DoubleSidedList *doublesidedlist)
{
	if (doublesidedlist == NULL)
	{
		exit(-1);
	}
	if (*doublesidedlist == NULL)
	{
		*doublesidedlist = (DoubleSidedList)malloc(sizeof(DoubleListNode));
	}
	(*doublesidedlist)->Next = NULL;
	(*doublesidedlist)->Pre = NULL;

	return 0;
}

void Destroy_DoubleSidedList(DoubleSidedList doublesidedlist)
{
	if (doublesidedlist == NULL)
	{
		return;
	}
	free(doublesidedlist);
}

void Clear_DoubleSidedList(DoubleSidedList doublesidedlist)
{
	if (doublesidedlist == NULL)
	{
		return;
	}
	doublesidedlist->Next = NULL;
	doublesidedlist->Pre = NULL;
}

int Empty_DoubleSidedList(DoubleSidedList doublesidedlist)
{
	if (doublesidedlist==NULL)
	{
		return -1;
	}
	// 如果next为空，肯定链表也是空的
	return doublesidedlist->Next == NULL;
	//
}

int Length_DoubleSidedList(DoubleSidedList doublesidedlist)
{
	if (doublesidedlist == NULL)
	{
		return 0;
	}
	int length = 0;
	// 第一个元素的开始的位置在 定义Next开始
	DoubleListNode *pCurrent =doublesidedlist->Next;

	while (pCurrent!= NULL)
	{
		++length;
		pCurrent = pCurrent->Next;
	}
	return length;
}

void * GetElem_DoubleSidedList(DoubleSidedList doublesidedlist, int Pos)
{
	if (doublesidedlist == NULL)
	{
		return NULL;
	}
	if (Pos<0 || Pos>Length_DoubleSidedList(doublesidedlist)-1)
	{
		return NULL;
	}
	DoubleListNode *pCurrent = doublesidedlist->Next;
	int i = 0;
	while (i<Pos)
	{
		pCurrent = pCurrent->Next;
		++i;
	}
	// 返回所在的位置 从 0 开始
	return pCurrent;
}

int  LocateElem_DoubleSidedList(DoubleSidedList doublesidedlist, void* data, int(*compare)(void *data1, void *data2))
{
	if (doublesidedlist==NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -2;
	}
	if (compare == NULL)
	{
		return -4;
	}
	DoubleListNode *Node = (DoubleListNode *)data;
	int i = 0;
	DoubleListNode *pCurrent = doublesidedlist->Next;

	while (pCurrent!= NULL)
	{
		// 必须要传入比较函数
		if (compare(pCurrent, Node))
		{
			return i;
		}
		pCurrent = pCurrent->Next;
		++i;
	}
	return -3;
}

void *PriorElem_DoubleSidedList(DoubleSidedList doublesidedlist, void *data)
{
	if (doublesidedlist == NULL)
	{
		return NULL;
	}
	if (data == NULL)
	{
		return NULL;
	}

	DoubleListNode *pCurrent = doublesidedlist->Next;

	while (pCurrent != NULL)
	{
#if 0

		if (pCurrent->Next==data)
		{
			return pCurrent;
		}

#else

		if (pCurrent == data)
		{
			//这就是双向链表的好处
			return pCurrent->Pre;
		}
		
#endif
		pCurrent = pCurrent->Next;
	}
	return NULL;
}

void* NextElem_DoubleSidedList(DoubleSidedList doublesidedlist, void *data)
{
	if (doublesidedlist == NULL)
	{
		return NULL;
	}
	if (data == NULL)
	{
		return NULL;
	}

	DoubleListNode *pCurrent = doublesidedlist;

	while (pCurrent->Next != NULL)
	{
		if (pCurrent == data)
		{
			return pCurrent->Next;
		}
		pCurrent = pCurrent->Next;
	}
	return NULL;
}

int Insert_DoubleSidedList(DoubleSidedList doublesidedlist, int Pos, void * data)
{
	if (doublesidedlist == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -2;
	}
	if (Pos < 0)
	{
		Pos = 0;
	}
	if (Pos > Length_DoubleSidedList(doublesidedlist))
	{
		Pos = Length_DoubleSidedList(doublesidedlist);
	}

	DoubleListNode *pCurrent = doublesidedlist;

	for (int i = 0; i < Pos; ++i)
	{
		pCurrent = pCurrent->Next;
	}
	DoubleListNode *Node = (DoubleListNode *)data;
	
	// 
	if (Pos==0 && Length_DoubleSidedList(doublesidedlist) == 0)
	{
		// 最前面一个位置插入 && 当前长度为0 插入的结点不存在后继结点
			Node->Next = pCurrent->Next;
			Node->Pre = pCurrent;
			pCurrent->Next = Node;
	}
	else if (Length_DoubleSidedList(doublesidedlist) == Pos)
	{
		// 最后一个结点不存在后继结点
		Node->Next = pCurrent->Next;
		Node->Pre = pCurrent;
		pCurrent->Next = Node;
	}
	else
	{
		Node->Next = pCurrent->Next;
		pCurrent->Next->Pre = Node;
		pCurrent->Next = Node;
		Node->Pre = pCurrent;
	}
	

	return 0;
}

int  DeleteByPos_DoubleSidedList(DoubleSidedList doublesidedlist, int Pos)
{
	if (doublesidedlist == NULL)
	{
		return -1;
	}
	if (Pos<0 || Pos>Length_DoubleSidedList(doublesidedlist) - 1)
	{
		return -2;
	}
	DoubleListNode *pCurrent = doublesidedlist->Next;
	// 找到前驱

	for (int i = 0; i < Pos; ++i)
	{
		pCurrent = pCurrent->Next;
	}
	// 如果删除的是最后一个结点,那么找不到最后一个结点的下一个结点
	if (Pos == Length_DoubleSidedList(doublesidedlist))
	{
		pCurrent->Pre->Next = NULL;
	}
	else
	{
		pCurrent->Next->Pre = pCurrent;
		pCurrent->Next = pCurrent->Next->Next;
	}
	
	return 0;

}

int  DeleteByVal_DoubleSidedList(DoubleSidedList doublesidedlist, void* data)
{
	if (doublesidedlist == NULL)
	{
		return -1;
	}
	DoubleListNode *pCurrent = doublesidedlist->Next;

	while (pCurrent->Next != NULL )
	{
		if (pCurrent == data)
		{
			break;
		}
		pCurrent = pCurrent->Next;
	}
	// 如果是最后一个结点，
	if (pCurrent->Next == NULL)
	{
		pCurrent->Pre->Next = NULL;
	}
	else
	{
		pCurrent->Next->Pre = pCurrent;
		pCurrent->Next = pCurrent->Next->Next;
	}
	
	return 0;
}

void Traverse_DoubleSidedList(DoubleSidedList doublesidedlist, void(*Traverse)(void *data))
{
	if (doublesidedlist == NULL)
	{
		return;
	}
	if (Traverse == NULL)
	{
		return;
	}
	DoubleListNode *pCurrent = doublesidedlist->Next;
	while (pCurrent != NULL)
	{
		Traverse(pCurrent);
		pCurrent = pCurrent->Next;
	}
}