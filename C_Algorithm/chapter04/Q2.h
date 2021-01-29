#ifndef ___IntStack   // 디파인 안되잇으면
#define ___IntStack  // 요걸 디파인해라   ... 만약 정의되어있으면 요걸 정의 하지 않겠다

typedef struct {
	int max;	// 스택 용량
	int ptr_A;		// 스택 포인터(top)
	int ptr_B;
	int* stk;	// 스택을 가리키는 포인터(bottom) ... 배열 .... 첫 인덱스 주소값을 가짐

}IntStack;

int Initialize(IntStack* s, int max);

int Push_A(IntStack* s, int x);

int Push_B(IntStack* s, int x);

int Pop_A(IntStack* s, int* x);

int Pop_B(IntStack* s, int* x);

int Peek_A(const IntStack* s, int* x);

int Peek_B(const IntStack* s, int* x);

void Clear(IntStack* s);

int Capacity(const IntStack* s);

int Size_A(const IntStack* s);

int Size_B(const IntStack* s);

int IsEmpty(const IntStack* s);

int IsFull(const IntStack* s);

int Search(const IntStack* s, int x);

void Print(const IntStack* s);

void Terminate(IntStack* s);
#endif#pragma once
