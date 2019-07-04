#include <stdio.h>
#include <stdlib.h>

/*
 * 线索二叉树
 */

typedef struct TBTNode {
	char data;
	int ltag, rtag; // 线索标记
	struct TBTNode *lchild;
	struct TBTNode *rchild;
} TBTNode;

void InThread(TBTNode *p, TBTNode **pre) {
	if (p != NULL) {
		InThread(p->lchild, pre);
		// 建立当前结点的前驱线索
		if (p->lchild == NULL) {
			p->lchild = *pre;
			p->ltag = 1;
		}
		// 建立前驱结点的后继线索
		if (pre != NULL && (*pre)->rchild == NULL) {
			(*pre)->rchild = p;
			(*pre)->rtag = 1;
		}
		(*pre) = p;
		InThread(p->rchild, pre);
	}
}

void createInThread(TBTNode *root) {
	TBTNode *pre = (TBTNode*)malloc(sizeof(TBTNode));
	if (root != NULL) {
		InThread(root, &pre);
		pre->rchild = NULL;
		pre->rtag = 1;
	}
}

int main() {
	TBTNode *p1 = (TBTNode*)malloc(sizeof(TBTNode));
	TBTNode *p2 = (TBTNode*)malloc(sizeof(TBTNode));
	TBTNode *p3 = (TBTNode*)malloc(sizeof(TBTNode));
	p1->data = '1';
	p2->data = '2';
	p3->data = '3';
	p1->lchild = p2;
	p1->rchild = p3;
	p2->lchild = NULL;
	p2->rchild = NULL;
	p3->lchild = NULL;
	p3->rchild = NULL;
	createInThread(p1);
	return 0;
}