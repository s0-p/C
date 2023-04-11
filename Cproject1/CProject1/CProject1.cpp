﻿// CProject1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.

//#include <time.h>
//#include <string.h>
//#include <conio.h>	//console

 
//#define WP_SWORD		0x00000001
//#define WP_AXE		0x00000002
//#define WP_GUN		0x00000004
//#define WP_BOW		0x00000008
//#define WP_STAFF		0x00000010
//#define SQUARE1(a)	a*a
//#define SQUARE2(a)	((a)*(a))

#include <stdio.h>	// include standard input output head
#include <string.h>
#include <stdlib.h>
#include <Windows.h>

int main()
{
	FILE* fp;
	BITMAPFILEHEADER bfh;
	BITMAPINFOHEADER bih;
	unsigned char* image = NULL;
	int r, g, b, color;

	fp = fopen("image01.bmp", "rb");
	if (fp == NULL)
	{
		printf("파일을 여는데 실패했습니다.\n");
		return 0;
	}
	fread(&bfh, sizeof(BITMAPFILEHEADER), 1, fp);
	if (bfh.bfType != 'MB')	// little endian
	{
		printf("비트맵 파일이 아닙니다.\n");
		fclose(fp);
		return 0;
	}
	printf("비트맵 타입: %c%c\n", bfh.bfType, bfh.bfType >> 8);	//BM
	printf("비트맵 크기: %.2fMB\n", (float)bfh.bfSize / 1024.0 / 1024.0f);	//byte -> KB -> MB

	fread(&bih, sizeof(BITMAPINFOHEADER), 1, fp);
	printf("이미지 가로 넓이: %dpixel\n", bih.biWidth);
	printf("이미지 세로 높이: %dpixel\n", bih.biHeight);
	printf("이미지 비트 수: %dbit\n", bih.biBitCount);
	printf("이미지 크기: %dbyte\n", bih.biSizeImage);

	image = (unsigned char*)malloc(bih.biSizeImage);
	fread(image, bih.biSizeImage, 1, fp);
	fclose(fp);

	fp = fopen("output.bmp", "wb");
	fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, fp);
	fwrite(&bih, sizeof(BITMAPINFOHEADER), 1, fp);
	for (int i = 0; i < bih.biSizeImage - 3; i += 3)
	{
		//원래는 bgr순
		r = image[i + 0];
		g = image[i + 1];
		b = image[i + 2];

		color = (r + g + b) / 3;
		image[i + 0] = color;
		image[i + 1] = color;
		image[i + 2] = color;
	}
	fwrite(image, bih.biSizeImage, 1, fp);
	fclose(fp);
}
	//파일 io
	/*FILE* fp;
	int num1 = 0, num2 = 0, result = 0;
	char ch1, ch2;
	fp = fopen("multupl_table.txt", "wt");

	if (fp == NULL)
	{
		printf("파일을 여는데 실패하였습니다.");
		return 0;
	}
	for (int i = 1; i < 10; i++)
	{
		fprintf(fp, "2 * %d = %d\n", i, 2 * i);
	}
	fclose(fp);
	fp = fopen("multupl_table.txt", "rt");
	if (fp == NULL)
	{
		printf("파일을 여는데 실패하였습니다.");
		return 0;
	}
	for (int i = 0; i < 10; i++)
	{
		fscanf(fp, "%d %c %d %c %d", &num1, &ch1, &num2, &ch2, &result);
		printf("%d %c %d %c %d\n", num1, ch1, num2, ch2, result);
	}
	fclose(fp);*/

	/*PERSON person = { 0 };
	PERSON tmpperson;
	FILE* fp;
	fp = fopen("person.txt", "wb+");
	if (fp == NULL)
	{
		printf("파일을 여는데 실패했습니다.\n");
		return 0;
	}
	printf("이름을 입력하세요: ");
	scanf("%s", person.name);
	printf("나이를 입력하세요: ");
	scanf("%d", &person.age);
	printf("몸무게를 입력하세요: ");
	scanf("%f", &person.weight);

	fwrite((void*)&person, sizeof(person), 1, fp);
	fseek(fp, 0, SEEK_SET);
	fread((void*)&tmpperson, sizeof(tmpperson), 1, fp);
	printf("이름: %s, 나이: %d, 몸무게: %.2f\n", tmpperson.name, tmpperson.age, tmpperson.weight);
	fclose(fp);*/


