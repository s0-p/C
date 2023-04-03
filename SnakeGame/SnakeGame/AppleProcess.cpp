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
		printf("��");

		if (snakeR[snakeLength - 1] == snakeR[snakeLength - 2])
		{
			snakeR[snakeLength] = snakeR[snakeLength - 1];	// ������ ������ ���� �� �ٸ� ���� �ְ�
			if (snakeC[snakeLength - 1] < snakeC[snakeLength - 2])	//	���� ������ ���ʿ� �����Ƿ�
			{
				snakeC[snakeLength] = snakeC[snakeLength - 1]--;
			}
			else	//	���� ������ �����ʿ� �����Ƿ�
			{
				snakeC[snakeLength] = snakeC[snakeLength - 1]++;
			}
		}
		else
		{
			snakeC[snakeLength] = snakeC[snakeLength - 1];	// ������ ������ �ٸ� �� ���� ���� �ְ�
			if (snakeR[snakeLength - 1] < snakeR[snakeLength - 2])	//	���� ������ ���ʿ� �����Ƿ�
			{
				snakeR[snakeLength] = snakeR[snakeLength - 1]--;
			}
			else	// ���� ������ �Ʒ��ʿ� �����Ƿ�
			{
				snakeR[snakeLength] = snakeR[snakeLength - 1]++;
			}
		}
		snakeLength++;
		GotoXY(snakeC[snakeLength - 1], snakeR[snakeLength - 1]);
		printf("��");
	}
}