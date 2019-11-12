//구조체 배우기

#include<stdio.h>

struct GameInfo
{
	const char * name;
	const char * company;
	int year;
	int price;

	struct GameInfo * friendGame;	//연관 업체 게임
};

//치환
typedef struct GameInformation
{
	const char * name;
	const char * company;
	int year;
	int price;

	struct GameInfo * friendGame;	//연관 업체 게임

}Game_INFO;


int main(void)
{
	//[게임 출시]
	//이름 : 나도게임
	//발매년도 : 2017년
	//가격 : 50원
	//제작사 : 나도회사


	//구조체 사용
	struct GameInfo gameinfo1;
	gameinfo1.name = "나도게임";
	gameinfo1.year = 2017;
	gameinfo1.price = 50;
	gameinfo1.company = "나도회사";

	printf("--게임 출시 정보 --\n");
	printf("게임명    :%s\n", gameinfo1.name);
	printf("발매년도  :%d\n", gameinfo1.year);
	printf("가격     :%d\n", gameinfo1.price);
	printf("제작사   :%s\n", gameinfo1.company);


	//구조체를 배열처럼 초기화
	struct GameInfo gameinfo2 = {"너도게임", "너도회사", 2017, 100};

	printf("--또다른 게임 출시 정보 --\n");
	printf("게임명    :%s\n", gameinfo2.name);
	printf("발매년도  :%d\n", gameinfo2.year);
	printf("가격     :%d\n", gameinfo2.price);
	printf("제작사   :%s\n", gameinfo2.company);

	//구조체 배열
	struct GameInfo gameArray[2] = {
		{"나도게임", "나도회사", 2017, 50},
	{"너도게임", "너도회사", 2017, 100}
	};

	//구조체 포인터

	struct GameInfo *gamePtr;
		gamePtr = &gameinfo1;
		printf("\n\n-- 미션맨의 게임 출시 정보--\n");
		printf("게임명   :%s\n",(*gamePtr).name );
		printf("발매년도 :%d\n", (*gamePtr).year);
		printf("가격    :%d\n", (*gamePtr).price);
		printf("제작사  :%s\n", (*gamePtr).company);
		//printf("연습  : %s\n", gamePtr->company);



		//연관업체 게임
		gameinfo1.friendGame = &gameinfo2;
		printf("\n\n-- 연관업체 게임 출시 정보--\n");
		printf("게임명   :%s\n", gameinfo1.friendGame->name);
		printf("발매년도 :%d\n", gameinfo1.friendGame->year);
		printf("가격    :%d\n", gameinfo1.friendGame->price);
		printf("제작사  :%s\n", gameinfo1.friendGame->company);


		//typedef
		//자료형에 별명지정
		int i = 1;
		typedef int 정수;
		typedef float 실수;
		정수 정수변수 = 3;		//int i=3;
		실수 실수변수 = 3.23f;
		printf("정수변수 : %d, 실수변수 : %.2f\n\n", 정수변수, 실수변수);


		typedef struct GameInfo 게임정보;
		게임정보 game1;
		game1.name = "한글게임";
		game1.year = 2015;


		Game_INFO game2;
		game2.name = "한글게임2";
		game2.year = 2015;
		printf("게임이름 : %s\n", game2.name);
		printf("발매일 : %d\n", game2.year);
	return 0;
}