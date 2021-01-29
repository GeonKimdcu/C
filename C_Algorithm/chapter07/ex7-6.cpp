#include <stdio.h>
#include "BitSet.h"

// 집합 s에 n이 들어 있는지 확인(논리곱) / 집합 s에 n값이 없다면 공집합 / n이 들어있다면 {n} 출력
int IsMember(BitSet s, int n) {
	return s & SetOf(n);
}

// 집합 s에 n을 추가(논리합) / 집합 s에 n이 없다면 n에 대응하는 비트가 0에서 1로 변경 
// 원래 n이 있는 경우 집합 s는 그대로임
void Add(BitSet* s, int n) {
	*s |= SetOf(n);
}

// 집합 s에서 n을 삭제 / 집합 s의 비트 벡터와 SetOf(n)으로 얻은 비트 벡터의 보수로 논리곱 연산 -> n삭제
void Remove(BitSet* s, int n) {
	*s &= ~SetOf(n);
}

// 집합 s의 원소 개수를 반환 / 비트 벡터안의 '1'인 비트가 몇 개인지 파악
// s에서 s-1과 논리곱 연산 후 s에서 가장 아래쪽의 비트가 0으로 변경
int Size(BitSet s) {
	int n = 0;	// 연산 횟수
	for (; s != BitSetNull; n++)	// 공집합이 될 때까지 반복
		s &= s - 1;
	return n;
}

// 집합 s의 모든 원소를 출력
void Print(BitSet s) {
	int i;
	printf("{ ");
	for (i = 0; i < BitSetBits; i++)
		if (IsMember(s, i))
			printf("%d", i);
	printf("}");
}

// 집합 s의 모든 원소를 출력(줄 바꿈 문자 포함)
void PrintLn(BitSet s) {
	Print(s);
	putchar('\n');
}