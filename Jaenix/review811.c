#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main() {
	//exam1();
	//exam2();
	//exam3();
	//exam4();
	//exam5();
	//exam7();
	//exam8();
	//exam8_2();
	exam10();

	return 0;
}

int exam1() {
	char str[100];
	int i;
	FILE* fp;

	fp = fopen("jihan.txt", "w");
	/*
	FILE *fopen(char *filename, char *mode);
	filename으로 주어진 파일을 지정된 mode로 연다.
	지정된 파일을 여는데 성공하면 FILE형 구조체 포인터를 반환하고, 오류가 발생하면 널(NULL)을 반환한다.
	mode의 종류 : r, w, a, r+, w+, a+, b, t
	*/

	printf("문자열을 입력하세요 : ");
	gets_s(str, sizeof(str));
	/*
	gets_s(버퍼, 버퍼크기);
	성공하면 입력된 문자열을 반환, 실패하면 NULL을 반환
	*/

	for (i = 0; str[i] != NULL; i++) {
		fputc(str[i], fp);
		/*
		int fputc(int c, FILE *stream);
		매개변수 c에 있는 1개의 문자를 지정된 스트림에 출력한다.
		출력에 성공하면 출력한 문자 c를 반환하고, 오류가 발생하면 EOF를 반환한다.
		*/
	}

	fclose(fp);
	/*
	int fclose(FILE *stream);
	파일 닫기가 성공하면 0을, 오류면 EOF를 반환한다.
	*/

	return 0;
}

int exam2() {
	int c;
	FILE* fp;

	fp = fopen("text.txt", "r");
	if (fp == NULL) {
		puts("File not found!!");
		/*
		puts(문자열);
		성공하면 음수가 아닌 값을 반환, 실패하면 EOF(-1)를 반환
		*/
		exit(1);
		/*
		exit() 함수는 stdio.h 헤더파일을 include하여 사용.
		exit(0)은 '정상종료', exit(1)은 '에러메시지 종료'
		(각각 EXIT_SUCCESS, EXIT_FAILURE로 미리 정의되어 있기 때문)
		exit() 함수는 바로 프로세스 종료.
		*/
	}

	while ((c = fgetc(fp)) != EOF) {
		/*
		int fgetc(FILE *stream);
		지정된 스트림으로부터 1개의 문자를 읽고 int형으로 반환한다.
		만약 오류가 발생하거나 파일의 끝이면 EOF를 반환한다.
		*/
		printf("%c", c);
	}

	fclose(fp);

	return 0;
}

int exam3() {
	int c, line = 1;
	char fName[20];
	FILE* fp;

	printf("파일 이름 입력 : ");
	scanf("%s", fName);

	fp = fopen(fName, "r");
	if (fp == NULL) {
		puts("File not found!!");
		exit(1);
	}

	while ((c = fgetc(fp)) != EOF) {
		printf("%c", c);
		if (c == '\n') {
			line++;
		}
		if (line >= 24) {
			line = 1;
			puts("##Press any key to continue##");
			_getch();
		}
	}
	fclose(fp);

	return 0;
}

int exam4() {
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

int exam5() {
	char buf[256];
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

	while (fgets(buf, 256, source) != NULL) {
		if (fputs(buf, destin) == EOF) {
			break;
		}
	}

	printf("%s copied to %s\n", file1, file2);

	fclose(source);
	fclose(destin);

	return 0;
}

int exam7() {
	int i, kor, eng, mat, tot;
	FILE* in, * out;
	char name[10];
	float avg;

	in = fopen("input.txt", "r");
	if (in == NULL) {
		puts("File not found!!");
		exit(1);
	}

	out = fopen("output.txt", "w");

	fprintf(out, "Name | Korea | English | Mathematic | Total | Average\n");

	for (i = 0; i < 5; i++) {
		fscanf(in, "%s%d%d%d", name, &kor, &eng, &mat);
		tot = kor + eng + mat;
		avg = tot / 3.0;
		fprintf(out, "%s | %d | %d | %d | %d | %.2f\n", name, kor, eng, mat, tot, avg);
	}

	fclose(in);
	fclose(out);

	return 0;
}

int exam8() {
	FILE* in, * out;
	char buf[100];

	in = fopen("input.txt", "r");
	if (in == NULL) {
		puts("File not found!!");
		exit(1);
	}
	out = fopen("output2.txt", "w");

	while (fread(buf, 14, 2, in) != 0) {
		fwrite(buf, 14, 1, out);
	}

	fclose(in);
	fclose(out);

	return 0;
}

int exam8_2() {
	FILE* in, * out;
	char buf[100];

	in = fopen("input.txt", "r");
	if (in == NULL) {
		puts("File not found!!");
		exit(1);
	}
	out = fopen("output2.txt", "w");

	/*while (fread(buf, 14, 2, in) != 0) {
		fwrite(buf, 14, 1, out);
	}*/

	while (fread(buf, 14, 2, in) != 0)
		fwrite(buf, 14, 1, out);

	fclose(in);
	fclose(out);

	return 0;
}

int exam10() {
	FILE* stream;

	stream = fopen("test.txt", "w");
	fprintf(stream, "C Language");
	//printf("현재 파일 포인터 위치 : %ld\n", ftell(stream));
	printf("현재 파일 포인터 위치 : %d\n", ftell(stream));

	return 0;
}