# include <stdio.h>

int str_len(const char* s) {
	const char* p = s;
	while (*s)
		s++;
	return s - p;
}
int main(void) {
	char str[256];
	printf("���ڿ� : ");
	scanf_s("%s", str, sizeof(str));    // scanf_s("%s", name, sizeof(name))�����ؾ� ���� �߻�����
	// scanf("%s", str) <- str�� &�Ⱥٿ��� ��. str�� ù ��° ���ڿ� ���� �������̹Ƿ� �ּҰ��ʿ���� ����
	printf("�� ���ڿ��� ���̴� %d�Դϴ�.\n", str_len(str));

	return 0;
}