#include <stdio.h>

int main(void) {
	char a = '*';
	char* p = &a;

	printf("a�� �ּҰ� : %d\n", p);
	printf("a�� �ڵ尪 : %d\n", *p);
	printf("a�� ���� : %c\n", *p);

	return 0;
}