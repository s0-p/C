#include "InitApple.h"

void InitApple()
{
	appleR = MAP_HEIGHT / 2;
	appleC = MAP_WIDTH / 2 + 4;
	GotoXY(appleC, appleR);
	printf("¢¾");
}