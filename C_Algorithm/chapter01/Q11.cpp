#include <stdio.h>



int main(void) {
	int n;
	int count = 0;
	

	do {
		puts("양의 정수를 입력하세요!");
		scanf_s("%d", &n);
	} while (n <= 0);

	while(n>0)	{
		n /= 10; 
		count++;
	}
	
	printf("그 수는 %d자리입니다.\n", count);

	return 0;
}