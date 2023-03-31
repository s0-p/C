#ifndef _Util_H_
#define	_Util_H_
#include <Windows.h>

enum CURSOR_TYPE
{
	NO_CURSOR,
	SOLID_CUSOR,
	NORMAL_CURSOR
};

void GotoXY(int x, int y);
void SetCorsorType(CURSOR_TYPE c);
#endif
