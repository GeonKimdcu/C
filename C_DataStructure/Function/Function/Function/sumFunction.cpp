#include <stdio.h>
#include "sumFunction.h"

/* int main(void)
{
	int x = 10;
	int y = 20;
	int z = 0;

	z = sum(x, y);
	printf("합계는 %d 이다.\n", z);
} */


int sum(int numa, int numb) // 실매개변수
{
	int total = 0;
	total = numa + numb;
	return total;
}