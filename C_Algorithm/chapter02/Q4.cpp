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
	
	srand(time(NULL));
	printf("사람 수 : ");
	number = 5 + rand() % 16;
	printf(" %d\n", number);

	height = (int*)calloc(number, sizeof(int));

	for (i = 0; i < number; i++) {
		height[i] = 150 + rand() % 40;
		printf("height[%d] = %d\n", i, height[i]);
	}
	printf("최댓값은 %d입니다,\n", maxof(height, number));
	free(height);

	return 0;

}