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

// 查找data域为key的结点是否存在
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

// 层次遍历（队列实现）
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

/*
 * 非递归实现
 */

// 先序遍历（栈实现）
void preorderNonrecursion(BTNode *bt) {
	if (bt != NULL) {
		BTNode *Stack[maxSize];
		int top = -1;
		BTNode *p;
		Stack[++top] = bt;
		while (top != -1) {
			p = Stack[top--];
			Visit(p);
			if (p->rchild != NULL) {
				Stack[++top] = p->rchild;
			}
			if (p->lchild != NULL) {
				Stack[++top] = p->lchild;
			}
		}
	}
}

// 中序遍历（栈实现）
void inorderNonrecursion(BTNode *bt) {
	if (bt != NULL) {
		BTNode *Stack[maxSize];
		int top = -1;
		BTNode *p;
		p = bt;
		while (top != -1 || p != NULL) {
			// 当p指向结点不为空时（可为左孩子或右孩子）
			while (p != NULL) {
				// 该结点入栈
				Stack[++top] = p;
				// 入栈后，p接着指向该结点左孩子
				p = p->lchild;
			}
			// 直到p指向结点为空
			if (top != -1) {
				// 栈顶结点出栈
				p = Stack[top--];
				Visit(p);
				// 出栈并访问栈顶结点后，p接着指向该结点右孩子
				p = p->rchild;
			}
		}
	}
}

// 后序遍历（栈实现）
void postorderNonrecursion(BTNode *bt) {
	if (bt != NULL) {
		// 定义两个栈
		BTNode *Stack1[maxSize];
		BTNode *Stack2[maxSize];
		int top1 = -1;
		int top2 = -1;
		BTNode *p = NULL;
		Stack1[++top1] = bt;
		while (top1 != -1) {
			// Stack1出栈，进入Stack2
			p = Stack1[top1--];
			Stack2[++top2] = p;
			// 左孩子先入
			if (p->lchild != NULL) {
				Stack1[++top1] = p->lchild;
			}
			if (p->rchild != NULL) {
				Stack1[++top1] = p->rchild;
			}
		}
		while (top2 != -1) {
			p = Stack2[top2--];
			Visit(p);
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
	search(p1, &q, '2');
	printf("查找值为2的元素: %c\n", q == NULL ? '\\' : q->data);
	printf("层次遍历: ");level(p1);printf("\n");
	printf("---非递归实现---\n");
	printf("先序遍历: ");preorderNonrecursion(p1);printf("\n");
	printf("中序遍历: ");inorderNonrecursion(p1);printf("\n");
	printf("后序遍历: ");postorderNonrecursion(p1);printf("\n");
	return 0;
}