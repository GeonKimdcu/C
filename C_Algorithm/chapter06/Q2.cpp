#include <stdio.h>
#include <stdlib.h>
#define swap(type, x, y) do{type t = x; x = y; y = t;} while(0)



void bubble(int a[], int n) {
	int i, j, k;
	int count_swap = 0, count_scan = 0;
	for (i = 0; i < n - 1; i++) {
		printf("�н� %d: \n", i+1);
		for (j = n - 1; j > i; j--) {
			for (k = 0; k < n - 1; k++)
				printf("%3d %c", a[k], (k != j - 1) ? ' ' : (a[j - 1] > a[j]) ? '+' : '-');
			printf("%3d \n", a[n - 1]);
			count_scan++;
			if (a[j - 1] > a[j]) {
				swap(int, a[j - 1], a[j]);
				count_swap++;
			}
		}
		for (k = 0; k < n - 1; k++)
			printf("%3d", a[k]);
		putchar('\n');
	}
	printf("�� %dȸ : \n", count_scan);
	printf("��ü %dȸ : \n", count_swap);
}

int main(void) {
	int i, nx;
	int* x;

	puts("��������");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	bubble(x, nx);

	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	

	free(x);

	return 0;
}