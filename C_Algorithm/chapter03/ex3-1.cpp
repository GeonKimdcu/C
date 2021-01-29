#include <stdio.h>
#include <stdlib.h>

int search(const int a[], int n, int key) {	 // key는 찾는 값 
	int i = 0;
	while (1) {	// 정지 조건
		if (i == n)			// 배열 끝까지 도달 => 검색 실패
			return -1;
		if (a[i] == key)	// 검색 성공 
			return i;
		i++;
	}
}

int main(void) {
	int i, nx, ky, idx;
	int* x;
	puts("선형 검색");
	printf("요소 개수 : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	printf("검색값 : ");
	scanf_s("%d", &ky);
	idx = search(x, nx, ky);			// 배열x의 값이 ky인 요소를 선형 검색
	if (idx == -1)
		puts("검색에 실패했습니다.");
	else
		printf("%d(은)는 x[%d]에 있습니다.\n", ky, idx);
	free(x);

	return 0;
}