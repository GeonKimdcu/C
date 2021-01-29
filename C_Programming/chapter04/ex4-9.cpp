
#include <stdio.h>

int main(void) {
	int a, b, c, d;
	
	
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &a);
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &b);
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &c);
	printf("정수를 입력하세요 : ");
	scanf_s("%d", &d);
	int sum = a + b + c+d;
	printf("%d\n", sum);
	
	return 0;
}