#ifndef ___ClosedHash
#define ___ClosedHash

#include "Member.h"

 // 요소의 상태
typedef enum {
	Occupied, Empty, Deleted
} Status;

// 요소
typedef struct {
	Member data;	// 데이터
	Status stat;	// 요소의 상태
}Bucket;

// 해시 테이블
typedef struct {
	int size;				// 해시 테이블의 크기
	Bucket* table;		// 해시 테이블의 첫 번째 요소에 대한 포인터
}ClosedHash;

int Initialize(ClosedHash* h, int size);

Bucket* Search(const ClosedHash* h, const Member* x);

int Add(ClosedHash* h, const Member* x);

int Remove(ClosedHash* h, const Member* x);

void Dump(const ClosedHash* h);

void Clear(ClosedHash* h);

void Terminate(ClosedHash* h);

#endif