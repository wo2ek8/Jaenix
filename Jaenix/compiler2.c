#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
	pointPosition();

	return 0;
}

int pointPosition() {
	FILE* stream;

	stream = fopen("test.txt", "w");
	fprintf(stream, "C Language");
	printf("���� ���� ������ ��ġ : %ld\n", ftell(stream));

	return 0;
}