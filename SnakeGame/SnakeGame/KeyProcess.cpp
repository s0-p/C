#include "KeyProcess.h"

void KeyProcess()
{
	if (_kbhit())
	{
		key = _getch();
		if (key == 224)
		{
			key = _getch();
		}
	}

	if (key == ESC)
	{
		GotoXY(0, MAP_HEIGHT + 1);
		printf("게임을 종료합니다.\n");
		exit(0);
	}

	if( (key == LEFT && dir != RIGHT) ||
		(key == RIGHT && dir != LEFT) ||
		(key == UP && dir != DOWN) ||
		(key == DOWN && dir != UP) )
	{
		dir = key;
	}
}