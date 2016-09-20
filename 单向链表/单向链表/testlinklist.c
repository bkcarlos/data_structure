#include"linklist.h"

typedef struct _STUDENT
{
	LinkListNode node;
	char name[64];
	int age;
}Student;

void printStu(void *STU)
{
	if (STU == NULL)
		return;
	Student *stu = (Student *)STU;
	printf("%s->%d\n", stu->name, stu->age);
}

int compare(void *Data1, void *Data2)
{
	if (Data1 == NULL && Data2 != NULL)
		return 1;
	if (Data2 == NULL && Data1 != NULL)
		return -1;
	if (Data1 == NULL && Data2 != NULL)
		return 0;
	Student *data1 = (Student *)Data1;
	Student *data2 = (Student *)Data2;

	if (data1->age > data2->age)
		return -1;
	else if (data1->age < data2->age)
		return 1;
	else
		return 0;
}

void test()
{
	Student p1 = { NULL,"aaa",13 };
	Student p2 = { NULL,"bbb",14 };
	Student p3 = { NULL,"ccc",15 };
	Student p4 = { NULL,"ddd",16 };
	Student p5 = { NULL,"eee",17 };
	Student p6 = { NULL,"fff",18 };

	LinkList *linklist = NULL;
	Init_LinkList(&linklist);

	InsertByPos_LinkList(linklist, 0, &p1);
	InsertByPos_LinkList(linklist, 0, &p2);
	InsertByPos_LinkList(linklist, 0, &p3);
	InsertByPos_LinkList(linklist, 0, &p4);
	//FrontInsert_LinkList(linklist, &p5);
	//BackInsert_LinkList(linklist, &p6);
	Print_LinkList(linklist, printStu);

	EraseByPos_LinkList(linklist, 2);
	Print_LinkList(linklist, printStu);

	FrontInsert_LinkList(linklist,&p5);
	Print_LinkList(linklist, printStu);

	BackInsert_LinkList(linklist,&p6);
	Print_LinkList(linklist, printStu);

	FrontErase_LinkList(linklist);
	Print_LinkList(linklist, printStu);

	BackErase_LinkList(linklist);
	Print_LinkList(linklist, printStu);

	SortExchangePos_LinkList(linklist,compare);
	Print_LinkList(linklist, printStu);

	Retrograde_LinkList(linklist);
	Print_LinkList(linklist, printStu);

	Destroy_LinkList(linklist);

}

int main()
{

	
	test();

	system("pause");
	return 0;
}