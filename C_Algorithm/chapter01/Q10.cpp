#include <stdio.h> 

int main(void) {
	int a, b;
	
	puts("b -a�� ���� ���մϴ�.");
	printf("a�� �� : ");	scanf_s("%d", &a);
	printf("b�� �� : ");	scanf_s("%d", &b); 
	do {
		printf("a���� ū ���� �Է��ϼ���!\n");

		printf("b�� �� : ");	scanf_s("%d", &b);
	} while (a >=b);
	printf("b - a �� %d �Դϴ�.\n", b - a);

	return 0;
}

/*
int main(void) {
	int a, b;
	printf("a�� �� : ");	scanf_s("%d", &a);
	
	while (1) {
		printf("b�� �� : ");	scanf_s("%d", &b);
		if (a >= b)
			printf("a���� ū ���� �Է��ϼ���!\n");
		else break;
	}
	printf("b - a�� %d�Դϴ�.\n", b - a);

	return 0;
}
*/