#include <stdlib.h>
#include <time.h>
#include "Util.h"
#include "Initalize.h"
#include "DrawMap.h"
#include "KeyProcess.h"
#include "DrawSnake.h"
#include "AppleProcess.h"
#include "CheckGameout.h"

int snakeR[MAX_SNAKE_LEGTH];
int snakeC[MAX_SNAKE_LEGTH];
int snakeLength;
int speed;
int dir;

int appleR;
int appleC;

int key;

int currScore;

int main()
{
	Initalize();

	srand((unsigned int)time(NULL));
	SetCursorType(NO_CURSOR);
	while (true)
	{
		KeyProcess();
		DrawSnake();
		AppleProcess();
		DrawMap();
		CheckGameOut();
	}
}