#include <stdio.h>
#include <stdlib.h>

/*
 * 稀疏矩阵的十字链表表示法
 */

// 普通结点
typedef struct OLNode {
	int row, col;	// 行号和列号
	struct OLNode *right, *down;	// 指向右边结点和下方结点的指针
	float val;
} OLNode;

// 头节点
typedef struct {
	OLNode *rhead, *chead;	// 指向两头结点数组的指针
	int m, n, k;	// 矩阵行数、列数以及非零结点总数
} CrossList;

int createcrossListmat(float A[][4], int m, int n, int k, CrossList *M) {
	if (M->rhead) {
		free(M->rhead);
	}
	if (M->chead) {
		free(M->chead);
	}
	M->m = m;
	M->n = n;
	M->k = k;
	// 申请头结点数组空间
	if (!(M->chead = (OLNode*)malloc(sizeof(OLNode) * m))) {
		return 0;
	}
	if (!(M->rhead = (OLNode*)malloc(sizeof(OLNode) * n))) {
		return 0;
	}
	// 头结点数组right和down指针置空
	for (int i = 0; i < m; ++i) {
		M->chead[i].right = NULL;
		M->chead[i].down = NULL;
	}
	for (int j = 0; j < n; ++j) {
		M->rhead[j].right = NULL;
		M->rhead[j].down = NULL;
	}
	// 建立列链表的辅助指针数组
	OLNode *temp_c[m];
	for (int j = 0; j < n; ++j) {
		temp_c[j] = &(M->rhead[j]);
	}
	// 开始建立十字链表
	for (int i = 0; i < m; ++i) {
		// 行链表的尾指针
		OLNode *r = &(M->chead[i]);
		for (int j = 0; j < n; ++j) {
			if (A[i][j] != 0) {
				OLNode *p = (OLNode*)malloc(sizeof(OLNode));
				p->row = i;
				p->col = j;
				p->val = A[i][j];
				p->right = NULL;
				p->down = NULL;
				r->right = p;
				r = p;	// 尾指针右移
				temp_c[j]->down = p;
				temp_c[j] = p;	// 尾指针下移
			}
		}
	}
	return 1;
}

int main() {
	float A[4][4] = {
		{0, 0, 0, 1},
		{0, 0, 3, 2},
		{1, 0, 0, 0},
		{0, 2, 0, 0}
	};
	CrossList *M = (CrossList*)malloc(sizeof(CrossList));
    M->rhead = (OLNode*)malloc(sizeof(OLNode));
    M->chead = (OLNode*)malloc(sizeof(OLNode));
	createcrossListmat(A, 4, 4, 5, M);
	// 打印十字链表
	for (int i = 0; i < 4; ++i) {
		OLNode *p = M->chead[i].right;
		while (p != NULL) {
			printf("%f ", p->val);
			p = p->right;
		}
		printf("\n");
	}
	return 0;
}
