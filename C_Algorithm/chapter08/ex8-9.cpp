#include <stdio.h>
		
// 문자열 s에서 문자열 c를 찾기
int str_chr(const char* s, int c) {		// int c로 아스키코드값 매개변수로 받음
	int i = 0;	
	c = (char)c;	// 아스키코드값을 char로 타입변환
	while (s[i] != c) {
		if (s[i] == '\0')	// 검색실패 (끝에 NULL문자 도달)
			return -1;
		i++;
	}
	return i;	// 검색 성공
}

int main(void) {
	char str[64];		// 이 문자열에서 검색
	char tmp[64];
	int ch;				// 검색할 문자
	int idx;

	printf("문자열 : ");
	scanf_s("%s", str, sizeof(str));

	printf("검색할 문자 : ");
	scanf_s("%s", tmp, sizeof(tmp));	// 먼저 문자열로 검색할 문자를 읽어 들입니다.
	ch = tmp[0];		// 첫 번째 문자를 검색할 문자로 지정

	if ((idx = str_chr(str, ch)) == -1)		// 처음 나오는 문자를 검색
		printf("문자 '%c'은(는) 문자열에 없습니다.\n", ch);
	else
		printf("문자 '%c' 은(는) %d번째에 있습니다.\n", ch, idx+1);

	return 0;
}