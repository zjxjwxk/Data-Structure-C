#include <stdio.h>
#include <stdlib.h>

/*
 * 链队
 */

typedef struct QNode {
	int data;
	struct QNode *next;
} QNode;

typedef struct {
	struct QNode *front;
	struct QNode *rear;
} LiQueue;

void initQueue(LiQueue **lqu) {
	(*lqu) = (LiQueue *)malloc(sizeof(LiQueue));
	(*lqu)->front = (*lqu)->rear = NULL;
}

int isQueueEmpty(LiQueue *lqu) {
	if (lqu->rear == NULL || lqu->front == NULL) {
		return 1;
	} else {
		return 0;
	}
}

void enQueue(LiQueue *lqu, int x) {
	QNode *p;
	p = (QNode *)malloc(sizeof(QNode));
	p->data = x;
	p->next = NULL;
	if (lqu->rear == NULL) {
		lqu->front = lqu->rear = p;
	} else {
		lqu->rear->next = p;
		lqu->rear = p;
	}
}

int deQueue(LiQueue *lqu, int *x) {
	QNode *p;
	if (lqu->rear == NULL) {
		return 0;
	} else {
		p = lqu->front;
	}
	if (lqu->front == lqu->rear) {  //只有一个结点时出队操作需特殊处理
		lqu->front = lqu->rear = NULL;
	} else {
		lqu->front = lqu->front->next;
	}
	*x = p->data;
	free(p);
	return 1;
}

void printQueue(LiQueue *lqu) {
	QNode *p = lqu->front;
	while (p != NULL) {
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main() {
	LiQueue *lqu;
	initQueue(&lqu);
	printf("队列是否为空: %d\n", isQueueEmpty(lqu));
	enQueue(lqu, 1);
	enQueue(lqu, 2);
	enQueue(lqu, 3);
	enQueue(lqu, 4);
	printQueue(lqu);
	int x;
	deQueue(lqu, &x);
	printf("出队元素: %d\n", x);
	printQueue(lqu);
	return 0;
}
