#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Member.h"

// 회원 번호 비교 함수 
int MemberNoCmp(const Member* x, const Member* y) {
	return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;	
	// x->no == y->no : 0		// x->no > y->no : 1			// x->no < y->no : -1
}

// 회원 이름 비교 함수
int MemberNameCmp(const Member* x, const Member* y) {
	return strcmp(x->name, y->name);	
	// srtcmp(s1, s2) -> 문자열이 같으면 0, s1 > s2 이면 양의 정수 , s1 < s2 이면 음의 정수
}

// 회원 데이터(번호와 이름)을 출력  (줄 바꿈 X)
void PrintMember(const Member* x) {
	printf("%d %s", x->no, x->name);
}

// 회원 데이터(번호와 이름)을 출력  (줄 바꿈 O)
void PrintLnMember(const Member* x) {
	printf("%d %s\n", x->no, x->name);
}

// 회원 데이터(번호와 이름)을 읽어 들임
Member ScanMember(const char* message, int sw) {
	Member temp;
	printf("%s하는 데이터를 입력하세요.\n", message);	// 문자열 출력위한 변수가 message임
	if (sw & MEMBER_NO) { printf("번호 : "); scanf("%d", &temp.no); }
	if (sw & MEMBER_NAME) { printf("이름 : "); scanf("%s", temp.name); }

	return temp;	 // scanf로 입력받은 값을 저장하는 변수 ...  이 함수를 받는 곳에서 복사가 이뤄짐
}