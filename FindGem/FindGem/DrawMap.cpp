#include "DrawMap.h"

void DrawMap()
{
	for (int r = 0; r < MAP_WIDTH; r++)
	{
		for (int c = 0; c < MAP_HEIGHT; c++)
		{
			GotoXY(c, r);
			if (playerR == r && playerC == c)
			{
				printf("��");
			}
			else if (map[r][c] == ROAD)
			{
				printf("��");
			}
			else if (map[r][c] == WALL)
			{
				printf("��");
			}
			else if (map[r][c] == GEM)
			{
				printf("��");
			}
		}
		printf("\n");
	}
	//_sleep(200);
	//system("cls");
}