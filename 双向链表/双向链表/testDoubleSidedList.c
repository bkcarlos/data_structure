#include "Double_Sided_List.h"


typedef struct _PEOPLE
{
	DoubleListNode Node;
	char Name[64];
	int age;
}People;

int comparePeople(void *data1, void *data2)
{
	People *p1 = (People *)data1;
	People *p2 = (People *)data2;

	return (p1->age == p2->age);
}

void printPeople(void *data)
{

	People *p = (People *)data;
	printf("%s->%d\n", p->Name, p->age);
}

void test()
{
	People p[10];

	for (int i = 0; i < 10; ++i)
	{
		p[i].Node.Next = NULL;
		p[i].Node.Pre = NULL;
		p[i].age = i + 20;
		p[i].Name[0] = i + 'A';
		p[i].Name[1] = i + 'A';
		p[i].Name[2] = i + 'A';
		p[i].Name[3] = i + 'A';
		p[i].Name[4] =  '\0';

	}

	DoubleSidedList list = NULL;
	Init_DoubleSidedList(&list);

	for (int i = 0; i < 5; ++i)
	{
		Insert_DoubleSidedList(list,i,p+i);
	}


	People *p14 = NULL;

	p14 = PriorElem_DoubleSidedList(list, p+3);
	printf("打印接下来结点的前驱：");
	printPeople(p+3);
	printPeople(p14);

	p14 = NextElem_DoubleSidedList(list, p+3);
	printf("打印接下来结点的后继：");
	printPeople(p+3);
	printPeople(p14);
	printf("%d\n", Length_DoubleSidedList(list));
	Traverse_DoubleSidedList(list, printPeople);

	p14 = GetElem_DoubleSidedList(list, 4);
	printPeople(p14);
	printf("打印接下来结点的是否存在：");
	printPeople(p+2);
	printf("%d\n", LocateElem_DoubleSidedList(list, p+2, comparePeople));


	DeleteByPos_DoubleSidedList(list, 2);
	Traverse_DoubleSidedList(list, printPeople);

	DeleteByVal_DoubleSidedList(list, p+4);
	Traverse_DoubleSidedList(list, printPeople);


	Clear_DoubleSidedList(list);
	printf("链表是否为空：%s\n", Empty_DoubleSidedList(list) ? "是" : "否");

	Destroy_DoubleSidedList(list);
	printf("链表是否为空：%s\n", Empty_DoubleSidedList(list) ? "是" : "否");
}

int main()
{
	test();
	system("pause");
	return 0;


}