#include <stdio.h>

int main(void) {
	int i, n;
	int factorial = 0;

	printf("������ �Է��ϼ��� : ");
	scanf_s("%d", &n);
	if (n == 0) {
		printf("%d\n", 1);
	}
	else
	{
		factorial = factorial + (n);

		for (i = 1; i < n; i++)
			factorial = factorial * (n - i);
		printf("%d\n", factorial);
	}
	return 0;
}