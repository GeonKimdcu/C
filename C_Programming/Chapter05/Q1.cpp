#include <stdio.h>

int main(void) {
	int a, b;

	puts("�� ������ �Է��ϼ���.");
	printf("a�� : ");		scanf_s("%d", &a);
	printf("b�� : ");		scanf_s("%d", &b);

	if (a > b)
		printf("�� : %d ������ : %d\n", a/b, a % b);
	else if(b > a)
		printf("�� : %d ������ : %d\n", b / a, b % a);
	
	return 0;
}