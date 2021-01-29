#include <stdio.h>

int main(void) {
	double degree[] = { -5.34, 3.67, 19.76, 28.76, 35.63 };
	
	int size = sizeof(degree) / sizeof(degree[0]);

	for (int i = 0; i < size; i++)
		printf("%.2f\n", degree[i]);

	return 0;
}