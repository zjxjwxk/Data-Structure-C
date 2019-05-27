#include <stdio.h>
#include <stdlib.h>

/*
 * 顺序栈
 */

#define maxSize 10

typedef struct {
	int data[maxSize];
	int top;
} SqStack;

void initStack(SqStack *st) {
	st->top = -1;
}

int isEmpty(SqStack st) {
	if (st.top == -1) {
		return 1;
	} else {
		return 0;
	}
}

int push(SqStack *st, int x) {
	if (st->top == maxSize) {
		return 0;
	}
	st->data[++st->top] = x;
	return 1;
}

int pop(SqStack *st, int *x) {
	if (st->top == -1) {
		return 0;
	}
	*x = st->data[st->top--];
	return 1;
}

void printTop(SqStack st) {
	printf("栈顶元素: %d \n", st.data[st.top]);
}

int main() {
	SqStack st;
	initStack(&st);
	printf("栈是否为空: %d\n", isEmpty(st));
	push(&st, 1);
	push(&st, 2);
	push(&st, 3);
	push(&st, 4);
	int x;
	pop(&st, &x);
	printf("出栈元素: %d\n", x);
	printTop(st);
	return 0;
}