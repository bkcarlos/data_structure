#include"dynamicarrayINT.h"

// ��ʼ��
int Init_IntDynamicArray(IntDynamicArray **Array, int Capacity)
{
	// �Դ���Ĳ��������жϣ����Ϊ�գ�����ֹ�����ִ�У�û�ռ�û��ִ��
	if (Array == NULL)
	{
		exit(-1);
	}

	// Ϊ��̬����Ľṹ�忪�ٿռ�
	*Array = (IntDynamicArray *)malloc(sizeof(IntDynamicArray));
	if (*Array == NULL)
	{
		exit(-2);
	}

	// Ϊ(*Array)->array ����һ�γ���Ϊ Capacity �Ŀռ������洢���������
	(*Array)->array = (int *)malloc(sizeof(int)*Capacity);

	// �Կ��ٵĿռ�һ��Ҫ�жϣ����û����return ��ԭ���ǿ��ٿռ�ʧ�ܣ�����Ĳ����б���Ŀ���
	if ((*Array)->array == NULL)
		exit(-2);
	
	// �Կ��ٵĿռ丳��ʼֵ
	for (int i = 0; i < Capacity; ++i)
		(*Array)->array[i] = 0;
	// �Խṹ���еĹؼ��ֽ��г�ʼ��
	(*Array)->arrayLen = 0;
	(*Array)->capacity = Capacity;

	return 0;
}

// ����
int Insert_IntDynamicArray(IntDynamicArray *Array, int Data,int Pos)
{
	// �Դ���Ĳ������м��
	if (Array == NULL)
	{
		return -1;
	}

	// �Դ���Ĳ������к�������
	if (Pos < 0 )
	{
		Pos = 0;
	}
	if (Pos > Array->arrayLen)
	{
		Pos = Array->arrayLen;
	}

	// ����ռ䲻������ô����һ�οռ����洢�µ�����
	if (Array->arrayLen == Array->capacity)
	{
		// ���������Ŀռ�
		int *array = (int *)malloc(sizeof(int) * 2 * Array->capacity);
		if (array == NULL)
		{
			return -2;
		}
		
		// ��ԭ���ݵ�Ԫ�ؿ������������Ҳ������ѭ��
		memcpy(array, Array->array, sizeof(int)*Array->arrayLen);
		
		// �ͷ�ԭ���Ŀռ�
		free(Array->array);

		Array->array = array;
		Array->capacity *= 2;

		// ���¿��ٵĿռ���г�ʼ��
		for (int i = Array->arrayLen; i < Array->capacity; ++i)
		{
			array[i] = 0;
		}
	}
	// Ϊ����Ԫ���ڳ��ռ�
	for (int i = Array->arrayLen-1; i >= Pos; --i)
	{
		Array->array[i+1] = Array->array[i];
	}

	// ������Ԫ��
	Array->array[Pos] = Data;

	++ Array->arrayLen;

	return 0;
}

// ɾ��
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

	// ֱ��ͨ�����ǵķ�ʽɾ��
	for (int i = Pos; i < Array->arrayLen - 1; ++i)
	{
		Array->array[i] = Array->array[i + 1];
	}

	-- Array->arrayLen;
	return 0;
}

// �޸�
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

// ͨ��λ�ò���
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

// ���ҵ�һ�γ���ĳֵ��λ��
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

// ��ӡ��̬����
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

// ���鳤��
int Size_IntDynamicArray(IntDynamicArray *Array)
{
	if (Array == NULL)
	{
		return -1;
	}
	return Array->arrayLen;
}


// ��������
int Capacity_IntDynamicArray(IntDynamicArray *Array)
{
	if (Array == NULL)
	{
		return -1;
	}
	return Array->capacity;
}

// ����
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