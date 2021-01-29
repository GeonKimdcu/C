#include <stdio.h>

int main(void) {
	int angle_a;

	printf("각도 : ");
	scanf_s("%d", &angle_a);

	int angle = angle_a % 360;

	if (0 <= angle && angle <= 90) {
		if (angle == 0)
			printf("양의 x축\n");
		else if (angle == 90)
			printf("양의 y축\n");
		else
			printf("1사분면\n");
	}
	else if (90 < angle && angle <= 180) {
		if (angle == 180)
			printf("음의 x축\n");
		else
			printf("2사분면\n");
	}
	else if (180 < angle && angle <= 270) {
		if (angle == 270)
			printf("음의 y축\n");
		else
			printf("3사분면\n");
	}
	else if (270 < angle && angle <= 360) {
		if (angle == 360)
			printf("양의 x축");
		else
			printf("4사분면\n");
	}
	else
		printf("0~360도 사이에 값을 입력하세요\n");

	return 0;
}