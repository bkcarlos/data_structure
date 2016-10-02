#include "QueueStack.h"


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

	QueueStack *stack = NULL;

	Init_QueueStack(&stack, 10);

	Push_QueueStack(stack,&p1);
	Push_QueueStack(stack, &p2);
	Push_QueueStack(stack, &p3);
	Push_QueueStack(stack, &p4);
	Push_QueueStack(stack, &p5);
	Push_QueueStack(stack, &p6);
	Push_QueueStack(stack, &p7);
	Push_QueueStack(stack, &p8);
	Push_QueueStack(stack, &p9);
	Push_QueueStack(stack, &p10);
	Push_QueueStack(stack, &p11);
	Push_QueueStack(stack, &p12);
	Push_QueueStack(stack, &p13);
	
	People *p14 = Top_QueueStack(stack);

	printf("Name:%s Age:%d\n", p14->Name, p14->age);
	Pop_QueueStack(stack);

	p14 = Top_QueueStack(stack);
	printf("Name:%s Age:%d\n", p14->Name, p14->age);
	printf("栈的长度%d\n", Size_QueueStack(stack));
	while (Size_QueueStack(stack))
	{
		Pop_QueueStack(stack);
	}
	printf("栈的长度%d\n", Size_QueueStack(stack));

	Destory_QueueStack(stack);


}

int main()
{

	test();

	system("pause");
	return 0;
}