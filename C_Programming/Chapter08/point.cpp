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

	printf("�� �Ǽ� �Է�: ");
	scanf_s("%lf %lf", px, py);
	printf("%.2f + %.2f = %.2f\n", *px, *py, *px + *py);

	return 0;
} */

int main(void) {
	int i = 10; // i�� �ּҰ��� 1000�� ���
	printf("i: %d\n", i);
	int* p = &i; 
	printf("p: %d\n", p);
	int* t = p - 1;	// p�� i�� �ּҰ��� 1000�� ������������ int�̱⶧���� -4�� �Ͽ� 996�� ��
	printf("t : %d\n", t);

	return 0;
}