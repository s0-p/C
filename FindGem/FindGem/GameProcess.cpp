#include "GameProcess.h"

void GameProcess()
{
	if (map[playerR][playerC] == GEM)
	{
		printf("축하합니다. 보석을 찾았습니다!\n");
		playerR = playerC = 0;
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
}