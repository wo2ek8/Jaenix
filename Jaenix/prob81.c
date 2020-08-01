#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	//prob1();
	//prob1_2();
	//prob1_3();
	//prob1_4();
	//prob1_5();
	//prob1_6();
	//prob1_7();
	prob1_8();
	return 0;
}

int prob1() {
	char string[100];
	int i = 0;
	int j = 0;
	int rest;
	char result[100];
	int b = 1;
	int sum = 0;
	printf("\'0\'~\'1\'로 구성된 문자열을 입력 : ");
	scanf("%s", string);
	while (string[i] != NULL) {
		i++;
	}
	rest = i % 4;
	for (int k = 0; k < rest; k++) {
		printf("%c", string[k]);
		if (string[k] == '1') {
			for (int a = 0; a < 3 - rest; a++) {
				
				b *= 2;

			}
			sum += b;
		}
	}
	printf("\n");
	while (string[rest + j] != NULL) {
		printf("%c", string[rest + j]);
		j++;
		if (j == 4) {
			printf("\n");
			rest += 4;
			j = 0;
		}
	}
	return 0;
}

int prob1_2() {
	char string[100];
	int count = 0;
	int nextVal = 0;
	int intArr[100];
	printf("\'0\'~\'1\'로 구성된 문자열을 입력 : ");
	scanf("%s", string);
	while (string[count] != NULL) {
		count++;
	}
	int rest = count % 4;
	for (int k = 0; k < rest; k++) {
		printf("%c => %d\n", string[k], string[k]);
	}
	/*printf("\n");
	while (string[rest + nextVal] != NULL) {
		printf("%c", string[rest + nextVal]);
		nextVal++;
		if (nextVal == 4) {
			printf("\n");
			rest += 4;
			nextVal = 0;
		}
	}*/
	return 0;
}

int prob1_3() {
	char input[100];
	int count = 0;
	int intArr[100];
	int j = 0;
	printf("입력 : ");
	scanf("%s", input);
	printf("%s\n", input);
	while (input[count] != NULL) {
		count++;
	}
	printf("%d\n", count);
	for (int i = count - 1; i >= 0; i--) {
		printf("%c", input[i]);
		intArr[j] = input[i] - 48;
		printf("=> %d\n", intArr[j]);
		j++;
	}
	printf("\n");
	return 0;
}

int prob1_4() {
	char input[100];
	int count = 0;
	int intArr[100];
	int j = 0;
	int val = 1;
	int sum = 0;
	printf("입력 : ");
	scanf("%s", input);
	printf("%s\n", input);
	while (input[count] != NULL) {
		count++;
	}
	printf("%d\n", count);
	for (int i = count - 1; i >= 0; i--) {
		//printf("%c", input[i]);
		intArr[j] = input[i] - 48;
		//printf("%d : ", intArr[j]);
		j++;
		//printf("%d\n", i);

		if (intArr[j] != 0) {
			val = 1;
			for (int time = 0; time < i; time++) {
				val *= 2;
			}
			sum += val;
		}
		
	}
	printf("\n");
	printf("sum : %d\n", sum);

	
	return 0;
}

int prob1_5() {
	char input[100];
	int count = 0;
	printf("입력 : ");
	scanf("%s", input);
	while (input[count] != NULL) {
		count++;
	}
	printf("count : %d\n", count);
	int rest = count % 4;
	printf("rest : %d\n", rest);
	int temp = 1;
	int sum = 0;
	for (int i = 0; i < rest; i++) {
		//printf("%c", input[i]);
		//printf("%d\n", (rest - 1) - i);
		if (input[i] != 0) {
			for (int k = 0; k < (rest - 1) - i; k++) {
				printf("k : %d\n", k);
				printf("(rest - 1) - i : %d\n", k < (rest - 1) - i);
				temp *= 2;
				printf("temp : %d\n", temp);
			}
			
			sum += temp;
			printf("sum : %d\n", sum);
		}
		
	}
	//printf("%d", sum);
	/*printf("\n");
	int j = 0;
	while (input[rest + j] != NULL) {
		printf("%c", input[rest + j]);
		j++;
		if (j == 4) {
			printf("\n");
			rest += 4;
			j = 0;
		}
	}*/
	return 0;
}

int prob1_6() {
	char input[100];
	int count = 0;
	int intArr[100] = {0, };
	printf("입력 : ");
	scanf("%s", input);
	while (input[count] != NULL) {
		count++;
	}
	printf("count : %d\n", count);
	int j = 0;
	for (int i = count - 1; i >= 0; i--) {
		printf("i : %d\n", i);
		
		intArr[i] = input[j] - 48;
		printf("intArr[%d] : %d\n", i, intArr[i]);
		j++;
	}
	int sum = 0;
	for (int k = 0; k < count; k++) {
		
		if (intArr[k] == 1) {
			printf("intArr[%d] : %d\n", k, intArr[k]);
			int times = 1;
			for (int a = 0; a < k; a++) {
				times *= 2;
				printf("times : %d\n", times);
			}
			
			sum += times;
			printf("sum : %d\n", sum);
		}
	}
	int newArr[100];
	int index = 0;
	for (; sum != 0; index++) {
		newArr[index] = sum % 16;
		if (newArr[index] >= 10) {
			printf("newArr[%d] + 55 : %c\n", index, newArr[index] + 55);
		}
		else {
			printf("newArr[%d] : %d\n", index, newArr[index]);
		}
		sum /= 16;
		printf("sum : %d\n", sum);
	}

	

	return 0;
}

int prob1_7() {
	char input[100];
	int count = 0;
	printf("입력 : ");
	scanf("%s", input);
	while (input[count] != NULL) {
		count++;
	}
	printf("count : %d\n", count);
	int i = 0;
	int sum = 0;
	while (input[i] != NULL) {
		if (input[i] == 1) {
			int times = 1;
			for (int j = 0; j < (count - j) - 1; j++) {
				times *= 2;
			}
			sum += times;
		}
		i++;
	}
	
	printf("sum : %d\n", sum);
	return 0;
}

int prob1_8() {
	
}