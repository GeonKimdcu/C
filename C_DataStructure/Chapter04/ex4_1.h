#pragma once
// 단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	char data[4];			// 데이터를 저장할 멤버
	struct ListNode* link;		// 다음 노드의 주소를 저장할 멤버 
}listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	listNode*head;
}linkedList_h;

linkedList_h* createLinkedList_h(void);		//// 공백 연결 리스트를 생성하는 연산
void freeLinkedList_h(linkedList_h*L);		// 연결 리스트의 전체 메모리를 해제하는 연산
void printList(linkedList_h*L);			// 연결 리스트를 순서대로 출력하는 연산
void insertFirstNode(linkedList_h * L, const char *x);			// 알고리즘 4-1
void insertMiddleNode(linkedList_h* L, listNode *pre, const char*x);			// 알고리즘 4-2
void insertLastNode(linkedList_h*L, const  char* x);			// 알고리즘 4-3
