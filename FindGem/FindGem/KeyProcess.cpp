#include "keyprocess.h"

void KeyProcess()
{
	move = -1;
	//printf("1.��, 2.��, 3. ��, 4.��, 0. ����: ");
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