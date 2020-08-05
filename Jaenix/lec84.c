#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	//exam1();
	//exam2();
	//exam3();

	prob1();

	return 0;
}

int exam1() {
	char str[100];
	int i;
	FILE* fp;

	fp = fopen("text.txt", "w");

	printf("문자열을 입력하세요 : ");
	gets_s(str, sizeof(str));

	for (i = 0; str[i] != NULL; i++) {
		fputc(str[i], fp);
	}

	fclose(fp);

	return 0;
}

int exam2() {
	int c;
	FILE* fp;

	fp = fopen("text.txt", "r");
	if (fp == NULL) {
		puts("File not found!!");
		exit(1);
	}

	while ((c = fgetc(fp)) != EOF) {
		printf("%c", c);
	}

	fclose(fp);

	return 0;
}

int exam3() {
	int ch;
	char file1[20], file2[20];
	FILE* source, * destin;

	printf("원본 파일 이름 입력 : ");
	scanf("%s", file1);

	printf("복사 파일 이름 입력 : ");
	scanf("%s", file2);

	source = fopen(file1, "rb");
	if (source == NULL) {
		puts("File not found!!");
		exit(1);
	}

	destin = fopen(file2, "wb");

	while ((ch = fgetc(source)) != EOF) {
		if (fputc(ch, destin) == EOF) {
			break;
		}
	}

	printf("%s copied to %s\n", file1, file2);

	fclose(source);
	fclose(destin);

	return 0;
}

int prob1() {
	int c;
	FILE* fp;
	char fileName[100];

	printf("입력 : ");
	scanf("%s", fileName);
	fp = fopen(fileName, "r");
	if (fp == NULL) {
		puts("File not found!!");
		exit(1);
	}
	int i = 0;
	while ((c = fgetc(fp)) != EOF) {
		printf("%x ", c);
		i++;
		if (i % 20 == 0) {
			printf("\n");
		}
	}

	fclose(fp);

	return 0;
}