#include <stdio.h>

int main(void) {
	int  n;
	int sum;

	puts("1���� n������ ���� ���ϼ���.\n");

	printf("n�� �� : ");
	scanf_s("%d", &n);
	// ���콺�� ���� Ȱ��...�������� 1���� 0������ �Ǵ�
	sum = (n+1) * (n / 2) + (n % 2 == 1 ? (n + 1) / 2 : 0);

	printf("1���� %d������ ���� %d�Դϴ�.\n", n, sum);

	return 0;
}