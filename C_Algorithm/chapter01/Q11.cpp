#include <stdio.h>



int main(void) {
	int n;
	int count = 0;
	

	do {
		puts("���� ������ �Է��ϼ���!");
		scanf_s("%d", &n);
	} while (n <= 0);

	while(n>0)	{
		n /= 10; 
		count++;
	}
	
	printf("�� ���� %d�ڸ��Դϴ�.\n", count);

	return 0;
}