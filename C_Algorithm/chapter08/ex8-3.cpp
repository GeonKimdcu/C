#include <stdio.h>

int main(void) {
	char st[10] = "ABCD";	// NULL 자동추가
	printf("문자열 st에는 \"%s\"가 들어 있습니다.\n", st);

	char ct[10] = { 'A', 'B', 'C', 'D', '\0' };	// NULL 수작업으로 추가 해야함.
	// 초기화에서 사용한 코드는 초기화에서만 사용할 것!
	// ct = "ABCD"; 에러 발생
	printf("문자열 ct에는 \"%s\"가 들어 있습니다.\n", ct);

	char bt[] = "ABCD";	// 배열 요소 개수 5개 (NULL문자 포함)
	// 요소 개수 생략하고 문자열 선언시, 초기화할 때 입력한 문자열의 요소 개수가 배열의 요소 개수가 된다.
	printf("문자열 bt에는 \"%s\"가 들어 있습니다.\n", bt);

	return 0;
}