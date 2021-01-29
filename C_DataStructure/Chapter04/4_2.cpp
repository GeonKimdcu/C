#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ex4_2.h"

// ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void) {
	linkedList_h*L;			// linkedList_h�� ����ƮL�� ����Ŵ
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;  // ���� ����Ʈ �̹Ƿ� NULL�� ����   // ȭ��ǥ ������ ���
	return L;
}

// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList_h(linkedList_h*L) {
	listNode* p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

//  ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h*L) {
	listNode* p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(",");
	}
	printf(") \n");
}

// ù ��° ���� �����ϴ� ����				[�˰��� 4-1] ����
void insertFirstNode(linkedList_h*L, const char*x) {
	listNode*newNode;
	newNode = (listNode*)malloc(sizeof(listNode));			// ������ �� ��� �Ҵ�
	strcpy_s(newNode->data, x);		// strcpy_s(�ּ� ��, ������ ������ ��)
	newNode->link = L->head;
	L->head = newNode;
}
// ��带  pre �ڿ� �����ϴ� ����
void insertMiddleNode(linkedList_h*L, listNode*pre, const char*x) {
	listNode*newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy_s(newNode->data, x);
	if (L == NULL) {			// ���鸮��Ʈ�� ���
		newNode->link = NULL;		// �� ��带 ù ��°���� ������ ���� ����
		L->head = newNode;
	}
	else if (pre == NULL) {			// ���� ��ġ�� �����ϴ� ������ pre�� NULL�� ���
		L->head = newNode;			// �� ��带 ù ��° ���� ����
	}
	else {
		newNode->link = pre->link;				// ������ pre�� ��� �ڿ� �� ��� ����
		pre->link = newNode;
	}
}
// ������ ���� �����ϴ� ����					[�˰��� 4-3] ����
void insertLastNode(linkedList_h*L, const char*x) {
	listNode*newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy_s(newNode->data, x);
	newNode->link = NULL;    // ������ ����̱� ������ NULL�� ����
	if (L->head == NULL) {		// ���� ����Ʈ�� ������ ���
		L->head = newNode;			// �� ��带 ����Ʈ�� ���� ���� ����
		return;
	}
	// ���� ����Ʈ�� ������ �ƴ� ���
	temp = L->head;
	while (temp->link != NULL) temp = temp->link;		// ���� ����Ʈ�� ������ ��带 ã��
	temp->link = newNode;			// �� ��带 ������ ���(temp)�� ���� ���� ����
}

// ����Ʈ���� ���p�� �����ϴ� ����					[�˰��� 4-4] ���� ����
void deleteNode(linkedList_h*L, listNode* p) {
	listNode*pre;										// ������ ����� ������ ��带 ��Ÿ�� ������
	if (L->head == NULL) return;				//  ���� ����Ʈ��� ���� ���� �ߴ�
	if (L->head->link == NULL) {				// ����Ʈ�� ��尡 �� ���� �ִ� ���
		free(L->head);									// ù ��° ��带 �޸𸮿��� �����ϰ�
		L->head = NULL;								// ����Ʈ ���� �����͸�  NULL�� ����
		return;
	}
	else if (p == NULL) return;			// ������ ��尡 ���ٸ� ���� ���� �ߴ�
	else {											// ������ ��� p�� ������ ��带 ������ pre�� �̿��� ã��
		pre = L->head;
		while (pre->link != p) {
			pre = pre->link;
		}
		pre->link = p->link;					// ������ ��� p�� ������ ���� ���� ��带 ����
		free(p);										// ���� ����� �޸� ����
	}
}
// ����Ʈ���� x ��带 Ž���ϴ� ����				     [�˰��� 4-5] ����
listNode* searchNode(linkedList_h*L, const char*x) {
	listNode*temp;
	temp = L->head;
	while (temp != NULL) {
		if (strcmp(temp->data, x) == 0) return temp;						// strcmp(str1, str2) �� ���ϰ��� 0�� ��� ���� ���ڿ� /  0�� �ƴ� ��� �ٸ� ���ڿ�
		else temp = temp->link;
	}
	return temp;
}
// ����Ʈ�� ��� ������ �������� �ٲٴ� ����								// �߰�����
void reverse(linkedList_h*L) {
	listNode*p;
	listNode*q;
	listNode*r;

	p = L->head;			// ������ p�� ù ��° ��忡 ����
	q = NULL;
	r = NULL;

	// ����Ʈ�� ù ��° ������ ��ũ�� ���� ���� ���� �̵��ϸ鼭
	// ��� ���� ������ �ٲ�
	while (p != NULL) {
		r = q;
		q = p;
		p = p->link;
		q->link = r;
	}
	L->head = q;
}