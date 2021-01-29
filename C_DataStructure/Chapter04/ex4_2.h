#pragma once

// �ܼ� ���� ����Ʈ�� ��� ������ ����ü�� ����
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

// ����Ʈ ������ ��Ÿ���� head ��带 ����ü�� ����
typedef struct {
	listNode* head;
}linkedList_h;

// ���� ���� ����Ʈ�� �����ϴ� ����
linkedList_h* createLinkedList_h(void);

// ���� ����Ʈ�� ��ü �޸𸮸� �����ϴ� ����
void freeLinkedList_h(linkedList_h*L);

//  ���� ����Ʈ�� ������� ����ϴ� ����
void printList(linkedList_h*L);

// ù ��° ���� �����ϴ� ����				[�˰��� 4-1] ����
void insertFirstNode(linkedList_h*L, const char*x);

// ��带  pre �ڿ� �����ϴ� ����
void insertMiddleNode(linkedList_h*L, listNode*pre, const char*x);

// ������ ���� �����ϴ� ����					[�˰��� 4-3] ����
void insertLastNode(linkedList_h*L, const char*x);

// ����Ʈ���� ���p�� �����ϴ� ����					[�˰��� 4-4] ���� ����
void deleteNode(linkedList_h*L, listNode* p);

// ����Ʈ���� x ��带 Ž���ϴ� ����				     [�˰��� 4-5] ����
listNode* searchNode(linkedList_h*L, const char*x);

// ����Ʈ�� ��� ������ �������� �ٲٴ� ����								// �߰�����
void reverse(linkedList_h*L);
