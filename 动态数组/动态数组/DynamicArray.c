#include"DynamicArray.h"

// 开辟数组的容量
int Init_DynamicArray(void **DArray)
{
	if (DArray == NULL)
	{
		exit(-1);
	}

	DynamicArray *dynamicarray = (DynamicArray *)malloc(sizeof(DynamicArray));

	dynamicarray->Array = (void **)malloc(sizeof(void *)*MAXCAPACITY);
	if (dynamicarray->Array == NULL)
	{
		exit(-2);
	}

	for (int i = 0; i < MAXCAPACITY; ++i)
	{
		// 将开辟void * 指针指向NULL
		//dynamicarray->Array[i] = NULL;
		*((dynamicarray->Array) + i) = NULL;
	}

	// 将数组的变化写入想关数据
	dynamicarray->ArrayLen = 0;
	dynamicarray->Capacity = MAXCAPACITY;

	*DArray = dynamicarray;

	return 0;

}

// 在数组末尾插入数据
int pushBack_DynamicArray(void *DArray, void *Data)
{
	if (DArray == NULL)
	{
		return -1;
	}
	if (Data == NULL)
	{
		return -2;
	}

	DynamicArray *dynamicarray = (DynamicArray *)DArray;

	if (dynamicarray->ArrayLen == dynamicarray->Capacity)
	{
		void ** tempCapaticy = (void **)malloc(sizeof(void *)*dynamicarray->Capacity * 2);

		if (tempCapaticy == NULL)
		{
			return -3;
		}

		memcpy(tempCapaticy, dynamicarray->Array, sizeof(void *)*dynamicarray->Capacity);

		free(dynamicarray->Array);

		dynamicarray->Array = tempCapaticy;

		for (int i = dynamicarray->Capacity; i < dynamicarray->Capacity * 2; ++i)
		{
			dynamicarray->Array[i] = NULL;
		}
		dynamicarray->Capacity *= 2;
	}


	dynamicarray->Array[dynamicarray->ArrayLen] = Data;

	++dynamicarray->ArrayLen;

	return 0;

}

// 指定位置插入
void InsertByPos(void *DArray, int Pos, void *Val)
{

	if (DArray == NULL)
	{
		return;
	}

	DynamicArray *dynamicarray = (DynamicArray *)DArray;

	dynamicarray->Array[Pos] = Val;
}


//  指定位置删除
int eraseByPos_DynamicArray(void *DArray, int Pos)
{
	if (DArray == NULL)
	{
		return -1;
	}

	DynamicArray *dynamicarray = (DynamicArray *)DArray;


	if (Pos < 0 || Pos >= dynamicarray->ArrayLen)
	{
		return -2;
	}

	for (int i = Pos; i < dynamicarray->ArrayLen - 1; ++i)
	{
		dynamicarray->Array[i] = dynamicarray->Array[i + 1];
	}

	dynamicarray->Array[dynamicarray->ArrayLen - 1] = NULL;

	--dynamicarray->ArrayLen;

	return 0;
}

// 头删
int eraseFront_DynamicArray(void *DArray)
{
	int ret = eraseByPos_DynamicArray(DArray, 0);
	return ret;
}


// 尾删
int eraseBack_DynamicArray(void *DArray)
{
	if (DArray == NULL)
	{
		return -1;
	}

	DynamicArray *dynamicarray = (DynamicArray *)DArray;

	int ret = eraseByPos_DynamicArray(DArray, dynamicarray->ArrayLen - 1);

	return ret;
}

void * GetByPos_DynamicArray(void *DArray, int Pos)
{
	// 这儿没有做安全检查的原因是，因为在实际的数组中，我们访问一个不存在的值时可能导致程序崩溃，这儿也是这样的
	DynamicArray *dynamicarray = (DynamicArray *)DArray;
	return dynamicarray->Array[Pos];
}


int  GetByVal_DynamicArray(void *DArray, void *Val, COMPARE compare)
{
	if (DArray == NULL)
	{
		return -1;
	}

	DynamicArray *dynamicarray = (DynamicArray *)DArray;

	for (int i = 0; i < dynamicarray->ArrayLen; ++i)
	{
		if (!compare(dynamicarray->Array[i], Val))
		{
			return i;
		}
	}

	return -1;
}

int Size_DynamicArray(void *DArray)
{
	if (DArray == NULL)
	{
		return 0;
	}
	DynamicArray *dynamicarray = (DynamicArray *)DArray;

	return dynamicarray->ArrayLen;
}

int Capacity_DynamicArray(void *DArray)
{
	if (DArray == NULL)
	{
		return 0;
	}
	DynamicArray *dynamicarray = (DynamicArray *)DArray;

	return dynamicarray->Capacity;
}


void Traversal_DynamicArray(void *DArray, TRAVERSAL traversal)
{
	if (DArray == NULL)
	{
		return;
	}

	DynamicArray *dynamicarray = (DynamicArray *)DArray;

	printf("<……………………………………………………>\n");
	for (int i = 0; i < dynamicarray->ArrayLen; ++i)
	{
		traversal(dynamicarray->Array[i]);
	}
}

int Inverted_DynamicArray(void *DArray)
{
	if (DArray == NULL)
	{
		return -1;
	}

	DynamicArray *dynamicarray = (DynamicArray *)DArray;

	for (int i = 0; i < dynamicarray->ArrayLen / 2; ++i)
	{
		void *temp = dynamicarray->Array[i];
		dynamicarray->Array[i] = dynamicarray->Array[dynamicarray->ArrayLen - 1 - i];
		dynamicarray->Array[dynamicarray->ArrayLen - 1 - i] = temp;
	}

	return 0;
}

void Quick_Sort(void  **array, int low, int height, COMPARE compare)
{
	// 将low 和 height  缓存 为后面的递归的实现提供界限
	int right = low, left = height;

	if (low < height)
	{
		void *pivotkey = array[right];
		while (right < left)
		{
			while (right < left && (compare(array[left], pivotkey) <= 0))
				--left;
			if (right < left)
			{
				array[right++] = array[left];
			}

			while (right < left && (compare(array[right], pivotkey)>0))
				++right;
			if (right < left)
			{
				array[left--] = array[right];
			}
		}
		// 将关键字插入想关的位置
		array[right] = pivotkey;

		Quick_Sort(array, low, right - 1, compare);
		Quick_Sort(array, right + 1, height, compare);
	}
}


int Sort__DynamicArray(void *DArray, COMPARE compare)
{
	if (DArray == NULL)
	{
		return -1;
	}
	DynamicArray *dynamicarray = (DynamicArray *)DArray;

	if (dynamicarray->ArrayLen == 1)
	{
		return 0;
	}
	Quick_Sort(dynamicarray->Array, 0, dynamicarray->ArrayLen - 1, compare);
	return 0;
}


int Destroy__DynamicArray(void *DArray)
{
	if (DArray == NULL)
	{
		return -1;
	}
	DynamicArray *dynamicarray = (DynamicArray *)DArray;

	if (dynamicarray->Array != NULL)
	{
		free(dynamicarray->Array);
		dynamicarray->Array = NULL;
	}
	free(dynamicarray);
	dynamicarray = NULL;
	return 0;
}