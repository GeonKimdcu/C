#include <stdio.h>
#include "localVariable.h"
	/*numA �� numB�� ���������̱� ������ ���� �������̾
   sumOne() �� sumTwo() �Լ��������� ������ �ٸ�����*/
void sumOne(void) {
	int numA = 10;
	int numB = 20;
	numA++;
	numB--;
	printf("numA : %d  \t numB : %d\n", numA, numB);
}

void sumTwo(void) {
	int numA = 100;
	int numB = 200;
	numA++;
	numB--;
	printf("numA : %d \t numB : %d\n", numA, numB);
}