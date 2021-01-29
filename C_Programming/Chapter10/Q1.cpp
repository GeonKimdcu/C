#include <stdio.h>

int main(void) {
	int inch;
	printf("inch : ");
	scanf_s("%d", &inch);

	printf("inch를 cm로 변환\n");

	double cm = 2.54 * inch;

	printf("cm : %.2f\n", cm);
	return 0;
}