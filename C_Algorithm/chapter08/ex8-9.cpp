#include <stdio.h>
		
// ���ڿ� s���� ���ڿ� c�� ã��
int str_chr(const char* s, int c) {		// int c�� �ƽ�Ű�ڵ尪 �Ű������� ����
	int i = 0;	
	c = (char)c;	// �ƽ�Ű�ڵ尪�� char�� Ÿ�Ժ�ȯ
	while (s[i] != c) {
		if (s[i] == '\0')	// �˻����� (���� NULL���� ����)
			return -1;
		i++;
	}
	return i;	// �˻� ����
}

int main(void) {
	char str[64];		// �� ���ڿ����� �˻�
	char tmp[64];
	int ch;				// �˻��� ����
	int idx;

	printf("���ڿ� : ");
	scanf_s("%s", str, sizeof(str));

	printf("�˻��� ���� : ");
	scanf_s("%s", tmp, sizeof(tmp));	// ���� ���ڿ��� �˻��� ���ڸ� �о� ���Դϴ�.
	ch = tmp[0];		// ù ��° ���ڸ� �˻��� ���ڷ� ����

	if ((idx = str_chr(str, ch)) == -1)		// ó�� ������ ���ڸ� �˻�
		printf("���� '%c'��(��) ���ڿ��� �����ϴ�.\n", ch);
	else
		printf("���� '%c' ��(��) %d��°�� �ֽ��ϴ�.\n", ch, idx+1);

	return 0;
}