//구조체	
//typedef struct _Student
//{
//	char name[10];
//	int koScore;
//	int enScore;
//	int mathScore;
//}Student;
	/*Student student[5];
	for (int i = 0; i < 5; i++)
	{
		printf("학생의 이름을 입력해주세요 : ");
		scanf("%s", &student[i].name);

		printf("국어, 영어, 수학 순으로 성적을 입력해주세요\n");
		scanf("%d %d %d", &student[i].koScore, &student[i].enScore, &student[i].mathScore);
		printf("\n");
	}

	for (int i = 0; i < 5; i++)
	{
		printf("%s - 국어: %d 영어: %d 수학: %d\n", student[i].name, student[i].koScore, student[i].enScore, student[i].mathScore);
	}*/

//typedef struct _Name
//{
//	char first[10];
//	char last[10];
//}Name;
//typedef struct _Student
//{
//	int num;
//	int cls;
//	Name *name;
//}Student;
	/*Name name = { "소영", "박" };
	Student me = { 1, 2 };
	me.name = &name;
	printf("번호: %d 반: %d 이름: %s 성: %s\n", me.num, me.cls, (*me.name).first, me.name->last);*/

	//동적할당 예제
	/*int length = 0;
	int* pList = NULL;

	printf("배열의 길이를 입력하세요: ");
	scanf("%d", &length);

	pList = (int*)malloc(sizeof(int) * length);
	for (int i = 0; i < length; i++)
	{
		pList[i] = i + 1;
		printf("pList[%d] : %3d\n", i, pList[i]);
	}
	free(pList);*/

	/*char* str1 = (char*)malloc(strlen("공유는") + 1);	//+1은 '\0'을 위한 공간
	char* str2 = (char*)malloc(strlen("TVN드라마") + 1);
	char* str3 = (char*)malloc(strlen("도깨비에서 남자 주인공이다.") + 1);

	strcpy(str1, "공유는");
	strcpy(str2, "TVN드라마");
	strcpy(str3, "도깨비에서 남자 주인공이다.");
	printf("%s %s %s\n", str1, str2, str3);
	free(str1);
	free(str2);
	free(str3);*/

	/*int* ptr = NULL;
	int size = 10;

	ptr = (int*)malloc(sizeof(int) * size);
	if (ptr != NULL)
	{
		memset(ptr, 0, sizeof(int) * 10);
		for (int i = 0; i < size; i++)
		{
			printf("%d: %d\n", i + 1, *ptr++);
		}
		free(ptr);	//error
	}*/

//typedef struct _Value
//{
//	char a;
//	char b;
//	int c;
//}Value;
//typedef struct _Value2
//{
//	char a;
//	int b;
//	char c;
//}Value2;

	//Value val;
	//Value2 val2;
	//printf("구조체 Value 크기: %d\n", sizeof(val));		//8
	//printf("구조체 Value2 크기: %d\n", sizeof(val2));	//12
	//// padding byte 발생

	// 포인터 사용 예제
	/*//int arr[5];
	//int* pArr = arr;
	//printf("%d\n", sizeof(arr));	// 20
	//printf("%d\n", sizeof(pArr));	// 8*/

	/*//char str1[5] = "abcd";
	//const char* str2 = "ABCD";

	//printf("%s\n", str1);
	//printf("%s\n", str2);

	//str1[0] = 'x';
	////str2[0] = 'x' // error

	//printf("%s\n", str1);
	//printf("%s\n", str2);*/

	/*//int a = 10, b = 20, c = 30;
	//int* pArr[3] = { &a, &b, &c };

	//printf("%d, %10d, %3d \n", &a, pArr[0], *pArr[0]);
	//printf("%d, %10d, %3d \n", &b, pArr[1], *pArr[1]);
	//printf("%d, %10d, %3d \n", &c, pArr[2], *pArr[2]);*/

	//const char* pArr[3];
	//pArr[0] = "C 언어";
	//pArr[1] = "C++ 언어";
	//pArr[2] = "C# 언어";

	//for (int i = 0; i < 3; i++)
	//{
	//	printf("%s\n", pArr[i]);
	//}

	/*int arr1[4] = { 1,2,3,4 };
	int arr2[4] = { 5,6,7,8 };
	int arr3[4] = { 9,10,11,12 };
	int* pArr[3] = { arr1, arr2, arr3 };

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%4d", pArr[i][j]);
		}
		printf("\n");

	}*/

	/*const char* pstr1 = "Bear";
	const char* pstr2 = "Rabbit";

	printf("변경 전 pstr1 = %s pstr2 = %s\n", pstr1, pstr2);
	Swap(&pstr1, &pstr2);
	printf("변경 후 pstr1 = %s pstr2 = %s\n", pstr1, pstr2);

	//void Swap(const char** pstr1, const char** pstr2)
	//{
	//	const char* str;
	//	str = *pstr1;
	//	*pstr1 = *pstr2;
	//	*pstr2 = str;
	//}*/

	//전처리기
	//#if((defined IPHONE) || (defined ANDROID))
	//P("모바일 코드를 실행합니다.\n");
	//#elif((defined WIN7) || (defined WIN8) || (defined WIN10))
	//P("PC 코드를 실행합니다.\n");
	//#endif

	//#if ((!defined WIN7) || (!defined WIN8) || (!defined WIN10))
	//P("PC버전이 활성화 되어있지 않습니다.\n");
	//#endif

	//타이머
	//clock_t start = clock();
	//clock_t now;
	//int msecPerSec = 1000;
	//int msecPerMin = msecPerSec * 60;
	//int msecPerHour = msecPerMin * 60;
	//int msecPerDay = msecPerHour * 24;
	//int day, hour, min, sec;
	//while (true)
	//{
	//	now = clock() - start;

	//	day = now / msecPerDay;
	//	if (day > 0)
	//	{
	//		now -= day * msecPerDay;
	//	}
	//	hour = now / msecPerHour;
	//	if (hour > 0)
	//	{
	//		now -= hour * msecPerHour;
	//	}
	//	min = now / msecPerMin;
	//	if (min > 0)
	//	{
	//		now -= min * msecPerMin;
	//	}
	//	sec = now / msecPerSec;
	//	GotoXY(0, 0);
	//	printf("%.2d day %.2d hour %.2d min %.2d sec", day, hour, min, sec);
	//}

	//버블 정렬 시간 확인
	//clock_t start, end;

	//srand((unsigned int)time(NULL));
	//for (int i = 0; i < MAX_NUM; i++)
	//{
	//	num[i] = rand() % MAX_NUM + 1;
	//}
	//printf("버블 정렬 시작\n");
	//start = clock();
	//BubbleSort();
	//end = clock();
	//printf("버블정렬에 걸린 시간: %.2lf초\n", (end - start) / (double)CLOCKS_PER_SEC);

