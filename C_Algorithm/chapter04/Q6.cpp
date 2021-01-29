#include <stdio.h>
#include <stdlib.h>
#include "Q6.h"

// 덱 초기화
int Initialize(IntDeck *q, int max) {
	q->num = q->front = q->rear = 0;
	if ((q->que = (int*)calloc(max, sizeof(int))) == NULL) {
		q->max = 0;				// 메모리 생성 실패
		return -1;
	}
	q->max = max;
	return 0;
}

//  맨앞 인큐
int Enque_front(IntDeck *q, int x) {
	if (q->num >= q->max)
		return -1;							// 덱이 가득 참
	else {
		q->num++;
		if (--q->front < 0)	// front의 인덱스가 음수가 되었을 때
			q->front = q->max - 1;	// front의 인덱스를 max-1로 변경
		q->que[q->front] = x;
		return 0;
	}
}

// 맨끝 인큐
int Enque_rear(IntDeck *q, int x) {
	if (q->num >= q->max)	// 가득 찼을 때
		return -1;						
	else {
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max) // rear의 인덱스가 max와 같을 때
			q->rear = 0;		// rear의 인덱스를 0으로 변경
		return 0;
	}
}
// 맨앞 디큐
int Deque_front(IntDeck *q, int *x) {
	if (q->num <= 0)						// 덱이 비었을 때
		return -1;
	else {
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max)	// front인덱스가 max와 같을 때
			q->front = 0;	// front인덱스를 0으로 초기화
		return 0;
	}
}
// 맨뒤 디큐
int Deque_rear(IntDeck *q, int *x)
{
	if (q->num <= 0)						// 덱이 비었을 때
		return -1;
	else {
		q->num--;
		if (--q->rear < 0)			
			q->rear = q->max - 1;
		*x = q->que[q->rear]; // rear 증감식 필요한지?
		return 0;
	}
}


int Peek_front(const IntDeck *q, int *x)
{
	if (q->num <= 0)		// 덱이 비었을 때			
		return -1;
	*x = q->que[q->front];	// 증감식?
	return 0;
}


int Peek_rear(const IntDeck *q, int *x)
{
	if (q->num <= 0)							
		return -1;
	*x = q->que[q->rear];		// 증감식?
	return 0;
}

void Clear(IntDeck *q)
{
	q->num = q->front = q->rear = 0;
}


int Capacity(const IntDeck *q)
{
	return q->max;
}

int Size(const IntDeck *q)
{
	return q->num;
}

int IsEmpty(const IntDeck *q)
{
	return q->num <= 0;
}

int IsFull(const IntDeck *q)
{
	return q->num >= q->max;
}

int Search(const IntDeck *q, int x)
{
	int i, idx;

	for (i = 0; i < q->num; i++) {
		if (q->que[idx = (i + q->front) % q->max] == x)
			return idx;		
	}
	return -1;				
}

int Search2(const IntDeck *q, int x)
{
	int i;

	for (i = 0; i < q->num; i++) {
		if (q->que[(i + q->front) % q->max] == x)
			return i;	
	}
	return -1;				
}

void Print(const IntDeck *q)
{
	int i;

	for (i = 0; i < q->num; i++)
		printf("%d ", q->que[(i + q->front) % q->max]);
	putchar('\n');
}

void Terminate(IntDeck *q)
{
	if (q->que != NULL)
		free(q->que);						
	q->max = q->num = q->front = q->rear = 0;
}
