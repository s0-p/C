﻿#include <stdlib.h>
#include <time.h>
#include "Util.h"
#include "InitSnake.h"
#include "InitApple.h"
#include "DrawMap.h"
#include "KeyProcess.h"
#include "DrawSnake.h"
#include "AppleProcess.h"
#include "CheckGameout.h"

int snakeR[MAX_SNAKE_LEGTH];
int snakeC[MAX_SNAKE_LEGTH];
int snakeLength;
int dir;

int appleR;
int appleC;

int key;

int main()
{
	InitSnake();
	InitApple();

	srand((unsigned int)time(NULL));
	SetCursorType(NO_CURSOR);
	while (true)
	{
		DrawMap();
		KeyProcess();
		DrawSnake();
		AppleProcess();
		CheckGameOut();
	}
}