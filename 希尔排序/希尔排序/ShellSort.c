#include<stdio.h>
#include<stdlib.h>



// �����������
#include<time.h>


#define MAXSIZE 10

void Shell_Sort1(int array[], int arrayLen);

void Shell_Sort2(int array[], int arrayLen);

void Shell_Sort3(int array[], int arrayLen);

void Shell_Sort4(int array[], int arrayLen);

void Print_Array(int array[], int arrayLen);

void Swap_IntVal(int *valA, int *valB);

void Test_Bubble_sort();



int main()
{
	Test_Bubble_sort();

	system("pause");
	return 0;
}

void Test_Bubble_sort()
{
	// srand() �ٶȰٿ� http://baike.baidu.com/view/1458234.htm
	srand((unsigned int)time(NULL));

	int array[MAXSIZE] = { 0 };
	for (int i = 0; i < MAXSIZE; ++i)
	{
		array[i] = rand()%100;
	}
	// ��ӡ��ǰ������
	Print_Array(array, MAXSIZE);

	// ����ϣ������
	Shell_binary_Sort(array, MAXSIZE);

	// ��ӡ����õ�����
	Print_Array(array, MAXSIZE);

}

void Print_Array(int array[], int arrayLen)
{
	printf("��������< ��ǰ������Ԫ�� >��������������������\n");
	for (int i = 0; i < arrayLen; ++i)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}

void Swap_IntVal(int *valA, int *valB)
{
	int temp = *valA;
	*valA = *valB;
	*valB = temp;
}


void Shell_Sort1(int array[], int arrayLen)
{
	// ����һ������
	int Incremental = arrayLen;
	do	
	{
		Incremental = Incremental / 3 + 1;
		for (int i = 0; i < Incremental;++ i)
		{
			for (int j = i + Incremental; j < arrayLen; j += Incremental)
			{
				// �Ӵ�С
				if (array[j - Incremental] < array[j])
				{
					int InsertNum = array[j];
					int k = j - Incremental;
					// �����ݺ���
					while (k >= 0 && array[k] < InsertNum)
					{
						array[k + Incremental] = array[k];
						k -= Incremental;
					}
					array[k + Incremental] = InsertNum;
				}
			}
		}
	} while (Incremental > 1);
}


void Shell_Sort2(int array[], int arrayLen)
{
	// ȷ��ÿ�������Ĵ�С
	for (int Incremental = arrayLen / 2; Incremental > 0; Incremental /= 2)
	{
		// ������в�������
		for (int i = 0; i < Incremental; ++ i)
		{
			for (int j = i + Incremental; j < arrayLen; j+= Incremental)
			{
				// �Ӵ�С
				if (array[j - Incremental] < array[j])
				{
					int InsertNum = array[j];
					int k = j-Incremental;
					
					while (k >= 0 && array[k] < InsertNum)
					{
						array[k + Incremental] = array[k];
						k -= Incremental;
					}
					array[k + Incremental] = InsertNum;
				}
			}
			
		}
	}
}

void Shell_Sort3(int array[], int arrayLen)
{
	for (int Incremental = arrayLen / 2; Incremental > 0; Incremental /= 2)
	{
		// ������в�������
		for (int i = Incremental; i < arrayLen; ++ i)
		{
			// �ɴ�С
			if (array[i] > array[i - Incremental])
			{
				int InsertNum = array[i];
				int j = i - Incremental;
				
				// ע����� j �� InsertNum ��������ݵ�λ�ã��������Ĵ�С˳��
				while (j >= 0 && array[j] < InsertNum)  
				{
					array[j + Incremental] = array[j];
					j -= Incremental;
				}
				array[j + Incremental] = InsertNum;
			}
		}
	}
}


void Shell_Sort4(int array[], int arrayLen)
{
	for (int Incremental = arrayLen / 2; Incremental > 0; Incremental /= 2)
	{
		// ������в�������
		for (int i = Incremental; i < arrayLen; ++i)
		{
			for (int j = i - Incremental; j >=0 && array[j] < array[j + Incremental]; j -= Incremental)
			{
				Swap_IntVal(array + j, array + j + Incremental);
			}
		}
	}
}


