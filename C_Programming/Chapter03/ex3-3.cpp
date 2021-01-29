#include <stdio.h>

int main(void) {
	int math = 99;
	int korean = 90;

	int science;
	science = 94;

	int english = 91;

	int total = math + korean + science + english;

	printf("수학: %d\n", math);
	printf("국어: %d\n", korean);
	printf("과학: %d\n", science);
	printf("영어: %d\n", english);
	printf("총점 %d\n", total);

	return 0;
}