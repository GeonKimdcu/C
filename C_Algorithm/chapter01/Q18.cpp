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

	puts("n���� ���� �Ƕ�̵带 ����ϰڽ��ϴ�.");
	do {
		printf("�� ��? : ");	scanf_s("%d", &n);
	} while (n <= 0);

	nrpira(n);

	return 0;
}