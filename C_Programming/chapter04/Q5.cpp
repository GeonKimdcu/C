#include <stdio.h>
#include <stdlib.h>

int main(void) {
	double *ct, *ft;
	ct = (double*)calloc(3, sizeof(double));
	ft = (double*)calloc(3, sizeof(double));

	for (int i = 0; i < 3; i++) {
		printf("섭씨온도를 입력하세요 : ");
		scanf_s("%lf", &ct[i]);
	}

	for (int i = 0; i < 3; i++) {
		ft[i] = (9.0 / 5.0) * ct[i] + 32.0;
	}
	for (int i = 0; i < 3; i++) {
		printf("%.4f\n", ft[i]);
		}

	free(ct);
	free(ft);

	return 0;
} 
/* 
int main(void) {
	double ct1, ct2, ct3;
	double ft1, ft2, ft3;

	printf("섭씨온도를 입력해주세요! \n");
	printf("ct1 : ");		scanf_s("%lf", &ct1);
	printf("ct2 : ");		scanf_s("%lf", &ct2);
	printf("ct3 : ");		scanf_s("%lf", &ct3);

	ft1 = (9.0 / 5.0) * ct1 + 32.0;
	ft2 = (9.0 / 5.0) * ct2 + 32.0;
	ft3 = (9.0 / 5.0) * ct3 + 32.0;

	printf("화씨온도 출력\n");
	printf("ft1 : %.4f\n", ft1);		
	printf("ft2 : %.4f\n", ft2);		
	printf("ft3 : %.4f\n", ft3);		

	return 0;
} */