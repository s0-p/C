#include "GameProcess.h"

void GameProcess()
{
	if (map[playerR][playerC] == GEM)
	{
		printf("�����մϴ�. ������ ã�ҽ��ϴ�!\n");
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
				printf("�ش� �������� �̵��� �� �����ϴ�.\n");
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
				printf("�ش� �������� �̵��� �� �����ϴ�.\n");
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
				printf("�ش� �������� �̵��� �� �����ϴ�.\n");
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
				printf("�ش� �������� �̵��� �� �����ϴ�.\n");
			}
		}
		break;
	case ESC:
		printf("������ �����մϴ�.\n");
		exit(0);
	default:
		if (move != -1)
		{
			printf("�߸��� �Է��Դϴ�.\n");
			break;
		}
	}
}