#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

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
		_sleep(200);
		system("cls");
	}
}