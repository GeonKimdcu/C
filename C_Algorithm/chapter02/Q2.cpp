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
	printf("사람 수 : ");
	scanf_s("%d", &number);

	height = (int*)calloc(number, sizeof(int));
	printf("%d 사람의 키를 입력하세요.\n", number);
	for (i = 0; i < number; i++) {
		printf("height[%d] : ", i);
		scanf_s("%d", &height[i]);
	}

	printf("키의 합계는 %d입니다.\n", sumof(height, number));
	free(height);

	return 0;
}
