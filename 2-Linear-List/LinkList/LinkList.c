#include <stdio.h>
#include <stdlib.h>

/*
 * 单链表
 */

typedef int Element;

typedef struct LNode {
	Element data;
	struct LNode *next;
} LNode;

/* 头插法 */
void List_HeadInsert(LNode **L, int a[], int n) {
	LNode *s;
	(*L) = (LNode*) malloc(sizeof(LNode));
	(*L)->next = NULL;
	for (int i = 0; i < n; i ++) {
		s = (LNode*) malloc(sizeof(LNode));
		s->data = a[i];
		s->next = (*L)->next;
		(*L)->next = s;
	}
}

/* 顺序输出链表 */
void PrintList(LNode *L) {
	//L = L->next;
	if (L->next == NULL) {
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
	LNode *L;
	int a[] = {1, 2, 3, 4};
	List_HeadInsert(&L, a, 4);
	PrintList(L);
	reprint(L->next);
	return 0;
}