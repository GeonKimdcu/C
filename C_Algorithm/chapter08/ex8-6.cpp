#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int str_len(const char* s) {
	int len = 0;
	
	while (s[len])	// while���� �� ���ڸ� ������ s[len] = 0�� �Ǿ� ���ڿ� ��ĵ ����
		len++;
	
	return len;	// len�� ���� �� ���ڰ� ����ִ� ����� �ε����� ����.
}

int main(void) {
	char str[256];
	printf("���ڿ� : ");
	scanf_s("%s", str, sizeof(str));    // scanf_s("%s", name, sizeof(name))�����ؾ� ���� �߻�����
	// scanf("%s", str) <- str�� &�Ⱥٿ��� ��. str�� ù ��° ���ڿ� ���� �������̹Ƿ� �ּҰ��ʿ���� ����
	printf("�� ���ڿ��� ���̴� %d�Դϴ�.\n", str_len(str));

	return 0;
}