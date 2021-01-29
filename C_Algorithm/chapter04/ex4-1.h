#ifndef ___IntStack   // 디파인 안되잇으면
#define ___IntStack  // 요걸 디파인해라   ... 만약 정의되어있으면 요걸 정의 하지 않겠다

typedef struct {
	int max;	// 스택 용량
	int ptr;		// 스택 포인터(top)
	int* stk;	// 스택을 가리키는 포인터(bottom) ... 배열 .... 첫 인덱스 주소값을 가짐

}IntStack;

int Initialize(IntStack* s, int max);

int Push(IntStack* s, int x);

int Pop(IntStack* s, int* x);

int Peek(const IntStack* s, int* x);

void Clear(IntStack* s);

int Capacity(const IntStack* s);

int Size(const IntStack* s);

int IsEmpty(const IntStack* s);

int IsFull(const IntStack* s);

int Search(const IntStack* s, int x);

void Print(const IntStack* s);

void Terminate(IntStack* s);
#endif