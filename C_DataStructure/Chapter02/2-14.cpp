#include <stdio.h>

long int fact(int); //메소드블록 팩토리얼 함수지정

void main() {
	int n, result;
	printf("\n 정수를 입력하세요 : ");
	scanf_s("%d", &n);
	result = fact(n);
	printf("\n\n %d의 팩토리얼 값은 %ld입니다.\n", n, result); // %ld는 long int 타입임 
	getchar();  getchar();
}
long int fact(int n) {
	int value;
	if (n <= 1) {
		printf("\n fact(1) 함수호출!");
		printf("\n fact(1) 값 1 반환!!");
		return 1;
	}
	else {
		printf("\n fact(%d) 함수호출!", n);
		value = (n*fact(n - 1));
		printf("\n fact(%d) 값 %ld 반환!!", n, value);
		return value;
	}
}