#pragma once
#define MAX(a,b) ((a>b) ? a:b)

typedef int element;

typedef struct treeNode {
	element key;
	struct treeNode *left;
	struct treeNode *right;
} treeNode;
