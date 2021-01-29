// int형 객체를 동적으로 생성하고 해제합니다.
#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int* x;
	x = (int *)calloc(1, sizeof(int));       // calloc()만 하면 형변환 오류 발생  ->  (int *)를 calloc앞에 붙여 강제형변환 시켜야함
	if (x == NULL) { 
		puts("메모리 할당에 실패했습니다.");
	}
	else {
		*x = 57;
		printf("*x = %d\n", *x);
		free(x);
	}

	return 0;
}