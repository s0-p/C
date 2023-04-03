#include "InitApple.h"

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