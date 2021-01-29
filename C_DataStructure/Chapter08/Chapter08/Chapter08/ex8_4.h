#pragma once
#define MAX_VERTEX 10
#define FALSE 0
#define TRUE 1

typedef struct graphNode {
	int vertex;
	struct graphNode* link;
}graphNode;

typedef struct graphType {
	int n;
	graphNode* adjList_H[MAX_VERTEX];
	int visited[MAX_VERTEX];
}graphType;

typedef int element;

typedef struct QNode {
	element data;
	struct QNode *link;
}QNode;

typedef struct {
	QNode *front, *rear;
}LQueueType;

LQueueType *createLinkedQueue();
int isEmpty(LQueueType *LQ);
void enQueue(LQueueType *LQ, element item);
element deQueue(LQueueType *LQ);
void createGraph_4(graphType* g);
void insertVertex_4(graphType* g, int v);
void insertEdge_4(graphType* g, int u, int v);
void print_adjList_4(graphType* g);
void BFS_adjList(graphType* g, int v);
