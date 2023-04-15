#include <stdio.h>
#include <string.h>

#define NAME_MAX_LEN 11
#define EMAIL_MAX_LEN 26
#define PASSWORD_MIN_LEN 6
#define PASSWORD_MAX_LEN 9

int main()
{
	char input[NAME_MAX_LEN + 10];
	char name[NAME_MAX_LEN];
	char email[EMAIL_MAX_LEN];
	char password[PASSWORD_MAX_LEN];
	int isTry;

	do
	{
		isTry = 0;
		printf("가입하실 이름을 입력해주세요.(한글 5, 영문 10글자 이내)\n");
		scanf("%s", input);

		if (strlen(input) > NAME_MAX_LEN)
		{
			printf("이름이 너무 깁니다. 다시 입력해주세요.\n");
			isTry = 1;
		}
	} while (isTry);
	strcpy(name, input);
	
	do
	{
		isTry = 0;
		printf("가입하실 아이디를 email 주소로 입력해주세요.\n");
		scanf("%s", input);

		if (strchr(input, '@') == NULL)
		{
			printf("email 형식이 아닙니다. 다시 입력해주세요.\n");
			isTry = 1;
		}
	} while (isTry);
	strcpy(email, input);

	do
	{
		isTry = 0;
		printf("비밀번호를 입력해주세요.(6글자 이상 8글자 이내)\n");
		scanf("%s", input);

		if (strlen(input) < PASSWORD_MIN_LEN)
		{
			printf("비밀번호가 너무 짧습니다.\n");
			isTry = 1;
		}
		else if (strlen(input) >= PASSWORD_MAX_LEN)
		{
			printf("비밀번호가 너무 깁니다.\n");
			isTry = 1;
		}
	} while (isTry);
	strcpy(password, input);


	do
	{
		isTry = 0;
		printf("비밀번호 확인을 위해 다시 입력해주세요.(6글자 이상 8글자 이내)\n");
		scanf("%s", input);

		if (strcmp(password, input) != 0)
		{
			printf("비밀번호가 다릅니다.\n");
			isTry = 1;
		}
	} while (isTry);

	printf("이름 : %s\n", name);
	printf("아이디: %s\n", email);
	printf("비밀번호: %s\n", password);
	printf("회원 가입되었습니다.\n");

}