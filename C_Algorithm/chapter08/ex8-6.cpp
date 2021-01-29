#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int str_len(const char* s) {
	int len = 0;
	
	while (s[len])	// while문은 널 문자를 만나면 s[len] = 0이 되어 문자열 스캔 종료
		len++;
	
	return len;	// len의 값은 널 문자가 들어있는 요소의 인덱스와 같다.
}

int main(void) {
	char str[256];
	printf("문자열 : ");
	scanf_s("%s", str, sizeof(str));    // scanf_s("%s", name, sizeof(name))까지해야 에러 발생안함
	// scanf("%s", str) <- str에 &안붙여도 됨. str은 첫 번째 문자에 대한 포인터이므로 주소값필요없기 때문
	printf("이 문자열의 길이는 %d입니다.\n", str_len(str));

	return 0;
}