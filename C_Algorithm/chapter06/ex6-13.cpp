#include <stdio.h>
#include <stdlib.h>

void merge(const int a[], int na, const int b[], int nb, int c[]) {
	int pa = 0;	// 각 배열 커서 초기화
	int pb = 0;
	int pc = 0;
	while (pa < na && pb < nb)	// a배열과 b배열이 끝까지 다다르기 전까지 반복
		c[pc++] = (a[pa] <= b[pb]) ? a[pa++] : b[pb++];	// 두 배열 중 작은 값을 c배열에 저장
	while (pa < na)	// 만약 b배열이 c배열에 다 복사되었고 a배열만 남았을 경우 a배열의 모든 값을 c배열에 복사
		c[pc++] = a[pa++];
	while (pb < nb)
		c[pc++] = b[pb++];
}

int main(void) {
	int i, na, nb;
	int *a, * b, * c;
	printf("a의 요소 개수 : ");		scanf_s("%d", &na);
	printf("b의 요소 개수 : ");		scanf_s("%d", &nb);
	a = (int*)calloc(na, sizeof(int));
	b = (int*)calloc(nb, sizeof(int));
	c = (int*)calloc(na + nb, sizeof(int));
	printf("a[0] : ");
	scanf_s("%d", &a[0]);
	for (i = 1; i < na; i++) {
		do {
			printf("a[%d] : ", i);
			scanf_s("%d", &a[i]);
		} while (a[i] < a[i - 1]);
	}
	printf("b[0] : ");
	scanf_s("%d", &b[0]);
	for (i = 1; i < nb; i++) {
		do {
			printf("b[%d] : ", i);
			scanf_s("%d", &b[i]);
		} while (b[i] < b[i - 1]);
	}
	merge(a, na, b, nb, c);
	puts("배열 a와 b를 병합하여 배열 c에 저장했습니다.");
	for (i = 0; i < na + nb; i++)
		printf("c[%2d] = %2d\n", i, c[i]);
	free(a); free(b); free(c);

	return 0;
}