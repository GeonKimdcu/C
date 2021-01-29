#include <stdio.h>

int main() {

	int a;
	int b;
	int n;
	int m;


	scanf_s("%d  %d", &m, &n);
	
	for (int a = 0;  a <  n;  a++)
	{
		for (int b = 0;  b <  m;  b++)
		{
		printf("*");
		}
		printf("\n");
	}



	
}