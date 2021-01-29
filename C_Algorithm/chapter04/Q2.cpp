#include <stdio.h>
#include <stdlib.h>
#include "Q2.h"

// ���� �ʱ�ȭ
int Initialize(IntStack* s, int max)
{
	s->ptr_A = 0;  // ptr(top) �� 0�� ����
	s->ptr_B = max;
	if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) {   // �޸� �Ҵ� �������� ���
		s->max = 0; // �迭���� ������ ��� max = 0 �����ؼ� �������� �ʴ� �迭stk�� �ٸ� �Լ��� ���� ����
		s->ptr_B = 0;
		return -1;
	}
	s->ptr_B = max-1;
	s->max = max; // �ٸ� �Լ������� ����ϱ� ���ؼ� max���� ����ϰ� �־�� ��
	return 0;
}

// ����A�� ������ Ǫ��
int Push_A(IntStack* s, int x) {
	if (s->ptr_A >= s->max)	// ������ ���� �� ���    = if(s->ptr == s->max) �� ���� ��
		return -1;
	s->stk[s->ptr_A++] = x;  // ���� ptr�� x���� ������ �Ŀ� ptr�� 1������Ŵ
	return 0;
}

// ���� B�� ������ Ǫ��
int Push_B(IntStack* s, int x) {
	if (s->ptr_A >= s->ptr_B+1)
		return -1;
	s->stk[s->ptr_B--] = x;
	return 0;
}

// ���ÿ��� �����͸� ��
int Pop_A(IntStack* s, int* x) {
	if (s->ptr_A <= 0)		// ������ ������� ���
		return -1;
	*x = s->stk[--s->ptr_A];	// ������... ������ -1�ڸ��� ptr�� x�� ����(x�� ����Ű�� ����)�� ����
	return 0;
}

int Pop_B(IntStack* s, int* x) {
	if (s->ptr_B >= s->max-1)
		return -1;
	*x = s->stk[++s->ptr_B];
	return 0;
}

// ���ÿ��� �����͸� ��ũ(������)
int Peek_A(const IntStack* s, int* x) {
	if (s->ptr_A <= 0)		// ������ ������� ���
		return -1;
	*x = s->stk[s->ptr_A - 1];
	return 0;
}

int Peek_B(const IntStack* s, int* x) {
	if (s->ptr_B >= s->max-1)		// ������ ������� ���
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