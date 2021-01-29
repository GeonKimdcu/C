#include <stdio.h>
#include <stdlib.h>

void fsort(int a[], int n, int max) {
	int i;
	int* f = (int*)calloc(max + 1, sizeof(int));	// 배열f는 누적 도수
	int* b = (int*)calloc(n, sizeof(int));	// 배열 b는 목적 배열

	for (i = 0; i <= max; i++) f[i] = 0;	// [Step0] : 배열  f를 0으로 초기화
	for (i = 0; i < n; i++) f[a[i]]++;		// [Step1] : 도수분표포 만들기
	for (i = 1; i <= max; i++) f[i] += f[i - 1];			// [Step2] : 누적 도수분포표 만들기
 	for (i = n - 1; i >= 0; i--) b[--f[a[i]]] = a[i];	// [Step3] : 목적 배열 만들기
	for (i = 0; i < n; i++) a[i] = b[i];					    // [Step4] : 배열 복사하기

	free(b);
	free(f);
}

int main(void) {
	int i, nx;
	int* x;
	const int max = 100;
	puts("도수 정렬");
	printf("요소 개수 : ");

	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	printf("0 ~ %d의 정수를 입력하세요.\n", max);
	
	for (i = 0; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i]<0 || x[i]>max);
	}

	fsort(x, nx, max);
	puts("오름차순으로 정렬했습니다.");

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}