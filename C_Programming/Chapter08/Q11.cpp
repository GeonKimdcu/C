#include <stdio.h>

int main(void) {
	char a = '*';
	char* p = &a;

	printf("a�� �ּҰ� : %p\n", p);
	printf("a�� �ڵ尪 : %p\n", *p);
	printf("a�� ���� : %s\n", *p);

	return 0;
}