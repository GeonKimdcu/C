#include <stdio.h>
/*
int main(void) {
	int a = 10;
	int* p = &a;

	int b = *p;
	*p = 20;

	int** pp = &p;
	int c = **pp;
	**pp = 30;

	printf("a : %d  \n", a);
	printf("b : %d\n", b);
	printf("c : %d\n", c);

	return 0;
}
*/
/*
int main(void) {
	double x, y;
	double* px = &x;
	double* py = &y;

	printf("두 실수 입력: ");
	scanf_s("%lf %lf", px, py);
	printf("%.2f + %.2f = %.2f\n", *px, *py, *px + *py);

	return 0;
} */

int main(void) {
	int i = 10; // i의 주소값이 1000일 경우
	printf("i: %d\n", i);
	int* p = &i; 
	printf("p: %d\n", p);
	int* t = p - 1;	// p는 i의 주소값인 1000을 가지고있으며 int이기때문에 -4를 하여 996이 됨
	printf("t : %d\n", t);

	return 0;
}