#include "DrawMap.h"

void DrawMap()
{
	for (int r = 1; r < MAP_HEIGHT; r++)
	{
		GotoXY(0, r);
		printf("��");
		GotoXY(MAP_WIDTH - 1, r);
		printf("��");
	}
	for (int c = 0; c < MAP_WIDTH; c++)
	{
		GotoXY(c, 0);
		printf("��");
		GotoXY(c, MAP_HEIGHT - 1);
		printf("��");
	}
	printf("\n");
}