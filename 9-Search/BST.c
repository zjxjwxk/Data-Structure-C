#include <stdio.h>
#include <stdlib.h>

/*
 * 二叉排序树
 */

typedef struct BTNode {
	int key;
	struct BTNode *lchild;
	struct BTNode *rchild;
} BTNode;

// 查找关键字
BTNode* BSTSearch(BTNode* bt, int key) {
	if (bt == NULL) {
		return NULL;
	} else {
		if (bt->key == key) {
			return bt;
		} else if (key < bt->key) {
			return BSTSearch(bt->lchild, key);
		} else {
			return BSTSearch(bt->rchild, key);
		}
	}
}

// 插入关键字
int BSTInsert(BTNode* *bt, int key) {
	if ((*bt) == NULL) {
		(*bt) = (BTNode*)malloc(sizeof(BTNode));
		(*bt)->lchild = (*bt)->rchild = NULL;
		(*bt)->key = key;
		return 1;
	} else {
		if ((*bt)->key == key) {
			return 0;
		} else if (key < (*bt)->key) {
			return BSTInsert(&(*bt)->lchild, key);
		} else {
			return BSTInsert(&(*bt)->rchild, key);
		}
	}
}

// 构造二叉排序树
void CreateBST(BTNode* *bt, int key[], int n) {
	int i;
	(*bt) = NULL;
	for (i = 0; i < n; ++i) {
		BSTInsert(bt, key[i]);
	}
}

int main() {
	BTNode* bt;
	int key[10] = {5, 4, 2, 1, 7, 8, 9, 3, 10, 6};
	CreateBST(&bt, key, 10);
	int searchKey = 6;
	printf("查找元素%d: %s \n", searchKey, BSTSearch(bt, searchKey) == NULL ? "n" : "y");
	return 0;
}