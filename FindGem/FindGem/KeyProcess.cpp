#include "keyprocess.h"

void KeyProcess()
{
	move = -1;
	//printf("1.좌, 2.우, 3. 상, 4.하, 0. 종료: ");
	//scanf("%d", &move);
	if (_kbhit())
	{
		move = _getch();
		if (move == 224)
		{
			move = _getch();
		}
	}
}