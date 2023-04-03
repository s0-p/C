#include "DrawSnake.h"

void DrawSnake()
{
	GotoXY(snakeC[HEAD], snakeR[HEAD]);
	printf("¡Ü");
	GotoXY(snakeC[snakeLength - 1], snakeR[snakeLength - 1]);
	printf("  ");
	for (int i = snakeLength - 1; i > 0; i--)
	{
		snakeC[i] = snakeC[i - 1];
		snakeR[i] = snakeR[i - 1];
	}

	switch (dir)
	{
	case LEFT:
		snakeC[HEAD]--;
		break;
	case RIGHT:
		snakeC[HEAD]++;
		break;
	case UP:
		snakeR[HEAD]--;
		break;
	case DOWN:
		snakeR[HEAD]++;
		break;
	default:
		break;
	}
	GotoXY(snakeC[HEAD], snakeR[HEAD]);
	printf("¢Â");
	Sleep(speed);
}