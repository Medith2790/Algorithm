//����ü ����

#include<stdio.h>

struct GameInfo
{
	const char * name;
	const char * company;
	int year;
	int price;

	struct GameInfo * friendGame;	//���� ��ü ����
};

//ġȯ
typedef struct GameInformation
{
	const char * name;
	const char * company;
	int year;
	int price;

	struct GameInfo * friendGame;	//���� ��ü ����

}Game_INFO;


int main(void)
{
	//[���� ���]
	//�̸� : ��������
	//�߸ų⵵ : 2017��
	//���� : 50��
	//���ۻ� : ����ȸ��


	//����ü ���
	struct GameInfo gameinfo1;
	gameinfo1.name = "��������";
	gameinfo1.year = 2017;
	gameinfo1.price = 50;
	gameinfo1.company = "����ȸ��";

	printf("--���� ��� ���� --\n");
	printf("���Ӹ�    :%s\n", gameinfo1.name);
	printf("�߸ų⵵  :%d\n", gameinfo1.year);
	printf("����     :%d\n", gameinfo1.price);
	printf("���ۻ�   :%s\n", gameinfo1.company);


	//����ü�� �迭ó�� �ʱ�ȭ
	struct GameInfo gameinfo2 = {"�ʵ�����", "�ʵ�ȸ��", 2017, 100};

	printf("--�Ǵٸ� ���� ��� ���� --\n");
	printf("���Ӹ�    :%s\n", gameinfo2.name);
	printf("�߸ų⵵  :%d\n", gameinfo2.year);
	printf("����     :%d\n", gameinfo2.price);
	printf("���ۻ�   :%s\n", gameinfo2.company);

	//����ü �迭
	struct GameInfo gameArray[2] = {
		{"��������", "����ȸ��", 2017, 50},
	{"�ʵ�����", "�ʵ�ȸ��", 2017, 100}
	};

	//����ü ������

	struct GameInfo *gamePtr;
		gamePtr = &gameinfo1;
		printf("\n\n-- �̼Ǹ��� ���� ��� ����--\n");
		printf("���Ӹ�   :%s\n",(*gamePtr).name );
		printf("�߸ų⵵ :%d\n", (*gamePtr).year);
		printf("����    :%d\n", (*gamePtr).price);
		printf("���ۻ�  :%s\n", (*gamePtr).company);
		//printf("����  : %s\n", gamePtr->company);



		//������ü ����
		gameinfo1.friendGame = &gameinfo2;
		printf("\n\n-- ������ü ���� ��� ����--\n");
		printf("���Ӹ�   :%s\n", gameinfo1.friendGame->name);
		printf("�߸ų⵵ :%d\n", gameinfo1.friendGame->year);
		printf("����    :%d\n", gameinfo1.friendGame->price);
		printf("���ۻ�  :%s\n", gameinfo1.friendGame->company);


		//typedef
		//�ڷ����� ��������
		int i = 1;
		typedef int ����;
		typedef float �Ǽ�;
		���� �������� = 3;		//int i=3;
		�Ǽ� �Ǽ����� = 3.23f;
		printf("�������� : %d, �Ǽ����� : %.2f\n\n", ��������, �Ǽ�����);


		typedef struct GameInfo ��������;
		�������� game1;
		game1.name = "�ѱ۰���";
		game1.year = 2015;


		Game_INFO game2;
		game2.name = "�ѱ۰���2";
		game2.year = 2015;
		printf("�����̸� : %s\n", game2.name);
		printf("�߸��� : %d\n", game2.year);
	return 0;
}