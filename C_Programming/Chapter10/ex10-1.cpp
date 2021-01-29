#include <stdio.h>

int add2(int a, int b);
int findMin2(int x, int y);
int findMax2(int x, int y);

int main(void) {
	int a = 3, b = 5;
	
	int sum = add2(a, b);
	printf("합 : %d\n", sum);

	int min = findMin2(a, b);
	printf("최소값 : %d\n", min);

	int max = findMax2(a, b);
	printf("최대값 : %d\n", max);

	return 0;
}

int add2(int a, int b) {
	int sum = a + b;

	return sum;
} 

int findMin2(int x, int y) {
	int min = x < y ? x : y;

	return min;
}

int findMax2(int x, int y) {
	int max = x > y ? x : y;

	return max;
}