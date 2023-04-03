#ifndef _INITALIZE_H
#define	_INITALIZE_H
#include <stdio.h>
#include "Constants.h"
#include "Util.h"

extern int snakeR[MAX_SNAKE_LEGTH];
extern int snakeC[MAX_SNAKE_LEGTH];
extern int snakeLength;
extern int speed;
extern int dir;

extern int appleR;
extern int appleC;
extern int currScore;

void Initalize();
void InitSnake();
void InitApple();
#endif


