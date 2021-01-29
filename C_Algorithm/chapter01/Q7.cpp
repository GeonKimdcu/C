#include <stdio.h>

int main(void) {
	int i, n;
	int sum;

	puts("1부터 n까지의 합을 구하세요.");
	scanf_s("%d", &n);
	sum = 0;
	for (i = 1; i <= n; i++) {
		sum += i;
	}

	for (i = 1; i < n; i++)
		printf("%d+", i);
	printf("%d=%d\n", n, sum);
	return 0;
}