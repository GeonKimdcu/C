#include <stdio.h>

void swap_ptr(char **x,  char **y) { // 이중포인터 사용하는 이유 : s1, s2,가 이미 포인터 변수이므로 
															// 포인터 변수의 주소값을 불러와야하기 때문에 이중 포인터 사용
	char *tmp = *x;
	*x = *y;
	*y = tmp;
}

int  main(void) {
	 char *s1 = (char*)"ABCD";
	 char*s2 = (char*)"EFGH";

	printf("포인터 s1은 \" %s \"를 가리킵니다.\n", s1);
	printf("포인터 s2는 \" %s \"를 가리킵니다.\n", s2);

	swap_ptr(&s1, &s2);	// 주소값 전달

	puts("\n포인터 s1과 s2의 값을 서로 교환했습니다.\n");

	printf("포인터 s1은 \" %s \"를 가리킵니다.\n", s1);
	printf("포인터 s2는 \" %s \"를 가리킵니다.\n", s2);

	return 0;
}