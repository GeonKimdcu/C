#include <stdio.h>
#include <stdlib.h>

int search(const int a[], int n, int key)
{
	int i;

	printf("   |");
	for (i = 0; i < n; i++)
		printf("%3d", i);
	printf("\n---+");
	for (i = 0; i < n; i++)
		printf("---", i);
	printf("-\n");

	for (i = 0; i < n; i++) {
		int j;
		printf("   |");
		printf("%*s", 3 * (i - 1) + 5, "");  // 3*(i-1)+5가 *(애스터리스크)값으로 들어감 그 숫자값만큼 공백
		printf("*\n");
		printf("%3d|", i);
		for (j = 0; j < n; j++)
			printf("%3d", a[j]);
		putchar('\n');

		if (a[i] == key)
			return i; 

		printf("   |\n");
	}

	return -1; 
}

int main(void)
{
	int i, nx, ky, idx;
	int *x;						

	puts("선형 검색");
	printf("요솟수 : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int)); 

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	printf("검색 값 : ");
	scanf_s("%d", &ky);

	idx = search(x, nx, ky);	

	if (idx == -1)
		puts("검색에 실패했습니다.");
	else
		printf("%d는 x[%d]에 있습니다.\n", ky, idx);

	free(x); 

	return 0;
}
