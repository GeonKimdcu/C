#include <stdio.h>

int main(void) {
	int i, n;
	int prime[500];				// 소수를 저장하는 배열
	int ptr = 0;					// 이미 얻은 소수의 개수 
	unsigned long counter = 0;
	prime[ptr++] = 2;			// 2는 소수
	for (n = 3; n <= 1000; n+=2) {			// 홀수만을 대상으로 나눔
		for (i = 1; i < ptr; i++) {				// 이미 얻은 소수로 나눈다
			counter++;
			if (n % prime[i] == 0)
				break;
		}
		if (ptr == i)					// 마지막까지 나누어떨어지지 않으면 소수임
			prime[ptr++] = n;		// 배열에 소수 저장
	}
	for (i = 0; i < ptr; i++)
		printf("%d\n", prime[i]);
	printf("나눗셈을 실행한 횟수 : %lu\n", counter);

	return 0;
}