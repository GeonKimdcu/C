#include <stdio.h>

int main(void) {
	float x = 3.14F;	// 부동소수 상수 3.14F로 반드시 F나 f 삽입
	double  y = -3.141592;
	long double z = 180000000.0;

	printf("저장값: %f \n %f\n  %f\n", x, y, z);

	return 0;
}