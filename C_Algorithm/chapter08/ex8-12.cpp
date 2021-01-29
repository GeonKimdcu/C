#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int bf_match(const char txt[], const char pat[]) {	// txt(텍스트, 원본) , pat(패턴, 검색할 문자)
	int pt = 0;		// txt 커서
	int pp = 0;	// pat 커서
	while (txt[pt] != '\0' && pat[pp] != '\0') {	// 텍스트와 패턴의 요소 모두 끝까지 도달하기 전까지 반복
		if (txt[pt] == pat[pp]) { // 첫 번째 요소가 같을 경우  계속해서 다음요소 검색
			pt++;
			pp++;
		}
		else { // 다를 경우, pt는 1증가해서 다음요소 검색
			pt = pt - pp + 1;
			pp = 0;		// 패턴의 인덱스는 0으로 초기화해서 다시 검색
		}
	}
	if (pat[pp] == '\0')	// 검색성공
		return pt - pp;	// 인덱스 반환
	return -1;
}

int main(void) {
	int idx;
	char s1[256];	// 텍스트
	char s2[256];	// 패턴
	puts("브루트-포스법");
	printf("텍스트: ");
	scanf("%s", s1);
	printf("패턴 : ");
	scanf("%s ", s2);
	idx = bf_match(s1, s2);
	if (idx == -1)
		printf("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match합니다.\n", idx + 1);

	return 0;
}