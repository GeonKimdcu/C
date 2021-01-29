 #include <stdio.h>
#include <stdlib.h>

void ary_rcopy(int a[], const int b[], int n) {
	int i;
	for (i = 0; i < n; i++)
		a[i] = b[n - i - 1];
}

int main(void)
{
	int i;
	int* x, * y;			/* �迭�� ù ��° ��ҿ� ���� ������ */
	int n;				/* �迭 x�� y�� ��ڼ� */

	printf("��ڼ� : ");
	scanf_s("%d", &n);
	x = (int*)calloc(n, sizeof(int));			/* ��ڼ� n�� int �� �迭 x�� ���� */
	y = (int*)calloc(n, sizeof(int));			/* ��ڼ� n�� int �� �迭 y�� ���� */

	printf("%d ���� ������ �Է��ϼ���.\n", n);
	for (i = 0; i < n; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}

	ary_rcopy(y, x, n); /* �迭 x�� ��� ��Ҹ� �迭 y�� �������� �����մϴ�. */

	printf("�迭 x�� ��� ��Ҹ� �迭 y�� �������� �����߽��ϴ�.\n");
	for (i = 0; i < n; i++)
		printf("y[%d] = %d\n", i, y[i]);

	free(x); /* �迭 x�� ���� */
	free(y); /* �迭 y�� ���� */

	return 0;
}