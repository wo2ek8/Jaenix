#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {
	prob1();
	//prob2();

	return 0;
}

/*
[����1] 3/4 - 4/7 + 5/4 - 6/9 + 7/6 - 8/13...�� ��� ����� 5�� �ʰ��� �� ���ڰ��� ����Ͻÿ�.
[����2] 2���� ������ �Է¹޾Ƽ� ���� ������ ���� ���� �� ����� �ݺ��ؼ� ���(������ ����)�ϴ� ���α׷��� �ۼ��Ͻÿ�.
   ��) �Է� : 100 60
	   ��� : 100 60 40 20 20 0 20
[����3] ���� ���� 1���� �Է¹޾Ƽ� ������ ���� �����ؼ� ����Ͻÿ�.
   ��) �Է� : 1234
	  ��� : 4 34 234 1234
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

	printf("2���� ������ �Է� : ");
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