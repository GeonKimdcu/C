 #include <stdio.h>
#include <stdlib.h>

int sumof(const int a[], int n) {
	int i;
	int sum = a[0];

	for (i = 1; i < n; i++)
		sum += a[i];
	return sum;
}

int main(void) {
	int i;
	int* height;
	int number;
	printf("��� �� : ");
	scanf_s("%d", &number);

	height = (int*)calloc(number, sizeof(int));
	printf("%d ����� Ű�� �Է��ϼ���.\n", number);
	for (i = 0; i < number; i++) {
		printf("height[%d] : ", i);
		scanf_s("%d", &height[i]);
	}

	printf("Ű�� �հ�� %d�Դϴ�.\n", sumof(height, number));
	free(height);

	return 0;
}
