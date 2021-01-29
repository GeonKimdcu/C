#include <stdio.h>
#define MAX 9

int main(void) {
	int i, j;
	puts("=== 구구단 출력 ===");
	for (i = 2; i <= MAX; i++) {
		printf("%6d단 출력\n", i);
		for (j = 2; j <= MAX; j++)
			printf("%d * %d = %2d  ", i, j, i * j);
		putchar('\n');
		}
	return 0;
}