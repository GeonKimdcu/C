#include <stdio.h>
#include <stdlib.h>

#define swap(type, x ,y) do{ type t =x; x = y; y = t;} while(0)


static void downheap(int a[], int left, int right) {
	int temp = a[left];		// 루트노드 값을 temp에 저장  // left는 배열 인덱스
	int child;
	int parent;
	for (parent = left; parent < (right + 1) / 2; parent = child) {		// left는 배열 첫번째 인덱스, right는 배열 마지막 인덱스
		int cl = parent * 2 + 1;		// 왼쪽 자식
		int cr = cl + 1;					// 오른쪽 자식 (=parent *2 + 2)
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl;		// 큰 값을 선택합니다 
		if (temp >= a[child])			// 루트노드보다 자식이 더 클 때
			break;
		a[parent] = a[child];			// 자식과 부모값을 교환
	}
	a[parent] = temp;		// 루트노드 값인 배열의 첫 번째 요소의 값을 parent인덱스 값으로 옮김.
}

void heapsort(int a[], int n) {
	int i;
	for (i = (n - 1) / 2; i >= 0; i--)
		downheap(a, i, n - 1);		// 배열a를 힙으로 만듦
	for (i = n - 1; i > 0; i--) {
		swap(int, a[0], a[i]);	
		// 루트 a[0]에 있는 가장 큰 값을 빼내어 배열 마지막 요소와 바꾸고 배열의 나머지 부분을 다시 힙으로 만듦
		downheap(a, 0, i - 1);
	}
}

int main(void) {
	int i, nx;
	int* x;
	puts("힙 정렬");
	printf("요소 개수 : ");		scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	heapsort(x, nx);
	puts("오름차순으로 정렬했습니다.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}

