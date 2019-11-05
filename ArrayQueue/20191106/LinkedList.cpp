#include<stdio.h>
#include<stdlib.h>

#define MAX 8

typedef struct QUEUE {
	int data;
	int arr[MAX];
	struct Node *_node;
	int front;
	int rear;

}_queue;


int InitQueue(_queue *QU)
{
	if (QU->front == QU->rear)
	{
		QU->front = 0;
		QU->rear = 0;
		printf("초기화 되었습니다.");
	}
	return 0;
}

int enqueue(_queue *QU, int data)
{
	
		QU->front = data;
		QU->rear = QU->front;
	

	if (QU->data < 0)
	{
		return 0;
	}

	QU->data++;


	return data;
}

int dequeue(_queue *QU)
{
	if (QU->data == 0)
	{
		printf("가장 오래 기다린 번호 %d 나옴 ", QU->data);
	}
	else if (QU->data == NULL)
	{
		printf("Queue Full!!!");
	}

	return 0;
}

int main()
{
	/*
	메인 함수는 모든 입출력에 대한 프로그램 스크립트이며
	함수에 접근을 하여 데이터를 추출 하기 위한 함수이다.
	*/
	_queue *Qu = (_queue *)malloc(sizeof(_queue));
	
	printf("입력할 데이터 숫자: ");
	scanf_s("%d",&Qu->data);			//포인터로 연결된 주소참조를 받아 데이터를 가져온다.
	
	//초기화 부분
	//	InitQueue(Qu->arr[8]);

	//arr배열크기만큼만 반복하여 더이상 받지 않게 한다.
	for (int i = Qu->data; i <= Qu->arr[MAX]; i++)
	{
		Qu->arr[i];
		printf("%d을 큐에 넣음\n", Qu->data);
	}


	return 0;
}