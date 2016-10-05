
#include "Circular_List.h"

/* 单循环链表的13个基本操作 */
int Init_CircularList(CircularList **circularlist)
{ /* 操作结果：构造一个空的线性表circularlist */
	if (circularlist == NULL)
	{
		exit(-1);
	}
	*circularlist = (CircularList *)malloc(sizeof(CircularList)); /* 产生头结点，并使circularlist指向此头结点 */
	if (!*circularlist) /* 存储分配失败 */
		exit(-2);
	(*circularlist)->next = *circularlist; /* 指针域指向头结点 */
	return 0;
}

void Destroy_CircularList(CircularList *circularlist)
{ /* 操作结果：销毁线性表circularlist */
	if (circularlist == NULL)
	{
		return;
	}
	if (circularlist != NULL)
		free(circularlist);
	circularlist = NULL;
}

void Clear_CircularList(CircularList *circularlist) /* 改变circularlist */
{ /* 初始条件：线性表circularlist已存在。操作结果：将circularlist重置为空表 */
	if (circularlist == NULL)
	{
		return;
	}
	circularlist->next = circularlist;
}

int Empty_CircularList(CircularList *circularlist)
{ /* 初始条件：线性表circularlist已存在。操作结果：若circularlist为空表，则返回TRUE，否则返回FALSE */
	if (circularlist == NULL)
	{
		return 0;
	}
	if (circularlist->next == circularlist) /* 空 */
		return 1;
	else
		return 0;
}

int Length_CircularList(CircularList *circularlist)
{ /* 初始条件：circularlist已存在。操作结果：返回circularlist中数据元素个数 */
	if (circularlist == NULL)
	{
		return -1;
	}
	int i = 0;
	ListNode *pCurrent = circularlist->next; /* p指向头结点 */
	while (pCurrent != circularlist) /* 没到表尾 */
	{
		i++;
		pCurrent = pCurrent->next;
	}
	return i;
}

void * GetElem_CircularList(CircularList *circularlist, int Pos)
{ /* 当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR */

	if (circularlist == NULL)
	{
		return NULL;
	}
	int j = 0; /* 初始化，j为计数器 */
	ListNode *pCurrent = circularlist->next; /* p指向第一个结点 */
	if (Pos < 0 || Pos > Length_CircularList(circularlist)) /* 第i个元素不存在 */
		return NULL;
	while (j < Pos)
	{ /* 顺指针向后查找，直到p指向第i个元素 */
		pCurrent = pCurrent->next;
		j++;
	}
	return (void *)pCurrent;
}

int  LocateElem_CircularList(CircularList *circularlist, void* data, int(*compare)(void *data1, void *data2))
{ /* 初始条件：线性表circularlist已存在，compare()是数据元素判定函数 */
  /* 操作结果：返回circularlist中第1个与e满足关系compare()的数据元素的位序。*/
  /*           若这样的数据元素不存在，则返回值为0 */

	if (circularlist == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -2;
	}
	if (compare == NULL)
	{
		return -3;
	}
	int i = 0;
	ListNode *pCurrent = circularlist->next; /* p指向第一个结点 */
	while (pCurrent != circularlist)
	{
		// 这儿不能使用比较地址的办法来实现，因为可能需要比较的值来至链表的外部
		if (compare(pCurrent, data)) /* 满足关系 */
			return i;
		pCurrent = pCurrent->next;
		++i;
	}
	return -1;
}

