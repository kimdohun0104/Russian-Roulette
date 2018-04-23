#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

#define NUMBER_OF_BULLETS 6

int gun[NUMBER_OF_BULLETS] = { 0 };
int bulletLocation = 0;

void menu();
void game();
void reload();

int main()
{
	reload();
	game();
}

void menu()
{
	int userInput = 0;

	printf("1. 다시하기\n");
	printf("2. 종료\n");

	scanf("%d", &userInput);

	if (userInput == 1)
	{
		reload();
		system("cls");
		game();
	}
	if (userInput == 2)
	{
		system("cls");
		printf("게임을 종료합니다\n");
		exit(1);
	}
}
void game()
{
	int remainBullet = NUMBER_OF_BULLETS;
	printf("게임을 시작하려면 아무 버튼이나 누르세요\n");
	_getch();
	system("cls");

	for (int i = 0; i < NUMBER_OF_BULLETS; i++)
	{
		--remainBullet;
		if (gun[i] == 0)
		{
			printf("살음\n");
			printf("남은 총알 수 : %d", remainBullet);
			_getch();
			system("cls");
		}
		else if (gun[i] == 1)
		{
			printf("죽음\n");
			_getche();
			system("cls");
			menu();
		}
	}
}
void reload()
{
	for (int i = 0; i < NUMBER_OF_BULLETS; i++)
		gun[i] = 0;
	srand(time(NULL));

	bulletLocation = rand() % 6;
	gun[bulletLocation] = 1;
}