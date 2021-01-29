#include <stdio.h>

int main(void) {
	int x;
	printf("4자리 정수 입력 : ");
	scanf_s("%d", &x);
	
	printf("%10d\n", x);
	printf("%010d\n", x);
	printf("%+010d\n", x);
	printf("%-d\n", x);
	printf("%10o\n", x);
	printf("%010o\n", x);
	printf("%10x\n", x);
	printf("%0#10x\n", x);
	return 0;
}