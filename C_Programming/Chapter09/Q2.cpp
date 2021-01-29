#include <stdio.h>

int main(void) {
	int data[] = { 3, 21, 35, 57, 24, 82, 8 };
	

	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
		*(data + i) = data[i] + 10;
		//data[i] = data[i] + 10;

	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
		printf("%d\n", data[i]);

	return 0;
}