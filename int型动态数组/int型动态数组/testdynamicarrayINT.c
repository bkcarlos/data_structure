#include"dynamicarrayINT.h"

#define MAXSIZE 10

void test()
{
	IntDynamicArray *array = NULL;


	Init_IntDynamicArray(&array, MAXSIZE);

	for (int i = 0; i < MAXSIZE + 1; ++i)
	{
		Insert_IntDynamicArray(array, i + 1, i);
	}

	printf(".......<����:%d>....\n", Size_IntDynamicArray(array));
	printf(".......<����:%d>....\n", Capacity_IntDynamicArray(array));

	


	Print_IntDynamicArray(array);

	printf(".......<λ5�޸�Ϊ80>....\n");
	Modif_IntDynamicArray(array, 5, 80);
	Print_IntDynamicArray(array);

	printf(".......<λ5ɾ��>....\n");
	EraseByPos_IntDynamicArray(array, 5);
	Print_IntDynamicArray(array);

	printf(".......<��ֵ10:%d>....\n", SeekByVal_IntDynamicArray(array,10));









}

int main()
{

	test();
	system("pause");
	return 0;
}