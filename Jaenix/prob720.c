#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//prob1();
	//prob2();
	prob3();

	return 0;
}

int prob1() {
	int a;
	int i = 0;
	int b;

	printf("����� �Է� : ");
	scanf("%d", &a);

	b = a; //�Է°��� b�� ������

	while (a != 0) { //�ڸ����� ����
		a /= 10;
		i++;
	}

	for (; i > 0; i--) { //i�� 0���� Ŭ �� i�� 1�� ������
		int c = 1;

		for (int j = 0; j < i - 1; j++) {
			c *= 10;
		}

		printf("%d", 9 - (b / c)); //9 - �����ص� �� ������ c �����

		b %= c; //������ ����
	}

	/*while (1) {
		int c = 1;

		for (int j = 0; j < i - 1; j++) {
			c *= 10;
		}

		printf("%d", 9 - (b / c));

		b %= c;

		i--;

		if (i == 0) {
			break;
		}
	}*/

	return 0;
}

int prob2() {
	char input; //���� ��
	int lastBit; //������ ��Ʈ

	printf("���ڸ� �Է�(��ȣ ���� ������) : "); //�Է�
	scanf("%c", &input);

	//printf("%d\n", input);

	for (int j = 0; j < 8; j++) { //8�� �ű�
		for (int i = 7; i >= 0; i--) { //2������ ���
			printf("%d", input >> i & 1);
		}

		lastBit = input >> 0 & 1; //������ ��Ʈ ����

		printf("\n"); //�� �ٲ�

		input = input >> 1; //������ �����̼�

		if (lastBit == 1) { //������ ��Ʈ 1�̸�
			//printf("lastBit : %d\n", lastBit);
			input = input | 0x80; //�� ���� ��Ʈ 1�� �ٲ�
		}
		else {
			input = input & 0x7f; //�ƴϸ� 0���� �ٲ�
		}
	}

	/*for (int i = 7; i >= 0; i--) {
		printf("%d", input >> i & 1);
		lastBit = input >> 0 & 1;
	}

	printf("\n");

	input = input >> 1;

	if (lastBit == 1) {
		printf("lastBit : %d\n", lastBit);
		input = input | 0x80;
	}

	for (int i = 7; i >= 0; i--) {
		printf("%d", input >> i & 1);
	}*/

	return 0;
}

int prob3() {
	int input; //�Է� ���� ��
	char array[20] = { 0, }; //16���� ��ȯ �� ������ �迭
	int index = 0; //�迭 index

	printf("����� �Է� : "); //�� �Է�
	scanf("%d", &input);

	while (1) {
		int remain = input % 16; //16���� ���� ������ ����
		if (remain < 10) { //10���� �۴ٸ� ������
			array[index] = 48 + remain; //array index���� ���� ����
			/*
			array �ڷ��� char�ϱ� �ƽ�Ű�ڵ� �ʿ�
			0�� 48 ������ �� ����
			*/
		}
		else { //10���� ũ�� ���ĺ���
			array[index] = 65 + (remain - 10); //array index���� ���ĺ� ����
			//A�� 65
		}

		input /= 16; //16 ������

		index++; //index ����

		if (input == 0) { //�Է°� 0, 16���� �۾����� break
			break;
		}
	}

	for (int i = index - 1; i >= 0; i--) { //�Ʊ� ��Ƶ� �迭 ���
		//�������� index �ϳ� �� �����ؼ� index - 1���� ����
		printf("%c", array[i]); //���� ���
	}

	return 0;
}