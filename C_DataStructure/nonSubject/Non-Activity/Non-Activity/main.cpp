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
	return queue[++front];  // ������ deQueue�� ������ �ƴ϶� ������ �ε����� �ִ� �����͸� ������ ����
	//  ���� front�� 0�ε����� ����Ű��, �����ʹ� 1�ε������� ���ԵǾ�����
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
