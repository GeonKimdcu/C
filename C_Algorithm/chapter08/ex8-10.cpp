#include <stdio.h>

int str_cmp(const char* s1, const char* s2) {
	while (*s1 == *s2) {  // s1과 s2가 다를때까지 반복
		if (*s1 == '\0')	// 같음 <- 끝까지 도달하였기 때문
			return 0;
		s1++;
		s2++;
	}	// 다를 경우
	return (unsigned char)* s1 - (unsigned char)* s2;	// 다를 경우, 아스키코드 값의 차이를 반환
}

int main(void) {
	char st[128];
	puts("\"ABCD\"와 비교합니다.");
	puts("\"XXXX\"면 종료합니다.");
	while (1) {
		printf("문자열 st : ");
		scanf_s("%s", st, sizeof(st));
		if (str_cmp("XXXX", st) == 0)		// 종료 조건
			break;
		printf("str_cmp(\"ABCD\", st) = %d\n", str_cmp("ABCD", st));
	}
	return 0;
}