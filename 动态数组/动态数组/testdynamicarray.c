#include"DynamicArray.h"

typedef struct _STUDENT
{
	char name[64];
	int age;
}Student;

int Compare(void *Data1, void *Data2)
{
	if (Data1 == NULL && Data2 == NULL)
		return 0;
	if (Data1 != NULL && Data2 == NULL)
		return -1;
	if (Data1 == NULL && Data2 != NULL)
		return 1;

	Student *stu1 = (Student *)Data1;
	Student *stu2 = (Student *)Data2;

	if (stu1->age > stu2->age)
		return -1;
	if (stu1->age < stu2->age)
		return 1;
	if (stu1->age == stu2->age)
		return 0;
	return 0;
}

// 遍历函数指针
void Traversal(void *Val)
{
	if (Val == NULL)
		return;
	Student *stu = (Student *)Val;
	printf("Name: %s\tAge: %d\n", stu->name, stu->age);
}

void test()
{

	Student stu1 = { "aaaa",10 };
	Student stu2 = { "bbbb",11 };
	Student stu3 = { "cccc",12 };
	Student stu4 = { "dddd",13 };
	Student stu5 = { "eeee",14 };
	Student stu6 = { "ffff",15 };
	Student stu7 = { "gggg",16 };
	Student stu8 = { "hhhh",17 };
	Student stu9 = { "iiii",18 };
	Student stu10 = { "gggg",19 };
	Student stu11= { "kkkk",20};
	Student stu12= { "ffff",21 };

	DynamicArray *Array=NULL;

	Init_DynamicArray(&Array);

	pushBack_DynamicArray(Array, &stu2);
	pushBack_DynamicArray(Array, &stu10);
	pushBack_DynamicArray(Array, &stu3);
	pushBack_DynamicArray(Array, &stu6);
	pushBack_DynamicArray(Array, &stu7); 
	pushBack_DynamicArray(Array, &stu4);
	pushBack_DynamicArray(Array, &stu8);
	pushBack_DynamicArray(Array, &stu1);
	pushBack_DynamicArray(Array, &stu9);
	pushBack_DynamicArray(Array, &stu5);

	pushBack_DynamicArray(Array, &stu11);
	
	Traversal_DynamicArray(Array, Traversal);

	InsertByPos(Array, 10, &stu12);
	Traversal_DynamicArray(Array, Traversal);


	eraseByPos_DynamicArray(Array, 10);
	Traversal_DynamicArray(Array, Traversal);
	printf("<…………………………头删和尾删……………………>\n");
	eraseFront_DynamicArray(Array);
	eraseBack_DynamicArray(Array);
	Traversal_DynamicArray(Array, Traversal);
	printf("<…………………………查找位置2的元素……………………>\n");
	Student * stu13=(Student *)GetByPos_DynamicArray(Array, 2);
	Traversal(stu13);
	
	int ret=GetByVal_DynamicArray(Array, &stu5, Compare);
	printf("<…………………………查找stu5的元素的位置  %d……………………>\n", ret);

	Inverted_DynamicArray(Array);
	Traversal_DynamicArray(Array, Traversal);

	Sort__DynamicArray(Array,Compare);
	Traversal_DynamicArray(Array, Traversal);

	Destroy__DynamicArray(Array);


}


int main()
{
	test();
	system("pause");
	return 0;
}