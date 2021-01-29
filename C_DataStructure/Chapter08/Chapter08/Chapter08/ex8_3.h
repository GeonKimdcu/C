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

typedef struct stackNode {			
	element data;
	struct stackNode *link;
}stackNode;



int isEmpty();
void push(element item);
element pop();
void createGraph_3(graphType* g);
void insertVertex_3(graphType* g, int v);
void insertEdge_3(graphType* g, int u, int v);
void print_adjList_3(graphType* g);
void DFS_asjList(graphType* g, int v);
