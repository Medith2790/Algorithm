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
		printf("Queue�� �� á���ϴ�.");
		exit(-1);
	}

	pq->rear = NextPosIdx(pq->rear);		//rear�� ��ĭ �̵�
	pq->queArr[pq->rear] = data;				//rear�� ����Ű�� ���� ������ ����
}

Data Dequeue(Queue *pq)
{
	if (QIsEmpty(pq))
	{
		printf("queue ������ϴ�.\n");
		exit(-1);
	}
	
	pq->front = NextPosIdx(pq->front);			//front�� ��ĭ �̵�
	return pq->queArr[pq->front];				//front�� ����Ű�� ������ ��ȯ
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
		

		printf("�Է��� �� :");
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
		scanf_s("%d", &number);
		printf("\n");				//�����ָ� �ٷιٷ� ����ȵ� ���͵� ����� �ٷ� ����

		if (number > 0)
		{
			curinfo.dwCursorPosition.X += 10;
			//����Ŀ������ X = 12(�ѱ��� 2���� �þ) Y=0
			//X�� �뷫 10���� ���� ��Ų���� ����
			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curinfo.dwCursorPosition);
			//���� ������ ��ġ 22, 0���� Ŀ�� �� �̵�
			printf("%d�� ť�� ����\n", number);
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