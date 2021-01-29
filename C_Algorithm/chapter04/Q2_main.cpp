#include <stdio.h>
#include "Q2.h"

int main(void) {
	IntStack s;
	if (Initialize(&s, 64) == -1) {	// 64ũ���� ���� ���� 
		puts("���� ������ �����Ͽ����ϴ�.");
		return 1;
	}

	while (1) {
		int menu, x;
		printf("���� ������ �� = Stack_A: %d / %d \t Stack_B : %d / %d\n", Size_A(&s), Capacity(&s), Size_B(&s), Capacity(&s));
		printf("(1) AǪ�� (2) A�� (3) A��ũ (4) BǪ�� (5) B��  (6) B��ũ (7) ��� (0)���� : ");
		scanf_s("%d", &menu);

		if (menu == 0) break;
		switch (menu) {
		case 1:
			printf("������ : ");
			scanf_s("%d", &x);
			if (Push_A(&s, x) == -1)
				puts("\a���� : Ǫ�ÿ� �����Ͽ����ϴ�.");
			break;

		case 2:
			if (Pop_A(&s, &x) == -1)
				puts("\a ���� : �˿� �����Ͽ����ϴ�.");
			else
				printf("�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 3:
			if (Peek_A(&s, &x) == -1)
				puts("\a ���� : ��ũ�� �����Ͽ����ϴ�.");
			else
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 4 :
			printf("������ : ");
			scanf_s("%d", &x);
			if (Push_B(&s, x) == -1)
				puts("\a���� : Ǫ�ÿ� �����Ͽ����ϴ�.");
			break;

		case 5:
			if (Pop_B(&s, &x) == -1)
				puts("\a ���� : �˿� �����Ͽ����ϴ�.");
			else
				printf("�� �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 6:
			if (Peek_B(&s, &x) == -1)
				puts("\a ���� : ��ũ�� �����Ͽ����ϴ�.");
			else
				printf("��ũ �����ʹ� %d�Դϴ�.\n", x);
			break;

		case 7:
			Print(&s);
			break;
		}
	}
	Terminate(&s);
	return 0;
}