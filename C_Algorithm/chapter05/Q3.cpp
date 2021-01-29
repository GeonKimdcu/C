#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y) {
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

int gcd_array(const int a[], int n) {
	if (n == 1)
		return a[0];
	else if (n == 2)
		return gcd(a[0], a[1]);
	else
		return (gcd(a[0], gcd_array(&a[1], n - 1))); // ?
}

int main(void) {
	int  n;
	int* x;
	
	printf("배열 a의 모든 요소의 최대공약수를 구합니다.\n");
	printf("배열 a의 요소개수 : ");
	scanf_s("%d", &n);
	
	x = (int*)calloc(n, sizeof(int));

	for (int i = 0; i < n; i++) {
		do {
			printf("정수를 입력하세요 : ");
			scanf_s("%d", &x[i]);
		} while (x[i] <= 0);
	}

	printf("최대공약수는 %d입니다.\n", gcd_array(x, n));
	return 0;
}