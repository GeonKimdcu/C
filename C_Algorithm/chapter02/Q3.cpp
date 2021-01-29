 #include <stdio.h>
#include <stdlib.h>

double aveof(const int a[], int n) {
	int i;
	double ave;
	int sum = a[0];

	for (i = 1; i < n; i++)
		sum += a[i];
	ave = sum / n;
	return ave;
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

	printf("Ű�� ����� %f �Դϴ�.\n", aveof(height, number));
	free(height);

	return 0;
}
