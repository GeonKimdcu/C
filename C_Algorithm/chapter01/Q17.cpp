#include <stdio.h>

void spira(int n) {
	int i, j;
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n - i; j++)
			putchar(' ');
		for (j = 1; j <= (i - 1) * 2 + 1; j++)
			putchar('*');
		putchar('\n');
	}
}

int main(void) {
	int n;

	puts("n단의 피라미드를 출력하겠습니다.");
	do {
		printf("몇 단? : ");	scanf_s("%d", &n);
	} while (n <= 0);

	spira(n);

	return 0;
}