//void BubbleSort()
//{
//	int temp = 0;
//	for (int i = 0; i < MAX_NUM; i++)
//	{
//		for (int j = 0; j < MAX_NUM-1-i; j++)
//		{
//			if (num[j] > num[j+1])
//			{
//				temp = num[j];
//				num[j] = num[j+1];
//				num[j+1] = temp;
//			}
//		}
//	}
//}

	//	//열거형 예제
	//	enum JOBS
	//	{
	//		NONE = -1,
	//		WARRIOR,
	//		MAGE,
	//		HUNTER,
	//		THIFT,
	//		MAX
	//	};
	//	JOBS myJob = NONE;
	//	printf("*직업을 선택해주세요.*\n");
	//	printf("\t1. 전사\n");
	//	printf("\t2. 마법사\n");
	//	printf("\t3. 사냥꾼\n");
	//	printf("\t4. 도적\n");
	//	scanf("%d", &myJob);
	//
	//	switch (myJob - 1)
	//	{
	//	case WARRIOR:
	//		printf("전사를 선택 하셨습니다.\n");
	//		break;
	//	case MAGE:
	//		printf("마법사를 선택 하셨습니다.\n");
	//		break;
	//	case HUNTER:
	//		printf("사냥꾼을 선택 하셨습니다.\n");
	//		break;
	//	case THIFT:
	//		printf("도적을 선택 하셨습니다.\n");
	//		break;
	//	default:
	//		printf("잘못 선택 하셨습니다.\n");
	//		break;
	//	}
	//int Factorial(int n)
	//{
	//	if (n == 1 || n == 0)
	//	{
	//		printf("%d", n);
	//		return 1;
	//	}
	//	else
	//	{
	//		printf("%d*", n);
	//		return n * Factorial(n - 1);
	//	}
	//}

//void Input(int* a, int* b)		//call by reference
//{
//	printf("입력할 두 정수를 입력하세요: ");
//	scanf_s("%d %d", a, b);
//}
//int Sum(int a, int b)			//call by value
//{
//	return a + b;
//}
//void Output(int a, int b)
//{
//	printf("%d + %d = %d", a, b, Sum(a, b));
//}

//함수 예제
//int Sum(int a, int b)
//{
//	return a + b;
//}

