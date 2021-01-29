#include <stdio.h>

void nrpira(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= i - 1; j++)
			putchar(' ');
		for (j = 1; j <= (n - i) * 2 + 1; j++)
			printf("%d", i % 10);
		putchar('\n');
	}
}

int main(void) {
	int n;

	puts("n단의 숫자 피라미드를 출력하겠습니다.");
	do {
		printf("몇 단? : ");	scanf_s("%d", &n);
	} while (n <= 0);

	nrpira(n);

	return 0;
}