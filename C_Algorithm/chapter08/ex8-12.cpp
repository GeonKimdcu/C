#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int bf_match(const char txt[], const char pat[]) {	// txt(�ؽ�Ʈ, ����) , pat(����, �˻��� ����)
	int pt = 0;		// txt Ŀ��
	int pp = 0;	// pat Ŀ��
	while (txt[pt] != '\0' && pat[pp] != '\0') {	// �ؽ�Ʈ�� ������ ��� ��� ������ �����ϱ� ������ �ݺ�
		if (txt[pt] == pat[pp]) { // ù ��° ��Ұ� ���� ���  ����ؼ� ������� �˻�
			pt++;
			pp++;
		}
		else { // �ٸ� ���, pt�� 1�����ؼ� ������� �˻�
			pt = pt - pp + 1;
			pp = 0;		// ������ �ε����� 0���� �ʱ�ȭ�ؼ� �ٽ� �˻�
		}
	}
	if (pat[pp] == '\0')	// �˻�����
		return pt - pp;	// �ε��� ��ȯ
	return -1;
}

int main(void) {
	int idx;
	char s1[256];	// �ؽ�Ʈ
	char s2[256];	// ����
	puts("���Ʈ-������");
	printf("�ؽ�Ʈ: ");
	scanf("%s", s1);
	printf("���� : ");
	scanf("%s ", s2);
	idx = bf_match(s1, s2);
	if (idx == -1)
		printf("�ؽ�Ʈ�� ������ �����ϴ�.");
	else
		printf("%d��° ���ں��� match�մϴ�.\n", idx + 1);

	return 0;
}