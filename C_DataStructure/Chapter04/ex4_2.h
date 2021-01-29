#pragma once

// 단순 연결 리스트의 노드 구조를 구조체로 정의
typedef struct ListNode {
	char data[4];
	struct ListNode* link;
}listNode;

// 리스트 시작을 나타내는 head 노드를 구조체로 정의
typedef struct {
	listNode* head;
}linkedList_h;

// 공백 연결 리스트를 생성하는 연산
linkedList_h* createLinkedList_h(void);

// 연결 리스트의 전체 메모리를 해제하는 연산
void freeLinkedList_h(linkedList_h*L);

//  연결 리스트를 순서대로 출력하는 연산
void printList(linkedList_h*L);

// 첫 번째 노드로 삽입하는 연산				[알고리즘 4-1] 구현
void insertFirstNode(linkedList_h*L, const char*x);

// 노드를  pre 뒤에 삽입하는 연산
void insertMiddleNode(linkedList_h*L, listNode*pre, const char*x);

// 마지막 노드로 삽입하는 연산					[알고리즘 4-3] 구현
void insertLastNode(linkedList_h*L, const char*x);

// 리스트에서 노드p를 삭제하는 연산					[알고리즘 4-4] 수정 구현
void deleteNode(linkedList_h*L, listNode* p);

// 리스트에서 x 노드를 탐색하는 연산				     [알고리즘 4-5] 구현
listNode* searchNode(linkedList_h*L, const char*x);

// 리스트의 노드 순서를 역순으로 바꾸는 연산								// 추가연산
void reverse(linkedList_h*L);
