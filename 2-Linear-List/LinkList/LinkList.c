#include <stdio.h>
#include <stdlib.h>

/*
 * 单链表
 */

typedef struct LNode {
	int data;
	struct LNode *next;
} LNode;

/* 尾插法 */
void createlistR(LNode **C, int a[], int n) {
	LNode *s, *r;
	int i;
	(*C) = (LNode *)malloc(sizeof(LNode));
	(*C)->next = NULL;
	r = (*C);
	for (i = 0; i < n; ++i) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = a[i];
		r->next = s;
		r = r->next;
	}
	r->next = NULL;
}

/* 头插法 */
void createlistF(LNode **C, int a[], int n) {
	LNode *s;
	int i;
	(*C) = (LNode*)malloc(sizeof(LNode));
	(*C)->next = NULL;
	for (i = 0; i < n; ++i) {
		s = (LNode*)malloc(sizeof(LNode));
		s->data = a[i];
		s->next = (*C)->next;
		(*C)->next = s;
	}
}

/* 归并两个递增单链表A,B为递增单链表C */
void mergeIncre(LNode *A, LNode *B, LNode **C) {
	LNode *p = A->next;  // 跟踪A的最小值
	LNode *q = B->next;  // 跟踪B的最小值
	LNode *r;  // r始终指向C的终端结点
	(*C) = A;  // 用A的头结点来做C的头结点
	(*C)->next = NULL;
	free(B);
	r = (*C);
	while (p != NULL && q != NULL) {
		if (p->data <= q->data) {
			r->next = p;
			p = p->next;
			r = r->next;
		} else {
			r->next = q;
			q = q->next;
			r = r->next;
		}
	}
	r->next = NULL;
	// 将还有剩余结点的链表链接在C的尾部
	if (p != NULL) {
		r->next = p;
	}
	if (q != NULL) {
		r->next = q;
	}
}

/* 归并两个递增单链表A,B为递减单链表C */
void mergeDecre(LNode *A, LNode *B, LNode **C) {
	LNode *p = A->next;
	LNode *q = B->next;
	LNode *s;
	(*C) = A;
	(*C)->next = NULL;
	free(B);
	while (p != NULL && q != NULL) {
		if (p->data <= q->data) {
			s = p;
			p = p->next;
			s->next = (*C)->next;
			(*C)->next = s;
		} else {
			s = q;
			q = q->next;
			s->next = (*C)->next;
			(*C)->next = s;
		}
	}
	// 将剩余元素逐个插入(*C)的头部
	while (p != NULL) {
		s = p;
		p = p->next;
		s->next = (*C)->next;
		(*C)->next = s;
	}
	while (q != NULL) {
		s = q;
		q = q->next;
		s->next = (*C)->next;
		(*C)->next = s;
	}
}

// 查找并删除链表中值为x的结点
int findAndDelete(LNode *C, int x) {
	LNode *p, *q;
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
		p->next = p->next->next;
		free(q);
		return 1;
	}
}

/* 顺序输出链表 */
void print(LNode *L) {
	if (L == NULL) {
		printf("链表为空\n");
	}
	while (L->next != NULL) {
		printf("%d ", L->next->data);
		L = L->next;
	}
	printf("\n");
}

/* 逆序输出链表 */
void reprint(LNode *L) {
	if (L != NULL) {
		reprint(L->next);
		printf("%d ", L->data);
	}
}

int main() {
	LNode *A;
	LNode *B;
	LNode *C;
	int a[] = {1, 3, 5, 7};
	int b[] = {2, 4, 6, 8};
	//createlistF(&A, a, 4); // 头插法
	createlistR(&A, a, 4);  //尾插法
	createlistR(&B, b, 4);  //尾插法
	mergeIncre(A, B, &C);  // 归并为递增
	//mergeDecre(A, B, &C);  // 归并为递减
	findAndDelete(C, 2);
	print(C);  //正序输出
	reprint(C->next);  //逆序输出
	return 0;
}