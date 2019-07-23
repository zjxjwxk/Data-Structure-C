#include <stdio.h>
#include <stdlib.h>

/*
 * 拓扑排序
 */

#define maxSize 10
int visit[maxSize];

/* ----------定义---------- */

// 边表结点
typedef struct ArcNode {
	int adjvex; // 该边所指向的结点的位置
	struct ArcNode *nextarc; // 指向下一条边的指针
	int info; // 边的相关信息
} ArcNode;

// 顶点表结点
typedef struct {
	char data; // 顶点信息
	int count; // 统计顶点当前的入度
	ArcNode *firstarc; // 指向第一条边的指针
} VNode;

// 图的邻接表
typedef struct {
	VNode adjlist[maxSize];
	int n, e;
} AGraph;

// TopSort 拓扑排序
void TopSort(AGraph *G) {
	int i, j, n = 0;
	int stack[maxSize];
	int top = -1;
	ArcNode *p;
	// 将入度为0的顶点入栈
	for (i = 0; i < G.n; ++i) {
		if (G->adjlist[i].count == 0) {
			stack[++top] = i;
		}
	}
	// 关键操作
	while (top != -1) {
		i = stack[top--];
		++n;
		printf("%d ", i);
		p = G->adjlist[i].firstarc;
		// 将所有此顶点引出的边所指向的顶点入度都减1，并将这个过程中入度为0的顶点入栈
		while (p != NULL) {
			j = p->adjvex;
			--(G->adjlist[j].count);
			if (G->adjlist[j].count == 0) {
				stack[++top] = j;
			}
			p = p->nextarc;
		}
	}
	if (n == G->n) {
		return 1;
	} else {
		return 0;
	}
}

int main() {
	return 0;
}