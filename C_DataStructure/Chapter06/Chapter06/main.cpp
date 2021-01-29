#include <stdio.h>
#include<malloc.h>
#include "6_3.h"

void main() {
	LQueueType *LQ = createLinkedQueue();
	element data;
	printf(" ***** 연결 큐  연산 *****\n");
	printf("\n 삽입 A>>"); enQueue(LQ, 'A'); printLQ(LQ);
	printf("\n 삽입 B>>"); enQueue(LQ, 'B'); printLQ(LQ);
	printf("\n 삽입 C>>"); enQueue(LQ, 'C'); printLQ(LQ);
	data = peek(LQ);		printf("peek item : %c \n", data);
	printf("\n 삭제 >>");		data = deQueue(LQ);		printLQ(LQ);
	printf("\t 삭제 데이터 : % c", data);
	printf("\n 삭제 >>");		data = deQueue(LQ);		printLQ(LQ);
	printf("\t 삭제 데이터 : % c", data);
	printf("\n 삭제 >>");		data = deQueue(LQ);		printLQ(LQ);
	printf("\t 삭제 데이터 : % c", data);
	printf("\n 삽입 D>>"); enQueue(LQ, 'D');  printLQ(LQ);
	printf("\n 삽입 E>>"); enQueue(LQ, 'E');  printLQ(LQ);
	
	getchar();
}