#include <stdio.h>
#include <stdlib.h>
#include "ex4-1.h"

// 스택 초기화
int Initialize(IntStack* s, int max)
{
	s->ptr = 0;  // ptr(top) 에 0을 대입
	if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) {   // 메모리 할당 실패했을 경우
		s->max = 0; // 배열생성 실패할 경우 max = 0 대입해서 존재하지 않는 배열stk에 다른 함수의 접근 막음
		return -1;
	}
	s->max = max; // 다른 함수에서도 사용하기 위해서 max값을 기억하고 있어야 함
	return 0;
}

// 스택에 데이터 푸시
int Push(IntStack* s, int x) {
	if (s->ptr >= s->max)	// 스택이 가득 찰 경우    = if(s->ptr == s->max) 와 같은 뜻
		return -1;
	s->stk[s->ptr++] = x;  // 현재 ptr에 x값을 저장한 후에 ptr을 1증가시킴
	return 0;
}

// 스택에서 데이터를 팝
int Pop(IntStack* s, int* x) {
	if (s->ptr <= 0)		// 스택이 비어있을 경우
		return -1;
	*x = s->stk[--s->ptr];	// 역참조... 스택의 -1자리의 ptr을 x의 공간(x가 가리키는 변수)에 저장
	return 0;
}

// 스택에서 데이터를 피크(보여줌)
int Peek(const IntStack* s, int* x) {	// ptr값을 변경시키지 않기 위해 const 
	if (s->ptr <= 0)		// 스택이 비어있을 경우
		return -1;
	*x = s->stk[s->ptr - 1];		// 데이터의 입출력이 없으므로 스택 포인터는 변화x
	return 0;
}

// 스택의 모든 요소 삭제
void Clear(IntStack* s) {
	s->ptr = 0;	// ptr값을 0으로 하면 모든 요소 삭제
}

//  스택의 용량을 확인
int Capacity(const IntStack* s) {
	return s->max;
}

// 현재 스택에 쌓여 있는 데이터 개수 반환
int Size(const IntStack* s) {
	return s->ptr;
}

//  스택이 비어 있는지 검사
int IsEmpty(const IntStack* s) {
	return s->ptr <= 0;
}

// 스택이 가득 찼는지 검사
int IsFull(const IntStack* s) {
	return s->ptr >= s->max;
}

// 임의의 값의 데이터가 스택의 어느위치에 쌓여있는지 검사
int Search(const IntStack* s, int x) {
	int i;
	for (i = s->ptr - 1; i >= 0; i--)	// top부터 -> bottom 순서로 선형검색
		if (s->stk[i] == x)	
			return i;	// 검색 성공
	return -1;		//검색 실패
}

// 모든 데이터 출력
void Print(const IntStack* s) {
	int i;
	for (i = 0; i < s->ptr; i++)	// bottom -> top 순서로 출력
		printf("%d", s->stk[i]);
	putchar('\n');
}

// 스택 종료
void Terminate(IntStack* s) {
	if (s->stk != NULL)	
		free(s->stk);  // 스택 해제
	s->max = s->ptr = 0;		// 용량max와 스택포인터를 0으로 돌림
}