#include <stdio.h>
#include <string.h>

#define ITEM_CNT 5

typedef struct _ITEM
{
	char name[9];
	int price;
	float rating;
}ITEM;

int main()
{
	ITEM items[ITEM_CNT] = {
		{"니콘", 1000000, 4.5f},
		{"캐논", 1000354, 4.2f},
		{"소니", 1234500, 3.8f},
		{"라이카", 2134220, 4.0f},
		{"삼성", 1347823, 5.0f}
	};
	int sortType;
	int isTry = 1;

	while (isTry)
	{
		printf("-------------------------------------------------------\n");
		printf("%-15s %-15s %-15s %-15s\n", "번호", "상품명", "가격", "평점");
		printf("-------------------------------------------------------\n");
		for (int i = 0; i < ITEM_CNT; i++)
		{
			printf("[%2d]%-10s[%6s]%-8s", i + 1, " ", items[i].name, " ");
			printf("[%d]%-8s[%.3f]\n", items[i].price, " ", items[i].rating);
		}
		printf("-------------------------------------------------------\n");
		printf("어떤 기준으로 정렬할지 숫자로 입력해주세요.\n");
		printf("(1.이름순, 2.낮은 가격순, 3.높은 가격순, 4. 평점순, 0.종료) ");
		scanf("%d", &sortType);
		printf("\n");
		switch (sortType)
		{
		case 0:
			isTry = 0;
			printf("프로그램을 종료합니다.\n");
			break;
		case 1:
			printf("이름순\n");
			for (int i = 0; i < ITEM_CNT - 1; i++)
			{
				for (int j = 0; j < ITEM_CNT - i - 1; j++)
				{
					if (strcmp(items[j].name, items[j + 1].name) == 1)
					{
						ITEM tmp = items[j];
						items[j] = items[j + 1];
						items[j + 1] = tmp;
					}
				}
			}
			break;
		case 2:
			printf("낮은 가격순\n");
			for (int i = 0; i < ITEM_CNT - 1; i++)
			{
				for (int j = 0; j < ITEM_CNT - i - 1; j++)
				{
					if (items[j].price > items[j + 1].price)
					{
						ITEM tmp = items[j];
						items[j] = items[j + 1];
						items[j + 1] = tmp;
					}
				}
			}
			break;
		case 3:
			printf("높은 가격순\n");
			for (int i = 0; i < ITEM_CNT - 1; i++)
			{
				for (int j = 0; j < ITEM_CNT - i - 1; j++)
				{
					if (items[j].price < items[j + 1].price)
					{
						ITEM tmp = items[j];
						items[j] = items[j + 1];
						items[j + 1] = tmp;
					}
				}
			}
			break;
		case 4:
			printf("평점순\n");
			for (int i = 0; i < ITEM_CNT - 1; i++)
			{
				for (int j = 0; j < ITEM_CNT - i - 1; j++)
				{
					if (items[j].rating < items[j + 1].rating)
					{
						ITEM tmp = items[j];
						items[j] = items[j + 1];
						items[j + 1] = tmp;
					}
				}
			}
			break;
		default:
			printf("잘못된 입력입니다.\n");
			break;
		}




	}
}