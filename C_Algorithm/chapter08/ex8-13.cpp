#include<stdio.h>

int kmp_match(const char txt[], const char pat[]) {
	int pt = 1;		// txt Ŀ��
	int pp = 0;	// pat Ŀ��
	int skip[1024];		// �ǳʶٱ� ǥ
	// ǥ ����
	skip[pt] = 0;
	while (pat[pt] != '\0') {
		if (pat[pt] == pat[pp])	// ��ġ�� ��
			skip[++pt] = ++pt;
		else if (pp == 0)			// patĿ��
			skip[++pt] = pp;
		else								// ��ġ���� ���� ���
			pp = skip[pp];			// ���� ���ؾ� �� �ε����� ����
	}
	// �˻� ����
	pt = pp = 0;
	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (txt[pt] == pat[pp]) {	// ��ġ�ϸ� ���� �ε��� ��
			pt++; pp++;
		}
		else if (pp == 0)
			pt++;
		else
			pp = skip[pp];		// ������ ��� (�ٽ� �˻��� ������ ��ġ�� �̵�)
	}
	if (pat[pp] == '\0')	// ������ ã���� ���
		return pt - pp;		// �������� �ε��� ��ȯ

	return -1;
}

int main(void) {
	int idx;
	char s1[256];
	char s2[256];
	puts("KMP��");
	printf("�ؽ�Ʈ: ");
	scanf_s("%s", s1, sizeof(s1));
	printf("���� : ");
	scanf_s("%s ", s2, sizeof(s2));
	idx = kmp_match(s1, s2);
	if (idx == -1)
		printf("�ؽ�Ʈ�� ������ �����ϴ�.\n");
	else
		printf("%d��° ���ں��� match�մϴ�.\n", idx + 1);

	return 0;
}