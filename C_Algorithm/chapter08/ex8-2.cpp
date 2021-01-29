#include <stdio.h>

int main(void)
{
	char st[10];
	st[0] = 'A';
	st[1] = 'B';
	st[2] = 'C';
	st[3] = 'D';
	st[4] = '\0';	// 문자열에는 늘 끝에 NULL값을 줘야함.
	// 널문자는 문자열의 끝을 나타내므로 st[5]부터 어떤 문자를 대입해도 널 문자까지만 문자열로 인식함.
	st[5] = 'X';

	printf("문자열 st에는 \"%s\"가 들어 있습니다.\n", st);

	return 0;
}