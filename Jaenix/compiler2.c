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
	printf("현재 파일 포인터 위치 : %ld\n", ftell(stream));

	return 0;
}