#include <stdio.h>

int gcd(int x, int y) {
	int common = 0;

	while (y > 0) {
		common = x % y;
		x = y;
		y = common;
	} return x;
}

int main(void) {
	int x, y;

	puts("�� ������ �ִ������� ���մϴ�.");
	printf("������ �Է��ϼ���: ");
	scanf_s("%d", &x);
	printf("������ �Է��ϼ���: ");
	scanf_s("%d", &y);

	printf("�ִ� ������� %d�Դϴ�.\n", gcd(x, y));	
}