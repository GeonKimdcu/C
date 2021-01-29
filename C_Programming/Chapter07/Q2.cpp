#include <stdio.h>

int main(void) {
	int i;
	int j;
	for (i = 0; i < 5; i++) {
		for (j = 4; j >=i; j--) {
			printf("%s", " ");
		}
		for (j = 5-i; j<=5; j++)
			printf("%-d",6- j);
		putchar('\n');
	}
	return 0;
}