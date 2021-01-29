#include <stdio.h>

int main(void) {
	char c1 = 'a';
	char c2 = 65;			// 대문자 A의 코드값
	char c3 = '\132';	// 대문자 Z의 8진수 코드값
	char c4 = '\x5A';	// 대문자 Z의 16진수 코드값

	printf("저장값(문자) : %c %c %c %c\n", c1, c2, c3, c4);
	printf("저장값(정수) : %d %d %d %d\n", c1, c2, c3, c4);
		// %d는 문자의 코드값 십진수 출력	


	return 0;
}