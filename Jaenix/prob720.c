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

	printf("양수를 입력 : ");
	scanf("%d", &a);

	b = a; //입력값을 b에 저장함

	while (a != 0) { //자릿수를 구함
		a /= 10;
		i++;
	}

	for (; i > 0; i--) { //i가 0보다 클 때 i는 1씩 감소함
		int c = 1;

		for (int j = 0; j < i - 1; j++) {
			c *= 10;
		}

		printf("%d", 9 - (b / c)); //9 - 저장해둔 값 나누기 c 출력함

		b %= c; //나머지 구함
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
	char input; //받을 값
	int lastBit; //마지막 비트

	printf("문자를 입력(부호 없는 문자형) : "); //입력
	scanf("%c", &input);

	//printf("%d\n", input);

	for (int j = 0; j < 8; j++) { //8번 옮김
		for (int i = 7; i >= 0; i--) { //2진수로 출력
			printf("%d", input >> i & 1);
		}

		lastBit = input >> 0 & 1; //마지막 비트 저장

		printf("\n"); //줄 바꿈

		input = input >> 1; //오른쪽 로테이션

		if (lastBit == 1) { //마지막 비트 1이면
			//printf("lastBit : %d\n", lastBit);
			input = input | 0x80; //맨 왼쪽 비트 1로 바꿈
		}
		else {
			input = input & 0x7f; //아니면 0으로 바꿈
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
	int input; //입력 받을 값
	char array[20] = { 0, }; //16진수 변환 뒤 저장할 배열
	int index = 0; //배열 index

	printf("양수를 입력 : "); //값 입력
	scanf("%d", &input);

	while (1) {
		int remain = input % 16; //16으로 나눈 나머지 구함
		if (remain < 10) { //10보다 작다면 숫자임
			array[index] = 48 + remain; //array index번에 숫자 넣음
			/*
			array 자료형 char니까 아스키코드 필요
			0은 48 더해준 뒤 저장
			*/
		}
		else { //10보다 크면 알파벳임
			array[index] = 65 + (remain - 10); //array index번에 알파벳 넣음
			//A는 65
		}

		input /= 16; //16 나누기

		index++; //index 증감

		if (input == 0) { //입력값 0, 16보다 작아지면 break
			break;
		}
	}

	for (int i = index - 1; i >= 0; i--) { //아까 담아둔 배열 출력
		//마지막에 index 하나 더 증가해서 index - 1부터 시작
		printf("%c", array[i]); //문자 출력
	}

	return 0;
}