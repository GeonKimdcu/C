#include <stdio.h>
#include <stdlib.h>
#include "ex01.h"

void linked_list_test()
{
	node *head = NULL;   // head ���� ����    
	node *node1 = NULL;   // �޸��Ҵ� ������ġ ����
	node *node2 = NULL;    // ������ �����̱� ������ �� ������ ����
	node *node3 = NULL;

	node1 = (node*)malloc(sizeof(node));
	if (node1 == NULL) {    // �޸� �Ҵ��� ���� ������ Ȯ���ϰ� ��.
		printf("malloc() error\n");
		exit(1);
	}

	node2 = (node*)malloc(sizeof(node));		// 8byteũ�� ���� 
	node3 = (node*)malloc(sizeof(node));      //  (Ÿ�Ժ�ȯ )malloc(ũ�� �Ķ����)    Ÿ�Ժ�ȯ���� void�����͸� node �����ͷ� ��ȯ 

	node1->data = 1;
	node1->link = node2;  // ȭ��ǥ �����ڿ��� & �ּ� ������ ��� x

	node2->data = 2;
	node2->link = node3;

	node3->data = 3;
	node3->link = NULL;

	head = node1;   //  ù ��° ��� head�� ����

	node*temp = head;   //  ��� Ž�� ... temp ������ ������ head��� ����

	while (temp != NULL) {
		printf("%d \n", temp->data);
		temp = temp->link;
	}
	if (node1 != NULL) {
		free(node1);
		node1 = NULL;
	}
	free(node2);    // �޸� ����
	free(node3);

}