#include <stdio.h>
void main() {
	int i, sale[4] = { 157, 209, 251, 312 };

	for (i = 0; i < 4; i++) {
		printf("\n address : %u sale[%d] = %d", &sale[i], i, sale[i]);  // int 형이기 때문에 4byte 즉 주소값 4씩 차이
																		// 주소값 예측 가능
	}

	getchar();
}
