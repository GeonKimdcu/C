#include <stdio.h>
#include <stdlib.h>
#include "ex4-1.h"

// ���� �ʱ�ȭ
int Initialize(IntStack* s, int max)
{
	s->ptr = 0;  // ptr(top) �� 0�� ����
	if ((s->stk = (int*)calloc(max, sizeof(int))) == NULL) {   // �޸� �Ҵ� �������� ���
		s->max = 0; // �迭���� ������ ��� max = 0 �����ؼ� �������� �ʴ� �迭stk�� �ٸ� �Լ��� ���� ����
		return -1;
	}
	s->max = max; // �ٸ� �Լ������� ����ϱ� ���ؼ� max���� ����ϰ� �־�� ��
	return 0;
}

// ���ÿ� ������ Ǫ��
int Push(IntStack* s, int x) {
	if (s->ptr >= s->max)	// ������ ���� �� ���    = if(s->ptr == s->max) �� ���� ��
		return -1;
	s->stk[s->ptr++] = x;  // ���� ptr�� x���� ������ �Ŀ� ptr�� 1������Ŵ
	return 0;
}

// ���ÿ��� �����͸� ��
int Pop(IntStack* s, int* x) {
	if (s->ptr <= 0)		// ������ ������� ���
		return -1;
	*x = s->stk[--s->ptr];	// ������... ������ -1�ڸ��� ptr�� x�� ����(x�� ����Ű�� ����)�� ����
	return 0;
}

// ���ÿ��� �����͸� ��ũ(������)
int Peek(const IntStack* s, int* x) {	// ptr���� �����Ű�� �ʱ� ���� const 
	if (s->ptr <= 0)		// ������ ������� ���
		return -1;
	*x = s->stk[s->ptr - 1];		// �������� ������� �����Ƿ� ���� �����ʹ� ��ȭx
	return 0;
}

// ������ ��� ��� ����
void Clear(IntStack* s) {
	s->ptr = 0;	// ptr���� 0���� �ϸ� ��� ��� ����
}

//  ������ �뷮�� Ȯ��
int Capacity(const IntStack* s) {
	return s->max;
}

// ���� ���ÿ� �׿� �ִ� ������ ���� ��ȯ
int Size(const IntStack* s) {
	return s->ptr;
}

//  ������ ��� �ִ��� �˻�
int IsEmpty(const IntStack* s) {
	return s->ptr <= 0;
}

// ������ ���� á���� �˻�
int IsFull(const IntStack* s) {
	return s->ptr >= s->max;
}

// ������ ���� �����Ͱ� ������ �����ġ�� �׿��ִ��� �˻�
int Search(const IntStack* s, int x) {
	int i;
	for (i = s->ptr - 1; i >= 0; i--)	// top���� -> bottom ������ �����˻�
		if (s->stk[i] == x)	
			return i;	// �˻� ����
	return -1;		//�˻� ����
}

// ��� ������ ���
void Print(const IntStack* s) {
	int i;
	for (i = 0; i < s->ptr; i++)	// bottom -> top ������ ���
		printf("%d", s->stk[i]);
	putchar('\n');
}

// ���� ����
void Terminate(IntStack* s) {
	if (s->stk != NULL)	
		free(s->stk);  // ���� ����
	s->max = s->ptr = 0;		// �뷮max�� ���������͸� 0���� ����
}