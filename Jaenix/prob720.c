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

	printf("����� �Է� : "); //�Է� ����
	scanf("%d", &a);

	b = a; //b�� ����

	while (a != 0) { //�ڸ��� ����
		a /= 10;
		i++;
	}

	while (1) { //��� �ݺ�
		int c = 1; //c �ʱ�ȭ

		for (int j = 0; j < i - 1; j++) { //�ڸ�����ŭ �ݺ�
			c *= 10;
		}

		printf("%d", 9 - (b / c)); //b ������ c(= �� �ڸ��� ����)�� 9���� ���� ���

		b %= c; //������

		i--; //�ڸ���--

		if (i == 0) { //�ڸ��� 0 �Ǹ� break
			break;
		}
	}

	return 0;
}

int prob2() {
	return 0;
}