#include "OrderQueue.h"

typedef struct _PEOPLE
{
	char Name[64];
	int age;
}People;

void test()
{
	People p1 = { "aaa", 19 };
	People p2 = { "bbb", 20 };
	People p3 = { "ccc", 21 };
	People p4 = { "ddd", 23 };
	People p5 = { "eee", 24 };
	People p6 = { "fff", 25 };
	People p7 = { "ggg", 26 };
	People p8 = { "hhh", 27 };
	People p9 = { "iii", 28 };
	People p10 = { "jjj", 29 };
	People p11 = { "kkk", 39 };
	People p12 = { "lll", 14 };
	People p13 = { "mmm", 18 };

	OrderQueue *stack = NULL;

	Init_OrderQueue(&stack, 10);

	Push_OrderQueue(stack, &p1);
	Push_OrderQueue(stack, &p2);
	Push_OrderQueue(stack, &p3);
	Push_OrderQueue(stack, &p4);
	Push_OrderQueue(stack, &p5);
	Push_OrderQueue(stack, &p6);
	Push_OrderQueue(stack, &p7);
	Push_OrderQueue(stack, &p8);
	Push_OrderQueue(stack, &p9);
	Push_OrderQueue(stack, &p10);
	Push_OrderQueue(stack, &p11);
	Push_OrderQueue(stack, &p12);
	Push_OrderQueue(stack, &p13);

	People *p14 = Back_OrderQueue(stack);

	printf("Name:%s Age:%d\n", p14->Name, p14->age);
	Pop_OrderQueue(stack);

	p14 = Front_OrderQueue(stack);
	printf("Name:%s Age:%d\n", p14->Name, p14->age);
	printf("栈的长度%d\n", Size_OrderQueue(stack));
	while (Size_OrderQueue(stack))
	{
		Pop_OrderQueue(stack);
	}
	printf("栈的长度%d\n", Size_OrderQueue(stack));

	Destory_OrderQueue(stack);


}


int main()
{
	test();
	system("pause");
	return 0;
}