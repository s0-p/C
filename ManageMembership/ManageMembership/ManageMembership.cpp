#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS	3
typedef	struct _User
{
	int id;
	char name[11];
	int age;
}User;

int PrintMenu();
void AddUser(User users[], int usersCnt);
void DeleteUser(User users[], int usersCnt);
void PrintUsers(User users[], int usersCnt);

int main()
{
	User* users = (User*)malloc(sizeof(User) * MAX_USERS);
	int select = 1;
	int usersCnt = 0;

	do
	{
		switch (select)
		{
		case 0:
			printf("프로그램을 종료합니다.\n");
			free(users);
			return 0;

		case 1:
			AddUser(users, usersCnt);
			printf("\n");
			usersCnt++;
			break;

		case 2:
			DeleteUser(users, usersCnt);
			usersCnt--;
			break;
		
		case 3:
			PrintUsers(users, usersCnt);
			printf("\n");
			break;
		
		default:
			break;
		}
		select = PrintMenu();
		printf("\n");
	} while (true);

}
int PrintMenu()
{
	int select;
	printf("===========MENU===========\n");
	printf("1. User정보 추가\n");
	printf("2. User정보 삭제\n");
	printf("3. User정보 출력\n");
	printf("0. 종료\n");
	scanf("%d", &select);
	return select;
}
void AddUser(User users[], int usersCnt)
{
	int isTry = 1;
	while (isTry)
	{
		isTry = 0;
		printf("ID를 입력하세요: ");
		scanf("%d", &users[usersCnt].id);
		for (int i = 0; i < usersCnt  ; i++)
		{	
			if (users[i].id == users[usersCnt].id)
			{
				isTry = 1;
				printf("이미 존재하는 ID입니다.\n");
				printf("다른 ");
				break;
			}
		}
	}
	printf("이름을 입력하세요: ");
	scanf("%s", &users[usersCnt].name);
	printf("나이를 입력하세요: ");
	scanf("%d", &users[usersCnt].age);
}
void DeleteUser(User users[], int usersCnt)
{
	int userId;
	int isTry = 1;
	int pos = -1;
	
	printf("삭제할 사용자의 ID를 입력해주세요: ");
	scanf("%d", &userId);
	for (int i = 0; i < usersCnt; i++)
	{
		if (users[i].id == userId)
		{
			pos = i;
			isTry = 0;
			break;
		}
	}

	if (pos == -1)
	{
		printf("해당하는 ID가 없습니다.\n");
	}
	else
	{
		//User* temp;
		
		for (int i = pos; i < usersCnt - 1; i++)
		{
			users[i] = users[i + 1];
		}
		users[usersCnt].id = NULL;
		strcpy(users[usersCnt].name, "");
		users[usersCnt].age = NULL;

		printf("삭제되었습니다.\n");
	}
}
void PrintUsers(User users[], int usersCnt)
{
	printf("|%10s|%10s|%10s|\n", "ID", "Name", "Age");
	for (int i = 0; i < usersCnt; i++)
	{
		printf("|%10d|%10s|%10d|\n", users[i].id, users[i].name, users[i].age);
	}
}