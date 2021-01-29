#pragma once
typedef char element;
typedef struct treeNode {
	char key;
	struct treeNode* left;
	struct treeNode* right;
}treeNode;

treeNode* searchBST(treeNode* root, char x);
treeNode* insertNode(treeNode*p, char x);
void deleteNode(treeNode* root, element key);
void displayInorder(treeNode* root);
void menu();
