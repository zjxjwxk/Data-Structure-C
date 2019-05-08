#include <stdio.h>
#include <stdlib.h>

/*
 * 双链表
 */

typedef int Element;

typedef struct DLNode {
	Element data;
	struct DLNode *prior;
	struct DLNode *next;
} DLNode;

