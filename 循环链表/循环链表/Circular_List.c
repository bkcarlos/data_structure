
#include "Circular_List.h"

/* ��ѭ�������13���������� */
int Init_CircularList(CircularList **circularlist)
{ /* �������������һ���յ����Ա�circularlist */
	if (circularlist == NULL)
	{
		exit(-1);
	}
	*circularlist = (CircularList *)malloc(sizeof(CircularList)); /* ����ͷ��㣬��ʹcircularlistָ���ͷ��� */
	if (!*circularlist) /* �洢����ʧ�� */
		exit(-2);
	(*circularlist)->next = *circularlist; /* ָ����ָ��ͷ��� */
	return 0;
}

void Destroy_CircularList(CircularList *circularlist)
{ /* ����������������Ա�circularlist */
	if (circularlist == NULL)
	{
		return;
	}
	if (circularlist != NULL)
		free(circularlist);
	circularlist = NULL;
}

void Clear_CircularList(CircularList *circularlist) /* �ı�circularlist */
{ /* ��ʼ���������Ա�circularlist�Ѵ��ڡ������������circularlist����Ϊ�ձ� */
	if (circularlist == NULL)
	{
		return;
	}
	circularlist->next = circularlist;
}

int Empty_CircularList(CircularList *circularlist)
{ /* ��ʼ���������Ա�circularlist�Ѵ��ڡ������������circularlistΪ�ձ��򷵻�TRUE�����򷵻�FALSE */
	if (circularlist == NULL)
	{
		return 0;
	}
	if (circularlist->next == circularlist) /* �� */
		return 1;
	else
		return 0;
}

int Length_CircularList(CircularList *circularlist)
{ /* ��ʼ������circularlist�Ѵ��ڡ��������������circularlist������Ԫ�ظ��� */
	if (circularlist == NULL)
	{
		return -1;
	}
	int i = 0;
	ListNode *pCurrent = circularlist->next; /* pָ��ͷ��� */
	while (pCurrent != circularlist) /* û����β */
	{
		i++;
		pCurrent = pCurrent->next;
	}
	return i;
}

void * GetElem_CircularList(CircularList *circularlist, int Pos)
{ /* ����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR */

	if (circularlist == NULL)
	{
		return NULL;
	}
	int j = 0; /* ��ʼ����jΪ������ */
	ListNode *pCurrent = circularlist->next; /* pָ���һ����� */
	if (Pos < 0 || Pos > Length_CircularList(circularlist)) /* ��i��Ԫ�ز����� */
		return NULL;
	while (j < Pos)
	{ /* ˳ָ�������ң�ֱ��pָ���i��Ԫ�� */
		pCurrent = pCurrent->next;
		j++;
	}
	return (void *)pCurrent;
}

int  LocateElem_CircularList(CircularList *circularlist, void* data, int(*compare)(void *data1, void *data2))
{ /* ��ʼ���������Ա�circularlist�Ѵ��ڣ�compare()������Ԫ���ж����� */
  /* �������������circularlist�е�1����e�����ϵcompare()������Ԫ�ص�λ��*/
  /*           ������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */

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
	ListNode *pCurrent = circularlist->next; /* pָ���һ����� */
	while (pCurrent != circularlist)
	{
		// �������ʹ�ñȽϵ�ַ�İ취��ʵ�֣���Ϊ������Ҫ�Ƚϵ�ֵ����������ⲿ
		if (compare(pCurrent, data)) /* �����ϵ */
			return i;
		pCurrent = pCurrent->next;
		++i;
	}
	return -1;
}

