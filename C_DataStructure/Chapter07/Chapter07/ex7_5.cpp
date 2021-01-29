#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include "ex7_5.h"

treeNode* LL_rotate(treeNode *parent) {
	treeNode *child = parent->left;
	parent->left = child->right;
	child->right = parent;
	return child;
}

treeNode* RR_rotate(treeNode *parent) {
	treeNode *child = parent->right;
	parent->right = child->left;
	child->left = parent;
	return child;
}

treeNode *LR_rotate(treeNode *parent) {
	treeNode *child = parent->left;
	parent->left = RR_rotate(child);
	return LL_rotate(child);
}

treeNode *RL_rotate(treeNode *parent) {
	treeNode *child = parent->right;
	parent->right = LL_rotate(child);
	return RR_rotate(child);
}

// 서브 트리의 높이 구하는  연산
int getHeight(treeNode* p) {
	int height = 0;
	if (p != NULL) height = MAX(getHeight(p->left), getHeight(p->right)) + 1;
	return height;
}

// 서브 트리의 높이를 이용해 균형 인수 BF를 구하는 연산
int getBF(treeNode *p) {
	if (p == NULL) return 0;
	return getHeight(p->left) - getHeight(p->right);
}

// 서브 트리의 높이를 이용해 균형 인수 BF를 구하는 연산
treeNode* rebalance(treeNode** p) {
	int BF = getBF(*p);

	if(BF > 1) {
		if (getBF((*p)->left) > 0)
			*p = LL_rotate(*p);
		else *p = LR_rotate(*p);
	}
	else if (BF < -1) {
		if (getBF((*p)->right) < 0)
			*p = RR_rotate(*p);
		else *p = RL_rotate(*p);
	}
	return *p;
}