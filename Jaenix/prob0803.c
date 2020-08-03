#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int prob2_1(char c);

int main() {
	//prob1();
	//prob2();
	//prob3();
	prob32();
	return 0;
}

int prob1() {
	char string[100];
	int stringNum = 0;
	int sum = 0;
	printf("입력 : ");
	scanf("%s", string);
	while (string[stringNum] != NULL) {
		stringNum++;
	}
	//printf("stringNum : %d\n", stringNum);
	for (int i = stringNum - 1; i >= 0; i--) {
		//printf("string[%d] : %d\n", i, string[i] - 48);
		//printf("i : %d\n", i);
		if (string[i] - 48 == 1) {
			int appendNum = 1;
			for (int j = 1; j < stringNum - i; j++) {
				//printf("j : %d\n", j);
				appendNum = appendNum * (string[i] - 48) * 2;
				//printf("appendNum : %d\n", appendNum);
			}
			sum += appendNum;
			//printf("sum : %d\n", sum);
		}
	}
	//printf("sum : %d\n", sum);
	int k = 0;
	char arr[25];
	while (1) {
		if (sum % 16 < 10) {
			arr[k] = sum % 16 + 48;
		}
		else {
			arr[k] = sum % 16 + 55;
		}
		sum /= 16;
		k++;
		if (sum == 0) {
			break;
		}
	}
	printf("출력 : ");
	for (int i = k - 1; i >= 0; i--) {
		printf("%c", arr[i]);
	}
	return 0;
}

int prob2() {
	char charArr[10];
	printf("입력 : ");
	scanf("%s", charArr);
	printf("출력 : ");
	for (int i = 0; charArr[i] != NULL; i++) {
		printf("%d", prob2_1(charArr[i]));
	}
	return 0;
}

int prob2_1(char c) {
	return c - 48;
}

int prob3() {
	char charArr[100];
	printf("입력 : ");
	scanf("%s", charArr);
	int arrNum = 0;
	while (charArr[arrNum] != NULL) {
		arrNum++;
	}
	char resultArr[10];
	int resultArrIndex = 0;
	for (int i = 0; i < arrNum; i++) {
		for (int j = arrNum - 1; j >= i / 2; j--) {
				printf("charArr[%d] : %c\n", i, charArr[i]);
				printf("charArr[%d] : %c\n", j, charArr[j]);
				if (charArr[i] != charArr[j]) {
					printf("달라!\n");
					resultArrIndex = 0;
					while (resultArr[resultArrIndex] == NULL) {
						resultArr[resultArrIndex] = 0;
					}
					//break;
				}
				else {
					printf("같아!\n");
					resultArr[resultArrIndex] = charArr[i];
					resultArrIndex++;
				}
		}
	}
	
	
	return 0;
}

int prob32() {
	char charArr[100];
	printf("입력 : ");
	scanf("%s", charArr);
	int arrNum = 0;
	while (charArr[arrNum] != NULL) {
		arrNum++;
	}
	char newArr[100] = {0,};
	int j = arrNum - 1;
	for (int i = 0; i < arrNum; i++) {
		for (; j >= i / 2; j--) {
			printf("charArr[%d] : %c\n", i, charArr[i]);
			printf("charArr[%d] : %c\n", j, charArr[j]);
			if (charArr[i] != charArr[j]) {
				printf("달라!\n");
				
			}
			else {
				printf("같아!\n");
				newArr[i] = charArr[i];
				newArr[j] = charArr[j];
				//printf("%d\n", j + 1);
				break;
			}
		}

		if (charArr[i] == charArr[j]) {
			break;
		}
	}
	printf("%c\n", newArr[0]);
	int a = 0;
	printf("\n==========================\n");
	while (newArr[a] != NULL) {
		printf("%c", newArr[a]);
		a++;
	}
	printf("\n==========================\n");
	int real;
	if (a % 2 == 0) {
		real = a * 2;
	}
	else {
		real = a * 2 + 1;
	}
	printf("%d\n", real);
	/*첫번째 같다 나올때까지 길이? 이걸로하면 아예다른 숫자가 뒤에 나오면 출력이 잘되는데
	*/
	/*printf("\n%d\n", a);
	printf("\n%d\n", a - j);*/
	return 0;
}