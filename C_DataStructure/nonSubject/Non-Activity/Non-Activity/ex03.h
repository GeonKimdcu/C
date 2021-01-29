#pragma once
#define cQ_SIZE 5

/*typedef char element;
typedef struct {
	element queue[cQ_SIZE];
	int front, rear;
}QueueType; */
int front = 0;
int rear = 0;
int queue[cQ_SIZE] = { 0, };

void enQueue(int item);
int deQueue();
void printQ();
