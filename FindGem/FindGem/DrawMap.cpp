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
				printf("в╛");
			}
			else if (map[r][c] == ROAD)
			{
				printf("бр");
			}
			else if (map[r][c] == WALL)
			{
				printf("бс");
			}
			else if (map[r][c] == GEM)
			{
				printf("в┬");
			}
		}
		printf("\n");
	}
	//_sleep(200);
	//system("cls");
}