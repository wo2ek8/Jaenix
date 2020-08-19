#include <stdio.h>
int main(void)
{
	int var1;
	int var2;
	scanf("%d", &var1);
	var2 = 10;
	var1 += var2;
	printf("%d\n", var1);
	var1 -= 5;
	printf("%d\n", var1);
	var1 *= 3;
	printf("%d\n", var1);
	var1 /= 2;
	printf("%d\n", var1);

	return 0;
}