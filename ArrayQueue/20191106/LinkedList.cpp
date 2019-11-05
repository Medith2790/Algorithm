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
		printf("�ʱ�ȭ �Ǿ����ϴ�.");
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
		printf("���� ���� ��ٸ� ��ȣ %d ���� ", QU->data);
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
	���� �Լ��� ��� ����¿� ���� ���α׷� ��ũ��Ʈ�̸�
	�Լ��� ������ �Ͽ� �����͸� ���� �ϱ� ���� �Լ��̴�.
	*/
	_queue *Qu = (_queue *)malloc(sizeof(_queue));
	
	printf("�Է��� ������ ����: ");
	scanf_s("%d",&Qu->data);			//�����ͷ� ����� �ּ������� �޾� �����͸� �����´�.
	
	//�ʱ�ȭ �κ�
	//	InitQueue(Qu->arr[8]);

	//arr�迭ũ�⸸ŭ�� �ݺ��Ͽ� ���̻� ���� �ʰ� �Ѵ�.
	for (int i = Qu->data; i <= Qu->arr[MAX]; i++)
	{
		Qu->arr[i];
		printf("%d�� ť�� ����\n", Qu->data);
	}


	return 0;
}