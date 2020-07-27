#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int prob3_1(int a, int b);

int main() {
	//prob1();
	//prob1_1();
	//prob1_2();
	//exam4();
	//prob2();
	prob3();
	return 0;
}

int prob1() {
	int a;
	int b;
	printf("10진 양수 : ");
	scanf("%d", &a);
	printf("변환할 진법 : ");
	scanf("%d", &b);
	if (b < 2 || b > 20) {
		printf("진법은 2~20진수까지 만으로 제한한다.");
		return 0;
	}
	while (a != 0) {
		printf("%d\n", a % b);
		a = a / b;
	}
	return 0;
}

int prob1_1() {
	int a;
	int b;
	int arr[50] = {0,};
	int count = 0;
	printf("10진 양수 : ");
	scanf("%d", &a);
	printf("변환할 진법 : ");
	scanf("%d", &b);
	if (b < 2 || b > 20) {
		printf("진법은 2~20진수까지 만으로 제한한다.");
		return 0;
	}
	for (int i = 0; a > 0; i++) {
		if (a >= b) {
			arr[i] = a % b;
			a = a / b;
			count++;
		}
		else {
			arr[i] = a;
			count++;
			break;
		}
	}
	for (int j = 1; j <= count; j++) {
		if (arr[count - j] >= 10) {
			printf("%c", arr[count - j] + 55);
		}
		else {
			printf("%d", arr[count - j]);
		}
	}
	printf("\n");
	return 0;
}

int prob1_2() {
	int a;
	int b;
	int arr[50] = { 0, };
	int i = 0;
	printf("10진 양수 : ");
	scanf("%d", &a);
	printf("변환할 진법 : ");
	scanf("%d", &b);
	if (b < 2 || b > 20) {
		printf("진법은 2~20진수까지 만으로 제한한다.");
		return 0;
	}
	for (; a > 0; i++)  { //int i는 0부터 입력받은 수가 0보다 작을 때 i는 1씩 증가
		arr[i] = a % b; //arr i번째에 입력받은 수를 입력받은 진수로 나눈 나머지 저장
		a /= b; //몫을 a에 저장
	}
	for (i = i - 1; i >= 0; i--) { //i가 마지막에 증감되므로 i는 i - 1부터 시작 0보다 크거나 같을 때 1씩 감소
		if (arr[i] >= 10) { //i번째에 있는 수가 10보다 크거나 같을 경우
			printf("%c", arr[i] + 55); //알파벳 출력
		}
		else {
			printf("%d", arr[i]); //숫자 출력
		}
	}
	return 0;
}

int exam4() {
	int a;
	scanf("%d", &a);
	while (a != 0) {
		printf("%d", a % 10);
		a /= 10;
	}
	return 0;
}

int prob2() {
	char input[20];
	char output[] = {'Z', 'A', 'C', 'E', 'G', 'K', 'W', 'X', 'V', 'Q'}; //배열에 저장
	int i = 0;
	printf("0~9로 구성된 문자열을 입력(20자 미만) : ");
	scanf("%s", input);
	while (input[i] != NULL) { //문자열 끝날 때까지 반복
		//printf("%c\n", input[i]);
		int temp = input[i] - 48; //아스키에서 0~9로 바꿔주기!
		//printf("%d\n", temp);
		printf("%c", output[temp]);
		i++;
	}
	return 0;
}

int prob3() {
	int a;
	int b;
	printf("키보드로 양수 두 개(값과 구분자)를 입력 : ");
	scanf("%d%d", &a, &b);
	printf("%d", prob3_1(a, b)); //함수호출, 출력
	return 0;
}

int prob3_1(int a, int b) {
	int count = 0;
	for (int i = 7; i >= 0; i--) {
		//printf("%d", a >> i & 1);
		if ((a >> i & 1) == b) { //비트 하나씩 비교
			count++; //카운트
		}
	}
	return count; //리턴
}