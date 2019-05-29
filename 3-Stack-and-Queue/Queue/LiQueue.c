#include <stdio.h>
#include <stdlib.h>

/*
 * 链队
 */

typedef struct QNode {
	int data;
	struct QNode *next;
} LNode;

typedef struct {
	QNode *front;
	QNode *rear;
} LiQueue;

