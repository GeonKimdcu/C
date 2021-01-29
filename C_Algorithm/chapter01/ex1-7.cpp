#include <stdio.h>

int main(void) {
	int i, j;
	printf("-----곱셈표-----\n");
	for (i = 1; i <= 9; i++) {
		for (j = 1; j <= 9; j++) 
			printf("% 3d", i * j);
		putchar('\n');			// 개행문자   텍스트의 한 행이 끝나고 새로운 행이 시작됨을 의미
		
	}
	return 0;
}