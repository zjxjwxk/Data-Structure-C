#include <stdio.h>
#include <stdlib.h>

/*
 * 图的邻接矩阵
 */

#define maxSize 10
#define INF 99999;

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

/* 
 * 最小生成树
 */

/* 1. Prim 普里姆算法 */

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
		min = INF;
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

/* 2. Kruskal 克鲁斯卡尔算法 */

// Road结构体存放各边及所连接的两个顶点
typedef struct {
	int a, b; // 两个顶点
	int w; // 边的权值
} Road;

Road road[maxSize];
// 并查集数组
int v[maxSize];

// 在并查集中寻找根结点
int getRoot(int a) {
	while (a != v[a]) {
		a = v[a];
	}
	return a;
}

// Kruskal 克鲁斯卡尔算法
void Kruskal(MGraph g, int *sum, Road road[]) {
	int i;
	int N, E, a, b;
	N = g.n;
	E = g.e;
	(*sum) = 0;
	for (i = 0; i < N; ++i) {
		v[i] = i;
	}
	// sort(road); // 将road[]中各边按权值从小到大排序（排序算法未实现）
	for (i = 0; i < E; ++i) {
		a = getRoot(road[i].a);
		b = getRoot(road[i].b);
		if (a != b) {
			v[a] = b;
			(*sum) += road[i].w;
		}
	}
}

/* 
 * 最短路径
 */

// 1. Dijkstra 迪杰斯特拉算法

// 输出源点到任何一个顶点最短路径上所经过的所有结点
void printfPath(int path[], int a) {
	int stack[maxSize];
	int top = -1;
	while (path[a] != -1) {
		stack[++top] = a;
		a = path[a];
	}
	stack[++top] = a;
	while (top != -1) {
		printf("%d ", stack[top--]);
	}
	printf("\n");
}

/*
 * Dijkstra 迪杰斯特拉算法
 * dist[]存放v点到其余顶点的最短路径长度
 * path[]存放v点到其余各顶点的最短路径
 */
void Dijkstra(MGraph g, int v, int dist[], int path) {
	int set[maxSize];
	int min, i, j, u;
	// 对各数组进行初始化
	for (i = 0; i < g.n; ++i) {
		dist[i] = g.edge[v][i];
		set[i] = 0;
		if (g.edge[v][i] < INF) {
			path[i] = v;
		} else {
			path[i] = -1;
		}
	}
	set[v] = 1;
	path[v] = -1;
	// 关键操作开始
	for (i = 0; i < g.n - 1; ++i) {
		min = INF;
		// 选出dist[]中的最短路径
		for (j = 0; j < g.n; ++j) {
			if (set[j] = 0 && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		}
		// 将选出的顶点并入最短路径中
		set[u] = 1;
		// 以刚并入的顶点为中间点，更新dist[]和path[]
		for (j = 0; j < g.n; ++j) {
			if (set[j] = 0 && dist[u] + g.edge[u][j] < dist[j]) {
				dist[j] = dist[u] + g.edge[u][j];
				path[j] = u;
			}
		}
	}
}

int main() {

	return 0;
}