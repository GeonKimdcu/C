#include <stdio.h>
#include "sumFunction.h"

int main(void)
{
	int x = 10;
	int y = 20;
	int z = 0;

	z = sum(x, y);
	printf("합계는 %d 이다.\n", z);
}