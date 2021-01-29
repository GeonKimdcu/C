#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <limits.h>		// UCHAR_MAX�� ��ũ�θ� ����ϱ� ���ؼ�

int bm_match(const char txt[], const char pat[]) {
	int pt;	// txtĿ��
	int pp;	// pat Ŀ��
	int txt_len = strlen(txt);	// txt ���� ����
	int pat_len = strlen(pat);	// pat ���� ����
	int skip[UCHAR_MAX + 1];		// �ǳʶٱ� ǥ... UCHAR_MAX�� ǥ���� �� �ִ� ���� ������ �ǹ�
	for (pt = 0; pt <= UCHAR_MAX; pt++)	// �ǳʶٱ� ǥ �����
		skip[pt] = pat_len;	// �ǳʶٱ� ǥ�� ������ ���� n��ŭ �� ����
	for (pt = 0; pt < pat_len - 1; pt++)
		skip[pat[pt]] = pat_len - pt - 1;	// ���Ϲ���(�ƽ�Ű�ڵ� ��)�� n-k-1 ���� ���
	// (pt == pat_len -1)�� ����

	while (pt < txt_len) {		// ��
		pp = pat_len - 1;		// pat�� ������ ���ں��� �˻�
		while (txt[pt] == pat[pp]) {
			if (pp == 0)	// ã�� ���
				return pt;
			pp--;
			pt--;
		}	// ã�� ������ ��� .... ū ���� ��������� ȿ�������� �̵�
		pt += (skip[txt[pt]] > pat_len - pp) ? skip[txt[pt]] : pat_len - pp;
	}
	return -1;
}

int main(void) {
	int idx;
	char s1[256];
	char s2[256];
	puts("Boyer-Moore��");
	printf("�ؽ�Ʈ : ");
	scanf("%s", s1);
	printf("���� : ");
	scanf("%s", s2);
	idx = bm_match(s1, s2);
	if (idx == -1)
		puts("�ؽ�Ʈ�� ������ �����ϴ�.");
	else
		printf("%d��° ���ں��� match�մϴ�.\n", idx + 1);

	return 0;
}