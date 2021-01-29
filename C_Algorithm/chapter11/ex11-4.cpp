#include <stdio.h>
#include <stdlib.h>
#include "Member.h"
#include "ChainHash.h"

// 해시 함수 (key의 해시 값을 반환)
static int hash(int key, int size) {	// 실인수 key <- 회원 번호 값
	return key % size;	// 키의 나머지 -> 해시 값  [ 복잡도 O(1) ]
}

// 노드의 각 멤버에 값을 설정
static void SetNode(Node* n, const Member* x, const Node* next) {	// const Member x로 해도 같음
	n->data = *x;	//  n->data = x와 같음  // *x가 가리키는 데이터를 data에 저장
	n->next = (Node*)next;	// 다음 노드에 대한 포인터를 next에 저장
}

// 해시 테이블 초기화	(공백인 해시 테이블을 만드는 함수)
int Initialize(ChainHash* h, int size) {	// size <- 해시 테이블의 크기
	int i;
	if ((h->table = (Node**)calloc(size, sizeof(Node*))) == NULL) {	// table 본체 생성
		h->size = 0;	
		return 0;
	}
	h->size = size;		// 매개변수 size로 받은 값을 멤버 size에 복사
	for (i = 0; i < size; i++)
		h->table[i] = NULL;	// 배열 table의 모든 요소에 공백 포인터 NULL을 대입
	return 1;
}

// 키 값이 x->no인 요소를 검색
Node* Search(const ChainHash* h, const Member* x) {
	int key = hash(x->no, h->size);	// 검색하는 데이터의 해시 값
	Node* p = h->table[key];		// 현재 선택한 노드

	while (p != NULL) {
		if (p->data.no == x->no)		// 검색 성공
			return p;		// 찾아낸 데이터에 대한 포인터 반환
		p = p->next;		// 다음 노드를 선택
	}
	return NULL;	// 검색 실패
}

// 데이터 추가
int Add(ChainHash* h, const Member* x) {	// 포인터 x가 가리키는 데이터를 추가
	int key = hash(x->no, h->size);	// 추가하는 데이터의 해시 값	( 해시 함수가 키값을 해시 값으로 변환)
	Node* p = h->table[key];	// 현재 선택한 노드	(해시 값을 인덱스로 하는 버킷을 선택)
	Node* temp;
	while (p != NULL) {	// 버킷에 저장된 포인터가 가리키는 연결리스트를 처음부터 순차적으로 검색
		if (p->data.no == x->no)		// 이미 등록된 키가 있을 경우
			return 1;	// 추가 실패
		p = p->next;		// 다음 노드를 선택
	}	// 끝까지 스캔하여  찾지 못했을 경우, 리스트의 맨 앞 위치에 노드를 삽입
	if ((temp = (Node*)calloc(1, sizeof(Node))) == NULL)
		return 2;
	SetNode(temp, x, h->table[key]);	// 현재 선택한 노드에 템프 노드 값을 저장 (추가하는 노드에 값을 설정)
	h->table[key] = temp;		// 배열 table에 temp노드 추가
	return 0;		// 추가 성공
}

// 데이터 삭제 (키 값이 x->no인 요소를 삭제)
int Remove(ChainHash * h, const Member *x) {
	int key = hash(x->no, h->size);		// 삭제하는 데이터의 해시 값 (해시 함수가 키 값을 해시 값으로 변환)
	Node* p = h->table[key];				// 현재 선택한 노드 (해시 값을 인덱스로 하는 버킷을 선택)
	Node** pp = &h->table[key];			// 현재 선택한 노드에 대한 포인터
	while (p != NULL) {	// 선택한 버킷의 포인터가 가리키는 연결 리스트를 순차적으로 검색
		if (p->data.no == x->no) {	// 키 값과 같은 값을 찾으면 
			*pp = p->next;		// 삭제하는 다음 노드의 포인터를 버킷에 대입
			free(p);								// 해제 (노드를 리스트에서 삭제)
			return 0;							// 삭제 성공
		}
		pp = &p->next;
		p = p->next;							// 다음 노드를 선택
	}
	return 1;									// 삭제 실패 (존재하지 않음)
}

// 해시 테이블 덤프 (해시 테이블의 내용을 출력)
void Dump(const ChainHash* h) {	
	int i;
	for (i = 0; i < h->size; i++) {	// 해시 테이블의 모든 요소를 출력 (table[0] ~ table[size -1])
		Node* p = h->table[i];
		printf("%02d	", i);		// 해시 값 출력
		while (p != NULL) {
			printf("→ %d : (%s)	", p->data.no, p->data.name);
			p = p->next;		// 같은 해시 값을 갖는 데이터도 출력
		}
		putchar('\n');
	}
}

// 모든 데이터 삭제 (해시 테이블에 등록된 모든 데이터 삭제)
void  Clear(ChainHash* h) {
	int i;
	for (i = 0; i < h->size; i++) {
		Node* p = h->table[i];	// 현재 선택한 노드
		while (p != NULL) {
			Node* next = p->next;	// 다음 노드로 연결하기 위해 값을 전달
			free(p);							// 현재 선택한 노드의 메모리 해제
			p = next;						// 다음 노드 선택
		}
		h->table[i] = NULL;	// 마지막 배열 요소에 NULL값 대입
	}	// 모든 커빗이 '공백'상태
}

// 해시 테이블 종료
void Terminate(ChainHash* h) {
	Clear(h);	// 모든 데이터 삭제
	free(h->table);	// 해시 테이블 배열의 메모리 해제
	h->size = 0;	// 해시 테이블 크기를 0으로 초기화
}