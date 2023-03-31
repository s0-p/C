#include <stdio.h>
#include <time.h>
#include "Util.h"
#include "KeyProcess.h"
#include "DrawMap.h"
#include "GameProcess.h"

int map[MAP_WIDTH][MAP_HEIGHT] = {		//tile map
		{0,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,0,0,1},
		{1,0,0,0,0,0,1,1,0,1},
		{1,0,0,0,2,0,1,1,0,1},
		{1,1,1,1,1,0,1,1,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,0,0,0,0,0,0,0,0,1},
		{1,1,1,1,1,1,1,1,1,1}
};
int playerR = 0, playerC = 0;
int move = 0;

int main()
{
	SetCorsorType(NO_CURSOR);

	while (true)
	{
		KeyProcess();
		GameProcess();
		DrawMap();
	}
}
