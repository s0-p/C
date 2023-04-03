#ifndef _INIT_SNAKE_H
#define	_INIT_SNAKE_H
#include <stdio.h>
#include "Constants.h"
#include "Util.h"

extern int snakeR[MAX_SNAKE_LEGTH];
extern int snakeC[MAX_SNAKE_LEGTH];
extern int snakeLength;
extern int speed;
extern int dir;

void InitSnake();
#endif // !_INIT_SNAKE_H

