#include<stdio.h>
#include<stdlib.h>

typedef struct _LISTNODE
{
	struct _LISTNODE *next;
}ListNode, CircularList;

/* 单循环链表的13个基本操作 */
int Init_CircularList(CircularList **circularlist);

void Destroy_CircularList(CircularList *circularlist);

void Clear_CircularList(CircularList *circularlist);

int Empty_CircularList(CircularList *circularlist);

int Length_CircularList(CircularList *circularlist);

void * GetElem_CircularList(CircularList *circularlist, int Pos);

int  LocateElem_CircularList(CircularList *circularlist, void* data, int(*compare)(void *data1, void *data2));

void *PriorElem_CircularList(CircularList *circularlist, void *data, int(*compare)(void *data1, void *data2));

void* NextElem_CircularList(CircularList *circularlist, void *data, int(*compare)(void *data1, void *data2));

int Insert_CircularList(CircularList *circularlist, int Pos, void * data);

int  DeleteByPos_CircularList(CircularList *circularlist, int Pos);

int  DeleteByVal_CircularList(CircularList *circularlist, void* data);

void Traverse_CircularList(CircularList *circularlist, void(*Traverse)(void *data));
