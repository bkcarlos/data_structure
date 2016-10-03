#include<stdio.h>
#include<stdlib.h>
#include <string.h>

typedef struct _ORDERQUEUE
{
	// ����
	void ** Data;
	
	// ���ݳ���
	int Size;

	// ��������
	int Capacity;
}OrderQueue;


int Init_OrderQueue(void **orderqueue, int capacity);
int Push_OrderQueue(void *orderqueue, void *data);
int Pop_OrderQueue(void *orderqueue);
void *Back_OrderQueue(void *orderqueue);
void *Front_OrderQueue(void *orderqueue);
int Destory_OrderQueue(void *orderqueue);
int Size_OrderQueue(void *orderqueue);