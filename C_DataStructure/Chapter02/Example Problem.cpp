#include <stdio.h>
void main() {
	int i, j, A[100];
	for (i = 0; i < 100; i++)
		A[i] = i;
	j = i - 1;
	printf("%d", &A[0]+j);

	getchar();
}