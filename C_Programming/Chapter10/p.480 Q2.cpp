#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main(void) {
	time_t  current_time;
	time(&current_time);

	printf("%ld\n", current_time);
	printf(ctime(&current_time));

	return 0;
}