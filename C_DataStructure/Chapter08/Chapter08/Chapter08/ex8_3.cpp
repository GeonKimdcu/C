#include <stdio.h>
#include <memory.h>
#include <stdlib.h>
#include "ex8_3.h"

stackNode* top;
int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}

// 스택의 top에 원소를 삽입하는 연산					포인터를 이용한 [알고리즘 5-1] 구현
void push(element item) {
	stackNode* temp = (stackNode *)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}

// 스택의 top에서 원소를 삭제하는 연산
element pop() {
	element item;
	stackNode* temp = top;

	if (top == NULL) {				// 스택이 공백 리스트인 경우
		printf("\n\n Stack is empty !\n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;			// top 위치를 삭제 노드 아래로 이동
		free(temp);			//삭제된 노드의 메모리 반환   헤더 <stdlib.h> 인클루드 해야함
		return item;
	}
}

void createGraph_3(graphType* g) {
	int v;
	g->n = 0;
	for (v = 0; v < MAX_VERTEX; v++) {
		g->visited[v] = FALSE;
		g->adjList_H[v] = NULL;
	}
}

void insertVertex_3(graphType* g, int v) {
	if (((g->n) + 1) > MAX_VERTEX) {
		printf("\n 그래프 정점의 개수를 초과하였습니다!");
		return;
	}
	g->n++;
}

void insertEdge_3(graphType* g, int u, int v) {
	graphNode* node;

	if (u >= g->n || v >= g->n) {
		printf("\n 그래프에 없는 정점입니다!");
		return;
	}
	node = (graphNode *)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node;
}

void print_adjList_3(graphType* g) {
	int i;
	graphNode* p;
	for (i = 0; i < g->n; i++) {
		printf("\n\t\t 정점 %c의 인접 리스트", i + 65);
		p = g->adjList_H[i];
		while (p) {
			printf(" -> %c", p->vertex + 65);
			p = p->link;
		}
	}
}

void DFS_asjList(graphType* g, int v) {
	graphNode* w;
	top = NULL;
	push(v);
	g->visited[v] = TRUE;
	printf("%c", v + 65);

	while (!isEmpty()) {
		v = pop();
		w = g->adjList_H[v];
		while (w) {
			if (!g->visited[w->vertex]) {
				if (isEmpty()) push(v);
				push(w->vertex);
				g->visited[w->vertex] = TRUE;
				printf("%c", w->vertex + 65);
				v = w->vertex;
				w = g->adjList_H[v];
			}
			else w = w->link;
		}
	}
}