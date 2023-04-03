#include "AppleProcess.h"

void AppleProcess()
{
	if (snakeR[HEAD] == appleR && snakeC[HEAD] == appleC)
	{
		currScore++;
		GotoXY(0, MAP_HEIGHT);
		printf("Score: %d\n", currScore);
		bool check;
		do
		{
			check = false;
			appleR = rand() % (MAP_HEIGHT - 2) + 1;
			appleC = rand() % (MAP_WIDTH - 2) + 1;

			for (int i = 0; i < snakeLength; i++)
			{
				if (appleR == snakeR[i] && appleC == snakeC[i])
				{
					check = true;
					break;
				}
			}
		} while (check);
		GotoXY(appleC, appleR);
		printf("♥");

		if (snakeR[snakeLength - 1] == snakeR[snakeLength - 2])
		{
			snakeR[snakeLength] = snakeR[snakeLength - 1];	// 꼬리와 몸통이 같은 행 다른 열에 있고
			if (snakeC[snakeLength - 1] < snakeC[snakeLength - 2])	//	현재 꼬리가 왼쪽에 있으므로
			{
				snakeC[snakeLength] = snakeC[snakeLength - 1]--;
			}
			else	//	현재 꼬리가 오른쪽에 있으므로
			{
				snakeC[snakeLength] = snakeC[snakeLength - 1]++;
			}
		}
		else
		{
			snakeC[snakeLength] = snakeC[snakeLength - 1];	// 꼬리와 몸통이 다른 행 같은 열에 있고
			if (snakeR[snakeLength - 1] < snakeR[snakeLength - 2])	//	현재 꼬리가 위쪽에 있으므로
			{
				snakeR[snakeLength] = snakeR[snakeLength - 1]--;
			}
			else	// 현재 꼬리가 아래쪽에 있으므로
			{
				snakeR[snakeLength] = snakeR[snakeLength - 1]++;
			}
		}
		snakeLength++;
		GotoXY(snakeC[snakeLength - 1], snakeR[snakeLength - 1]);
		printf("●");
	}
}