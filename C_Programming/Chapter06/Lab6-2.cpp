#include <stdio.h>

int main(void) {
	int x, y, z;
	printf("세 정수를 입력: ");
	scanf_s("%d %d %d", &x, &y, &z);

	if (x > y) {
		if (x > z)
			printf("최대수: %d\n", x);
		else
			printf("최대수: %d\n", z);
	}
	else {
		if (y > z)
			printf("최대수: %d\n", y);
		else
			printf("최대수: %d\n", z);
	}
	return 0;
}