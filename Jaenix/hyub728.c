#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	prob1();
	return 0;
}

/* [문제1] 키보드로 10진 양수와 변환할 진법을 입력받아서 해당 진법으로 변환해서 출력하시오.
단, 진법은 2~20진수까지 만으로 제한한다.
예)	입력 : 125 16
	출력 : 7D */
int prob1() {
	int num, jinsu;
	int changeNumArr[50] = { 0, };
	int i, j, k;
	int temp = 0;

	printf("입력 : ");
	scanf("%d %d", &num, &jinsu);
	printf("출력 : ");

	for (i = 0; num > 0; i++) {
		if (num > jinsu - 1) {
			k = num % jinsu;
			changeNumArr[i] = k;
			num = num / jinsu;
			temp++;
		}
		else {
			changeNumArr[i] = num;
			temp++;
			break;
		}
	}
	for (j = 1; j <= temp; j++) {
		if (changeNumArr[temp - j] >= 10) {
			printf("%c", changeNumArr[temp - j] + 55);
		}
		else {
			printf("%d", changeNumArr[temp - j]);
		}
	}

	printf("\n");
	return 0;
}

/* [문제2] '0'~'9'로 구성된 문자열을 입력(20자 미만)받아서
0 : Z	1 : A	2 : C	3 : E	4 : G
5 : K	6 : W	7 : X	8 : V	9 : Q 으로 출력.
예)  입력 : 2130986715
	출력 : CAEZQVWXAG	*/
int prob2() {
	int num, temp = 0, k;

	printf("입력 : ");
	scanf("%d", &num);
	printf("출력 : ");

	int arr[20] = { 0, };
	for (int i = 0; num > 0; i++) {
		if (num > 10) {
			k = num % 10;
			arr[i] = k;
			num = num / 10;
			temp++;
		}
		else {
			arr[i] = num;
			temp++;
			break;
		}
	}

	for (int j = 0; j < temp; j++) {
		switch (arr[temp - j - 1]) {
		case 0:printf("Z"); break;
		case 1:printf("A"); break;
		case 2:printf("C"); break;
		case 3:printf("E"); break;
		case 4:printf("G"); break;
		case 5:printf("K"); break;
		case 6:printf("W"); break;
		case 7:printf("X"); break;
		case 8:printf("V"); break;
		case 9:printf("Q"); break;
		}
	}
	printf("\n");
	return 0;
} // clear

/* [문제3] 키보드로 양수 두 개(값과 구분자)를 입력받아 갑과 구분자를 함수의 매개변수로 전달한다.
함수는 매개변수로 전달받은 구분자가 일이면 비트의 개수를, 구분자가 0이면 0인 비트의 개수를 반환하고
이 반환값을 출력하는 프로그램 작성
예)  입력 : 17 1
	출력 : 2	*/
int prob3() {
	int num, guboonja, count_zero = 0, temp = 0, k;

	printf("입력 : ");
	scanf("%d %d", &num, &guboonja);
	printf("출력 : ");
	int arr[20] = { 0, };
	for (int i = 0; num > 0; i++) {
		if (num > 10) {
			k = num % 10;
			arr[i] = k;
			num = num / 10;
			temp++;
		}
		else {
			arr[i] = num;
			temp++;
			break;
		}
	}

	if (guboonja == 1) {
		printf("%d", temp);
	}
	else if (guboonja == 0)
	{
		for (int j = 0; j < temp; j++)
		{
			if (arr[temp - j - 1] == 0)
			{
				count_zero += 1;
			}
			// printf("%d %d\n",j,count_zero);
		}
		printf("%d", count_zero);
	}
	printf("\n");
	return 0;
}	// clear