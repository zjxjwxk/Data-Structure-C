#include <stdio.h>
#include <stdlib.h>

/*
 * 顺序队
 */

#define maxSize 10

typedef struct {
	int data[maxSize];
	int front;
	int rear;
} SqQueue;

void initQueue(SqQueue *qu) {
	qu->front = qu->rear = 0;
}

int isQueueEmpty(SqQueue qu) {
	if (qu.front == qu.rear) {
		return 1;
	} else {
		return 0;
	}
}

int enQueue(SqQueue *qu, int x) {
	if ((qu->rear + 1) % maxSize == qu->front) {
		return 0;
	}
	qu->rear = (qu->rear + 1) % maxSize;
	qu->data[qu->rear] = x;
	return 1;
}

int deQueue(SqQueue *qu, int *x) {
	if (qu->front == qu->rear) {
		return 0;
	}
	qu->front = (qu->front + 1) % maxSize;
	*x = qu->data[qu->front];
	return 1;
}

void printQueue(SqQueue qu) {
	int i;
	for (i = qu.front + 1; i <= qu.rear; ++i) {
		printf("%d ", qu.data[i]);
	}
	printf("\n");
}

int main() {
	SqQueue qu;
	initQueue(&qu);
	printf("队列是否为空: %d\n", isQueueEmpty(qu));
	enQueue(&qu, 1);
	enQueue(&qu, 2);
	enQueue(&qu, 3);
	enQueue(&qu, 4);
	printQueue(qu);
	int x;
	deQueue(&qu, &x);
	printf("出队元素: %d\n", x);
	printQueue(qu);
	return 0;
}