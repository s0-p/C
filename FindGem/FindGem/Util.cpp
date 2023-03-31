#include "Util.h"

void GotoXY(int x, int y)	//커서제어
{
	COORD pos = { 2 * x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}
void SetCorsorType(CURSOR_TYPE c)	//커서 숨기기
{
	CONSOLE_CURSOR_INFO cursorInfo;

	switch (c)
	{
	case NO_CURSOR:
		cursorInfo.dwSize = 1;
		cursorInfo.bVisible = FALSE;
		break;
	case SOLID_CUSOR:
		cursorInfo.dwSize = 100;
		cursorInfo.bVisible = TRUE;
		break;
	case NORMAL_CURSOR:
		cursorInfo.dwSize = 20;
		cursorInfo.bVisible = TRUE;
		break;
	default:
		break;
	}
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}