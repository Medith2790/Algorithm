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
			printf("%4d큐에 담았습니다.\n", Qu.rear);
			Qu.queue[++Qu.rear] = data;
		}
		else
		{
			printf("큐가 꽉 찼습니다.");
		}
	
	return 0;
}

int DeQueue()
{
	struct ArrayQueue *Qu;
	int r;	
	if (Qu->size == 0)
	{
		printf("큐가 비었습니다.\n");
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

		printf("입력할 값 :");
		GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curinfo);
		scanf_s("%d ", &data);

		if (data > 0)
		{
			curinfo.dwCursorPosition.X += 10;
			//이전커서정보 X = 12(한글은 2개씩 늘어남) Y=0
			//X는 대략 10정도 증가 시킨곳에 저장

			SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), curinfo.dwCursorPosition);
			//이제 조정한 위치 22, 0으로 커서 를 이동

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