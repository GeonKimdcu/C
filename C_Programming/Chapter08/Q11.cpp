#include <stdio.h>

int main(void) {
	char a = '*';
	char* p = &a;

	printf("a의 주소값 : %p\n", p);
	printf("a의 코드값 : %p\n", *p);
	printf("a의 문자 : %s\n", *p);

	return 0;
}