#ifndef ___BitSet
#define ___BitSet

typedef unsigned long BitSet;		// ������ ��Ÿ���� �ڷ��� ... 4Byte¥�� Ÿ�԰���

#define BitSetNull (BitSet) 0     // ������(��� ��Ʈ�� 0)
#define BitSetBits 32					// ��ȿ ��Ʈ ��
#define SetOf(no) ((BitSet)1 << (no))		// ���� {no}�� ǥ���ϴ� ��Ʈ���͸� ����
													// ����{0}���� ��Ʈ�� �������� no��ŭ ����Ʈ�� ����{no}�� ����

int IsMember(BitSet s, int n);

void Add(BitSet* s, int n);

void Remove(BitSet* s, int n);

int Size(BitSet s);

void Print(BitSet s);

void PrintLn(BitSet s);
#endif
