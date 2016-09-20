#include "linklist.h"

// 初始化
int Init_LinkList(void ** LINKLIST)
{
	// 对传入的参数进行检查
	if (LINKLIST == NULL)
	{
		exit(-1);
	}
	// 开辟空间
	LinkList *linklist =(LinkList *) malloc(sizeof(LinkList));
	if (linklist == NULL)
	{
		// 空间开辟是否成功
		exit(-2);
	}

	// 赋初始值
	linklist->head.Next = NULL;
	linklist->LinkListLen = 0;

	// 指针间的间接赋值
	*LINKLIST = (void *)linklist;

	return 0;
}

// 指定位置插入
int InsertByPos_LinkList(void * LINKLIST, int Pos, void * Data)
{
	if (LINKLIST == NULL)
	{
		return -1;
	}
	if (Data == NULL)
	{
		return -2;
	}

	// 对传入的参数进行类型强转
	LinkList *linklist = (LinkList *)LINKLIST;

	// 对 Pos 合理化处理
	if (Pos < 0)
	{
		Pos = 0;
	}
	if (Pos > linklist->LinkListLen)
	{
		Pos = linklist->LinkListLen;
	}

	LinkListNode *Current = &(linklist->head);

	for (int i = 0; i < Pos; ++i)
	{
		Current = Current->Next;
	}
	// 转化指针类型
	LinkListNode *data = (LinkListNode *)Data;

	// 将传入的值加入到链表中
	data->Next = Current->Next;
	Current->Next = data;

	++ linklist->LinkListLen;

	return 0;
}

int FrontInsert_LinkList(void * LINKLIST, void * Data)
{
	if (LINKLIST == NULL)
	{
		return -1;
	}
	if (Data == NULL)
	{
		return -2;
	}
	// 直接调用函数 实现
	InsertByPos_LinkList(LINKLIST, 0, Data);
	return 0;
}

int BackInsert_LinkList(void * LINKLIST, void * Data)
{
	if (LINKLIST == NULL)
	{
		return -1;
	}
	if (Data == NULL)
	{
		return -2;
	}
	LinkList *linklist = (LinkList *)LINKLIST;
	// 直接调用函数实现
	InsertByPos_LinkList(LINKLIST, linklist->LinkListLen, Data);

	return 0;
}

int EraseByPos_LinkList(void * LINKLIST, int Pos)
{
	if (LINKLIST == NULL)
	{
		return -1;
	}

	LinkList *linklist = (LinkList *)LINKLIST;

	// 检测删除位置的合理性
	if (Pos < 0 || Pos>=linklist->LinkListLen)
	{
		return -2;
	}
	

	LinkListNode *Current =&(linklist->head);

	/* 为什么需要检测Current->Next->Next!=NULL不为空，因为后面需要直接将Current->Next->Next赋值给Current->Next
	 * 如果为空的话，访问会出错
	 */

	
	for (int i = 0; i < Pos && Current->Next->Next!=NULL ; ++i)
	{
		Current = Current->Next;
	}

	// 直接越过需要删除的值
	Current->Next = Current->Next->Next;

	// 维护链表的长度
	--linklist->LinkListLen;

	return 0;
}

int FrontErase_LinkList(void * LINKLIST)
{
	if (LINKLIST == NULL)
	{
		return -1;
	}
	// 调用函数实现
	EraseByPos_LinkList(LINKLIST, 0);
	return 0;
}

int BackErase_LinkList(void * LINKLIST)
{
	if (LINKLIST == NULL)
	{
		return -1;
	}
	// 调用函数实现
	LinkList *linklist = (LinkList *)LINKLIST;
	EraseByPos_LinkList(LINKLIST, linklist->LinkListLen);

	return 0;
}

// 返回链表数据的长度
int Len_LinkList(void * LINKLIST)
{
	if (LINKLIST == NULL)
	{
		return -1;
	}
	LinkList *linklist = (LinkList *)LINKLIST;

	return linklist->LinkListLen;
}

