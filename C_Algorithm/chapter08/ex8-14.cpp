#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>		// UCHAR_MAX의 매크로를 사용하기 위해서

int bm_match(const char txt[], const char pat[]) {
	int pt;	// txt커서
	int pp;	// pat 커서
	int txt_len = strlen(txt);	// txt 문자 개수
	int pat_len = strlen(pat);	// pat 문자 개수
	int skip[UCHAR_MAX + 1];		// 건너뛰기 표... UCHAR_MAX는 표현할 수 있는 문자 개수를 의미
	for (pt = 0; pt <= UCHAR_MAX; pt++)	// 건너뛰기 표 만들기
		skip[pt] = pat_len;	// 건너뛰기 표에 패턴의 길이 n만큼 다 저장
	for (pt = 0; pt < pat_len - 1; pt++)
		skip[pat[pt]] = pat_len - pt - 1;	// 패턴문자(아스키코드 값)에 n-k-1 공식 사용
	// (pt == pat_len -1)와 같음

	while (pt < txt_len) {		// 비교
		pp = pat_len - 1;		// pat의 마지막 문자부터 검사
		while (txt[pt] == pat[pp]) {
			if (pp == 0)	// 찾은 경우
				return pt;
			pp--;
			pt--;
		}	// 찾지 못했을 경우 .... 큰 값을 움직여줘야 효율적으로 이동
		pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
	}
	return -1;
}

int main(void) {
	int idx;
	char s1[256];
	char s2[256];
	puts("Boyer-Moore법");
	printf("텍스트 : ");
	scanf("%s", s1);
	printf("패턴 : ");
	scanf("%s", s2);
	idx = bm_match(s1, s2);
	if (idx == -1)
		puts("텍스트에 패턴이 없습니다.");
	else
		printf("%d번째 문자부터 match합니다.\n", idx + 1);

	return 0;
}