void *PriorElem_CircularList(CircularList *circularlist, void *data, int(*compare)(void *data1, void *data2))
{ /* 初始条件：线性表circularlist已存在 */
  /* 操作结果：若cur_e是circularlist的数据元素，且不是第一个，则用pre_e返回它的前驱，*/
  /*           否则操作失败，pre_e无定义 */


	if (circularlist == NULL)
	{
		return NULL;
	}
	if (data == NULL)
	{
		return NULL;
	}
	if (compare == NULL)
	{
		return NULL;
	}

	ListNode *pCurrent = circularlist->next; /* p指向第一个结点 */

	while (pCurrent != circularlist) /* p没到表尾 */
	{
		// 其实这儿也可以不使用比较函数指针，想知道为什么，看 DeleteByVal_CircularList
		// 但是这样的用法仅限于比较的两个数据现在都是单循环链表里面的一个值
		if (compare(pCurrent->next, data))
		{
			return pCurrent;
		}
		pCurrent = pCurrent->next;
	}
	return NULL; /* 操作失败 */
}

void* NextElem_CircularList(CircularList *circularlist, void *data, int(*compare)(void *data1, void *data2))
{ /* 初始条件：线性表circularlist已存在 */
  /* 操作结果：若cur_e是circularlist的数据元素，且不是最后一个，则用next_e返回它的后继，*/
  /*           否则操作失败，next_e无定义 */

	if (circularlist == NULL)
	{
		return NULL;
	}
	if (data == NULL)
	{
		return NULL;
	}
	if (compare == NULL)
	{
		return NULL;
	}

	ListNode *pCurrent = circularlist->next; /* p指向第一个结点 */
	while (pCurrent != circularlist) /* p没到表尾 */
	{
		if (compare(pCurrent, data))
		{
			return pCurrent->next;
		}
		pCurrent = pCurrent->next;
	}
	return NULL; /* 操作失败 */
}

int Insert_CircularList(CircularList *circularlist, int Pos, void * data) /* 改变circularlist */
{ /* 在circularlist的第i个位置之前插入元素e */

	if (circularlist == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -2;
	}


	ListNode *pCurrent = circularlist; /* p指向头结点 */
	int j = 0;
	if (Pos < 0 || Pos > Length_CircularList(circularlist)) /* 无法在第i个元素之前插入 */
	{
		return -3;
	}
	while (j < Pos) /* 寻找第i-1个结点 */
	{
		pCurrent = pCurrent->next;
		j++;
	}
	((ListNode *)data)->next = pCurrent->next;
	pCurrent->next = data;

	return 0;
}

int  DeleteByPos_CircularList(CircularList *circularlist, int Pos) /* 改变circularlist */
{ /* 删除circularlist的第i个元素，并由e返回其值 */

	if (circularlist == NULL)
	{
		return -1;
	}

	ListNode *pCurrent = circularlist; /* p指向头结点 */
	int j = 0;
	if (Pos < 0 || Pos > Length_CircularList(circularlist) - 1) /* 第i个元素不存在 */
		return -1;
	// 找到被删除结点的前驱
	while (j < Pos) /* 寻找第i-1个结点 */
	{
		pCurrent = pCurrent->next;
		j++;
	}
	pCurrent->next = pCurrent->next->next;
	return 0;
}

int  DeleteByVal_CircularList(CircularList *circularlist, void* data) /* 改变circularlist */
{ /* 删除circularlist的第i个元素，并由e返回其值 */

	if (circularlist == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -2;
	}

	ListNode *pCurrent = circularlist; /* p指向头结点 */
	while (pCurrent->next != circularlist)
	{
		// 找到被删除结点的前驱
		if (pCurrent->next == data)
		{
			pCurrent->next = pCurrent->next->next;
			break;
		}
		pCurrent = pCurrent->next;

	}
	pCurrent = pCurrent->next;
	return 0;
}





void Traverse_CircularList(CircularList *circularlist, void(*Traverse)(void *data))
{ /* 初始条件：circularlist已存在。操作结果：依次对circularlist的每个数据元素调用函数vi() */

	if (circularlist == NULL)
	{
		return;
	}
	if (Traverse == NULL)
	{
		return;
	}

	ListNode *pCurrent = circularlist->next; /* p指向首元结点 */
	while (pCurrent != circularlist) /* p不指向头结点 */
	{
		Traverse(pCurrent);
		pCurrent = pCurrent->next;
	}
	printf("\n");
}
