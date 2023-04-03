#include "Initalize.h"

void Initalize()
{
	InitSnake();
	InitApple();
}

void InitSnake()
{
	snakeLength = 4;
	speed = 300;
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
void InitApple()
{
	appleR = MAP_HEIGHT / 2;
	appleC = MAP_WIDTH / 2 + 4;
	GotoXY(appleC, appleR);
	printf("¢¾");

	currScore = 0;
	GotoXY(0, MAP_HEIGHT);
	printf("Score: %d\n", currScore);
}