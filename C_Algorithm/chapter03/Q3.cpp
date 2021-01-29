#include <stdio.h>
#include <stdlib.h>

int search_idx(const int a[], int n, int key, int idx[])
{
int i, count = 0;

	for (i = 0; i < n; i++)
		if (a[i] == key)
			idx[count++] = i;
	return count;
}

int main(void)
{
	int i, nx, ky;
	int no;		
	int *x;		
	int *idx;	

	puts("선형 검색");
	printf("요솟수 : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));	
	idx = (int*)calloc(nx, sizeof(int));	

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	printf("검색 값 :");
	scanf_s("%d", &ky);

	no = search_idx(x, nx, ky, idx);	

	if (no == -1)
		puts("일치하는 요소는 존재하지 않습니다.");
	else {
		printf("일치하는 요소는 %d 개입니다.\n", no);
		for (i = 0; i < no; i++)
			printf("x[%d] ", idx[i]);
		putchar('\n');
	}

	free(x);	/* 배열을 해제 */
	free(idx);	/* 배열을 해제 */

	return 0;
}
