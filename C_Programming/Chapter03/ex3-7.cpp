#include <stdio.h>

int main(void) {
	char c1 = 'a';
	char c2 = 65;			// �빮�� A�� �ڵ尪
	char c3 = '\132';	// �빮�� Z�� 8���� �ڵ尪
	char c4 = '\x5A';	// �빮�� Z�� 16���� �ڵ尪

	printf("���尪(����) : %c %c %c %c\n", c1, c2, c3, c4);
	printf("���尪(����) : %d %d %d %d\n", c1, c2, c3, c4);
		// %d�� ������ �ڵ尪 ������ ���	


	return 0;
}