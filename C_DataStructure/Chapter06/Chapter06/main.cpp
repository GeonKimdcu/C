#include <stdio.h>
#include<malloc.h>
#include "6_3.h"

void main() {
	LQueueType *LQ = createLinkedQueue();
	element data;
	printf(" ***** ���� ť  ���� *****\n");
	printf("\n ���� A>>"); enQueue(LQ, 'A'); printLQ(LQ);
	printf("\n ���� B>>"); enQueue(LQ, 'B'); printLQ(LQ);
	printf("\n ���� C>>"); enQueue(LQ, 'C'); printLQ(LQ);
	data = peek(LQ);		printf("peek item : %c \n", data);
	printf("\n ���� >>");		data = deQueue(LQ);		printLQ(LQ);
	printf("\t ���� ������ : % c", data);
	printf("\n ���� >>");		data = deQueue(LQ);		printLQ(LQ);
	printf("\t ���� ������ : % c", data);
	printf("\n ���� >>");		data = deQueue(LQ);		printLQ(LQ);
	printf("\t ���� ������ : % c", data);
	printf("\n ���� D>>"); enQueue(LQ, 'D');  printLQ(LQ);
	printf("\n ���� E>>"); enQueue(LQ, 'E');  printLQ(LQ);
	
	getchar();
}