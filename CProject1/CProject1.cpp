// CProject1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

#include <stdio.h>	// include standard input output head
//#include <string.h>
//#define WP_SWORD	0x00000001
//#define WP_AXE		0x00000002
//#define WP_GUN		0x00000004
//#define WP_BOW		0x00000008
//#define WP_STAFF	0x00000010
int main()
{
	//while문 예제
	/*int num = 0, sum = 0, i = 1;
	printf("정수를 입력 해주세요: ");
	scanf("%d", &num);

	while (i <= num)
	{
		sum += i;
		i++;
	}
	printf("입력한 정수의 1부터의 총합은 %d입니다.\n", sum);*/
	/*int i = 65;
	while (i <= 122)
	{
		printf("%5d - %c\t\t", i, i);
		i++;
	}
	printf("\n\n");
	for (i = 65; i <= 122; i++)
	{
		printf("%5d - %c\t\t", i, i);
	}*/
	//구구단
	int step = 0, num = 1;
	printf("출력할 단을 입력하세요: ");
	scanf("%d", &step);
	while (num <= 9)
	{
		printf("%d * %d = %d\n", step, num, step * num);
		num++;
	}
	
	//for문
	/*char name[] = "welcome to SBS Games Academy";
	for (int i = 0; i < strlen(name); i++)
	{
		printf("%c\n", name[i]);
	}*/
	/*int num = 0;
	int sum = 0;
	printf("정수를 입력하세요: ");
	scanf("%d", &num);

	for (int i = 1; i <= num; i++)
	{
		sum += i;
	}
	printf("입력한 정수의 1부터의 총합은 %d입니다.\n", sum);*/
	//*사각형 그리기(for문)
	//int line = 0;
	//printf("출력할 라인 수를 입력하세요: ");
	//scanf("%d", &line);
	//for (int i = 0; i < line; i++)
	//{
	//	for (int j = 0; j < line; j++);
	//	{
	//		printf("*");
	//	}
	//	printf("\n");
	//}
	//삼각형 그리기(for문)
	/*int line = 0;
	printf("라인 수를 입력하세요: ");
	scanf("%d", &line);

	for (int i = 0; i < line; i++)
	{
		for (int j = 0; j < line - i - 1; j++)
		{
			printf(" ");
		}
		for (int k = 0; k < 2 * i + 1; k++)
		{
			printf("*");
		}
		printf("\n");
	}*/

	//BMI 계산기(제어문)
	/*char name[11], sex[5];
	float height, weight, bmi;

	printf("이름을 입력해주세요: ");
	scanf("%s", name);
	printf("성별을 입력해주세요(남자/여자): ");
	scanf("%s", sex);
	printf("키를 입력해주세요(cm): ");
	scanf("%f", &height);
	printf("체중을 입력해주세요(kg): ");
	scanf("%f", &weight);

	if (height < 0 || weight < 0)
	{
		printf("잘못된 입력입니다.");
	}
	else
	{
		height *= 0.01f;
		bmi = weight / (height * height);
		if (bmi < 18.5f)
		{
			printf("이름: %s 성별: %s 키: %.2f(m) 체중: %.2f(kg) BMI: %.2f 저체중입니다.", name, sex, height, weight, bmi);
		}
		else if (bmi <= 22.9f)
		{
			printf("이름: %s 성별: %s 키: %.2f(m) 체중: %.2f(kg) BMI: %.2f 정상체중입니다.", name, sex, height, weight, bmi);

		}
		else if (bmi <= 24.9f)
		{
			printf("이름: %s 성별: %s 키: %.2f(m) 체중: %.2f(kg) BMI: %.2f 과체중입니다.", name, sex, height, weight, bmi);

		}
		else if (bmi <= 29.9f)
		{
			printf("이름: %s 성별: %s 키: %.2f(m) 체중: %.2f(kg) BMI: %.2f 비만입니다.", name, sex, height, weight, bmi);

		}
		else
		{
			printf("이름: %s 성별: %s 키: %.2f(m) 체중: %.2f(kg) BMI: %.2f 고도비만입니다.", name, sex, height, weight, bmi);
		}
	}*/

	//swich-case 예제
	/*int score;
	printf("점수를 입력하세요(1~100): ");
	scanf("%d", &score);
	if (score > 100 || score < 0)
	{
		printf("잘못된 입력입니다.\n");
	}
	else
	{
		switch (score/10)
		{
		case 10: case 9:
			printf("A 학점입니다.\n");
			break;
		case 8:
			printf("B 학점입니다.\n");
			break;
		case 7:
			printf("C 학점입니다.\n");
			break;
		case 6:
			printf("D 학점입니다.\n");
			break;
		default:
			printf("F 학점 입니다.\n");
			break;
		}
	}*/

	//else if 예제
	/*
	if (score > 100 || score < 0)
	{
		printf("잘못된 입력입니다.\n");
	}
	else if (score >= 90)
	{
		printf("A 학점입니다.\n");
	}
	else if (score >= 80)
	{
		printf("B 학점입니다.\n");
	}
	else if (score >= 70)
	{
		printf("C 학점입니다.\n");
	}
	else if (score >= 60)
	{
		printf("D 학점입니다.\n");
	}
	else
	{
		printf("F 학점입니다.\n");
	}*/

	//비트연산자 활용
	////무기 장착
	//int iWeapon = WP_SWORD | WP_AXE | WP_GUN;
	////장착 해제
	//iWeapon = iWeapon & ~WP_AXE;
	//if (iWeapon & WP_SWORD)
	//{	printf("SWORD 장착\n");	}
	//if (iWeapon & WP_AXE)
	//{	printf("AXE 장착\n");}
	//if (iWeapon & WP_GUN)
	//{	printf("GUN 장착\n");}
	//if (iWeapon & WP_BOW)
	//{	printf("BOW 장착\n");	}
	//if (iWeapon & WP_STAFF)
	//{	printf("STAFF 장착\n");	}

	//제어문
	/*int num1 = 0, num2 = 0;
	printf("두 개의 정수를 입력하세요: ");
	scanf("%d %d", &num1, &num2);
	if (num1 > num2)
	{
		printf("두 수 중에 큰 수는 %d입니다\n", num1);
	}
	else if (num1 < num2)
	{
		printf("두 수 중에 큰 수는 %d입니다\n", num2);
	}
	else
	{
		printf("두 수는 같습니다.\n");
	}*/

	/*	비트연산
	val1 = 0111, val2 = 0101
	val1 & val2 = 0101 = 5
	val1 | val2 = 0111
	val1 ^ val2 = 0010 = 2
	~val1 = 1000 = -8
	val1 << 2 = 1 1100 = 28
	val2 >> 2 = 0001 = 1
	*/
	/*unsigned char val1 = 7, val2 = 5;
	printf("val1 & val2 = %d\n", val1 & val2);
	printf("val1 | val2 = %d\n", val1 | val2);
	printf("val1 ^ val2 = %d\n", val1 ^ val2);
	printf("~val1 = %d\n", ~val1);
	printf("val1 << 2 = %d\n", val1 << 2);
	printf("val1 >> 2 = %d\n", val2 >> 2);*/

	//char name[11];	// 마지막 byte에는 \0(null)
	//int age = 0;
	//float height = 0;
	//float weight = 0;
	
	//입출력, 주소지정자
	/*printf("이름을 입력해주세요: ");
	scanf("%s", name);
	printf("나이를 입력해주세요: ");
	scanf("%d", &age);

	printf("신장을 입력해주세요: ");
	scanf("%f", &height);

	printf("체중을 입력해주세요: ");
	scanf("%f", &weight);

	printf("내 이름은 %s입니다. 나이는 %d입니다.\n신장은 %.1fcm이고 체중은 %.1fkg입니다.\n", name, age, height, weight);
	*/

	//필드 지정 정렬
	/*printf("[%-8s] [%-4s] [%10s]\n", "이름", "나이", "주소");
	printf("[%-8s] [%-4d] [%10s]\n", "이민수", 40, "서울특별시");
	printf("[%-8s] [%-4d] [%10s]\n", "원빈", 5, "수원시");
	printf("[%-8s] [%-4d] [%10s]\n", "제갈공명", 220, "강릉");*/

	//정밀도 지정
	/*printf("%.4d\n", 12);
	printf("%.5s\n", "hello world");*/

	


}