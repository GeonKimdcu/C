#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "ex8_4.h"

void main() {
	int i;
	graphType *G9;
	G9 = (graphType *)malloc(sizeof(graphType));
	createGraph_4(G9);

	for (i = 0; i < 7; i++);
	insertVertex_4(G9, i);
	insertEdge_4(G9, 0, 2);
	insertEdge_4(G9, 0, 1);
	insertEdge_4(G9, 1, 4);
	insertEdge_4(G9, 1, 3);
	insertEdge_4(G9, 1, 0);
	insertEdge_4(G9, 2, 4);
	insertEdge_4(G9, 2, 0);
	insertEdge_4(G9, 3, 6);
	insertEdge_4(G9, 3, 1);
	insertEdge_4(G9, 4, 6);
	insertEdge_4(G9, 4, 2);
	insertEdge_4(G9, 4, 1);
	insertEdge_4(G9, 5, 6);
	insertEdge_4(G9, 6, 5);
	insertEdge_4(G9, 6, 4);
	insertEdge_4(G9, 6, 3);
	printf("\n G9의 인접 리스트");
	print_adjList_4(G9);

	printf("\n\n//////////////////////////////\n\n 너비 우선 탐색 >>");
	BFS_adjList(G9, 0);

	getchar();

}