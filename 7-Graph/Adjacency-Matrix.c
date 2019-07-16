#include <stdio.h>
#include <stdlib.h>

/*
 * 图的邻接矩阵
 */

#define maxSize 10

/* ----------定义---------- */

// 顶点
typedef struct {
	int no; // 顶点编号
	char info; // 顶点其他信息
} VertexType;

// 图的邻接矩阵
typedef struct {
	int edge[maxSize][maxSize]; // 邻接矩阵定义
	int n, e; // 顶点数、边数
	VertexType vex[maxSize]; // 结点信息
} MGraph;

/* ----------方法---------- */

/* 最小生成树 */

// 普里姆算法
void Prim(MGraph g, int v0, int *sum) {
	int lowcost[maxSize];
	int vset[maxSize];
	int v;
	int i, j, k, min;
	v = v0;
	// 初始化lowcost[]和vset[]
	for (i = 0; i < g.n; ++i) {
		lowcost[i] = g.edge[v0][i];
		vset[i] = 0;
	}
	vset[v0] = 1;
	(*sum) = 0;
	// 将其余顶点并入树中
	for (i = 0; i < g.n - 1; ++i) {
		min = 99999;
		// 选出当前结点候选边中的最小者
		for (j = 0; j < g.n; ++j) {
			if (vset[j] == 0 && lowcost[j] < min) {
				min = lowcost[j];
				k = j;
			}
		}
		// 最短边所到达的顶点并入树
		vset[k] = 1;
		v = k;
		// 记录最小生成树的权值
		(*sum) += min;
		// 以刚并入的顶点为媒介更新候选边
		for (j = 0; j < g.n; ++j) {
			if (vset[j] == 0 && g.edge[v][j] < lowcost[j]) {
				lowcost[j] = g.edge[v][j];
			}
		}
	}
}

int main() {

	return 0;
}