#include <stdio.h>

int main(void) {
	int angle_a;

	printf("���� : ");
	scanf_s("%d", &angle_a);

	int angle = angle_a % 360;

	if (0 <= angle && angle <= 90) {
		if (angle == 0)
			printf("���� x��\n");
		else if (angle == 90)
			printf("���� y��\n");
		else
			printf("1��и�\n");
	}
	else if (90 < angle && angle <= 180) {
		if (angle == 180)
			printf("���� x��\n");
		else
			printf("2��и�\n");
	}
	else if (180 < angle && angle <= 270) {
		if (angle == 270)
			printf("���� y��\n");
		else
			printf("3��и�\n");
	}
	else if (270 < angle && angle <= 360) {
		if (angle == 360)
			printf("���� x��");
		else
			printf("4��и�\n");
	}
	else
		printf("0~360�� ���̿� ���� �Է��ϼ���\n");

	return 0;
}