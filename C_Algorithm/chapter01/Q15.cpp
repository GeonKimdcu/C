#include <stdio.h>

int main(void) {
	int i, j, h, w;

	puts("직사각형을 출력합니다.");
	printf("높이 : ");	scanf_s("%d", &h);
	printf("너비 : ");	scanf_s("%d", &w);

	for (i = 1; i <= h; i++) {
		for (j = 1; j <= w; j++)
			printf("*");
		putchar('\n');
	}
	return 0;
}