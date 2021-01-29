#include <stdio.h>
#include "BitSet.h"

// ���� s�� n�� ��� �ִ��� Ȯ��(����) / ���� s�� n���� ���ٸ� ������ / n�� ����ִٸ� {n} ���
int IsMember(BitSet s, int n) {
	return s & SetOf(n);
}

// ���� s�� n�� �߰�(����) / ���� s�� n�� ���ٸ� n�� �����ϴ� ��Ʈ�� 0���� 1�� ���� 
// ���� n�� �ִ� ��� ���� s�� �״����
void Add(BitSet* s, int n) {
	*s |= SetOf(n);
}

// ���� s���� n�� ���� / ���� s�� ��Ʈ ���Ϳ� SetOf(n)���� ���� ��Ʈ ������ ������ ���� ���� -> n����
void Remove(BitSet* s, int n) {
	*s &= ~SetOf(n);
}

// ���� s�� ���� ������ ��ȯ / ��Ʈ ���;��� '1'�� ��Ʈ�� �� ������ �ľ�
// s���� s-1�� ���� ���� �� s���� ���� �Ʒ����� ��Ʈ�� 0���� ����
int Size(BitSet s) {
	int n = 0;	// ���� Ƚ��
	for (; s != BitSetNull; n++)	// �������� �� ������ �ݺ�
		s &= s - 1;
	return n;
}

// ���� s�� ��� ���Ҹ� ���
void Print(BitSet s) {
	int i;
	printf("{ ");
	for (i = 0; i < BitSetBits; i++)
		if (IsMember(s, i))
			printf("%d", i);
	printf("}");
}

// ���� s�� ��� ���Ҹ� ���(�� �ٲ� ���� ����)
void PrintLn(BitSet s) {
	Print(s);
	putchar('\n');
}