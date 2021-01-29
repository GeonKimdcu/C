#include <stdio.h>
int main(void) {
	double a, b;
	int menu;
	printf("두 실수 입력 : ");
	scanf_s("%lf %lf", &a, &b);

	printf("연산종류 번호 선택");
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
		printf("잘못된 입력!\n");
	}
	return 0;
}