#include <stdio.h>

int main(void) {
	char a = '*';
	char* p = &a;

	printf("a의 주소값 : %d\n", p);
	printf("a의 코드값 : %d\n", *p);
	printf("a의 문자 : %c\n", *p);

	return 0;
}