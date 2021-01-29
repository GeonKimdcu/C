// 문자배열에 문자열을 저장하고 출력하기 
#include <stdio.h>

void main() {
	char str[] = "Data Structure!";
	int i;
	printf("\n 문자배열 str[] : ");
	for (i = 0; str[i]; i++) {
		printf("%c", str[i]);
	}
	getchar();
}