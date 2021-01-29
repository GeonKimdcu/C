#ifndef ___IntStack   // ������ �ȵ�������
#define ___IntStack  // ��� �������ض�   ... ���� ���ǵǾ������� ��� ���� ���� �ʰڴ�

typedef struct {
	int max;	// ���� �뷮
	int ptr_A;		// ���� ������(top)
	int ptr_B;
	int* stk;	// ������ ����Ű�� ������(bottom) ... �迭 .... ù �ε��� �ּҰ��� ����

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
