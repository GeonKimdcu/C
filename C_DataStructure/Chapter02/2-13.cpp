#include <stdio.h>
#include <string.h>

struct employee {
	char name[10];
	int year;
	int pay;
};

int main() {
	struct employee Lee;
	struct employee *Sptr = &Lee;
	strcpy_s(Sptr->name, "이순신"); //strcpy_s는 문자열 복사함수 
	Sptr->year = 2015;
	Sptr->pay = 5900;

	printf("\n 이름 : %s", Sptr->name);
	printf("\n 입사 : %d", Sptr -> year);
	printf("\n 연봉 : %d", Sptr->pay);

	return 0;
}