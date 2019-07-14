#include <stdio.h>
#include <stdlib.h>

/*
 * 图的邻接表
 */

#define maxSize 10
int visit[maxSize];

// 边表结点
typedef struct ArcNode {
	int adjvex; // 该边所指向的结点的位置
	struct ArcNode *nextarc; // 指向下一条边的指针
	int info; // 边的相关信息
} ArcNode;

// 顶点表结点
typedef struct {
	char data; // 顶点信息
	ArcNode *firstarc; // 指向第一条边的指针
} VNode;

// 图的邻接表
typedef struct {
	VNode adjlist[maxSize];
	int n, e;
} AGraph;

// 访问结点
void Visit(int v) {
	printf("%d ", v);
}

// 深度优先搜索
void DFS(AGraph *G, int v) {
	ArcNode *p;
	visit[v] = 1;
	Visit(v);
	p = G->adjlist[v].firstarc;
	if (p != NULL) {
		if (visit[p->adjvex] == 0) {
			DFS(G, p->adjvex);
		}
		p = p->nextarc;
	}
}

int main() {
	return 0;
}