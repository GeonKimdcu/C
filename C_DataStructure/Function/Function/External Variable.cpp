#include <stdio.h>
#include "External Variable.h"
  // 전역변수와 지역변수가 같은 이름을 사용할 경우 항상 지역변수가 우선이다.

/*int main(void) {
	int i;
	for (i = 0; i < 10; i++) {
		sum(i);
		printf("합계는 %d 이다.\n ", total);
	}
	return 0;
}
*/
void sum(int count) {
	total = total + count;
}

/* define 매크로 사용해서 변수를 선언하자
만약 프로그램 내부에서 변경되지 않는 값이 있다면 #define문을 사용하면 된다.
또한 간단한 연산을 처리하게 만들 수도 있다. */
// #define ONE 1    => 프로그램 내부에서 ONE은 항상 1의 값을 가지게 된다.
// #define TWO ONE+1  => TWO는 1+1인 2의 값을 가진다.