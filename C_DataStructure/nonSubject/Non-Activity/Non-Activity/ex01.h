#pragma once

// ����ü ����
typedef struct _node {    // ������ �̸� 
	int data;    // 4byte
	struct _node*link;   // 32bit ȯ�� �� 4byte
}node;   // �ڷ��� �̸� 

//typedef struct _node node;   // typedef ��������ʰ� struct ����� ��� ���� typedef�� ��������� ��!   

void linked_list_test();

