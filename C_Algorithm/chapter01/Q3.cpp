#include <stdio.h>

int main(void) {
	int a, b, c, d;
	int min;

	printf("최솟값을 구하세요.\n");
	
	printf("a : "); scanf_s("%d", &a);
	printf("b : "); scanf_s("%d", &b);
	printf("c : "); scanf_s("%d", &c);
	printf("d : "); scanf_s("%d", &d);

	min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	if (d < min) min = d;

	printf("최솟값은 %d 입니다.", min);
	
	return 0;
}