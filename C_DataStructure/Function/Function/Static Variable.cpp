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
	static int count = 0;  // 만약 static 문구를 삭제하면 지역변수가 되어 "정적변수 출력1" 이라는 결과값만 출력
	count = count + 1;
	printf("정적변수 출력 %d\n", count);
}