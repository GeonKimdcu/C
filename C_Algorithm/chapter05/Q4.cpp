#include <stdio.h>

void recur2(int n) {
	if (n > 0) {
		recur2(n - 2);
		printf("%d\n", n);
		recur2(n - 1);
	}
}

int main(void) {
	int x;
	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &x);
	recur2(x);

	return 0;
}