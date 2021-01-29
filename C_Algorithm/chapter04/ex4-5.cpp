#include <stdio.h>
#include <stdlib.h>
#include "ex4-5.h"

// 큐 초기화 
int Initialize(IntQueue* q, int max) {
	q->num = q->front = q->rear = 0;
	if ((q->que = (int*)calloc(max, sizeof(int))) == NULL) {		// 메모리 할당x 
		q->max = 0;		// 배열 생성에 실패
		return -1;
	}
	q->max = max;	// 큐의 최대용량 저장
	return 0;
}
// 큐에 데이터를 인큐
int Enque(IntQueue* q, int x) {
	if (q->num >= q->max)		// 큐가 가득 찼을 때
		return -1;
	else {
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max)		// 원형인덱스가 되게끔 초기화하기 위해서 
			q->rear = 0;
		return 0;
	}
}
// 큐에서 데이터를 디큐
int Deque(IntQueue* q, int* x) {
	if (q->num <= 0)	// 큐는 비어 있음
		return -1;
	else {
		q->num--;
		*x = q->que[q->front++];	// *x는 디큐할 요소를 담을 공간
		if (q->front == q->max)		// 원형그래프 형식의 인덱스 초과문제를 위해서
			q->front = 0;
		return 0;
	}
}
// 큐에서 데이터를 피크
int Peek(const IntQueue* q, int* x) {
	if (q->num <= 0)		// 큐는 비어 있음
		return -1;
	*x = q->que[q->front];
	return 0;
}
// 모든 데이터 삭제
void Clear(IntQueue* q) {
	q->num = q->front = q->rear = 0;
}
// 큐의 최대 용량
int Capacity(const IntQueue* q) {
	return q->max;
}
// 큐에 쌓여 있는 데이터 개수
int Size(const IntQueue* q) {
	return q->num;
}
// 큐가 비어 있는지
int IsEmpty(const IntQueue* q) {
	return q->num <= 0;
}
// 큐가 가득 찼는지
int IsFull(const IntQueue* q) {
	return q->num >= q->max;
}
// 큐에서 검색
int Search(const IntQueue* q, int x) {
	int i, idx;
	for (i = 0; i < q->num; i++) {
		if (q->que[idx = (i + q->front) % q->max] == x)
			return idx;	// 검색성공
	}
	return -1;		// 실패
}

// Q4 함수
int Search2(const IntQueue* q, int x) {
	int i;
	for (i = 0; i < q->num; i++) {
		if (q->que[(i + q->front) % q->max] == x)
			return i;
	}
	return -1;
}
// 모든 데이터 출력
void Print(const IntQueue* q) {
	int i;
	for (i = 0; i < q->num; i++)
		printf("%d", q->que[i + q->front] % q->max);
	putchar('\n');
}
// 큐의 종료
void Terminate(IntQueue* q) {
	if (q->que != NULL)
		free(q->que);
	q->max = q->num = q->front = q->rear = 0;
}