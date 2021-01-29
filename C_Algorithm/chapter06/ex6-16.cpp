#include <stdio.h>
#include <stdlib.h>

void fsort(int a[], int n, int max) {
	int i;
	int* f = (int*)calloc(max + 1, sizeof(int));	// �迭f�� ���� ����
	int* b = (int*)calloc(n, sizeof(int));	// �迭 b�� ���� �迭

	for (i = 0; i <= max; i++) f[i] = 0;	// [Step0] : �迭  f�� 0���� �ʱ�ȭ
	for (i = 0; i < n; i++) f[a[i]]++;		// [Step1] : ������ǥ�� �����
	for (i = 1; i <= max; i++) f[i] += f[i - 1];			// [Step2] : ���� ��������ǥ �����
 	for (i = n - 1; i >= 0; i--) b[--f[a[i]]] = a[i];	// [Step3] : ���� �迭 �����
	for (i = 0; i < n; i++) a[i] = b[i];					    // [Step4] : �迭 �����ϱ�

	free(b);
	free(f);
}

int main(void) {
	int i, nx;
	int* x;
	const int max = 100;
	puts("���� ����");
	printf("��� ���� : ");

	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	printf("0 ~ %d�� ������ �Է��ϼ���.\n", max);
	
	for (i = 0; i < nx; i++) {
		do {
			printf("x[%d] : ", i);
			scanf_s("%d", &x[i]);
		} while (x[i]<0 || x[i]>max);
	}

	fsort(x, nx, max);
	puts("������������ �����߽��ϴ�.");

	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);

	free(x);

	return 0;
}