#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ex4_2.h"


int main() {
	linkedList_h*L;
	listNode*p;
	L = createLinkedList_h();  // ���� ����Ʈ ����
	printf("(1) ����Ʈ�� [��], [��], [��] ��� �����ϱ�! \n");
	insertLastNode(L, "��"); insertLastNode(L, "��"); insertLastNode(L, "��");
	printList(L); getchar();

	printf("(2) ����Ʈ���� [��] ��� Ž���ϱ�! \n");
	p = searchNode(L, "��");
	if (p == NULL) printf("ã�� �����Ͱ� �����ϴ�. \n");
	else printf("[%s]�� ã�ҽ��ϴ�. \n", p->data);
	getchar();
	printf("(3) ����Ʈ���� [��] �ڿ� [��] ��� �����ϱ�! \n");
	insertMiddleNode(L, p, "��");
	printList(L); getchar();

	printf("(4) ����Ʈ���� [��] ��� �����ϱ�! \n");
	p = searchNode(L, "��");		//������ ��� ��ġ p�� ã��
	deleteNode(L, p);		// ������ p ��� ����
	printList(L); getchar();

	printf("(5) ����Ʈ ������ �������� �ٲٱ�! \n");
	reverse(L);
	printList(L);

	freeLinkedList_h(L);				// ����Ʈ�� �޸� ����
	getchar();

	return 0;
}