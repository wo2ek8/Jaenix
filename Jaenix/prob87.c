#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	//exam1();
	//exam2();
	exam3();
	return 0;
}

int exam1() {
	FILE* in, * out;
	char line[10];

	in = fopen("input.txt", "r");
	if (in == NULL) {
		puts("File not found!!");
		exit(1);
	}

	out = fopen("output.txt", "w");

	

	for (int i = 0; i < 5; i++) {
		fscanf(in, "%s", line);
		fprintf(out, "%d : %s\n", i + 1, line);

		
	}
	return 0;
}

int exam2() {
	char buf[256];
	FILE* source, * destin;

	source = fopen("input.txt", "rb");
	destin = fopen("output.txt", "wb");

	while (fgets(buf, 256, source) != NULL) {
		if (fputs(buf, destin) == EOF) {
			break;
		}
	}

	fclose(source);
	fclose(destin);

	return 0;
}

int exam3() {
	int cnt = 1, posi;
	char buf[256], inFile[100], outFile[100];
	FILE* in, * out;

	printf("원본 파일 이름 입력 : ");
	scanf("%s", inFile);
	in = fopen(inFile, "r");

	if (in == NULL) {
		puts("File not found!!");
		return 1;
	}

	posi = strcspn(inFile, ".");
	strncpy(outFile, inFile, posi);
	strcpy(outFile + posi, "2");
	strcpy(outFile + posi + 1, inFile + posi);

	out = fopen(outFile, "w");
	while (fgets(buf, 256, in) != NULL) {
		/*char *fgets(char *s, int n, FILE *stream);
		오류면 NULL을 반환한다.*/
		fprintf(out, "%d : %s", cnt++, buf);
		/*int fprintf(FILE *stream, char *format...);
		지정된 형식에 맞게 스트림에 입출력한다.*/
	}

	fclose(in);
	fclose(out);

	return 0;
}