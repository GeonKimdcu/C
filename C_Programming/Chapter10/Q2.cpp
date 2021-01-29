#include <stdio.h>

int intpow(int m, int n);
int main(void) {
	int a, b;
	printf("a:");
	scanf_s("%d", &a);
	printf("b:");
	scanf_s("%d", &b);

	printf("%d * %d = %d\n",a, b,intpow(a, b));

	return 0;
}

int intpow(int m, int n) {
	return m * n;
}