// 将链表的数据逆置
int Retrograde_LinkList(void * LINKLIST)
{

	if (LINKLIST == NULL)
	{
		return -1;
	}

	LinkList *linklist = (LinkList *)LINKLIST;
#if 1
	// 为什么要取(linklist->head)的地址
	// 因为 head 里面存的是数据的首地址

	LinkListNode *pPre = &(linklist->head);
	LinkListNode *Current = pPre->Next;

	// pPre 里面存储的是第一个元素的地址
	pPre = NULL;

	while (Current!= NULL)
	{
		// 用一个临时变量来缓存pPre;
		LinkListNode *Temp = pPre;
		// 让pPre指向current
		pPre = Current;
		// current 向前移动到下一个元素
		Current = Current->Next;
		// 将next指针指向它原来的直接前驱
		pPre->Next = Temp;
	}
	// 最后将 linklist 的 head 指向原来的最后一个数据的地址
	linklist->head.Next = pPre;
#else
	// 现将最后一个数据的位置缓存下来
	LinkListNode *kpBack= &(linklist->head);
	while (kpBack->Next != NULL)
	{
		kpBack = kpBack->Next;
	}

	int flag = 1;
	while (flag)
	{
		/*
		 * 第二种方式比较耗时间和内存，因为每次都需要循环遍历找到当前的末尾，让后将它的前驱置空，后继指向它的前驱
		*/
		LinkListNode *pPre = &(linklist->head);
		LinkListNode *Current = pPre->Next;

		// 循环遍历找到最后一个的前驱
		while (Current->Next != NULL )
		{
			pPre = pPre->Next;
			Current = Current->Next;
		}
		if (pPre ==linklist)
		{
			flag = 0;
			break;
		}
		// 前驱置空
		pPre->Next = NULL;
		// next 指向前驱
		Current->Next = pPre;
	}
	// 最后将head指向原来的最后一个元素
	linklist->head.Next = kpBack;
#endif

	return 0;
}


// 排序
int SortExchangePos_LinkList(void * LINKLIST,COMPARE compare)
{
	if (LINKLIST == NULL)
	{
		return -1;
	}
	LinkList *linklist = (LinkList *)LINKLIST;

	LinkListNode *Pre = linklist->head.Next;
	int IsSort=1;

	// 这儿借鉴了冒泡排序的有标记位的办法
	while (Pre!=NULL  && IsSort)
	{
		IsSort = 0;
		for (LinkListNode *pCurrent = linklist->head.Next; pCurrent!= NULL && pCurrent->Next != NULL ; pCurrent = pCurrent->Next)
		{
			if(compare(pCurrent,pCurrent->Next)< 0) // 需要自己写比较函数，比较函数待优化
			{
				LinkListNode *TempCurrent = &(linklist->head);

			while (TempCurrent!=NULL && TempCurrent->Next!=NULL && TempCurrent->Next != pCurrent)
				TempCurrent=TempCurrent->Next;  //找到pCurrent的直接前驱

			LinkListNode *Temp = pCurrent->Next->Next;  // 缓存pCurrent 的后继的后继
			TempCurrent->Next = pCurrent->Next;  //
			pCurrent->Next->Next = pCurrent;
			pCurrent->Next = Temp;
			IsSort = 1;
			}
		}
		Pre = Pre->Next;
	}
	return 0;
}

int Print_LinkList(void * LINKLIST, Print print)
{
	if (LINKLIST == NULL)
	{
		return -1;
	}
	if (print == NULL)
	{
		return -2;
	}
	LinkList *linklist = (LinkList *)LINKLIST;

	LinkListNode *Current = linklist->head.Next;

	while (Current != NULL)
	{
		print(Current);
		Current = Current->Next;
	}

	printf("……………………………………………………\n");

	return 0;
}

int Destroy_LinkList(void * LINKLIST)
{
	if (LINKLIST == NULL)
	{
		return -1;
	}
	LinkList *linklist = (LinkList *)LINKLIST;

	if (linklist != NULL)
	{
		free(linklist);
	}
	return 0;
}


