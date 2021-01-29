#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ChainHash.h"

// �ؽ� �Լ� (key�� �ؽ� ���� ��ȯ)
static int hash(int key, int size) {	// ���μ� key <- ȸ�� ��ȣ ��
	return key % size;	// Ű�� ������ -> �ؽ� ��  [ ���⵵ O(1) ]
}

// ����� �� ����� ���� ����
static void SetNode(Node* n, const Member* x, const Node* next) {	// const Member x�� �ص� ����
	n->data = *x;	//  n->data = x�� ����  // *x�� ����Ű�� �����͸� data�� ����
	n->next = (Node*)next;	// ���� ��忡 ���� �����͸� next�� ����
}

// �ؽ� ���̺� �ʱ�ȭ	(������ �ؽ� ���̺��� ����� �Լ�)
int Initialize(ChainHash* h, int size) {	// size <- �ؽ� ���̺��� ũ��
	int i;
	if ((h->table = (Node**)calloc(size, sizeof(Node*))) == NULL) {	// table ��ü ����
		h->size = 0;	
		return 0;
	}
	h->size = size;		// �Ű����� size�� ���� ���� ��� size�� ����
	for (i = 0; i < size; i++)
		h->table[i] = NULL;	// �迭 table�� ��� ��ҿ� ���� ������ NULL�� ����
	return 1;
}

// Ű ���� x->no�� ��Ҹ� �˻�
Node* Search(const ChainHash* h, const Member* x) {
	int key = hash(x->no, h->size);	// �˻��ϴ� �������� �ؽ� ��
	Node* p = h->table[key];		// ���� ������ ���

	while (p != NULL) {
		if (p->data.no == x->no)		// �˻� ����
			return p;		// ã�Ƴ� �����Ϳ� ���� ������ ��ȯ
		p = p->next;		// ���� ��带 ����
	}
	return NULL;	// �˻� ����
}

// ������ �߰�
int Add(ChainHash* h, const Member* x) {	// ������ x�� ����Ű�� �����͸� �߰�
	int key = hash(x->no, h->size);	// �߰��ϴ� �������� �ؽ� ��	( �ؽ� �Լ��� Ű���� �ؽ� ������ ��ȯ)
	Node* p = h->table[key];	// ���� ������ ���	(�ؽ� ���� �ε����� �ϴ� ��Ŷ�� ����)
	Node* temp;
	while (p != NULL) {	// ��Ŷ�� ����� �����Ͱ� ����Ű�� ���Ḯ��Ʈ�� ó������ ���������� �˻�
		if (p->data.no == x->no)		// �̹� ��ϵ� Ű�� ���� ���
			return 1;	// �߰� ����
		p = p->next;		// ���� ��带 ����
	}	// ������ ��ĵ�Ͽ�  ã�� ������ ���, ����Ʈ�� �� �� ��ġ�� ��带 ����
	if ((temp = (Node*)calloc(1, sizeof(Node))) == NULL)
		return 2;
	SetNode(temp, x, h->table[key]);	// ���� ������ ��忡 ���� ��� ���� ���� (�߰��ϴ� ��忡 ���� ����)
	h->table[key] = temp;		// �迭 table�� temp��� �߰�
	return 0;		// �߰� ����
}

// ������ ���� (Ű ���� x->no�� ��Ҹ� ����)
int Remove(ChainHash * h, const Member *x) {
	int key = hash(x->no, h->size);		// �����ϴ� �������� �ؽ� �� (�ؽ� �Լ��� Ű ���� �ؽ� ������ ��ȯ)
	Node* p = h->table[key];				// ���� ������ ��� (�ؽ� ���� �ε����� �ϴ� ��Ŷ�� ����)
	Node** pp = &h->table[key];			// ���� ������ ��忡 ���� ������
	while (p != NULL) {	// ������ ��Ŷ�� �����Ͱ� ����Ű�� ���� ����Ʈ�� ���������� �˻�
		if (p->data.no == x->no) {	// Ű ���� ���� ���� ã���� 
			*pp = p->next;		// �����ϴ� ���� ����� �����͸� ��Ŷ�� ����
			free(p);								// ���� (��带 ����Ʈ���� ����)
			return 0;							// ���� ����
		}
		pp = &p->next;
		p = p->next;							// ���� ��带 ����
	}
	return 1;									// ���� ���� (�������� ����)
}

// �ؽ� ���̺� ���� (�ؽ� ���̺��� ������ ���)
void Dump(const ChainHash* h) {	
	int i;
	for (i = 0; i < h->size; i++) {	// �ؽ� ���̺��� ��� ��Ҹ� ��� (table[0] ~ table[size -1])
		Node* p = h->table[i];
		printf("%02d	", i);		// �ؽ� �� ���
		while (p != NULL) {
			printf("�� %d : (%s)	", p->data.no, p->data.name);
			p = p->next;		// ���� �ؽ� ���� ���� �����͵� ���
		}
		putchar('\n');
	}
}

// ��� ������ ���� (�ؽ� ���̺� ��ϵ� ��� ������ ����)
void  Clear(ChainHash* h) {
	int i;
	for (i = 0; i < h->size; i++) {
		Node* p = h->table[i];	// ���� ������ ���
		while (p != NULL) {
			Node* next = p->next;	// ���� ���� �����ϱ� ���� ���� ����
			free(p);							// ���� ������ ����� �޸� ����
			p = next;						// ���� ��� ����
		}
		h->table[i] = NULL;	// ������ �迭 ��ҿ� NULL�� ����
	}	// ��� Ŀ���� '����'����
}

// �ؽ� ���̺� ����
void Terminate(ChainHash* h) {
	Clear(h);	// ��� ������ ����
	free(h->table);	// �ؽ� ���̺� �迭�� �޸� ����
	h->size = 0;	// �ؽ� ���̺� ũ�⸦ 0���� �ʱ�ȭ
}