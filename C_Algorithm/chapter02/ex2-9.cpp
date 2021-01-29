#include <stdio.h>

int main(void) {
	int i, n;
	unsigned long counter = 0;	// 나눗셈 횟수
	for (n = 2; n <= 1000; n++) {
		for (i = 2; i < n; i++) {		// 2부터 n-1까지 어떤 정수로도 나누어 떨어지지 않음
			counter++;
			if (n % i == 0)			// 나누어 떨어지면 소수가 아님
				break;					// 소수가 아니면 더이상 반복은 불필요
		}
		if (n == i)						// 마지막까지 나누어 떨어지지 않았을 때 = 소수일 때
			printf("%d\n", n);
	}
	printf("나눗셈을 실횡한 횟수 : %lu\n", counter);

	return 0;
}