#include <stdio.h>

int main(void) {
	int i, n;
	unsigned long counter = 0;	// ������ Ƚ��
	for (n = 2; n <= 1000; n++) {
		for (i = 2; i < n; i++) {		// 2���� n-1���� � �����ε� ������ �������� ����
			counter++;
			if (n % i == 0)			// ������ �������� �Ҽ��� �ƴ�
				break;					// �Ҽ��� �ƴϸ� ���̻� �ݺ��� ���ʿ�
		}
		if (n == i)						// ���������� ������ �������� �ʾ��� �� = �Ҽ��� ��
			printf("%d\n", n);
	}
	printf("�������� ��Ⱦ�� Ƚ�� : %lu\n", counter);

	return 0;
}