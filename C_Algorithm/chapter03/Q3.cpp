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

	puts("���� �˻�");
	printf("��ڼ� : ");
	scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));	
	idx = (int*)calloc(nx, sizeof(int));	

	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	printf("�˻� �� :");
	scanf_s("%d", &ky);

	no = search_idx(x, nx, ky, idx);	

	if (no == -1)
		puts("��ġ�ϴ� ��Ҵ� �������� �ʽ��ϴ�.");
	else {
		printf("��ġ�ϴ� ��Ҵ� %d ���Դϴ�.\n", no);
		for (i = 0; i < no; i++)
			printf("x[%d] ", idx[i]);
		putchar('\n');
	}

	free(x);	/* �迭�� ���� */
	free(idx);	/* �迭�� ���� */

	return 0;
}
