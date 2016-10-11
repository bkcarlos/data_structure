#include "LinkStack.h"

typedef struct _PEOPLE
{
	StackNode Next;
	char Name[64];
	int age;
}People;

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

	LinkStack *stack = NULL;

	Init_LinkStack(&stack);

	Push_LinkStack(stack, &p1);
	Push_LinkStack(stack, &p2);
	Push_LinkStack(stack, &p3);
	Push_LinkStack(stack, &p4);
	Push_LinkStack(stack, &p5);
	Push_LinkStack(stack, &p6);
	Push_LinkStack(stack, &p7);
	Push_LinkStack(stack, &p8);
	Push_LinkStack(stack, &p9);
	Push_LinkStack(stack, &p10);
	Push_LinkStack(stack, &p11);
	Push_LinkStack(stack, &p12);
	Push_LinkStack(stack, &p13);

	People *p14 = Top_LinkStack(stack);

	printf("Name:%s Age:%d\n", p14->Name, p14->age);
	Pop_LinkStack(stack);

	p14 = Top_LinkStack(stack);
	printf("Name:%s Age:%d\n", p14->Name, p14->age);

	printf("栈的长度%d\n", Size_LinkStack(stack));
#if 0
	while (Size_LinkStack(stack))
	{
		Pop_LinkStack(stack);
	}
#else
	while (Top_LinkStack(stack))
	{
		Pop_LinkStack(stack);
	}
#endif
	printf("栈的长度%d\n", Size_LinkStack(stack));

	Destory_LinkStack(stack);


}

int main()
{
	test();
	system("pause");
	return 0;
}