#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	prob1();
	//prob2();

	return 0;
}

int prob1() {
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

int prob2() {
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