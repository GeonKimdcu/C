#include <stdio.h>
#include "ex4-1.h"

int main(void)
{
	IntStack s;

	if (Initialize(&s, 64) == -1) {
		puts("������ ������ �����߽��ϴ�.");
		return 1;
	}

	while (1) {
		int menu, x;
		int idx;

		printf("���� ������ �� : %d / %d\n", Size(&s), Capacity(&s));
		printf("1)Ǫ�� 2)�� 3)��ũ 4)��� 5)�˻� 6)�ʱ�ȭ 7)�� ���� / ���� �� ���� 0) ���᣺");
		scanf_s("%d", &menu);

		if (menu == 0) break;

		switch (menu) {
		case 1:						/*--- Ǫ�� ---*/
			printf("������ : ");
			scanf_s("%d", &x);
			if (Push(&s, x) == -1)
				puts("\a���� : Ǫ�ÿ� �����߽��ϴ�.");
			break;

		case 2:						/*--- �� ---*/
			if (Pop(&s, &x) == -1)
				puts("\a���� : �˿� �����߽��ϴ�.");
			else
				printf("���� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 3:						/*--- ��ũ ---*/
			if (Peek(&s, &x) == -1)
				puts("\a���� : ��ũ�� �����߽��ϴ�.");
			else
				printf("��ũ�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 4:						/*--- ���---*/
			Print(&s);
			break;

		case 5:						/*--- �˻� ---*/
			printf("�˻� �����ͣ�");
			scanf_s("%d", &x);
			if ((idx = Search(&s, x)) == -1)
				puts("\a���� : �˻��� �����߽��ϴ�.");
			else
				printf("�����ʹ� �ε��� %d ��ġ�� �ֽ��ϴ�.\n", idx);
			break;

		case 6:						/*--- �ʱ�ȭ ---*/
			Clear(&s);
			break;

		case 7:						/*--- �� ���� / ���� �� ���� ---*/
			printf("������ ��� %s.\n", IsEmpty(&s) ? "�ֽ��ϴ�" : "���� �ʽ��ϴ�");
			printf("������ ���� %s.\n", IsFull(&s) ? "á���ϴ�" : "���� �ʾҽ��ϴ�");
			break;
		}
	}

	Terminate(&s);

	return 0;
}
