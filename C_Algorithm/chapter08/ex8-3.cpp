#include <stdio.h>

int main(void) {
	char st[10] = "ABCD";	// NULL �ڵ��߰�
	printf("���ڿ� st���� \"%s\"�� ��� �ֽ��ϴ�.\n", st);

	char ct[10] = { 'A', 'B', 'C', 'D', '\0' };	// NULL ���۾����� �߰� �ؾ���.
	// �ʱ�ȭ���� ����� �ڵ�� �ʱ�ȭ������ ����� ��!
	// ct = "ABCD"; ���� �߻�
	printf("���ڿ� ct���� \"%s\"�� ��� �ֽ��ϴ�.\n", ct);

	char bt[] = "ABCD";	// �迭 ��� ���� 5�� (NULL���� ����)
	// ��� ���� �����ϰ� ���ڿ� �����, �ʱ�ȭ�� �� �Է��� ���ڿ��� ��� ������ �迭�� ��� ������ �ȴ�.
	printf("���ڿ� bt���� \"%s\"�� ��� �ֽ��ϴ�.\n", bt);

	return 0;
}