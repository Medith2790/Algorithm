#include <stdio.h>

#define MAX     8

typedef struct queue {
	int head;
	int tail;
	int arr[MAX];
}QUEUE;

int queue_empty(QUEUE);
void enqueue(QUEUE *, int);
int dequeue(QUEUE *);

int main(void)
{
	QUEUE Q;
	
	// 초기 head, tail값
	Q.head = 0;
	Q.tail = 0;

	printf("Input Queue: ");
	scanf_s("%d", &Q.head);

	for (int i = 0; i <= Q.head; i++)
	{
	
		scanf("%d", &Q.tail);

			for (int i = 0; i < Q.tail; i++)
			{
				int value;
				scanf_s("%d", &value);
				enqueue(&Q, value);
				printf("SetValue");
			}

			printf("#%d", i);

			while (!queue_empty(Q))
			{

				if (dequeue(&Q) == 1)
				{
					printf("%d", Q);
				}
			}
			printf("\n");
	}

	return 0;
}

/*
	queue_empty( QUEUE)
	큐가 비었는지 확인하는 기능
*/
int queue_empty(QUEUE q)
{
	if (q.head == q.tail)
		return 1;

	return 0;
}

/*
	enqueue( QUEUE *, int)
	큐에 삽입할 데이터
*/
void enqueue(QUEUE *q, int data)
{
	q->arr[q->head++] = data;

	printf("ENQUEUE : %d\n", data);

	q->head = q->head % MAX;
}

/*
	dequeue( QUEUE *)
	큐에서 삭제할 데이터
*/
int dequeue(QUEUE *q)
{
	int data;

	if (queue_empty(*q))
	{
		printf("the queue is empty!\n");

		return -1;
	}

	data = q->arr[q->tail++];

	printf("DEQUEUE : %d\n", data);

	q->tail = q->tail % MAX;

	return data;
}