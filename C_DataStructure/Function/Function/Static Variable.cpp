#include <stdio.h>
#include "Static Variable.h"

/*
void sum();

void main() {
	sum();
	sum();
	sum();

	getchar();
}
*/
void sum() {
	static int count = 0;  // ���� static ������ �����ϸ� ���������� �Ǿ� "�������� ���1" �̶�� ������� ���
	count = count + 1;
	printf("�������� ��� %d\n", count);
}