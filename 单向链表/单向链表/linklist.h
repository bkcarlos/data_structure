#include<stdio.h>
#include<stdlib.h>

// 定义指针的结构体
typedef struct _LINKLISTNODE
{
	struct _LINKLISTNODE *Next;
}LinkListNode;

// 定义链表的结构体
typedef struct _LINKLIST
{
	LinkListNode head;
	int LinkListLen;
}LinkList;

// 定义两个回调函数，就是函数指针，用于打印时调用用户自己定义的打印函数，
typedef void(*Print)(void *);

// 比较函数指针
typedef int(*COMPARE)(void *, void *);

// 初始化
int Init_LinkList(void **LINKLIST);

// 指定位置的插入
int InsertByPos_LinkList(void *LINKLIST, int Pos, void *Data);

// 头插
int FrontInsert_LinkList(void *LINKLIST, void *Data);

// 尾插
int BackInsert_LinkList(void *LINKLIST, void *Data);

// 删除指定位置的元素，可以和插入函数配合使用，进行数据的修改，先把需要修改的数据移除，再把需要修改的值插入
int EraseByPos_LinkList(void *LINKLIST, int Pos);

// 头删
int FrontErase_LinkList(void *LINKLIST);

// 尾删
int BackErase_LinkList(void *LINKLIST);

// 单链表数据的长度
int Len_LinkList(void *LINKLIST);

// 单链表数据的逆置
int Retrograde_LinkList(void *LINKLIST);

// 单链表中数据的排序
int SortExchangePos_LinkList(void *LINKLIST, COMPARE compare);

// 打印单链表
int Print_LinkList(void *LINKLIST, Print print);

// 销毁单链表
int Destroy_LinkList(void *LINKLIST);
