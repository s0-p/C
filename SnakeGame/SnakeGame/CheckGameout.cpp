#include "CheckGameout.h"

void CheckGameOut()
{
	if (snakeC[HEAD] == 0 || snakeC[HEAD] == MAP_WIDTH - 1 || snakeR[HEAD] == 0 || snakeR[HEAD] == MAP_HEIGHT - 1)
	{
		GameOut();
	}

	for (int i = 1; i < snakeLength; i++)
	{
		if (snakeR[HEAD] == snakeR[i] && snakeC[HEAD] == snakeC[i])
		{
			GameOut();
		}
	}

}
void GameOut()
{
	GotoXY(snakeC[HEAD], snakeR[HEAD]);
	for (int i = 1; i < snakeLength; i++)
	{
		GotoXY(snakeC[i], snakeR[i]);
		printf("  ");
		Sleep(80);
	}
	GotoXY(0, MAP_HEIGHT+1);
	printf("-------------- GAME OUT --------------\n");
	exit(0);
}
