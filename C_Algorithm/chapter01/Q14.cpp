#include <stdio.h>

int main(void) {
	int i, j, n;

	puts("사각형을 출력합니다.");
	printf("입력할 수 : "); scanf_s("%d", &n);

	for (i = 1; i <= n; i++) {
		for(j = 1; j<=n; j++)
		printf("*");
		putchar('\n');
	}
	return 0;
}