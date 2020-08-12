#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
	exam13_1();

	return 0;
}

int exam13_1() {
	char str[100];
	int i;
	FILE* fp;

	fp = fopen("test.txt", "w");

	printf("문자열을 입력하세요 : ");
	gets_s(str, sizeof(str));

	for (i = 0; str[i] != NULL; i++) {
		fputc(str[i], fp);
	}

	fclose(fp);

	return 0;
}