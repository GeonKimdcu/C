//3차원 배열 입출력하기

#include <stdio.h>

void main() {

	int i, j, k, value = 1;
	int array[2][3][4];

	for (i = 0; i < 2; i++) {
		for (j = 0; j < 3; j++) {
			for (k = 0; k < 4; k++) {

				array[i][j][k] = value;

				printf("\n array[%d][%d][%d] = %d", i, j, k, value);
				value++;
			}
		}
	}
	getchar();
}