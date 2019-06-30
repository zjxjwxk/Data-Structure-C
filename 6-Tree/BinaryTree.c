#include <stdio.h>
#include <stdlib.h>

/*
 * 二叉树
 * 链式存储结构
 */

#define maxSize 3

typedef struct BTNode {
	char data;
	struct BTNode *lchild;
	struct BTNode *rchild;
} BTNode;

void Visit(BTNode *p) {
	printf("%c ", p->data);
}

// 先序遍历
void preorder(BTNode *p) {
	if (p != NULL) {
		Visit(p);
		preorder(p->lchild);
		preorder(p->rchild);
	}
}

// 中序遍历
void inorder(BTNode *p) {
	if (p != NULL) {
		inorder(p->lchild);
		Visit(p);
		inorder(p->rchild);
	}
}

// 后序遍历
void postorder(BTNode *p) {
	if (p != NULL) {
		postorder(p->lchild);
		postorder(p->rchild);
		Visit(p);
	}
}

// 获得树的深度
int getDepth(BTNode *p) {
	int LD, RD;
	if (p == NULL) {
		return 0;
	} else {
		LD = getDepth(p->lchild);
		RD = getDepth(p->rchild);
		return (LD > RD ? LD : RD) + 1;
	}
}

// 先序遍历
void search(BTNode *p, BTNode **q, int key) {
	if (p != NULL) {
		if (p->data == key) {
			*q = p;
		} else {
			search(p->lchild, q, key);
			search(p->rchild, q, key);
		}
	}
}

// 层次遍历
void level(BTNode *p) {
	int front, rear;
	BTNode *que[maxSize];
	front = rear = 0;
	BTNode *q;
	if (p != NULL) {
		rear = (rear + 1) % maxSize;
		que[rear] = p;
		while (front != rear) {
			front = (front + 1) % maxSize;
			q = que[front];
			Visit(q);
			if (q->lchild != NULL) {
				rear = (rear + 1) % maxSize;
				que[rear] = q->lchild;
			}
			if (q->rchild != NULL) {
				rear = (rear + 1) % maxSize;
				que[rear] = q->rchild;
			}
		}
	}
}

int main() {
	BTNode *p1 = (BTNode*)malloc(sizeof(BTNode));
	BTNode *p2 = (BTNode*)malloc(sizeof(BTNode));
	BTNode *p3 = (BTNode*)malloc(sizeof(BTNode));
	p1->data = '1';
	p2->data = '2';
	p3->data = '3';
	p1->lchild = p2;
	p1->rchild = p3;
	p2->lchild = NULL;
	p2->rchild = NULL;
	p3->lchild = NULL;
	p3->rchild = NULL;
	printf("先序遍历: ");preorder(p1);
	printf("\n");
	printf("数的深度: %d\n", getDepth(p1));
	BTNode *q = NULL;
	search(p1, &q, '4');
	printf("查找值为2的元素: %c\n", q == NULL ? '\\' : q->data);
	printf("层次遍历: ");level(p1);
	return 0;
}