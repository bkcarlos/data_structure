#include"LinkQueue.h"


typedef struct _PERSON
{
	LinkQueueNode *next;
	char name[64];
	int age;
}Person;


void test()
{
	Person p1 = { NULL,"qqq",14 };
	Person p2 = { NULL,"www",15 };
	Person p3 = { NULL,"eee",16 };
	Person p4 = { NULL,"rrr",17 };
	Person p5 = { NULL,"ttt",18 };
	Person p6 = { NULL,"yyy",19 };

	LinkQueue *queue = NULL;
	Init_LinkQueue(&queue);
	Push_LinkQueue(queue, &p1);
	Push_LinkQueue(queue, &p2);
	Push_LinkQueue(queue, &p3);
	Push_LinkQueue(queue, &p4);
	Push_LinkQueue(queue, &p5);
	Push_LinkQueue(queue, &p6);

	Person *p = Front_LinkQueue(queue);
	printf("%s->%d\n", p->name, p->age);
	p = Back_LinkQueue(queue);
	printf("%s->%d\n", p->name, p->age);



#if 0
	while (Size_LinkQueue(queue) > 0)
	{
		Person *p =(Person *)Front_LinkQueue(queue);
		printf("%s->%d\n", p->name, p->age);
		Pop_LinkQueue(queue);
	}
#else
	
	while ((p = (Person *)Front_LinkQueue(queue)))
	{
		printf("%s->%d\n", p->name, p->age);
		Pop_LinkQueue(queue);
	}

#endif

	// Destroy_LinkQueue(queue);
}

int main()
{
	test();
	system("pause");
	return 0;


}