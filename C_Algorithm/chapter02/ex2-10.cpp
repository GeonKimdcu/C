#include <stdio.h>

int main(void) {
	int i, n;
	int prime[500];				// �Ҽ��� �����ϴ� �迭
	int ptr = 0;					// �̹� ���� �Ҽ��� ���� 
	unsigned long counter = 0;
	prime[ptr++] = 2;			// 2�� �Ҽ�
	for (n = 3; n <= 1000; n+=2) {			// Ȧ������ ������� ����
		for (i = 1; i < ptr; i++) {				// �̹� ���� �Ҽ��� ������
			counter++;
			if (n % prime[i] == 0)
				break;
		}
		if (ptr == i)					// ���������� ����������� ������ �Ҽ���
			prime[ptr++] = n;		// �迭�� �Ҽ� ����
	}
	for (i = 0; i < ptr; i++)
		printf("%d\n", prime[i]);
	printf("�������� ������ Ƚ�� : %lu\n", counter);

	return 0;
}