#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//prob1();
	prob2();

	return 0;
}

int prob1() {
	int a;
	int i = 0;
	int b;

	printf("양수를 입력 : "); //입력 받음
	scanf("%d", &a);

	b = a; //b에 저장

	while (a != 0) { //자릿수 구함
		a /= 10;
		i++;
	}

	while (1) { //계속 반복
		int c = 1; //c 초기화

		for (int j = 0; j < i - 1; j++) { //자릿수만큼 반복
			c *= 10;
		}

		printf("%d", 9 - (b / c)); //b 나누기 c(= 각 자리의 숫자)를 9에서 빼고 출력

		b %= c; //나머지

		i--; //자릿수--

		if (i == 0) { //자릿수 0 되면 break
			break;
		}
	}

	return 0;
}

int prob2() {
	return 0;
}