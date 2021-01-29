#include <stdio.h>

void swap_ptr(char **x,  char **y) { // ���������� ����ϴ� ���� : s1, s2,�� �̹� ������ �����̹Ƿ� 
															// ������ ������ �ּҰ��� �ҷ��;��ϱ� ������ ���� ������ ���
	char *tmp = *x;
	*x = *y;
	*y = tmp;
}

int  main(void) {
	 char *s1 = (char*)"ABCD";
	 char*s2 = (char*)"EFGH";

	printf("������ s1�� \" %s \"�� ����ŵ�ϴ�.\n", s1);
	printf("������ s2�� \" %s \"�� ����ŵ�ϴ�.\n", s2);

	swap_ptr(&s1, &s2);	// �ּҰ� ����

	puts("\n������ s1�� s2�� ���� ���� ��ȯ�߽��ϴ�.\n");

	printf("������ s1�� \" %s \"�� ����ŵ�ϴ�.\n", s1);
	printf("������ s2�� \" %s \"�� ����ŵ�ϴ�.\n", s2);

	return 0;
}