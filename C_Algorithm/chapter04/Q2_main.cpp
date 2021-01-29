#include <stdio.h>
#include "Q2.h"

int main(void) {
	IntStack s;
	if (Initialize(&s, 64) == -1) {	// 64크기의 스택 생성 
		puts("스택 생성에 실패하였습니다.");
		return 1;
	}

	while (1) {
		int menu, x;
		printf("현재 데이터 수 = Stack_A: %d / %d \t Stack_B : %d / %d\n", Size_A(&s), Capacity(&s), Size_B(&s), Capacity(&s));
		printf("(1) A푸시 (2) A팝 (3) A피크 (4) B푸시 (5) B팝  (6) B피크 (7) 출력 (0)종료 : ");
		scanf_s("%d", &menu);

		if (menu == 0) break;
		switch (menu) {
		case 1:
			printf("데이터 : ");
			scanf_s("%d", &x);
			if (Push_A(&s, x) == -1)
				puts("\a오류 : 푸시에 실패하였습니다.");
			break;

		case 2:
			if (Pop_A(&s, &x) == -1)
				puts("\a 오류 : 팝에 실패하였습니다.");
			else
				printf("팝 데이터는 %d입니다.\n", x);
			break;

		case 3:
			if (Peek_A(&s, &x) == -1)
				puts("\a 오류 : 피크에 실패하였습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;

		case 4 :
			printf("데이터 : ");
			scanf_s("%d", &x);
			if (Push_B(&s, x) == -1)
				puts("\a오류 : 푸시에 실패하였습니다.");
			break;

		case 5:
			if (Pop_B(&s, &x) == -1)
				puts("\a 오류 : 팝에 실패하였습니다.");
			else
				printf("팝 데이터는 %d입니다.\n", x);
			break;

		case 6:
			if (Peek_B(&s, &x) == -1)
				puts("\a 오류 : 피크에 실패하였습니다.");
			else
				printf("피크 데이터는 %d입니다.\n", x);
			break;

		case 7:
			Print(&s);
			break;
		}
	}
	Terminate(&s);
	return 0;
}