//void Add()
//{
//	static int add = 0;
//	printf("현재 값 %d\n", ++add);
//}

	//rand() 예제
	// 로또 번호 생성기
	//가위바위보
	/*int	player, computer, result;
	int coin = 5, reward;

	srand((unsigned int)time(NULL));
	while (coin > 0)
	{
		printf("현재 코인 개수: %d (게임 1회당 1개 필요)\n", coin);
		printf("1.가위, 2.바위, 3.보, 0.종료 중 숫자 하나를 입력해주세요: ");
		scanf_s("%d", &player);
		if (player == 0)
		{
			printf("게임을 종료합니다.\n");
			exit(0);
		}

		computer = rand() % 3 + 1;
		result = player - computer;
		switch (computer)
		{
		case SCISSOR:
			coin--;
			printf("가위!\n");
			break;
		case ROCK:
			coin--;
			printf("바위!\n");
			break;
		case PAPER:
			coin--;
			printf("보!\n");
			break;
		default:
			printf("잘못된 입력입니다.");
		}

		if (result == 0)
		{
			printf("비겼습니다.\n\n");
		}
		else if (result == -1 || result == 2)
		{
			printf("졌습니다...\n\n");
		}
		else
		{
			reward = rand() % 5 + 1;
			coin += reward;
			printf("축하드립니다.이겼습니다!\n");
			printf("%d코인을 획득했습니다!\n\n", reward);
		}


	}*/

	//배열 예제
	/*int sudents[5] = { 0, };
	for (int i = 0; i < 5; i++)
	{
		printf("%d번 학생 출석 확인(o, x): ", i + 1);
		scanf("%c", &sudents[i]);
		while (getchar() != '\n');
	}
	printf("\n");
	for (int i = 0; i < 5; i++)
	{
		printf("%d번 학생 출석: %c\n", i+1, sudents[i]);
	}*/
	//2D 배열 예제
	/*int num[ROW][COL];
	for (int r = 0; r < ROW; r++)
	{
		for (int c = 0; c < COL; c++)
		{
			if (r % 2 == 0)
			{
				num[r][c] = c + COL * r + 1;
			}
			else
			{
				num[r][c] = (COL - c) + COL * r;
			}
			printf("%3d", num[r][c]);
		}
		printf("\n");
	}*/
	//보석 찾기 게임
	//테트리스 모양 출력
	/*char block[7][4][4] = {
		{	{0,0,0,0},
			{0,1,1,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{	{1,0,0,0},
			{1,0,0,0},
			{1,0,0,0},
			{1,0,0,0}
		},
		{	{0,0,0,0},
			{1,1,0,0},
			{0,1,1,0},
			{0,0,0,0}
		},
		{	{0,0,0,0},
			{0,1,1,0},
			{1,1,0,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,0,1,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{1,0,0,0},
			{1,1,1,0},
			{0,0,0,0}
		},
		{
			{0,0,0,0},
			{0,1,0,0},
			{1,1,1,0},
			{0,0,0,0}
		}
	};
	int type = 0;
	int key = 0;
	while (true)
	{
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				if (block[type][i][j] == 1)
				{
					printf("■");
				}
				else
				{
					printf("  ");
				}
			}
			printf("\n");
		}
		printf("명령어를 입력하세요 1.바꾸기 2.종료: ");
		key = getchar();
		while (getchar() != '\n');
		if (key == '1')
		{
			type = rand() % 7;
		}
		else if (key == '2')
		{
			exit(0);
		}
	}*/

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
	/*int step = 0;
	while (true)
	{
		do {
			printf("출력할 단을 입력하세요: ");
			scanf("%d", &step);
		} while (step <= 0 || step > 9);
		for(int i = 1; i <= 9; i++)
		{
			printf("%d * %d = %d\n", step, i, step * i);
		}
		printf("\n");

	}*/
	//덧셈 계산기
	//int num1 = 0, num2 = 0;
	//char ch = 'y';
	//printf("덧셈 계산기 프로그램입니다.\n");
	//do
	//{
	//	printf("두 수를 입력해주세요: ");
	//	scanf("%d %d", &num1, &num2);
	//	printf("%d + %d = %d입니다\n", num1, num2, num1 + num2);
	//	printf("계속 하시겠습니까(y, n)? ");
	//	while (getchar() != '\n');	//키버퍼에 남은 '\n'를 받아서 비움
	//	scanf("%c", &ch);
	//} while (ch == 'y' || ch == 'Y');

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
	printf("[%-8s] [%-4d] [%10s]\n", "박소영", 30, "서울특별시");
	printf("[%-8s] [%-4d] [%10s]\n", "원빈", 5, "수원시");
	printf("[%-8s] [%-4d] [%10s]\n", "제갈공명", 220, "강릉");*/

	//정밀도 지정
	/*printf("%.4d\n", 12);
	printf("%.5s\n", "hello world");*/