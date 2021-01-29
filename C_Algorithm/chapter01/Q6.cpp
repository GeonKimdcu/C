#include <stdio.h>

int main(void) {
	int i, n;
	int sum;

	puts("1부터 n까지의 합을 구합니다.");
	printf("n의 값 : ");
	scanf_s("%d", &n);
	sum = 0;
	i = 1;
	while (i <= n) {
		sum += i;
		i++;
	}
	printf("1부터 n까지의 합은 %d입니다.\n", sum);
	printf("i의 값은 %d 이고, n+1과 %s.\n", i, (i == n + 1) ? "같습니다": "같지 않습니다.");
	
	return 0;
}