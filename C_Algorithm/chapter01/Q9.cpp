#include <stdio.h>

int sumof(int a, int b) {
	int i, min, max;
	int sum = 0;
	// 두 정수의 최소 최대를 구분하기 위해서
	if (a < b) {
		min = a;
		max = b;
	}
	else {
		min = b;
		max = a;
	}
	for (i = min; i <= max; i++) 
		sum += i;
	
	return sum;
}

int main(void) {
	int a, b;
	int sum;
	printf("a 값 : ");	scanf_s("%d", &a);
	printf("b 값 : ");	scanf_s("%d", &b);

	printf("두 정수 a,b 사이의 모든 정수의 합은 %d 입니다.\n", sumof(a, b));

	return 0;

	
}