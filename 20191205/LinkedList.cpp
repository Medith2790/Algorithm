#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define TRUE 1
#define FALSE 0
#define MAX  8

typedef int Data;
typedef struct _cQueue
{
	int front;
	int rear;
	Data queArr[MAX];
}CQueue;

typedef CQueue Queue;

void QueueInit(Queue* pq)
{
	pq->front = 0;
	pq->rear = 0;
}

int QIsEmpty(Queue*pq)
{
	if (pq->front == pq->rear)
		return TRUE;
	else
		return FALSE;
}


int NextPosIdx(int pos)
{
	if (pos == MAX - 1)
	{
		return 0;
	}
	else
		return pos + 1;
}

void EnQueue(Queue *pq, Data data)
{
	if (NextPosIdx(pq->rear) == pq->front)
	{
		printf("Queue가 꽉 찼습니다.");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);		//rear을 한칸 이동
	pq->queArr[pq->rear] = data;				//rear이 가리키는 곳에 데이터 저장
}

Data Dequeue(Queue *pq)
{
	if (QIsEmpty(pq))
	{
		printf("queue 비었습니다.\n");
		exit(-1);
	}
	
	pq->front = NextPosIdx(pq->front);			//front를 한칸 이동
	return pq->queArr[pq->front];				//front가 가리키는 데이터 반환
}

int main()
{
	Queue q;
	int number;
	int r;
	CONSOLE_SCREEN_BUFFER_INFO curinfo;
	QueueInit(&q);
	for (number = 0; number <= MAX; number++)
	{
		

		printf("입력할 값 :");
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
		scanf_s("%d", &number);
		printf("\n");				//안해주면 바로바로 적용안됨 엔터뒤 결과를 바로 적용

		if (number > 0)
		{
			curinfo.dwCursorPosition.X += 10;
			//이전커서정보 X = 12(한글은 2개씩 늘어남) Y=0
			//X는 대략 10정도 증가 시킨곳에 저장
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curinfo.dwCursorPosition);
			//이제 조정한 위치 22, 0으로 커서 를 이동
			printf("%d을 큐에 넣음\n", number);
			EnQueue(&q,number);
		}
		else if (number == 0)
		{
			r = Dequeue(&q);
			printf("[%d]\n", r);
		}
	}
	return 0;
}