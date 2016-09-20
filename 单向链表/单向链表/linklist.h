#include<stdio.h>
#include<stdlib.h>

// ����ָ��Ľṹ��
typedef struct _LINKLISTNODE
{
	struct _LINKLISTNODE *Next;
}LinkListNode;

// ��������Ľṹ��
typedef struct _LINKLIST
{
	LinkListNode head;
	int LinkListLen;
}LinkList;

// ���������ص����������Ǻ���ָ�룬���ڴ�ӡʱ�����û��Լ�����Ĵ�ӡ������
typedef void(*Print)(void *);

// �ȽϺ���ָ��
typedef int(*COMPARE)(void *, void *);

// ��ʼ��
int Init_LinkList(void **LINKLIST);

// ָ��λ�õĲ���
int InsertByPos_LinkList(void *LINKLIST, int Pos, void *Data);

// ͷ��
int FrontInsert_LinkList(void *LINKLIST, void *Data);

// β��
int BackInsert_LinkList(void *LINKLIST, void *Data);

// ɾ��ָ��λ�õ�Ԫ�أ����ԺͲ��뺯�����ʹ�ã��������ݵ��޸ģ��Ȱ���Ҫ�޸ĵ������Ƴ����ٰ���Ҫ�޸ĵ�ֵ����
int EraseByPos_LinkList(void *LINKLIST, int Pos);

// ͷɾ
int FrontErase_LinkList(void *LINKLIST);

// βɾ
int BackErase_LinkList(void *LINKLIST);

// ���������ݵĳ���
int Len_LinkList(void *LINKLIST);

// ���������ݵ�����
int Retrograde_LinkList(void *LINKLIST);

// �����������ݵ�����
int SortExchangePos_LinkList(void *LINKLIST, COMPARE compare);

// ��ӡ������
int Print_LinkList(void *LINKLIST, Print print);

// ���ٵ�����
int Destroy_LinkList(void *LINKLIST);
