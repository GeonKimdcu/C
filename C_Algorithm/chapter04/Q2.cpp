#include <stdio.h>
#include <stdlib.h>
#include "Q2.h"

// 스택 초기화
int Initialize(IntStack* s, int max)
{
	s->ptr_A = 0;  // ptr(top) 에 0을 대입
	s->ptr_B = max;
	if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) {   // 메모리 할당 실패했을 경우
		s->max = 0; // 배열생성 실패할 경우 max = 0 대입해서 존재하지 않는 배열stk에 다른 함수의 접근 막음
		s->ptr_B = 0;
		return -1;
	}
	s->ptr_B = max-1;
	s->max = max; // 다른 함수에서도 사용하기 위해서 max값을 기억하고 있어야 함
	return 0;
}

// 스택A에 데이터 푸시
int Push_A(IntStack* s, int x) {
	if (s->ptr_A >= s->max)	// 스택이 가득 찰 경우    = if(s->ptr == s->max) 와 같은 뜻
		return -1;
	s->stk[s->ptr_A++] = x;  // 현재 ptr에 x값을 저장한 후에 ptr을 1증가시킴
	return 0;
}

// 스택 B에 데이터 푸시
int Push_B(IntStack* s, int x) {
	if (s->ptr_A >= s->ptr_B+1)
		return -1;
	s->stk[s->ptr_B--] = x;
	return 0;
}

// 스택에서 데이터를 팝
int Pop_A(IntStack* s, int* x) {
	if (s->ptr_A <= 0)		// 스택이 비어있을 경우
		return -1;
	*x = s->stk[--s->ptr_A];	// 역참조... 스택의 -1자리의 ptr을 x의 공간(x가 가리키는 변수)에 저장
	return 0;
}

int Pop_B(IntStack* s, int* x) {
	if (s->ptr_B >= s->max-1)
		return -1;
	*x = s->stk[++s->ptr_B];
	return 0;
}

// 스택에서 데이터를 피크(보여줌)
int Peek_A(const IntStack* s, int* x) {
	if (s->ptr_A <= 0)		// 스택이 비어있을 경우
		return -1;
	*x = s->stk[s->ptr_A - 1];
	return 0;
}

int Peek_B(const IntStack* s, int* x) {
	if (s->ptr_B >= s->max-1)		// 스택이 비어있을 경우
		return -1;
	*x = s->stk[s->ptr_B +1];
	return 0;
}

void Clear(IntStack* s) {
	s->ptr_A = 0;
	s->ptr_B = s->max-1;
}

int Capacity(const IntStack* s) {
	return s->max-1;
}

int Size_A(const IntStack* s) {
	return s->ptr_A;
}

int Size_B(const IntStack* s) {
	return s->ptr_B;
}

int IsEmpty(const IntStack* s) {
	return s->ptr_A <= 0;
}

int IsFull(const IntStack* s) {
	return s->ptr_A >= s->max;
}

int Search(const IntStack* s, int x) {
	int i;
	for (i = s->ptr_A - 1; i >= 0; i--)
		if (s->stk[i] == x)
			return i;
	return -1;
}

void Print(const IntStack* s) {
	int i;
	for (i = 0; i < s->ptr_A; i++)
		printf("%d", s->stk[i]);
	putchar('\n');
	for (i = s->max-1; i>s->ptr_B; i--)
		printf("%d", s->stk[i]);
	putchar('\n');
}

void Terminate(IntStack* s) {
	if (s->stk != NULL)
		free(s->stk);
	s->max = s->ptr_A = s->ptr_B = 0;
}