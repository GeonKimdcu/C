#include <stdio.h>
#include <stdlib.h>   // �����Ҵ� ���� �Լ� malloc()
#include <string.h>
#include "ex4_1.h"

// ���� ���� ����Ʈ�� �����ϴ� ���� 
linkedList_h* createLinkedList_h(void) {
	linkedList_h*L;
	L = (linkedList_h*)malloc(sizeof(linkedList_h));
	L->head = NULL;   // ���鸮��Ʈ�̹Ƿ� NULL�� ����
	return L;
}
// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList_h(linkedList_h*L) {
	listNode*p;
	while (L->head != NULL) {
		p = L->head;
		L->head = L->head->link;
		free(p);
		p = NULL;
	}
}

	// ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h*L) {
	listNode*p;
	printf("L = (");
	p = L->head;
	while (p != NULL) {
		printf("%s", p->data);
		p = p->link;
		if (p != NULL) printf(" , ");
	}
	printf(") \n");
}

// ù��° ���� �����ϴ� ����				[�˰��� 4-1 ����]
void insertFirstNode(linkedList_h * L, const char *x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));    // ������ �� ��� �Ҵ�
	strcpy_s(newNode->data, x);
	newNode->link = L->head;
	L->head = newNode;
}

// ��带 pre �ڿ� �����ϴ� ����				[�˰��� 4-2 ����]
void insertMiddleNode(linkedList_h* L, listNode *pre, const char*x) {
	listNode* newNode;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy_s(newNode->data, x);
	if (L == NULL) {			// ���� ����Ʈ�� ���
		newNode->link = NULL;			// �� ��带 ù ��°���� ������ ���� ����
		L->head = newNode;
	}
	else if(pre == NULL) {			// ���� ��ġ�� �����ϴ� ������ pre�� NULL�� ���
		L->head = newNode;		// �� ��带 ù ��° ���� ����
	}
	else {
		newNode->link = pre->link;   // ������ pre�� ��� �ڿ� �� ��� ����
		pre->link = newNode;
	}
}
// ������ ���� �����ϴ� ����			[�˰��� 4-3 ����]
void insertLastNode(linkedList_h*L,const  char* x) {
	listNode* newNode;
	listNode* temp;
	newNode = (listNode*)malloc(sizeof(listNode));
	strcpy_s(newNode->data, x);
	newNode->link = NULL;
	if (L->head == NULL) {		// ���� ����Ʈ�� ������ ���
		L->head = newNode;		// �� ��带 ����Ʈ�� ���� ���� ����
		return;
	}
	// ���� ����Ʈ�� ������ �ƴ� ���
	temp = L->head;
	while (temp->link != NULL) temp = temp->link;	// ���� ����Ʈ�� ������ ��带 ã��
	temp->link = newNode;		// �� ��带 ������ ���(temp)�� ���� ���� ����
}



/* #include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ex4_1.h"

int main() {
	linkedList_h*L;
	L = createLinkedList_h();
	printf("(1) ���� ����Ʈ �����ϱ�! \n");
	printList(L); getchar();

	printf("(2) ����Ʈ�� [��] ��� �����ϱ�! \n");
	insertFirstNode(L, "��");
	printList(L); getchar();

	printf("(3) ����Ʈ �������� [��] ��� �����ϱ�! \n");
	insertLastNode(L, "��");
	printList(L); getchar();

	printf("(4) ����Ʈ ù ��°�� [��] ��� �����ϱ�! \n");
	insertFirstNode(L, "��");
	printList(L); getchar();

	printf("(5) ����Ʈ ������ �����Ͽ� ���� ����Ʈ�� �����! \n");
	freeLinkedList_h(L);
	printList(L);

	getchar();

	return 0;
}
*/