#ifndef ___BitSet
#define ___BitSet

typedef unsigned long BitSet;		// 집합을 나타내는 자료형 ... 4Byte짜리 타입공간

#define BitSetNull (BitSet) 0     // 공집합(모든 비트가 0)
#define BitSetBits 32					// 유효 비트 수
#define SetOf(no) ((BitSet)1 << (no))		// 집합 {no}를 표현하는 비트벡터를 만듬
													// 집합{0}에서 비트를 왼쪽으로 no만큼 시프트해 집합{no}를 만듬

int IsMember(BitSet s, int n);

void Add(BitSet* s, int n);

void Remove(BitSet* s, int n);

int Size(BitSet s);

void Print(BitSet s);

void PrintLn(BitSet s);
#endif
