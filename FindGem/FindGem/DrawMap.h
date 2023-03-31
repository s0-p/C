#ifndef _DRAW_MAP_H_
#define _DRAW_MAP_H_

#include <stdio.h>
#include "Util.h"

#define MAP_WIDTH 10
#define MAP_HEIGHT 10

#define ROAD 0
#define WALL 1
#define GEM	2

extern int map[MAP_WIDTH][MAP_HEIGHT];
extern int playerR, playerC;

void DrawMap();
#endif

