#include <stdio.h>
#include "External Variable.h"
  // ���������� ���������� ���� �̸��� ����� ��� �׻� ���������� �켱�̴�.

/*int main(void) {
	int i;
	for (i = 0; i < 10; i++) {
		sum(i);
		printf("�հ�� %d �̴�.\n ", total);
	}
	return 0;
}
*/
void sum(int count) {
	total = total + count;
}

/* define ��ũ�� ����ؼ� ������ ��������
���� ���α׷� ���ο��� ������� �ʴ� ���� �ִٸ� #define���� ����ϸ� �ȴ�.
���� ������ ������ ó���ϰ� ���� ���� �ִ�. */
// #define ONE 1    => ���α׷� ���ο��� ONE�� �׻� 1�� ���� ������ �ȴ�.
// #define TWO ONE+1  => TWO�� 1+1�� 2�� ���� ������.