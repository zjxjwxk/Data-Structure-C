#include <stdio.h>
#include <stdlib.h>

/*
 * 链表
 */

typedef int Element;

typedef struct LNode {
	Element data;
	struct LNode *next;
} LNode, *LinkList;

LinkList List_HeadInsert(LinkList L) {
	LNode *s;
	int x;
	L = (LinkList) malloc(sizeof(LNode));
	if (L == NULL) {
		printf("头节点内存分配失败\n");
	}
	L->next = NULL;
	scanf("%d", &x);
	while(x != 9999) {
		s = (LNode *) malloc(sizeof(LNode));
		if (s == NULL) {
			printf("内存分配失败\n");
		}
		s->data = x;
		s->next = L->next;
		L->next = s;
		scanf("%d", &x);
	}
	return L;
}

void PrintList(LinkList L) {
	//L = L->next;
	if (L == NULL) {
		printf("链表为空\n");
	}
	printf("%d\n", L->data);
	// while (L != NULL) {
	// 	printf("%d ", L->data);
	// 	L = L->next;
	// }
}

int main() {
	LinkList L;
	List_HeadInsert(&L);
	PrintList(L);
	return 0;
}