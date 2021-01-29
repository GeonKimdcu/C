#include <stdio.h> 

int main(void) {
	int a, b;
	
	puts("b -a의 값을 구합니다.");
	printf("a의 값 : ");	scanf_s("%d", &a);
	printf("b의 값 : ");	scanf_s("%d", &b); 
	do {
		printf("a보다 큰 값을 입력하세요!\n");

		printf("b의 값 : ");	scanf_s("%d", &b);
	} while (a >=b);
	printf("b - a 는 %d 입니다.\n", b - a);

	return 0;
}

/*
int main(void) {
	int a, b;
	printf("a의 값 : ");	scanf_s("%d", &a);
	
	while (1) {
		printf("b의 값 : ");	scanf_s("%d", &b);
		if (a >= b)
			printf("a보다 큰 값을 입력하세요!\n");
		else break;
	}
	printf("b - a는 %d입니다.\n", b - a);

	return 0;
}
*/