#include <stdio.h>
#include <stdlib.h>
#include "ex03.h"





/* QueueType *createQueue() {
	QueueType *cQ;
	cQ = (QueueType*)malloc(sizeof(QueueType));
	cQ->front = 0;
	cQ->rear = 0;
	return cQ;
} */
/*
int isEmpty(QueueType *cQ) {
	if (cQ->front == cQ->rear) {
		printf("cQueue is empty!");
		return 1;
	}
	else return 0;
}

int isFull(QueueType *cQ) {
	if (((cQ->rear + 1) % cQ_SIZE) == cQ->front%cQ_SIZE) {
		printf("cQueue is Full!");
		return 1;
	}
	else return 0;
}
*/
void enQueue(int item) {
	//overflow check
	if ((rear + 1) % cQ_SIZE == front) {
		printf("overflow\n");
		return;
	}
	rear = (rear + 1) % cQ_SIZE;
	queue[rear] = item;
}

int deQueue() {
	//underflow check
	if (rear == front) {
		printf("underflow\n");
		return -1;
	}
	return queue[++front];  // 실제로 deQueue는 삭제가 아니라 원래의 인덱스에 있던 데이터를 덮어씌우는 원리
	//  실제 front는 0인덱스를 가리키고, 데이터는 1인덱스부터 삽입되어있음
}

void printQ() {
	if (front == rear) {
		printf(" [  ]\n");
		return;
	}
	printf(" [ ");
	for (int i = front + 1; i%cQ_SIZE != rear + 1; i++) {
		printf("%d", queue[i]);
	}
	printf(" ] \n");
	
}

/*
#include <stdio.h>
#include <stdlib.h>
#define cQ_SIZE 5

int front = 0;
int rear = 0;
int queue[cQ_SIZE] = { 0, };
void enQueue(int item);
int deQueue();
void printQ();

void enQueue(int item) {
	//overflow check
	if ((rear + 1) % cQ_SIZE == front) {
		printf("overflow\n");
		return;
	}
	rear = (rear + 1) % cQ_SIZE;
	queue[rear] = item;
}

int deQueue() {
	//underflow check
	if (rear == front) {
		printf("underflow\n");
		return -1;
	}
	return queue[++front];  // 실제로 deQueue는 삭제가 아니라 원래의 인덱스에 있던 데이터를 덮어씌우는 원리
	//  실제 front는 0인덱스를 가리키고, 데이터는 1인덱스부터 삽입되어있음
}

void printQ() {
	if (front == rear) {
		printf(" [  ]\n");
		return;
	}
	printf(" [ ");
	for (int i = front + 1; i%cQ_SIZE != (rear+1)%cQ_SIZE; i++) {
		printf("%d", queue[i]);
	}
	printf(" ] \n");

}



int main() {
	enQueue(1);		printQ();
	enQueue(2);		printQ();
	enQueue(3);		printQ();
	enQueue(4);		printQ();
	enQueue(5);		printQ();


	deQueue();		printQ();
	deQueue();		printQ();
	deQueue();		printQ();
	deQueue();		printQ();
	deQueue();		printQ();


	return 0;
}

*/