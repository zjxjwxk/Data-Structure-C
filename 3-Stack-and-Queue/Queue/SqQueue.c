#include <stdio.h>
#include <stdlib.h>

/*
 * 顺序队
 */

typedef struct {
	int data[maxSize];
	int front;
	int rear;
} SqQueue;