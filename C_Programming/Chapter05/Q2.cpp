#include <stdio.h>

int main(void) {
	double kg, pound;
	
	puts("kg을 입력하세요.");
	printf("kg : ");		scanf_s("%lf", &kg);

	pound = (kg / 453.6) * 1000;
	printf("pound°ª : %.3f\n", pound);
	return 0;
}
