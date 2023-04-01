#include "DrawMap.h"

void DrawMap()
{
	for (int r = 1; r < MAP_HEIGHT; r++)
	{
		GotoXY(0, r);
		printf("¢É");
		GotoXY(MAP_WIDTH - 1, r);
		printf("¢É");
	}
	for (int c = 0; c < MAP_WIDTH; c++)
	{
		GotoXY(c, 0);
		printf("¢É");
		GotoXY(c, MAP_HEIGHT - 1);
		printf("¢É");
	}
	printf("\n");
}