#ifndef ___ChainHash
#define ___ChainHash
#include "Member.h"

typedef struct __node {	// 버킷을 나타내는 노드 (원포인터)
	Member data;				// 버킷에 담을 Member형 데이터 (두 멤버로 구성)
	struct __node* next;	// 다음 노드에 대한 포인터	... 다음 노드가 없으면 NULL이 됨.
}Node;

typedef struct {		// 해시 테이블 (이중 포인터)
	int size;				// 해시 테이블의 크기	(table 배열의 요소 개수)
	Node** table;		// 해시 테이블의 첫 번째 요소에 대한 포인터
}ChainHash;



int Initialize(ChainHash* h, int size);

Node* Search(const ChainHash* h, const Member* x);

int Add(ChainHash* h, const Member* x);

int Remove(ChainHash* h, const Member* x);

void Dump(const ChainHash* h);

void  Clear(ChainHash* h);

void Terminate(ChainHash* h);

#endif
