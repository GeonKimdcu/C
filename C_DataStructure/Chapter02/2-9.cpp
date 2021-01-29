// 포인터를 이용해 문자열 처리하기
#include <stdio.h>

void main() {
	int i;
	char string1[20] = "Dreams come true!", string2[20], *ptr1, *ptr2;   /* char 자료형으로  ' , ' 마다 
																		 초기화 해주고 있는 것 임.*/

	ptr1 = string1; // 배열이름 이용하여 배열시작 주소 지정 == char string1[20];  / char *ptr1 = string1;
	printf("\n string1의 주소 = %u \t ptr1 = %u", string1, ptr1);
	printf("\n string1 = %s \n ptr1 = %s", string1, ptr1);
	printf("\n\n %s", ptr1 + 7);  // string1 중 +7번째부터 주소출력 
	ptr2 = &string1[7];	//string7번째 주소값을 ptr2에 대입 
	printf("\n %s\n\n", ptr2);

	for (i = 16; i >= 0; i--) {			//16번째 주소부터 -1 씩출력.  즉,  역순으로 출력
		putchar(*(ptr1 + i));		//putchar 은 하나의 정수형 인수를 받아 하나의 문자로 출력하는 함수
	}
	for (i = 0; i < 20; i++) {
		string2[i] = *(ptr1 + i);
	 }
	printf("\n\n  string1 = %s", string1);
	printf("\n\n string2 = %s", string2);

	*ptr1 = 'P';		//string1의 주소값 변경
	*(ptr1 + 1) = 'e';
	*(ptr1 + 2) = 'a';
	*(ptr1 + 3) = 'c';
	*(ptr1 + 4) = 'e';
	printf("\n\n string1= %s\n", string1);

	getchar();
}