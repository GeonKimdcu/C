#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Member.h"

// ȸ�� ��ȣ �� �Լ� 
int MemberNoCmp(const Member* x, const Member* y) {
	return x->no < y->no ? -1 : x->no > y->no ? 1 : 0;	
	// x->no == y->no : 0		// x->no > y->no : 1			// x->no < y->no : -1
}

// ȸ�� �̸� �� �Լ�
int MemberNameCmp(const Member* x, const Member* y) {
	return strcmp(x->name, y->name);	
	// srtcmp(s1, s2) -> ���ڿ��� ������ 0, s1 > s2 �̸� ���� ���� , s1 < s2 �̸� ���� ����
}

// ȸ�� ������(��ȣ�� �̸�)�� ���  (�� �ٲ� X)
void PrintMember(const Member* x) {
	printf("%d %s", x->no, x->name);
}

// ȸ�� ������(��ȣ�� �̸�)�� ���  (�� �ٲ� O)
void PrintLnMember(const Member* x) {
	printf("%d %s\n", x->no, x->name);
}

// ȸ�� ������(��ȣ�� �̸�)�� �о� ����
Member ScanMember(const char* message, int sw) {
	Member temp;
	printf("%s�ϴ� �����͸� �Է��ϼ���.\n", message);	// ���ڿ� ������� ������ message��
	if (sw & MEMBER_NO) { printf("��ȣ : "); scanf("%d", &temp.no); }
	if (sw & MEMBER_NAME) { printf("�̸� : "); scanf("%s", temp.name); }

	return temp;	 // scanf�� �Է¹��� ���� �����ϴ� ���� ...  �� �Լ��� �޴� ������ ���簡 �̷���
}