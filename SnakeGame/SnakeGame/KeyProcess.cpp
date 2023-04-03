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
	switch (key)
	{
	case LEFT:
		if (dir != RIGHT)
		{
			dir = key;
		}
		break;
	case RIGHT:
		if (dir != LEFT)
		{
			dir = key;
		}
		break;
	case UP:
		if (dir != DOWN)
		{
			dir = key;
		}
		break;
	case DOWN:
		if (dir != UP)
		{
			dir = key;
		}
		break;
	case ESC:
		GotoXY(0, MAP_HEIGHT+1);
		printf("게임을 종료합니다.\n");
		exit(0);
	default:
		break;
	}
}