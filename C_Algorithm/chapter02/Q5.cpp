 #include <stdio.h>
#include <stdlib.h>

# define swap(type, x, y) do{ type t = x; x = y; y = t;} while(0)

// 요솟수 n인 배열 a의 요소를 차례로 출력
void ary_print(const int a[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%3d", a[i]);
	putchar('\n');
}
// 요솟수 n인 배열 a의 요소를 역순으로 정렬
void ary_reverse(int a[], int n) {
	int i;
	for (i = 0; i < n / 2; i++) {
		ary_print(a, n);
		printf("a[%d]와 a[%d]를 교환합니다. \n", i, n - i - 1);
		swap(int, a[i], a[n - i - 1]);
	}
	ary_print(a, n);
	puts("역순정렬이 끝났습니다.");
}

int main(void) {
	int i;
	int* x;
	int nx;

	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	printf("%d개의 정수를 입력하세요.\n", nx);
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	ary_reverse(x, nx);
	printf("배열의 요소를 역순으로 정렬하겠습니다.\n");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}