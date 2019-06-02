#include <stdio.h>
#include <stdlib.h>

/*
 * 链栈
 */

typedef struct LNode {
	int data;
	struct LNode *next;
} LNode;

void initStack(LNode **lst) {
	(*lst) = (LNode*)malloc(sizeof(LNode));
	(*lst)->next = NULL;
}

int isEmpty(LNode *lst) {
	if (lst->next == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void push(LNode *lst, int x) {
	LNode *p;
	p = (LNode*)malloc(sizeof(LNode));
	p->data = x;
	p->next = lst->next;
	lst->next = p;
}

int pop(LNode *lst, int *x) {
	LNode *p;
	if (lst->next == NULL) {
		return 0;
	}
	p = lst->next;
	*x = p->data;
	lst->next = p->next;
	free(p);
	return 1;
}

void printTop(LNode *lst) {
	printf("栈顶元素: %d\n", lst->next->data);
}

int main() {
	LNode *lst;
	initStack(&lst);
	printf("栈是否为空: %d\n", isEmpty(lst));
	push(lst, 1);
	push(lst, 2);
	push(lst, 3);
	push(lst, 4);
	int x;
	pop(lst, &x);
	printf("出栈元素: %d\n", x);
	printTop(lst);
	return 0;
}

