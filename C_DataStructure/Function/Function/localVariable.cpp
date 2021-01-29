#include <stdio.h>
#include "localVariable.h"
	/*numA 와 numB는 지역변수이기 때문에 같은 변수명이어도
   sumOne() 과 sumTwo() 함수내에서는 완전히 다른변수*/
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