#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>

#define MAX  8


struct ArrayQueue
{
	int data=0;
	int queue[MAX];
	int front = -1;
	int rear = -1;
	int size = 0;
};

int EnQueue(ArrayQueue Qu, int data)
{
		Qu.rear = data;
		if (Qu.front <= Qu.rear)
		{
			printf("%4dť�� ��ҽ��ϴ�.\n", Qu.rear);
			Qu.queue[++Qu.rear] = data;
		}
		else
		{
			printf("ť�� �� á���ϴ�.");
		}
	
	return 0;
}

int DeQueue()
{
	struct ArrayQueue *Qu;
	int r;	
	if (Qu->size == 0)
	{
		printf("ť�� ������ϴ�.\n");
		return 0;
	}
	r = Qu->queue[Qu->front];
	Qu->front++;
	Qu->size--;
	return r;
}

int main()
{
	struct ArrayQueue Qu;
	int data =Qu.data;
	int front =Qu.front = 0;
	int rear =Qu.rear = 0;
	int r;
	CONSOLE_SCREEN_BUFFER_INFO curinfo;
	

	for (int i = 0; i <= MAX; i++)
	{
		front = rear = 0;

		printf("�Է��� �� :");
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
		scanf_s("%d ", &data);

		if (data > 0)
		{
			curinfo.dwCursorPosition.X += 10;
			//����Ŀ������ X = 12(�ѱ��� 2���� �þ) Y=0
			//X�� �뷫 10���� ���� ��Ų���� ����

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curinfo.dwCursorPosition);
			//���� ������ ��ġ 22, 0���� Ŀ�� �� �̵�

			EnQueue(Qu, data);
		}
		else if (data == 0)
		{
			r = DeQueue();
			printf("[%d]\n", r);

		}
	}
	return 0;
}