#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include "Util.h"

#define	MAP_HEIGHT	17
#define MAP_WIDTH	19

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27

#define HEAD	0
#define MAX_SNAKE_LEGTH	255

int snakeR[MAX_SNAKE_LEGTH];
int snakeC[MAX_SNAKE_LEGTH];
int snakeLength;
int dir;	// 현재방향
int key;	// 입력받은 방향

int appleR;
int appleC;
void DrawMap();

int main()
{
	DrawMap();
	snakeLength = 4;
	dir = RIGHT;
	snakeR[HEAD] = MAP_HEIGHT / 2;
	snakeC[HEAD] = MAP_WIDTH / 2 - 4;
	GotoXY(snakeC[HEAD], snakeR[HEAD]);
	printf("◈");
	for (int i = 1; i < snakeLength; i++)
	{
		snakeC[i] = snakeC[HEAD] - i;
		snakeR[i] = snakeR[HEAD];
		GotoXY(snakeC[i], snakeR[i]);
		printf("●");
	}
	appleR = MAP_HEIGHT / 2;
	appleC = MAP_WIDTH / 2 + 4;
	GotoXY(appleC, appleR);
	printf("♥");

	srand((unsigned int)time(NULL));
	SetCursorType(NO_CURSOR);
	while (true)
	{
		if (_kbhit())
		{
			key = _getch();
			if (key == 224)
			{
				key = _getch();
			}
		}
		switch (key)
		{
		case LEFT:
			if (dir != RIGHT)
			{
				dir = key;
			}
			break;
		case RIGHT:
			if (dir != LEFT)
			{
				dir = key;
			}
			break;
		case UP:
			if (dir != DOWN)
			{
				dir = key;
			}
			break;
		case DOWN:
			if (dir != UP)
			{
				dir = key;
			}
			break;
		default:
			break;
		}

		if (snakeC[HEAD] == 0 || snakeC[HEAD] == MAP_WIDTH - 1 || snakeR[HEAD] == 0 || snakeR[HEAD] == MAP_HEIGHT - 1)
		{
			GotoXY(snakeC[HEAD], snakeR[HEAD]);
			for (int i = 0; i < snakeLength; i++)
			{
				GotoXY(snakeC[i], snakeR[i]);
				printf("  ");
				Sleep(80);
			}
			GotoXY(0, MAP_HEIGHT);
			printf("-------------- GAME OUT --------------\n");
			exit(0);
		}

		if (snakeR[HEAD] == appleR && snakeC[HEAD] == appleC)
		{
			appleR = rand() % (MAP_HEIGHT-2) + 1;
			appleC = rand() % (MAP_WIDTH-2) + 1;
			GotoXY(appleC, appleR);
			printf("♥");

			if (snakeLength < MAX_SNAKE_LEGTH)
			{
				if (snakeR[snakeLength - 1] == snakeR[snakeLength - 2])
				{
					snakeR[snakeLength] = snakeR[snakeLength - 1];	// 꼬리와 몸통이 같은 행 다른 열에 있고
					if (snakeC[snakeLength - 1] < snakeC[snakeLength - 2])	//	현재 꼬리가 왼쪽에 있으므로
					{
						snakeC[snakeLength] = snakeC[snakeLength - 1]--;
					}
					else	//	현재 꼬리가 오른쪽에 있으므로
					{
						snakeC[snakeLength] = snakeC[snakeLength - 1]++;
					}
				}
				else
				{
					snakeC[snakeLength] = snakeC[snakeLength - 1];	// 꼬리와 몸통이 다른 행 같은 열에 있고
					if (snakeR[snakeLength - 1] < snakeR[snakeLength - 2])	//	현재 꼬리가 위쪽에 있으므로
					{
						snakeR[snakeLength] = snakeR[snakeLength - 1]--;
					}
					else	// 현재 꼬리가 아래쪽에 있으므로
					{
						snakeR[snakeLength] = snakeR[snakeLength - 1]++;
					}
				}
				snakeLength++;
				GotoXY(snakeC[snakeLength - 1], snakeR[snakeLength - 1]);
				printf("●");
			}
		}

		GotoXY(snakeC[HEAD], snakeR[HEAD]);
		printf("●");
		GotoXY(snakeC[snakeLength - 1], snakeR[snakeLength - 1]);
		printf("  ");
		for (int i = snakeLength - 1; i > 0; i--)
		{
			snakeC[i] = snakeC[i - 1];
			snakeR[i] = snakeR[i - 1];
		}

		switch (dir)
		{
		case LEFT:
			snakeC[HEAD]--;
			break;
		case RIGHT:
			snakeC[HEAD]++;
			break;
		case UP:
			snakeR[HEAD]--;
			break;
		case DOWN:
			snakeR[HEAD]++;
			break;
		case ESC:
			GotoXY(0, MAP_HEIGHT);
			printf("게임을 종료합니다.\n");
			exit(0);
		default:
			break;
		}
		GotoXY(snakeC[HEAD], snakeR[HEAD]);
		printf("◈");
		Sleep(200);
	}
}

void DrawMap()
{
	for (int r = 1; r < MAP_HEIGHT; r++)
	{
		GotoXY(0, r);
		printf("▨");
		GotoXY(MAP_WIDTH - 1, r);
		printf("▨");
	}
	for (int c = 0; c < MAP_WIDTH; c++)
	{
		GotoXY(c, 0);
		printf("▨");
		GotoXY(c, MAP_HEIGHT - 1);
		printf("▨");
	}
	printf("\n");
}