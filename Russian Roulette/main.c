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

	printf("1. �ٽ��ϱ�\n");
	printf("2. ����\n");

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
		printf("������ �����մϴ�\n");
		exit(1);
	}
}
void game()
{
	int remainBullet = NUMBER_OF_BULLETS;
	printf("������ �����Ϸ��� �ƹ� ��ư�̳� ��������\n");
	_getch();
	system("cls");

	for (int i = 0; i < NUMBER_OF_BULLETS; i++)
	{
		--remainBullet;
		if (gun[i] == 0)
		{
			printf("����\n");
			printf("���� �Ѿ� �� : %d", remainBullet);
			_getch();
			system("cls");
		}
		else if (gun[i] == 1)
		{
			printf("����\n");
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