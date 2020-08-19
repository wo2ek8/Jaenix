#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

void getWord(char *tempWork); //토큰(단어)으로 분리
int codePosi(char *word); //번역할 명령어 구하기
void zeroOperand(int posi); //0항 연산자 처리
void oneOperand(int posi); //단항 연산자 처리
void twoOperand(int posi); //이항 연산자 처리

char* src[] = {"start", "end", "var", "mov", "add", "sub", "mul", "div", "out", "in"};
char* code[] = {"#include <stdio.h>\nint main(void)\n{\n", "\n\treturn 0;\n}", "int", "=", "+=", "-=", "*=", "/=", "printf", "scanf"};

FILE* in, * out;

int main(void) {
	int posi;
	char word[100], srcFile[20], cFile[20];

	printf("소스 파일이름 입력 : ");
	scanf("%s", srcFile);

	in = fopen(srcFile, "r");

	if (in == NULL) {
		printf("File not found!\n");
		return 1;
	}

	posi = strcspn(srcFile, ".");
	strncpy(cFile, srcFile, posi + 1);
	strcpy(cFile + posi + 1, "c");

	out = fopen(cFile, "w");

	while (1) {
		getWord(word);

		if (word[0] == '\0') {
			continue;
		}

		posi = codePosi(word);

		if (posi == 0 || posi == 1) {
			zeroOperand(posi);
		}
		else if (posi == 2 || posi == 8 || posi == 9) {
			oneOperand(posi);
		}
		else if (posi >= 3 && posi <= 7) {
			twoOperand(posi);
		}
		else {
			printf("Error!\n");
			return 1;
		}
		if (posi == 1) {
			break;
		}
	}

	fclose(in);
	fclose(out);

	return 0;
}

void getWord(char* tempWord) {
	int i = 0;
	char ch;

	while ((ch = fgetc(in)) != EOF) {
		if (ch == ' ' || ch == '\t' || ch == '\n' || ch == ',' || ch == '.') {
			tempWord[i] = '\0';
			return;
		}
		else {
			tempWord[i++] = ch;
		}
	}

	tempWord[i] = '\0';
}

int codePosi(char* word) {
	int i;

	for (i = 0; i < 10; i++) {
		if (_stricmp(word, src[i]) == 0) {
			return i;
		}
	}

	return 10;
}

void zeroOperand(int posi) {
	fprintf(out, "%s", code[posi]);

	if (posi == 1) {
		printf("컴파일이 완료되었습니다\n");
	}
}

void oneOperand(int posi) {
	char operand[100];

	getWord(operand);

	switch (posi) {
	case 2:
		fprintf(out, "\t%s %s%s", code[posi], operand, ";\n");
		break;
	case 8:
		fprintf(out, "\t%s%s%s%s", code[posi], "(\"%d\\n\", ", operand, ");\n");
		break;
	case 9:
		fprintf(out, "\t%s%s%s%s", code[posi], "(\"%d\", &", operand, ");\n");
	}
}

void twoOperand(int posi) {
	char operand1[100], operand2[100];

	getWord(operand1);
	getWord(operand2);
	fprintf(out, "\t%s %s %s;\n", operand1, code[posi], operand2);
}