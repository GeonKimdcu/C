#include <stdio.h>

int main(void) {
	int a, b;

	puts("두 정수를 입력하세요.");
	printf("a값 : ");		scanf_s("%d", &a);
	printf("b값 : ");		scanf_s("%d", &b);

	if (a > b)
		printf("몫 : %d 나머지 : %d\n", a/b, a % b);
	else if(b > a)
		printf("몫 : %d 나머지 : %d\n", b / a, b % a);
	
	return 0;
}