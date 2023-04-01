#include "InitSnake.h"

void InitSnake()
{
	snakeLength = 4;
	dir = RIGHT;
	snakeR[HEAD] = MAP_HEIGHT / 2;
	snakeC[HEAD] = MAP_WIDTH / 2 - 4;
	GotoXY(snakeC[HEAD], snakeR[HEAD]);
	printf("¢Â");
	for (int i = 1; i < snakeLength; i++)
	{
		snakeC[i] = snakeC[HEAD] - i;
		snakeR[i] = snakeR[HEAD];
		GotoXY(snakeC[i], snakeR[i]);
		printf("¡Ü");
	}
}