#include <stdio.h>

int gcd(int x, int y) {
	int common = 0;

	while (y > 0) {
		common = x % y;
		x = y;
		y = common;
	} return x;
}

int main(void) {
	int x, y;

	puts("두 정수의 최대공약수를 구합니다.");
	printf("정수를 입력하세요: ");
	scanf_s("%d", &x);
	printf("정수를 입력하세요: ");
	scanf_s("%d", &y);

	printf("최대 공약수는 %d입니다.\n", gcd(x, y));	
}