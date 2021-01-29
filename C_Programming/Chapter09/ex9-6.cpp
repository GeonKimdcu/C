#include<stdio.h>

#define ROWSIZE 4
#define COLSIZE 2

int main(void) {
	int score[][ROWSIZE][COLSIZE] = {
		{{95, 85},
	{85, 83},
	{92, 75},
	{90, 88}},
	{{88, 77},
	{72, 95},
	{88, 92},
	{93, 83}}
	};
	
	for (int i = 0; i < 2; i++) {
		if (i == 0)printf("[°­ÁÂ1]");
		else printf("[°­ÁÂ2]");
		printf("%11s%7s%7s\n", "Áß°£", "±â¸»", "Æò±Õ");

		for (int j = 0; j < ROWSIZE; j++) {
			int sum = 0;	// sumÀ§Ä¡ Áß¿ä!
			printf("%10s%2d", "ÇÐ»ý", j + 1);
			for (int k = 0; k < COLSIZE; k++) {
				printf("%6d", score[i][j][k]);
				sum += score[i][j][k];
			}
			printf("%6d", sum / 2);
			printf("\n");
		}
		printf("\n");
	}

	return 0;
}