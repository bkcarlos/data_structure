#include "Circular_List.h"


typedef struct _PEOPLE
{
	ListNode Next;
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
	People p1 = { NULL,"aaa", 19 };
	People p2 = { NULL,"bbb", 20 };
	People p3 = { NULL,"ccc", 21 };
	People p4 = { NULL,"ddd", 23 };
	People p5 = { NULL,"eee", 24 };
	People p6 = { NULL,"fff", 25 };
	People p7 = { NULL,"ggg", 26 };
	People p8 = { NULL,"hhh", 27 };
	People p9 = { NULL,"iii", 28 };
	People p10 = { NULL, "jjj", 29 };
	People p11 = { NULL, "kkk", 39 };
	People p12 = { NULL, "lll", 14 };
	People p13 = { NULL, "mmm", 18 };

	CircularList *list = NULL;
	Init_CircularList(&list);

	Insert_CircularList(list, 0, &p1);
	Insert_CircularList(list, 0, &p2);
	Insert_CircularList(list, 0, &p3);
	Insert_CircularList(list, 0, &p4);
	Insert_CircularList(list, 0, &p5);
	Insert_CircularList(list, 0, &p6);
	Insert_CircularList(list, 0, &p7);
	Insert_CircularList(list, 0, &p8);
	Insert_CircularList(list, 0, &p9);
	Insert_CircularList(list, 0, &p10);


	People *p14 = NULL;

	p14 = PriorElem_CircularList(list,&p3,comparePeople);
	printf("打印接下来结点的前驱：");
	printPeople(&p3);
	printPeople(p14);

	p14 = NextElem_CircularList(list, &p3, comparePeople);
	printf("打印接下来结点的后继：");
	printPeople(&p3);
	printPeople(p14);
	printf("%d\n", Length_CircularList(list));
	Traverse_CircularList(list, printPeople);

	p14 = GetElem_CircularList(list, 4);
	printPeople(p14);
	printf("打印接下来结点的是否存在：");
	printPeople(&p2);
	printf("%d\n",LocateElem_CircularList(list, &p2, comparePeople));


	DeleteByPos_CircularList(list, 2);
	Traverse_CircularList(list, printPeople);

	DeleteByVal_CircularList(list, &p5);
	Traverse_CircularList(list, printPeople);


	Clear_CircularList(list);
	printf("链表是否为空：%s\n", Empty_CircularList(list) ? "是" : "否");
	
	Destroy_CircularList(list);
	printf("链表是否为空：%s\n", Empty_CircularList(list) ? "是" : "否");
}

int main()
{
	test();
	system("pause");
	return 0;


}