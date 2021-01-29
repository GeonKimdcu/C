#pragma once

#define MAX_VERTEX 30

typedef struct graphNode {
	int vertex;
	struct graphNode* link;
}graphNode;

typedef struct graphType {
	int n;
	graphNode* adjList_H[MAX_VERTEX];
}graphType;

void createGraph_2(graphType* g);
void insertVertex_2(graphType* g, int v);
void insertEdge_2(graphType* g, int u, int v);
void print_adjList_2(graphType* g);

