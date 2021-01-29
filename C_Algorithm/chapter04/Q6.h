#ifndef ___IntDequeue
#define ___IntDequeue


typedef struct {
	int max;		
	int num;		
	int front;		
	int rear;		
	int *que;		
} IntDeck;

int Initialize(IntDeck *q, int max);

int Enque_front(IntDeck *q, int x);

int Enque_rear(IntDeck *q, int x);

int Deque_front(IntDeck *q, int *x);

int Deque_rear(IntDeck *q, int *x);

int Peek_front(const IntDeck *q, int *x);

int Peek_rear(const IntDeck *q, int *x);

void Clear(IntDeck *q);

int Capacity(const IntDeck *q);

int Size(const IntDeck *q);

int IsEmpty(const IntDeck *q);

int IsFull(const IntDeck *q);

int Search(const IntDeck *q, int x);

int Search2(const IntDeck *q, int x);

void Print(const IntDeck *q);

void Terminate(IntDeck *q);

#endif

