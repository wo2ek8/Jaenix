#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

char cStart[] = { "start" };
char cVar[] = { "var" };
char cIn[] = { "in" };
char cMov[] = { "mov" };
char cAdd[] = { "add" };
char cOut[] = { "out" };
char cSub[] = { "sub" };
char cMul[] = { "mul" };
char cDiv[] = { "div" };
char cEnd[] = { "end" };

int main() {
	readFile();
	//test();

	return 0;
}

int readFile() {
	int c;
	FILE* fp;
	char charArr[100] = {0,};
	int i = 0;

	fp = fopen("source.txt", "r");
	if (fp == NULL) {
		puts("File not found!!");
		exit(1);
	}

	while ((c = fgetc(fp)) != EOF) {
		//printf("%c", c);
		
		//printf("%c", charArr[i]);
		
		if (c == '\n') {
			cLine(charArr);
			//break;
		}
		else {
			charArr[i] = c;
			i++;
		}
	}

	/*i = 0;
	while (charArr[i] != '\n') {
		printf("%c", charArr[i]);
		i++;
	}*/

	fclose(fp);

	return 0;
}

int cLine(char *charArr) {
	//int i = 0;
	int j = 0;

	printf("%d\n", i);

	while (charArr[i] != NULL) {
		printf("%c", charArr[i]);
		if (charArr[i] == ' ') {
			break;
		}
		i++;
	}
	printf("\n");

	/*while (cStart[j] != NULL) {
		printf("%c", cStart[j]);
		j++;
	}*/

	if (*charArr == *cStart) {
		printf("cStartFunction\n");
	}
	if (*charArr == *cVar) {
		printf("cVarFunction\n");
	}
	if (*charArr == *cIn) {
		printf("cInFunction\n");
	}
	if (*charArr == *cMov) {
		printf("cMovFunction\n");
	}
	if (*charArr == *cAdd) {
		printf("cAddFunction\n");
	}
	if (*charArr == *cOut) {
		printf("cOutFunction\n");
	}
	if (*charArr == *cMul) {
		printf("cMulFunction\n");
	}
	if (*charArr == *cDiv) {
		printf("cDivFunction\n");
	}
	if (*charArr == *cEnd) {
		printf("cEndFunction\n");
	}
	if (*charArr == *cVar) {
		printf("cVarFunction\n");
	}

	return 0;
}

int test() {
	printf("%s\n", cStart);
	printf("%s\n", cVar);
	printf("%s\n", cIn);
	printf("%s\n", cMov);
	printf("%s\n", cAdd);
	printf("%s\n", cOut);
	printf("%s\n", cSub);
	printf("%s\n", cMul);
	printf("%s\n", cDiv);
	printf("%s\n", cEnd);

	return 0;
}