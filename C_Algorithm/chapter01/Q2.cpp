#include <stdio.h>


int min3(int a, int b, int c) {
	int min = a;
	if (b < min) min = b;
	if (c < min) min = c;
	return min;
}

int main(void) {
	printf("최솟값을 구하세요.\n");
	printf("min3(%d, %d, %d) = %d\n", 15, 12, 17, min3(15, 12, 17));
	printf("min3(%d, %d, %d) = %d\n", 7, 6, 4, min3(7, 6, 4));
	
	return 0;
}