#include <stdio.h>
/*

int max4(int a, int b, int c, int d) {
	int max;

	max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;
	return max;
}

int main(void) {
	printf("최댓값을 구하세요.\n");
	printf("max4(%d, %d, %d, %d) = %d", 15, 12, 19, 11, max4(15, 12, 19, 11));
	return 0;
}
*/

int main(void) {
	int a, b, c, d;
	int max;
	
	printf("최댓값을 구하세요.\n");
	printf("a : "); scanf_s("%d", &a);
	printf("b : "); scanf_s("%d", &b);
	printf("c : "); scanf_s("%d", &c);
	printf("d : "); scanf_s("%d", &d);

	max = a;
	if (b > max) max = b;
	if (c > max) max = c;
	if (d > max) max = d;

	printf("최댓값은 %d입니다.\n", max);

	return 0;
}