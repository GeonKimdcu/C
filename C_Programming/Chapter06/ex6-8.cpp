#include <stdio.h>

int main(void) {
	int month;

	printf("년도의 월(month)을 입력: ");
	scanf_s("%d", &month);

	if (month == 4 || month == 5)
		printf("%d월은 봄입니다.\n", month);
	else if (month == 6 || month == 7 || month == 8)
		printf("%d월은 여름입니다.\n", month);
	else if (month == 9 || month == 10 || month == 11)
		printf("%d월은 가을입니다.\n", month);
	else if (month == 12 || month == 1 || month == 2 || month == 3)
		printf("%d월은 겨울입니다.\n", month);
	else
		printf("월(month)을 잘못 입력하셨습니다.\n");
	return 0;
}