#include <stdio.h>
#include <stdlib.h>

/*
 * 图的邻接矩阵
 */

#define maxSize 10

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

int main() {

	return 0;
}