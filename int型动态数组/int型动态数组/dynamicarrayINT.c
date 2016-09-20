#include"dynamicarrayINT.h"

// 初始化
int Init_IntDynamicArray(IntDynamicArray **Array, int Capacity)
{
	// 对传入的参数进行判断，如果为空，则终止下面的执行，没空间没法执行
	if (Array == NULL)
	{
		exit(-1);
	}

	// 为动态数组的结构体开辟空间
	*Array = (IntDynamicArray *)malloc(sizeof(IntDynamicArray));
	if (*Array == NULL)
	{
		exit(-2);
	}

	// 为(*Array)->array 开辟一段长度为 Capacity 的空间用来存储数组的数据
	(*Array)->array = (int *)malloc(sizeof(int)*Capacity);

	// 对开辟的空间一定要判断，这儿没有用return 的原因是开辟空间失败，后面的操作有报错的可能
	if ((*Array)->array == NULL)
		exit(-2);
	
	// 对开辟的空间赋初始值
	for (int i = 0; i < Capacity; ++i)
		(*Array)->array[i] = 0;
	// 对结构体中的关键字进行初始化
	(*Array)->arrayLen = 0;
	(*Array)->capacity = Capacity;

	return 0;
}

// 插入
int Insert_IntDynamicArray(IntDynamicArray *Array, int Data,int Pos)
{
	// 对传入的参数进行检查
	if (Array == NULL)
	{
		return -1;
	}

	// 对传入的参数进行合理化处理
	if (Pos < 0 )
	{
		Pos = 0;
	}
	if (Pos > Array->arrayLen)
	{
		Pos = Array->arrayLen;
	}

	// 如果空间不够，那么开辟一段空间来存储新的数据
	if (Array->arrayLen == Array->capacity)
	{
		// 开辟两倍的空间
		int *array = (int *)malloc(sizeof(int) * 2 * Array->capacity);
		if (array == NULL)
		{
			return -2;
		}
		
		// 将原数据的元素拷贝过来，这儿也可以用循环
		memcpy(array, Array->array, sizeof(int)*Array->arrayLen);
		
		// 释放原来的空间
		free(Array->array);

		Array->array = array;
		Array->capacity *= 2;

		// 对新开辟的空间进行初始化
		for (int i = Array->arrayLen; i < Array->capacity; ++i)
		{
			array[i] = 0;
		}
	}
	// 为插入元素腾出空间
	for (int i = Array->arrayLen-1; i >= Pos; --i)
	{
		Array->array[i+1] = Array->array[i];
	}

	// 插入新元素
	Array->array[Pos] = Data;

	++ Array->arrayLen;

	return 0;
}

// 删除
int EraseByPos_IntDynamicArray(IntDynamicArray *Array, int Pos)
{
	if (Array == NULL)
	{
		return -1;
	}
	if (Pos < 0 || Pos >= Array->arrayLen)
	{
		return -2;
	}

	// 直接通过覆盖的方式删除
	for (int i = Pos; i < Array->arrayLen - 1; ++i)
	{
		Array->array[i] = Array->array[i + 1];
	}

	-- Array->arrayLen;
	return 0;
}

// 修改
int Modif_IntDynamicArray(IntDynamicArray *Array, int Pos, int Data)
{
	if (Array == NULL)
	{
		return -1;
	}
	if (Pos<0 || Pos>Array->arrayLen - 1)
	{
		return -2;
	}

	Array->array[Pos] = Data;

	return 0;
}

// 通过位置查找
int SeekByPos_IntDynamicArray(IntDynamicArray *Array, int Pos)
{
	if (Array == NULL)
	{
		return 0x00;
	}
	if(Pos<0||Pos>Array->arrayLen-1)
	{
		return 0x01;
	}
	return Array->array[Pos];
}

// 查找第一次出现某值的位置
int SeekByVal_IntDynamicArray(IntDynamicArray *Array, int Val)
{
	if (Array == NULL)
	{
		return 0x00;
	}
	for (int i = 0; i < Array->arrayLen; ++i)
	{
		if (Array->array[i] == Val)
			return i;
	}
	return -1;
}

// 打印动态数组
void Print_IntDynamicArray(IntDynamicArray *Array)
{
	if (Array == NULL)
	{
		return;
	}
	for (int i = 0; i < Array->arrayLen; ++i)
	{
		printf("%d ", Array->array[i]);
	}
	printf("\n");
}

// 数组长度
int Size_IntDynamicArray(IntDynamicArray *Array)
{
	if (Array == NULL)
	{
		return -1;
	}
	return Array->arrayLen;
}


// 数组容量
int Capacity_IntDynamicArray(IntDynamicArray *Array)
{
	if (Array == NULL)
	{
		return -1;
	}
	return Array->capacity;
}

// 销毁
int Destroy_IntDynamicArray(IntDynamicArray *Array)
{
	if (Array == NULL)
	{
		return -1;
	}
	if (Array->array != NULL)
	{
		free(Array->array);
	}

	free(Array);

	return 0;
}