// �����͸� �̿��� ���ڿ� ó���ϱ�
#include <stdio.h>

void main() {
	int i;
	char string1[20] = "Dreams come true!", string2[20], *ptr1, *ptr2;   /* char �ڷ�������  ' , ' ���� 
																		 �ʱ�ȭ ���ְ� �ִ� �� ��.*/

	ptr1 = string1; // �迭�̸� �̿��Ͽ� �迭���� �ּ� ���� == char string1[20];  / char *ptr1 = string1;
	printf("\n string1�� �ּ� = %u \t ptr1 = %u", string1, ptr1);
	printf("\n string1 = %s \n ptr1 = %s", string1, ptr1);
	printf("\n\n %s", ptr1 + 7);  // string1 �� +7��°���� �ּ���� 
	ptr2 = &string1[7];	//string7��° �ּҰ��� ptr2�� ���� 
	printf("\n %s\n\n", ptr2);

	for (i = 16; i >= 0; i--) {			//16��° �ּҺ��� -1 �����.  ��,  �������� ���
		putchar(*(ptr1 + i));		//putchar �� �ϳ��� ������ �μ��� �޾� �ϳ��� ���ڷ� ����ϴ� �Լ�
	}
	for (i = 0; i < 20; i++) {
		string2[i] = *(ptr1 + i);
	 }
	printf("\n\n  string1 = %s", string1);
	printf("\n\n string2 = %s", string2);

	*ptr1 = 'P';		//string1�� �ּҰ� ����
	*(ptr1 + 1) = 'e';
	*(ptr1 + 2) = 'a';
	*(ptr1 + 3) = 'c';
	*(ptr1 + 4) = 'e';
	printf("\n\n string1= %s\n", string1);

	getchar();
}