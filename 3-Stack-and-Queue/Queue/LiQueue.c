#include <stdio.h>
#include <stdlib.h>

/*
 * 链队
 */

typedef struct LNode {
	int data;
	struct LNode *next;
} LNode;