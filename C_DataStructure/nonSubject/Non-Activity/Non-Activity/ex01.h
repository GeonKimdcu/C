#pragma once

// 구조체 정의
typedef struct _node {    // 구조형 이름 
	int data;    // 4byte
	struct _node*link;   // 32bit 환경 즉 4byte
}node;   // 자료형 이름 

//typedef struct _node node;   // typedef 사용하지않고 struct 사용할 경우 따로 typedef로 선언해줘야 함!   

void linked_list_test();

