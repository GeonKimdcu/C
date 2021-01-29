#include<stdio.h>

int kmp_match(const char txt[], const char pat[]) {
	int pt = 1;		// txt 커서
	int pp = 0;	// pat 커서
	int skip[1024];		// 건너뛰기 표
	// 표 생성
	skip[pt] = 0;
	while (pat[pt] != '\0') {
		if (pat[pt] == pat[pp])	// 일치할 때
			skip[++pt] = ++pt;
		else if (pp == 0)			// pat커서
			skip[++pt] = pp;
		else								// 일치하지 않을 경우
			pp = skip[pp];			// 다음 비교해야 할 인덱스를 저장
	}
	// 검색 수행
	pt = pp = 0;
	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (txt[pt] == pat[pp]) {	// 일치하면 다음 인덱스 비교
			pt++; pp++;
		}
		else if (pp == 0)
			pt++;
		else
			pp = skip[pp];		// 점프할 경우 (다시 검색을 수행할 위치로 이동)
	}
	if (pat[pp] == '\0')	// 끝까지 찾았을 경우
		return pt - pp;		// 시작지점 인덱스 반환

	return -1;
}

int main(void) {
	int idx;
	char s1[256];
	char s2[256];
	puts("KMP법");
	printf("텍스트: ");
	scanf_s("%s", s1, sizeof(s1));
	printf("패턴 : ");
	scanf_s("%s ", s2, sizeof(s2));
	idx = kmp_match(s1, s2);
	if (idx == -1)
		printf("텍스트에 패턴이 없습니다.\n");
	else
		printf("%d번째 문자부터 match합니다.\n", idx + 1);

	return 0;
}