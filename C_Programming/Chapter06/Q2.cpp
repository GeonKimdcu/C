#include <stdio.h>
int main(void) {
	double a, b;
	int menu;
	printf("�� �Ǽ� �Է� : ");
	scanf_s("%lf %lf", &a, &b);

	printf("�������� ��ȣ ����");
	printf("1(+), 2(-), (3*), 4(/) : ");
	scanf_s("%d", &menu);

	switch (menu) {
	case 1: 
		printf("%.2lf + %.2lf = %.2lf\n", a, b, a + b);
		break;

	case 2:
		printf("%.2lf - %.2lf = %.2lf\n", a, b, a - b);
		break;

	case 3:
		printf("%.2lf * %.2lf = %.2lf\n", a, b, a * b);
		break;

	case 4:
		printf("%.2lf / %.2lf = %.2lf\n", a, b, a / b);
		break;

	default:
		printf("�߸��� �Է�!\n");
	}
	return 0;
}