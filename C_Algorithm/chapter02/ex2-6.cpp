 #include <time.h>
#include <stdio.h>
#include <stdlib.h>

int maxof(const int a[], int n) {
	int i;
	int max = a[0];
	for (i = 1; i < n; i++)
		if (a[i] > max)
			max = a[i];
	return max;
}

int main(void) {
	int i;
	int* height;
	int number;
	printf("��� �� : ");
	scanf_s("%d", &number);
	height = (int*)calloc(number, sizeof(int));
	srand(time(NULL));
	for (i = 0; i < number; i++) {
		height[i] = 150 + rand() % 40;
		printf("height[%d] = %d\n", i, height[i]);
	}
	printf("�ִ��� %d�Դϴ�,\n", maxof(height, number));
	free(height);

	return 0;

}