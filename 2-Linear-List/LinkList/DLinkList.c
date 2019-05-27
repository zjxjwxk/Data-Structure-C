#include <stdio.h>
#include <stdlib.h>

/*
 * 双链表
 */

typedef struct DLNode {
	int data;
	struct DLNode *prior;
	struct DLNode *next;
} DLNode;

/* 尾插法建立双链表 */
void createDlistR(DLNode **L, int a[], int n) {
	DLNode *s, *r;
	int i;
	(*L) = (DLNode*)malloc(sizeof(DLNode));
	(*L)->prior = NULL;
	(*L)->next = NULL;
	r = (*L);
	for (i = 0; i < n; ++i) {
		s = (DLNode*)malloc(sizeof(DLNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}

/* 查找结点 */
DLNode* findNode(DLNode *C, int x) {
	DLNode *p = C->next;
	while (p != NULL) {
		if (p->data == x) {
			break;
		}
		p = p->next;
	}
	return p;
}

/* 插入结点，在p所指结点后插入一个结点s */
void insertNode(DLNode *p, DLNode *s) {
	s->next = p->next;
	s->prior = p;
	p->next = s;
	s->next->prior = s;
}

/* 删除结点 */
int deleteNode(DLNode *C, int x) {
	DLNode *p, *q;
	p = C;
	while (p->next != NULL) {
		if (p->next->data == x) {
			break;
		}
		p = p->next;
	}
	if (p->next == NULL) {
		return 0;
	} else {
		q = p->next;
		p->next = q->next;
		q->next->prior = p;
		free(q);
		return 1;
	}
}

/* 顺序输出链表 */
void print(DLNode *L) {
	if (L == NULL) {
		printf("链表为空\n");
	}
	while (L->next != NULL) {
		printf("%d ", L->next->data);
		L = L->next;
	}
	printf("\n");
}

int main() {
	DLNode *L;
	int a[] = {1, 3, 5, 7};
	createDlistR(&L, a, 4);  // 尾插法
	print(L);
	DLNode *p = findNode(L, 3);  // 寻找结点
	if (p != NULL) {
		printf("找到结点: %d\n", p->data);
	} else {
		printf("没有找到结点\n");
	}
	deleteNode(L, 3); // 删除结点
	print(L);
	DLNode *s = (DLNode*)malloc(sizeof(DLNode));  // 创建要插入的结点
	s->data = 6;
	s->next = NULL;
	s->prior = NULL;
	p = findNode(L, 5);
	insertNode(p, s);  // 插入结点
	print(L);
}