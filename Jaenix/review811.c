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
	filename���� �־��� ������ ������ mode�� ����.
	������ ������ ���µ� �����ϸ� FILE�� ����ü �����͸� ��ȯ�ϰ�, ������ �߻��ϸ� ��(NULL)�� ��ȯ�Ѵ�.
	mode�� ���� : r, w, a, r+, w+, a+, b, t
	*/

	printf("���ڿ��� �Է��ϼ��� : ");
	gets_s(str, sizeof(str));
	/*
	gets_s(����, ����ũ��);
	�����ϸ� �Էµ� ���ڿ��� ��ȯ, �����ϸ� NULL�� ��ȯ
	*/

	for (i = 0; str[i] != NULL; i++) {
		fputc(str[i], fp);
		/*
		int fputc(int c, FILE *stream);
		�Ű����� c�� �ִ� 1���� ���ڸ� ������ ��Ʈ���� ����Ѵ�.
		��¿� �����ϸ� ����� ���� c�� ��ȯ�ϰ�, ������ �߻��ϸ� EOF�� ��ȯ�Ѵ�.
		*/
	}

	fclose(fp);
	/*
	int fclose(FILE *stream);
	���� �ݱⰡ �����ϸ� 0��, ������ EOF�� ��ȯ�Ѵ�.
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
		puts(���ڿ�);
		�����ϸ� ������ �ƴ� ���� ��ȯ, �����ϸ� EOF(-1)�� ��ȯ
		*/
		exit(1);
		/*
		exit() �Լ��� stdio.h ��������� include�Ͽ� ���.
		exit(0)�� '��������', exit(1)�� '�����޽��� ����'
		(���� EXIT_SUCCESS, EXIT_FAILURE�� �̸� ���ǵǾ� �ֱ� ����)
		exit() �Լ��� �ٷ� ���μ��� ����.
		*/
	}

	while ((c = fgetc(fp)) != EOF) {
		/*
		int fgetc(FILE *stream);
		������ ��Ʈ�����κ��� 1���� ���ڸ� �а� int������ ��ȯ�Ѵ�.
		���� ������ �߻��ϰų� ������ ���̸� EOF�� ��ȯ�Ѵ�.
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

	printf("���� �̸� �Է� : ");
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

	printf("���� ���� �̸� �Է� : ");
	scanf("%s", file1);

	printf("���� ���� �̸� �Է� : ");
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

	printf("���� ���� �̸� �Է� : ");
	scanf("%s", file1);

	printf("���� ���� �̸� �Է� : ");
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
	//printf("���� ���� ������ ��ġ : %ld\n", ftell(stream));
	printf("���� ���� ������ ��ġ : %d\n", ftell(stream));

	return 0;
}