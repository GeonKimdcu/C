# include <stdio.h>
#include <stdlib.h>

int search(const int a[], int n, int key) {
	int i;
	for (i = 0; i < n; i++)
		if (a[i] == key)
			return i;
	return -1;
}

int main(void) {
	int i, nx, ky, idx;
	int* x;
	puts("���� �˻�");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	printf("�˻��� : ");
	scanf_s("%d", &ky);
	idx = search(x, nx, ky);
	if (idx == -1)
		puts("�˻��� �����߽��ϴ�.");
	else
		printf("%d(��)�� x[%d]�� �ֽ��ϴ�.\n", ky, idx);
	free(x);

	return 0;
}