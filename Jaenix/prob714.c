#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	prob1();
	//prob2();

	return 0;
}

/*
[문제1] 3/4 - 4/7 + 5/4 - 6/9 + 7/6 - 8/13...의 계산 결과가 5를 초과할 때 분자값을 출력하시오.
[문제2] 2개의 정수를 입력받아서 앞의 수에서 뒤의 수를 뺀 결과를 반복해서 출력(음수면 중지)하는 프로그램을 작성하시오.
   예) 입력 : 100 60
	   출력 : 100 60 40 20 20 0 20
[문제3] 양의 정수 1개를 입력받아서 다음과 같이 분할해서 출력하시오.
   예) 입력 : 1234
	  출력 : 4 34 234 1234
*/

int prob1(void) {
	int i = 3;
	int j = 4;
	float value = (float)3 / 4;

	int index = 1;
	int increase = 3;
	int decrease = -3;

	while (value <= 5) {
		
		i++;

		if (index % 2 == 0) {
			j += decrease;
			//printf("%d/%d\n", i, j);

			value += (float)i / j;
			//printf("%f\n", (float)i / j);

		}
		else {
			j += increase;
			increase += 2;
			//printf("%d/%d\n", i, j);

			value -= (float)i / j;
			//printf("%f\n", (float)i / j);

		}

		index++;

		printf("value : %f\n", value);
	}

	//printf("value : %f", value);

	return 0;
}

int prob2(void) {
	int a;
	int b;
	int temp = 0;

	printf("2개의 정수를 입력 : ");
	scanf("%d", &a);
	scanf("%d", &b);

	printf("%d\n", a);
	printf("%d\n", b);

	while (temp >= 0) {
		temp = a - b;
		if (temp < 0) {
			break;
		}
		printf("%d\n", temp);

		a = b;
		b = temp;

	}

	return 0;
}