#include <stdio.h>
#include <stdlib.h>

#define swap(type, x ,y) do{ type t =x; x = y; y = t;} while(0)


static void downheap(int a[], int left, int right) {
	int temp = a[left];		// ��Ʈ��� ���� temp�� ����  // left�� �迭 �ε���
	int child;
	int parent;
	for (parent = left; parent < (right + 1) / 2; parent = child) {		// left�� �迭 ù��° �ε���, right�� �迭 ������ �ε���
		int cl = parent * 2 + 1;		// ���� �ڽ�
		int cr = cl + 1;					// ������ �ڽ� (=parent *2 + 2)
		child = (cr <= right && a[cr] > a[cl]) ? cr : cl;		// ū ���� �����մϴ� 
		if (temp >= a[child])			// ��Ʈ��庸�� �ڽ��� �� Ŭ ��
			break;
		a[parent] = a[child];			// �ڽİ� �θ��� ��ȯ
	}
	a[parent] = temp;		// ��Ʈ��� ���� �迭�� ù ��° ����� ���� parent�ε��� ������ �ű�.
}

void heapsort(int a[], int n) {
	int i;
	for (i = (n - 1) / 2; i >= 0; i--)
		downheap(a, i, n - 1);		// �迭a�� ������ ����
	for (i = n - 1; i > 0; i--) {
		swap(int, a[0], a[i]);	
		// ��Ʈ a[0]�� �ִ� ���� ū ���� ������ �迭 ������ ��ҿ� �ٲٰ� �迭�� ������ �κ��� �ٽ� ������ ����
		downheap(a, 0, i - 1);
	}
}

int main(void) {
	int i, nx;
	int* x;
	puts("�� ����");
	printf("��� ���� : ");		scanf_s("%d", &nx);
	x = (int*)calloc(nx, sizeof(int));
	for (i = 0; i < nx; i++) {
		printf("x[%d] : ", i);
		scanf_s("%d", &x[i]);
	}
	heapsort(x, nx);
	puts("������������ �����߽��ϴ�.");
	for (i = 0; i < nx; i++)
		printf("x[%d] = %d\n", i, x[i]);
	free(x);

	return 0;
}