void *PriorElem_CircularList(CircularList *circularlist, void *data, int(*compare)(void *data1, void *data2))
{ /* ��ʼ���������Ա�circularlist�Ѵ��� */
  /* �����������cur_e��circularlist������Ԫ�أ��Ҳ��ǵ�һ��������pre_e��������ǰ����*/
  /*           �������ʧ�ܣ�pre_e�޶��� */


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

	ListNode *pCurrent = circularlist->next; /* pָ���һ����� */

	while (pCurrent != circularlist) /* pû����β */
	{
		// ��ʵ���Ҳ���Բ�ʹ�ñȽϺ���ָ�룬��֪��Ϊʲô���� DeleteByVal_CircularList
		// �����������÷������ڱȽϵ������������ڶ��ǵ�ѭ�����������һ��ֵ
		if (compare(pCurrent->next, data))
		{
			return pCurrent;
		}
		pCurrent = pCurrent->next;
	}
	return NULL; /* ����ʧ�� */
}

void* NextElem_CircularList(CircularList *circularlist, void *data, int(*compare)(void *data1, void *data2))
{ /* ��ʼ���������Ա�circularlist�Ѵ��� */
  /* �����������cur_e��circularlist������Ԫ�أ��Ҳ������һ��������next_e�������ĺ�̣�*/
  /*           �������ʧ�ܣ�next_e�޶��� */

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

	ListNode *pCurrent = circularlist->next; /* pָ���һ����� */
	while (pCurrent != circularlist) /* pû����β */
	{
		if (compare(pCurrent, data))
		{
			return pCurrent->next;
		}
		pCurrent = pCurrent->next;
	}
	return NULL; /* ����ʧ�� */
}

int Insert_CircularList(CircularList *circularlist, int Pos, void * data) /* �ı�circularlist */
{ /* ��circularlist�ĵ�i��λ��֮ǰ����Ԫ��e */

	if (circularlist == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -2;
	}


	ListNode *pCurrent = circularlist; /* pָ��ͷ��� */
	int j = 0;
	if (Pos < 0 || Pos > Length_CircularList(circularlist)) /* �޷��ڵ�i��Ԫ��֮ǰ���� */
	{
		return -3;
	}
	while (j < Pos) /* Ѱ�ҵ�i-1����� */
	{
		pCurrent = pCurrent->next;
		j++;
	}
	((ListNode *)data)->next = pCurrent->next;
	pCurrent->next = data;

	return 0;
}

int  DeleteByPos_CircularList(CircularList *circularlist, int Pos) /* �ı�circularlist */
{ /* ɾ��circularlist�ĵ�i��Ԫ�أ�����e������ֵ */

	if (circularlist == NULL)
	{
		return -1;
	}

	ListNode *pCurrent = circularlist; /* pָ��ͷ��� */
	int j = 0;
	if (Pos < 0 || Pos > Length_CircularList(circularlist) - 1) /* ��i��Ԫ�ز����� */
		return -1;
	// �ҵ���ɾ������ǰ��
	while (j < Pos) /* Ѱ�ҵ�i-1����� */
	{
		pCurrent = pCurrent->next;
		j++;
	}
	pCurrent->next = pCurrent->next->next;
	return 0;
}

int  DeleteByVal_CircularList(CircularList *circularlist, void* data) /* �ı�circularlist */
{ /* ɾ��circularlist�ĵ�i��Ԫ�أ�����e������ֵ */

	if (circularlist == NULL)
	{
		return -1;
	}
	if (data == NULL)
	{
		return -2;
	}

	ListNode *pCurrent = circularlist; /* pָ��ͷ��� */
	while (pCurrent->next != circularlist)
	{
		// �ҵ���ɾ������ǰ��
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
{ /* ��ʼ������circularlist�Ѵ��ڡ�������������ζ�circularlist��ÿ������Ԫ�ص��ú���vi() */

	if (circularlist == NULL)
	{
		return;
	}
	if (Traverse == NULL)
	{
		return;
	}

	ListNode *pCurrent = circularlist->next; /* pָ����Ԫ��� */
	while (pCurrent != circularlist) /* p��ָ��ͷ��� */
	{
		Traverse(pCurrent);
		pCurrent = pCurrent->next;
	}
	printf("\n");
}
