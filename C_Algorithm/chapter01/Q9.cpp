#include <stdio.h>

int sumof(int a, int b) {
	int i, min, max;
	int sum = 0;
	// �� ������ �ּ� �ִ븦 �����ϱ� ���ؼ�
	if (a < b) {
		min = a;
		max = b;
	}
	else {
		min = b;
		max = a;
	}
	for (i = min; i <= max; i++) 
		sum += i;
	
	return sum;
}

int main(void) {
	int a, b;
	int sum;
	printf("a �� : ");	scanf_s("%d", &a);
	printf("b �� : ");	scanf_s("%d", &b);

	printf("�� ���� a,b ������ ��� ������ ���� %d �Դϴ�.\n", sumof(a, b));

	return 0;

	
}