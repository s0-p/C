#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <Windows.h>

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

#define ROAD 0
#define WALL 1
#define GEM	2

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define ESC 27

enum CURSOR_TYPE
{
	NO_CURSOR,
	SOLID_CUSOR,
	NORMAL_CURSOR
};
void GotoXY(int x, int y);	//커서 제어
void SetCorsorType(CURSOR_TYPE c);	//커서 숨기기

int main()
{
	int map[MAP_WIDTH][MAP_HEIGHT] = {		//tile map
		{0,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,0,0,1},
		{1,0,0,0,0,0,1,1,0,1},
		{1,0,0,0,2,0,1,1,0,1},
		{1,1,1,1,1,0,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
	};
	int playerR = 0, playerC = 0;
	int move = 0;
	SetCorsorType(NO_CURSOR);

	while (true)
	{
		if (map[playerR][playerC] == GEM)
		{
			printf("축하합니다. 보석을 찾았습니다!\n");
			playerR = playerC = 0;
		}

		move = -1;
		//printf("1.좌, 2.우, 3. 상, 4.하, 0. 종료: ");
		//scanf("%d", &move);
		if (_kbhit())
		{
			move = _getch();
			if (move == 224)
			{
				move = _getch();
			}
		}
				
		switch (move)
		{
		case LEFT:
			if (playerC - 1 >= 0)
			{

				if (map[playerR][playerC - 1] != WALL)
				{
					playerC--;
				}
				else
				{
					printf("해당 방향으로 이동할 수 없습니다.\n");
				}

			}
			break;
		case RIGHT:
			if (playerC + 1 < MAP_WIDTH)
			{
				if (map[playerR][playerC + 1] != WALL)
				{
					playerC++;
				}
				else
				{
					printf("해당 방향으로 이동할 수 없습니다.\n");
				}
			}
			break;
		case UP:
			if (playerR - 1 >= 0)
			{
				if (map[playerR - 1][playerC] != WALL)
				{
					playerR--;
				}
				else
				{
					printf("해당 방향으로 이동할 수 없습니다.\n");
				}
			}
			break;
		case DOWN:
			if (playerR + 1 < MAP_HEIGHT)
			{
				if (map[playerR + 1][playerC] != WALL)
				{
					playerR++;
				}
				else
				{
					printf("해당 방향으로 이동할 수 없습니다.\n");
				}
			}
			break;
		case ESC:
			printf("게임을 종료합니다.\n");
			exit(0);
		default:
			if (move != -1)
			{
				printf("잘못된 입력입니다.\n");
				break;
			}
		}
			
		for (int r = 0; r < MAP_WIDTH; r++)
		{
			for (int c = 0; c < MAP_HEIGHT; c++)
			{
				GotoXY(c, r);
				if (playerR == r && playerC == c)
				{
					printf("♥");
				}
				else if (map[r][c] == ROAD)
				{
					printf("□");
				}
				else if (map[r][c] == WALL)
				{
					printf("■");
				}
				else if (map[r][c] == GEM)
				{
					printf("◈");
				}
			}
			printf("\n");
		}
		//_sleep(200);
		//system("cls");
	}
}
void GotoXY(int x, int y)
{
	COORD pos = { 2 * x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void SetCorsorType(CURSOR_TYPE c)
{
	CONSOLE_CURSOR_INFO cursorInfo;

	switch (c)
	{
	case NO_CURSOR:
		cursorInfo.dwSize = 1;
		cursorInfo.bVisible = FALSE;
		break;
	case SOLID_CUSOR:
		cursorInfo.dwSize = 100;
		cursorInfo.bVisible = TRUE;
		break;
	case NORMAL_CURSOR:
		cursorInfo.dwSize = 20;
		cursorInfo.bVisible = TRUE;
		break;
	default:
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}