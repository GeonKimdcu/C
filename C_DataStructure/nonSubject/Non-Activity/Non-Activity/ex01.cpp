#include <stdio.h>
#include <stdlib.h>
#include "ex01.h"

void linked_list_test()
{
	node *head = NULL;   // head 변수 생성    
	node *node1 = NULL;   // 메모리할당 안전장치 역할
	node *node2 = NULL;    // 포인터 변수이기 때문에 힙 영역에 생성
	node *node3 = NULL;

	node1 = (node*)malloc(sizeof(node));
	if (node1 == NULL) {    // 메모리 할당이 되지 않을때 확인하게 함.
		printf("malloc() error\n");
		exit(1);
	}

	node2 = (node*)malloc(sizeof(node));		// 8byte크기 생성 
	node3 = (node*)malloc(sizeof(node));      //  (타입변환 )malloc(크기 파라미터)    타입변환에서 void포인터를 node 포인터로 변환 

	node1->data = 1;
	node1->link = node2;  // 화살표 연산자에는 & 주소 연산자 사용 x

	node2->data = 2;
	node2->link = node3;

	node3->data = 3;
	node3->link = NULL;

	head = node1;   //  첫 번째 노드 head로 연결

	node*temp = head;   //  노드 탐색 ... temp 포인터 변수로 head노드 참조

	while (temp != NULL) {
		printf("%d \n", temp->data);
		temp = temp->link;
	}
	if (node1 != NULL) {
		free(node1);
		node1 = NULL;
	}
	free(node2);    // 메모리 해제
	free(node3);

}