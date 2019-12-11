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

//초기화 함수
void StackInit(Stack*pstack)
{
	pstack->topIndex =-1;
	//스택의 배열은 0번지를 가리키려면 -1를 해주어야 한다.
	//일반적으로는 IT에서 0부터 시작 하지만 예{ 0,1,2,3,4,5,6,7,8,9,10....,n}
	//배열의 주소를 가리켜야 할 때는 0,1,2,3,4,5,6,7,8,9,10
	//                          -1,0,1,2,3,4,5,6,7,8,9,...,n

}

//비었다면...
int SIsEmpty(Stack*pstack)
{
	if (pstack->topIndex == -1)
	{
		return TRUE;
	}
	else
		return FALSE;
}

//스택에 값을 너음
void SPush(Stack*pstack, Data data)
{
	pstack->topIndex += 1;
	//top이 가리키는 곳을 증가하겠다.
	pstack->structArr[pstack->topIndex] = data;
	//data를 배열안에 top이 가리키는 곳에 너음
}

//스택에서 값을 삭제
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

//데이터 확인시 필요한 부분
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
		printf("스택 값을 입력하시오.");
		scanf_s("%d", &data);
		StackInit(&stack);


		if (data > 0)
		{
			SPush(&stack, data);
			printf("스택에 쌓였습니다.");
		}
		else if (data == 0)
		{
			SPop(&stack);
			printf("스택에서 빠졌습니다.");
		}
		else
		{
			SIsEmpty(&stack);
		}
	}

	
	

	return 0;
}