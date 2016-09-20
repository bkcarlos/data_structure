#include "linklist.h"

// ��ʼ��
int Init_LinkList(void ** LINKLIST)
{
	// �Դ���Ĳ������м��
	if (LINKLIST == NULL)
	{
		exit(-1);
	}
	// ���ٿռ�
	LinkList *linklist =(LinkList *) malloc(sizeof(LinkList));
	if (linklist == NULL)
	{
		// �ռ俪���Ƿ�ɹ�
		exit(-2);
	}

	// ����ʼֵ
	linklist->head.Next = NULL;
	linklist->LinkListLen = 0;

	// ָ���ļ�Ӹ�ֵ
	*LINKLIST = (void *)linklist;

	return 0;
}

// ָ��λ�ò���
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

	// �Դ���Ĳ�����������ǿת
	LinkList *linklist = (LinkList *)LINKLIST;

	// �� Pos ��������
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
	// ת��ָ������
	LinkListNode *data = (LinkListNode *)Data;

	// �������ֵ���뵽������
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
	// ֱ�ӵ��ú��� ʵ��
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
	// ֱ�ӵ��ú���ʵ��
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

	// ���ɾ��λ�õĺ�����
	if (Pos < 0 || Pos>=linklist->LinkListLen)
	{
		return -2;
	}
	

	LinkListNode *Current =&(linklist->head);

	/* Ϊʲô��Ҫ���Current->Next->Next!=NULL��Ϊ�գ���Ϊ������Ҫֱ�ӽ�Current->Next->Next��ֵ��Current->Next
	 * ���Ϊ�յĻ������ʻ����
	 */

	
	for (int i = 0; i < Pos && Current->Next->Next!=NULL ; ++i)
	{
		Current = Current->Next;
	}

	// ֱ��Խ����Ҫɾ����ֵ
	Current->Next = Current->Next->Next;

	// ά������ĳ���
	--linklist->LinkListLen;

	return 0;
}

int FrontErase_LinkList(void * LINKLIST)
{
	if (LINKLIST == NULL)
	{
		return -1;
	}
	// ���ú���ʵ��
	EraseByPos_LinkList(LINKLIST, 0);
	return 0;
}

int BackErase_LinkList(void * LINKLIST)
{
	if (LINKLIST == NULL)
	{
		return -1;
	}
	// ���ú���ʵ��
	LinkList *linklist = (LinkList *)LINKLIST;
	EraseByPos_LinkList(LINKLIST, linklist->LinkListLen);

	return 0;
}

// �����������ݵĳ���
int Len_LinkList(void * LINKLIST)
{
	if (LINKLIST == NULL)
	{
		return -1;
	}
	LinkList *linklist = (LinkList *)LINKLIST;

	return linklist->LinkListLen;
}

// ���������������
int Retrograde_LinkList(void * LINKLIST)
{

	if (LINKLIST == NULL)
	{
		return -1;
	}

	LinkList *linklist = (LinkList *)LINKLIST;
#if 1
	// ΪʲôҪȡ(linklist->head)�ĵ�ַ
	// ��Ϊ head �����������ݵ��׵�ַ

	LinkListNode *pPre = &(linklist->head);
	LinkListNode *Current = pPre->Next;

	// pPre ����洢���ǵ�һ��Ԫ�صĵ�ַ
	pPre = NULL;

	while (Current!= NULL)
	{
		// ��һ����ʱ����������pPre;
		LinkListNode *Temp = pPre;
		// ��pPreָ��current
		pPre = Current;
		// current ��ǰ�ƶ�����һ��Ԫ��
		Current = Current->Next;
		// ��nextָ��ָ����ԭ����ֱ��ǰ��
		pPre->Next = Temp;
	}
	// ��� linklist �� head ָ��ԭ�������һ�����ݵĵ�ַ
	linklist->head.Next = pPre;
#else
	// �ֽ����һ�����ݵ�λ�û�������
	LinkListNode *kpBack= &(linklist->head);
	while (kpBack->Next != NULL)
	{
		kpBack = kpBack->Next;
	}

	int flag = 1;
	while (flag)
	{
		/*
		 * �ڶ��ַ�ʽ�ȽϺ�ʱ����ڴ棬��Ϊÿ�ζ���Ҫѭ�������ҵ���ǰ��ĩβ���ú�����ǰ���ÿգ����ָ������ǰ��
		*/
		LinkListNode *pPre = &(linklist->head);
		LinkListNode *Current = pPre->Next;

		// ѭ�������ҵ����һ����ǰ��
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
		// ǰ���ÿ�
		pPre->Next = NULL;
		// next ָ��ǰ��
		Current->Next = pPre;
	}
	// ���headָ��ԭ�������һ��Ԫ��
	linklist->head.Next = kpBack;
#endif

	return 0;
}


// ����
int SortExchangePos_LinkList(void * LINKLIST,COMPARE compare)
{
	if (LINKLIST == NULL)
	{
		return -1;
	}
	LinkList *linklist = (LinkList *)LINKLIST;

	LinkListNode *Pre = linklist->head.Next;
	int IsSort=1;

	// ��������ð��������б��λ�İ취
	while (Pre!=NULL  && IsSort)
	{
		IsSort = 0;
		for (LinkListNode *pCurrent = linklist->head.Next; pCurrent!= NULL && pCurrent->Next != NULL ; pCurrent = pCurrent->Next)
		{
			if(compare(pCurrent,pCurrent->Next)< 0) // ��Ҫ�Լ�д�ȽϺ������ȽϺ������Ż�
			{
				LinkListNode *TempCurrent = &(linklist->head);

			while (TempCurrent!=NULL && TempCurrent->Next!=NULL && TempCurrent->Next != pCurrent)
				TempCurrent=TempCurrent->Next;  //�ҵ�pCurrent��ֱ��ǰ��

			LinkListNode *Temp = pCurrent->Next->Next;  // ����pCurrent �ĺ�̵ĺ��
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

	printf("����������������������������������������\n");

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


