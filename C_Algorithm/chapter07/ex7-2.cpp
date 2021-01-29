#include <stdio.h>
#include <stdlib.h>
#include "IntSet.h"

// 집합 초기화
int Initialize(IntSet* s, int max) {
	s->num = 0;		// 초기 상태의 집합은 공집합이므로 num의 값은 0
	if ((s->set = (int*)calloc(max, sizeof(int))) == NULL) {	// 배열 생성 실패했을 경우
		s->max = 0;	
		return -1;
	}
	s->max = max;
	return 0;
}

// 집합 s에 n이 들어있는지 검색
int IsMember(const IntSet* s, int n) {
	int i;
	for (i = 0; i < s->num; i++)				// 선형검색 알고리즘
		if (s->set[i] == n)
			return i;
	return -1;
}

// 집합 s에 n을 추가
void Add(IntSet* s, int n) {
	if (s->num < s->max && IsMember(s, n) == -1)	// 배열에 공간이 남아있고, 집합에 같은 원소n이 들어있지 않은 경우
		s->set[s->num++] = n;
}

// 집합 s에 n을 삭제
void Remove(IntSet* s, int n) {
	int idx;
	if ((idx = IsMember(s, n)) != -1) {	// 집합에 n이 들어있는 경우... 삭제하려는 값의 인덱스가 idx에 대입
		s->set[idx] = s->set[--s->num];	// 마지막 요소를 삭제 위치로 옮김 
	}	// num을 1만큼 감소시킨 후 set의 마지막 요소를 삭제한 idx인덱스의 값에 대입
}

//집합 s에 넣을 수 있는 최대의 원소 개수 반환
int Capacity(const IntSet* s) {
	return s->max;
}

// 집합 s의 원소 개수를 반환
int Size(const IntSet* s) {
	return s->num;
}

// 집합 s2를 s1에 대입
void Assign(IntSet* s1, const IntSet* s2) {
	int i;
	int n = (s1->max < s2->num) ? s1->max : s2->num;
	// 복사하는 원소의 개수 -> s2의 num이 s1의 max보다 크다면 max값 까지만큼 복사해준다
	for (i = 0; i < n; i++)
		s1->set[i] = s2->set[i];
	s1->num = n;
}

// 집합 s1과 s2가 같은지 확인
int Equal(const IntSet* s1, const IntSet* s2) {
	int i, j;
	if (Size(s1) != Size(s2))	// 집합 s1과 s2의 원소 개수가 다른지
		return 0;
	for (i = 0; i < s1->num; i++) {
		for (j = 0; i < s2->num; j++)
			if (s1->set[i] == s2->set[j])			
				break;									// 같은 값이 있으면 break해서 다시 i의 반복문 실행
		if (j == s2->num)							// j가 끝까지 도달했을 경우 두 집합은 같지 않음으로 0반환
			return 0;
	}
	return 1;
}

// 집합 s2와 s3의 합집합을 s1에 대입
IntSet* Union(IntSet* s1, const IntSet* s2, const IntSet* s3) {
	int i;
	Assign(s1, s2);	// 집합s2를 s1에 복사
	for (i = 0; i < s3->num; i++)	// 집합 s3의 모든 원소를 s1에 추가 (중복된  원소는 추가x)
		Add(s1, s3->set[i]);
	return s1;
}

// 집합 s2와 s3의 교집합을 s1에 대입
IntSet* Intersection(IntSet* s1, const IntSet* s2, const IntSet* s3) {
	int i, j;
	s1->num = 0;	// 집합s1을 공집합으로 만듦
	for (i = 0; i < s2->num; i++)
		for (j = 0; j < s3->num; j++)
			if (s2->set[i] == s3->set[j])		// 집합 s2와 s3의 같은 원소가 있을 때
				Add(s1, s2->set[i]);		// 집합 s2와 s3의 같은 원소를 집합 s1에 추가
	return s1;
}

// 집합 s2에서 s3를 뺀 차집합을 s1에 대입
IntSet* Difference(IntSet* s1, const IntSet* s2, const IntSet* s3) {
	int i, j;
	s1->num = 0;						// s1을 공집합으로 만듭니다.
	for (i = 0; i < s2->num; i++) {
		for (j = 0; j < s3->num; j++)
			if (s2->set[i] == s3->set[j])
				break;
		if (j == s3->num)		// 집합 s2와 s3중 다른 원소가 있을 경우 집합 s1에 추가
			Add(s1, s2->set[i]);
	}
	return s1;
}

// 집합 s의 모든 원소를 출력
void Print(const IntSet* s) {
	int i;
	printf("{ ");
	for (i = 0; i < s->num; i++)
		printf("%d", s->set[i]);
	printf("}");
}

// 집합s의 모든 원소를 출력(줄 바꿈 문자 포함)
void PrintLn(const IntSet* s) {
	Print(s);
	putchar('\n');
}

// 집합 종료
void Terminate(IntSet* s) {
	if (s->set != NULL) {
		free(s->set);					// 배열 해제
		s->max = s->num = 0;
	}
}