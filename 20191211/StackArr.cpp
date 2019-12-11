#include<stdio.h>
#include<stdlib.h>
#include<windows.h>

#define Stack_LEN 100


typedef int Data;

typedef struct _StackArr
{
	int topIndex;
	Data structArr[Stack_LEN];
}_Stact;

typedef _Stact Stack;

//�ʱ�ȭ �Լ�
void StackInit(Stack*pstack)
{
	pstack->topIndex =-1;
	//������ �迭�� 0������ ����Ű���� -1�� ���־�� �Ѵ�.
	//�Ϲ������δ� IT���� 0���� ���� ������ ��{ 0,1,2,3,4,5,6,7,8,9,10....,n}
	//�迭�� �ּҸ� �����Ѿ� �� ���� 0,1,2,3,4,5,6,7,8,9,10
	//                          -1,0,1,2,3,4,5,6,7,8,9,...,n

}

//����ٸ�...
int SIsEmpty(Stack*pstack)
{
	if (pstack->topIndex == -1)
	{
		return TRUE;
	}
	else
		return FALSE;
}

//���ÿ� ���� ����
void SPush(Stack*pstack, Data data)
{
	pstack->topIndex += 1;
	//top�� ����Ű�� ���� �����ϰڴ�.
	pstack->structArr[pstack->topIndex] = data;
	//data�� �迭�ȿ� top�� ����Ű�� ���� ����
}

//���ÿ��� ���� ����
Data SPop(Stack*pstack)
{
	int rIdx;
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}

	rIdx = pstack->topIndex;
	pstack->topIndex -= 1;

	return pstack->structArr[rIdx];
}

//������ Ȯ�ν� �ʿ��� �κ�
Data Speek(Stack*pstack)
{
	if (SIsEmpty(pstack))
	{
		printf("Stack Memory Error!");
		exit(-1);
	}
	return pstack->structArr[pstack->topIndex];
}


int main()
{
	Stack stack;
	int data;
	for (int i = 0; i <= Stack_LEN; i++)
	{
		printf("���� ���� �Է��Ͻÿ�.");
		scanf_s("%d", &data);
		StackInit(&stack);


		if (data > 0)
		{
			SPush(&stack, data);
			printf("���ÿ� �׿����ϴ�.");
		}
		else if (data == 0)
		{
			SPop(&stack);
			printf("���ÿ��� �������ϴ�.");
		}
		else
		{
			SIsEmpty(&stack);
		}
	}

	
	

	return 0;
}