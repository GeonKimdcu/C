#include <stdio.h>

int main(void) {
	int i, j, h, w;

	puts("���簢���� ����մϴ�.");
	printf("���� : ");	scanf_s("%d", &h);
	printf("�ʺ� : ");	scanf_s("%d", &w);

	for (i = 1; i <= h; i++) {
		for (j = 1; j <= w; j++)
			printf("*");
		putchar('\n');
	}
	return 0;
}