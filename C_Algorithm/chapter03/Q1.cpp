#include <stdio.h>
#include <stdlib.h>

int search(int a[], int n, int key) {
	int i;
	a[n] = key;
	for (i = 0; i < n; i++) {
		if (a[i] == key)
			break;
	}
	return i == n ? -1 : i;
}

int main(void) {
	int i, nx, ky, idx;
	int* x;
	puts("�����˻� (���ʹ�)");
	printf("��� ���� : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx+1, sizeof(int));   // ���ʹ��̱� ������ ��Ұ��� 1���߰� 
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