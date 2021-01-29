#include <stdio.h>

int main(void) {
	double x = 5.29, *y;
	double* p = &x;
	y = p;
	*y = 3.89;

	printf("%f\n", x);
	return 0;
}