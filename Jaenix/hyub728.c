#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	prob1();
	return 0;
}

/* [����1] Ű����� 10�� ����� ��ȯ�� ������ �Է¹޾Ƽ� �ش� �������� ��ȯ�ؼ� ����Ͻÿ�.
��, ������ 2~20�������� ������ �����Ѵ�.
��)	�Է� : 125 16
	��� : 7D */
int prob1() {
	int num, jinsu;
	int changeNumArr[50] = { 0, };
	int i, j, k;
	int temp = 0;

	printf("�Է� : ");
	scanf("%d %d", &num, &jinsu);
	printf("��� : ");

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

/* [����2] '0'~'9'�� ������ ���ڿ��� �Է�(20�� �̸�)�޾Ƽ�
0 : Z	1 : A	2 : C	3 : E	4 : G
5 : K	6 : W	7 : X	8 : V	9 : Q ���� ���.
��)  �Է� : 2130986715
	��� : CAEZQVWXAG	*/
int prob2() {
	int num, temp = 0, k;

	printf("�Է� : ");
	scanf("%d", &num);
	printf("��� : ");

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

/* [����3] Ű����� ��� �� ��(���� ������)�� �Է¹޾� ���� �����ڸ� �Լ��� �Ű������� �����Ѵ�.
�Լ��� �Ű������� ���޹��� �����ڰ� ���̸� ��Ʈ�� ������, �����ڰ� 0�̸� 0�� ��Ʈ�� ������ ��ȯ�ϰ�
�� ��ȯ���� ����ϴ� ���α׷� �ۼ�
��)  �Է� : 17 1
	��� : 2	*/
int prob3() {
	int num, guboonja, count_zero = 0, temp = 0, k;

	printf("�Է� : ");
	scanf("%d %d", &num, &guboonja);
	printf("��� : ");
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