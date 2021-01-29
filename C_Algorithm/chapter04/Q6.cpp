#include <stdio.h>
#include <stdlib.h>
#include "Q6.h"

// �� �ʱ�ȭ
int Initialize(IntDeck *q, int max) {
	q->num = q->front = q->rear = 0;
	if ((q->que = (int*)calloc(max, sizeof(int))) == NULL) {
		q->max = 0;				// �޸� ���� ����
		return -1;
	}
	q->max = max;
	return 0;
}

//  �Ǿ� ��ť
int Enque_front(IntDeck *q, int x) {
	if (q->num >= q->max)
		return -1;							// ���� ���� ��
	else {
		q->num++;
		if (--q->front < 0)	// front�� �ε����� ������ �Ǿ��� ��
			q->front = q->max - 1;	// front�� �ε����� max-1�� ����
		q->que[q->front] = x;
		return 0;
	}
}

// �ǳ� ��ť
int Enque_rear(IntDeck *q, int x) {
	if (q->num >= q->max)	// ���� á�� ��
		return -1;						
	else {
		q->num++;
		q->que[q->rear++] = x;
		if (q->rear == q->max) // rear�� �ε����� max�� ���� ��
			q->rear = 0;		// rear�� �ε����� 0���� ����
		return 0;
	}
}
// �Ǿ� ��ť
int Deque_front(IntDeck *q, int *x) {
	if (q->num <= 0)						// ���� ����� ��
		return -1;
	else {
		q->num--;
		*x = q->que[q->front++];
		if (q->front == q->max)	// front�ε����� max�� ���� ��
			q->front = 0;	// front�ε����� 0���� �ʱ�ȭ
		return 0;
	}
}
// �ǵ� ��ť
int Deque_rear(IntDeck *q, int *x)
{
	if (q->num <= 0)						// ���� ����� ��
		return -1;
	else {
		q->num--;
		if (--q->rear < 0)			
			q->rear = q->max - 1;
		*x = q->que[q->rear]; // rear ������ �ʿ�����?
		return 0;
	}
}


int Peek_front(const IntDeck *q, int *x)
{
	if (q->num <= 0)		// ���� ����� ��			
		return -1;
	*x = q->que[q->front];	// ������?
	return 0;
}


int Peek_rear(const IntDeck *q, int *x)
{
	if (q->num <= 0)							
		return -1;
	*x = q->que[q->rear];		// ������?
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
