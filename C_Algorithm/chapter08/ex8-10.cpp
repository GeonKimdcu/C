#include <stdio.h>

int str_cmp(const char* s1, const char* s2) {
	while (*s1 == *s2) {  // s1�� s2�� �ٸ������� �ݺ�
		if (*s1 == '\0')	// ���� <- ������ �����Ͽ��� ����
			return 0;
		s1++;
		s2++;
	}	// �ٸ� ���
	return (unsigned char)* s1 - (unsigned char)* s2;	// �ٸ� ���, �ƽ�Ű�ڵ� ���� ���̸� ��ȯ
}

int main(void) {
	char st[128];
	puts("\"ABCD\"�� ���մϴ�.");
	puts("\"XXXX\"�� �����մϴ�.");
	while (1) {
		printf("���ڿ� st : ");
		scanf_s("%s", st, sizeof(st));
		if (str_cmp("XXXX", st) == 0)		// ���� ����
			break;
		printf("str_cmp(\"ABCD\", st) = %d\n", str_cmp("ABCD", st));
	}
	return 0;
}