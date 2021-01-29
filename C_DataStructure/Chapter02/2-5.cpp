// 입력한 문자열의 길이 계산하기
#include <stdio.h>

void main() {
	int i, length = 0;
	char str[50];
	printf("\n 문자열을 입력하세요 : ");
	gets_s(str);

	printf("\n 입력된 문자열은 \n ");
	for (i = 0; i < str[i]; i++) {
		printf(" %c", str[i]);
		length += 1;
	}
	printf("\n 입니다.");
	printf("\n\n 입력된 문자열의 길이 = %d", length);
}