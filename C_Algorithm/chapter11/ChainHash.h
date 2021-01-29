#ifndef ___ChainHash
#define ___ChainHash
#include "Member.h"

typedef struct __node {	// ��Ŷ�� ��Ÿ���� ��� (��������)
	Member data;				// ��Ŷ�� ���� Member�� ������ (�� ����� ����)
	struct __node* next;	// ���� ��忡 ���� ������	... ���� ��尡 ������ NULL�� ��.
}Node;

typedef struct {		// �ؽ� ���̺� (���� ������)
	int size;				// �ؽ� ���̺��� ũ��	(table �迭�� ��� ����)
	Node** table;		// �ؽ� ���̺��� ù ��° ��ҿ� ���� ������
}ChainHash;



int Initialize(ChainHash* h, int size);

Node* Search(const ChainHash* h, const Member* x);

int Add(ChainHash* h, const Member* x);

int Remove(ChainHash* h, const Member* x);

void Dump(const ChainHash* h);

void  Clear(ChainHash* h);

void Terminate(ChainHash* h);

#endif
